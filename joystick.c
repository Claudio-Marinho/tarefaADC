#include "joystick.h"
#include "hardware/adc.h"

void joystick_init() {
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27);
}

uint16_t joystick_read_x() {
    adc_select_input(0);
    return adc_read();
}

uint16_t joystick_read_y() {
    adc_select_input(1);
    return adc_read();
}