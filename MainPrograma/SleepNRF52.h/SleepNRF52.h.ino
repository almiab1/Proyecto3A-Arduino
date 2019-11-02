// ----------------------------------
// Carlos Mª Canut Domínguez
// SleepNRF52
// ----------------------------------

// ----------------------------------
// includes
// ----------------------------------

#ifndef _ARDUINO_LOW_POWER_H_
#define _ARDUINO_LOW_POWER_H_

#include <Arduino.h>

#ifdef ARDUINO_ARCH_AVR
#error The library is not compatible with AVR boards
#endif

#ifdef ARDUINO_ARCH_SAMD
#include "RTCZero.h"
#endif

#if defined(ARDUINO_SAMD_TIAN) || defined(ARDUINO_NRF52_PRIMO)
// add here any board with companion chip which can be woken up
#define BOARD_HAS_COMPANION_CHIP
#endif

#define RTC_ALARM_WAKEUP  0xFF


// NRF52 includes
#if defined(ARDUINO_ARCH_NRF52)

#include "ArduinoLowPower.h"
#include "WInterrupts.h"
#include "nrf_rtc.h"
// NRF52 includes

// Includes

// ----------------------------------
// ----------------------------------
// ----------------------------------

class SleepNRF52 {
  // Private

// ----------------------------------
  void SleepNRF52::setAlarmIn(uint32_t millis) {
  nrf_rtc_prescaler_set(NRF_RTC1, 32);
  //enable interrupt
  NVIC_SetPriority(RTC1_IRQn, 2); //high priority
  NVIC_ClearPendingIRQ(RTC1_IRQn);
  NVIC_EnableIRQ(RTC1_IRQn);
  nrf_rtc_event_clear(NRF_RTC1, NRF_RTC_EVENT_COMPARE_0);
  nrf_rtc_int_enable(NRF_RTC1, NRF_RTC_INT_COMPARE0_MASK);
  //Tick every 1 ms 
  nrf_rtc_cc_set(NRF_RTC1, 0, millis);
  
  //start RTC
  nrf_rtc_task_trigger(NRF_RTC1, NRF_RTC_TASK_START);
}
// ----------------------------------

  // Public

  void sleep(void);
    void sleep(uint32_t millis);
    void sleep(int millis) {
      sleep((uint32_t)millis);
    }

// ----------------------------------
  void SleepNRF52::sleep() {
  sd_power_mode_set(NRF_POWER_MODE_LOWPWR);
  event=false;    
  while(!event){
    sd_app_evt_wait();
  }       
}
// ----------------------------------

// ----------------------------------
  void SleepNRF52::sleep(uint32_t millis) {
  setAlarmIn(millis);
  sleep();
}
// ----------------------------------

  #ifdef __cplusplus
extern "C"{
#endif  

void RTC1_IRQHandler(void)
{
  event=true;
  nrf_rtc_event_clear(NRF_RTC1, NRF_RTC_EVENT_COMPARE_0);
  nrf_rtc_task_trigger(NRF_RTC1, NRF_RTC_TASK_CLEAR);
  nrf_rtc_task_trigger(NRF_RTC1, NRF_RTC_TASK_STOP);
  if(functionPointer)
    functionPointer();    
}

#ifdef __cplusplus
}
#endif

#endif // ARDUINO_ARCH_NRF52

#endif

}; // Class SleepNRF52
