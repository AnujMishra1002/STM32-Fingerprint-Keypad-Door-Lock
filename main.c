/* main.c - simplified */
#include "main.h"
#include "keypad.h"
#include "fingerprint.h"
#include "actuator.h"
#include "storage.h"


int main(void) {
HAL_Init();
SystemClock_Config();
MX_GPIO_Init();
MX_USART1_UART_Init(); // fingerprint
MX_TIM2_Init(); // actuator PWM if needed


fingerprint_init(&huart1);
keypad_init();
actuator_init();
storage_init();


// Simple loop
while (1) {
// 1) Check fingerprint
int fp_id = fingerprint_check();
if (fp_id >= 0) {
// success
actuator_unlock();
storage_log_event("FP_UNLOCK", fp_id);
HAL_Delay(3000);
actuator_lock();
continue;
}


// 2) Check keypad - non-blocking
char *pin = keypad_get_pin(); // returns NULL if none entered
if (pin) {
int ok = storage_check_pin(pin);
if (ok) {
actuator_unlock();
storage_log_event("PIN_UNLOCK", -1);
HAL_Delay(3000);
actuator_lock();
}
}


HAL_Delay(50);
}
}
