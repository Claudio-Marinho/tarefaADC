#include "pwm_control.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

void pwm_control_init() {
    gpio_set_function(11, GPIO_FUNC_PWM);
    gpio_set_function(12, GPIO_FUNC_PWM);
    gpio_set_function(13, GPIO_FUNC_PWM);
    
    uint slice_red = pwm_gpio_to_slice_num(11);
    uint slice_green = pwm_gpio_to_slice_num(12);
    uint slice_blue = pwm_gpio_to_slice_num(13);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_wrap(&config, 65535);
    pwm_init(slice_red, &config, true);
    pwm_init(slice_green, &config, true);
    pwm_init(slice_blue, &config, true);
}

void pwm_set_duty_cycle(uint32_t pin, uint16_t value) {  // Alterado uint -> uint32_t
    uint slice = pwm_gpio_to_slice_num(pin);
    pwm_set_gpio_level(pin, value);
    pwm_set_enabled(slice, true);
}
