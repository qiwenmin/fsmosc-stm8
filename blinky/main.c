#include "stm8s.h"
#include "fsmosc.h"
#include "util.h"

enum {
  STATE_LED_ON = FO_STATE_TASK_DEF_BEGIN,
  STATE_LED_OFF
};

void blink_task_f(fo_task_ptr t, FO_STATE state, FO_STATE new_state) {
    state;
  switch (new_state) {
  case FO_STATE_INIT:
    set_bit(PB_DDR, 5);
    set_bit(PB_CR1, 5);
    fo_goto_state(t, STATE_LED_ON);
    break;
  case STATE_LED_ON:
    clear_bit(PB_ODR, 5);
    fo_delay(t, 200, STATE_LED_OFF);
    break;
  case STATE_LED_OFF:
    set_bit(PB_ODR, 5);
    fo_delay(t, 800, STATE_LED_ON);
    break;
  case FO_STATE_INVALID:
    break;
  default:
    break;
  }
}

FO_INIT(1)

void setup() {
  fo_create_task(blink_task_f);
}

void loop() {
  fo_loop();
}
