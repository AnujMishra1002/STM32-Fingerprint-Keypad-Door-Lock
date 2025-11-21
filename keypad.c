#include "keypad.h"
#include "stm32f1xx_hal.h"


// Example pin arrays
GPIO_TypeDef* ROW_PORT[4] = {GPIOA, GPIOA, GPIOA, GPIOA};
uint16_t ROW_PIN[4] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3};
GPIO_TypeDef* COL_PORT[4] = {GPIOA, GPIOA, GPIOA, GPIOA};
uint16_t COL_PIN[4] = {GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7};


void keypad_init(void) {
// configure row pins as input pull-up, column pins as output high
}


char keypad_get_key(void) {
for (int c=0;c<4;c++) {
HAL_GPIO_WritePin(COL_PORT[c], COL_PIN[c], GPIO_PIN_RESET);
HAL_Delay(1);
for (int r=0;r<4;r++) {
if (HAL_GPIO_ReadPin(ROW_PORT[r], ROW_PIN[r]) == GPIO_PIN_RESET) {
// key pressed at (r,c)
HAL_GPIO_WritePin(COL_PORT[c], COL_PIN[c], GPIO_PIN_SET);
return map_key(r,c);
}
}
HAL_GPIO_WritePin(COL_PORT[c], COL_PIN[c], GPIO_PIN_SET);
}
return '\0';
}


// Implement keypad_get_pin() to collect digits until '#' pressed
