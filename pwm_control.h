#ifndef PWM_CONTROL_H
#define PWM_CONTROL_H
#include <stdint.h>  // Certifique-se de incluir este cabeçalho

void pwm_control_init();  
void pwm_set_duty_cycle(uint32_t pin, uint16_t value);  // Alterado uint -> uint32_t

#endif // PWM_CONTROL_H
