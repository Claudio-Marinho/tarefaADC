#ifndef BUTTONS_H
#define BUTTONS_H
#include <stdbool.h>

void buttons_init();

extern volatile bool button_a_pressed;
extern volatile bool joystick_button_pressed;

#endif // BUTTONS_H
