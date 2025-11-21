#include "storage.h"


void storage_init(void) {
// setup emulated EEPROM in flash or mount SD card
}


int storage_check_pin(const char *pin) {
// compare with stored pins
return strcmp(pin, "1234") == 0;
}


void storage_log_event(const char *event, int id) {
// append to SD card or save in flash circular buffer
}
