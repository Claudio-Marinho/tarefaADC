#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <stdint.h>

void joystick_init();
uint16_t joystick_read_x();
uint16_t joystick_read_y();

#endif // JOYSTICK_H