#include "hardware/gpio.h" // Adiciona a definição do GPIO_FUNC_I2C
#include "display.h"
#include "hardware/i2c.h"

void display_init() {
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(14, GPIO_FUNC_I2C);
    gpio_set_function(15, GPIO_FUNC_I2C);
    gpio_pull_up(14);
    gpio_pull_up(15);
}

void display_update_position(uint16_t x, uint16_t y) {
    // Código para atualizar a posição do quadrado no display SSD1306
}