#include <stdio.h>
#include "pico/stdlib.h"
#include "joystick.h"
#include "pwm_control.h"
#include "display.h"
#include "buttons.h"

#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13

int main() {
    stdio_init_all();
    
    // Inicializar os módulos
    joystick_init();
    pwm_control_init();
    display_init();
    buttons_init();
    
    while (1) {
        uint16_t x_value = joystick_read_x();
        uint16_t y_value = joystick_read_y();

        printf("Joystick X: %d, Joystick Y: %d\n", x_value, y_value);  // Debug
        
        // Atualiza o PWM dos LEDs com escala correta
        pwm_set_duty_cycle(LED_RED, (x_value * 65535) / 4095);
        pwm_set_duty_cycle(LED_GREEN, ((x_value + y_value) / 2) * 65535 / 4095);  // Verde = Média de X e Y
        pwm_set_duty_cycle(LED_BLUE, (y_value * 65535) / 4095);
        
        // Atualiza a posição do quadrado no display
        display_update_position(x_value, y_value);
        
        if (button_a_pressed) {
            printf("Ativando LEDs!\n");
            pwm_set_duty_cycle(LED_RED, 65535);
            pwm_set_duty_cycle(LED_GREEN, 65535);
            pwm_set_duty_cycle(LED_BLUE, 65535);
        }
    
        if (joystick_button_pressed) {
            printf("Desativando LEDs!\n");
            pwm_set_duty_cycle(LED_RED, 0);
            pwm_set_duty_cycle(LED_GREEN, 0);
            pwm_set_duty_cycle(LED_BLUE, 0);
        }


        sleep_ms(100);
    }
    return 0;
}