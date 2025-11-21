#include "actuator.h"


void actuator_init(void) {
// configure GPIO output for relay
}


void actuator_unlock(void) {
HAL_GPIO_WritePin(RELAY_PORT, RELAY_PIN, GPIO_PIN_SET); // energize
}


void actuator_lock(void) {
HAL_GPIO_WritePin(RELAY_PORT, RELAY_PIN, GPIO_PIN_RESET);
}
