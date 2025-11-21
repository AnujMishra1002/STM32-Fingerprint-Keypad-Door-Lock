#include "fingerprint.h"
#include "stm32f1xx_hal.h"


extern UART_HandleTypeDef huart1;


void fingerprint_init(UART_HandleTypeDef *huart) {
// send module init commands if needed
}


// Returns template ID on success, -1 on no match
int fingerprint_check(void) {
uint8_t cmd_search[] = { /* standard search command for R305 */ };
uint8_t resp[32];
HAL_UART_Transmit(&huart1, cmd_search, sizeof(cmd_search), 200);
if (HAL_UART_Receive(&huart1, resp, sizeof(resp), 500) > 0) {
// parse response
int matched_id = -1;
// parse code here
return matched_id;
}
return -1;
}
