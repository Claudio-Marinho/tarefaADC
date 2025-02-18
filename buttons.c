#include "buttons.h"
#include "pico/stdlib.h"
#include <stdio.h>

#define DEBOUNCE_DELAY_MS 200  // Tempo para evitar bouncing

volatile bool button_a_pressed = false;
volatile bool joystick_button_pressed = false;

void button_callback(uint gpio, uint32_t events) {
    static uint32_t last_interrupt_time = 0;
    uint32_t current_time = to_ms_since_boot(get_absolute_time());

    if (current_time - last_interrupt_time < DEBOUNCE_DELAY_MS) {
        return;  // Ignora bouncing
    }
    last_interrupt_time = current_time;

    if (gpio == 5) {
        button_a_pressed = !button_a_pressed;  // Alterna estado
        printf("Botão A pressionado!\n");
    } else if (gpio == 22) {
        joystick_button_pressed = !joystick_button_pressed;
        printf("Botão do joystick pressionado!\n");
    }
}

void buttons_init() {
    gpio_set_irq_enabled_with_callback(5, GPIO_IRQ_EDGE_FALL, true, &button_callback);
    gpio_set_irq_enabled_with_callback(22, GPIO_IRQ_EDGE_FALL, true, &button_callback);
}
