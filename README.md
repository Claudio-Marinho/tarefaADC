Tarefa - ADC

Este projeto foi desenvolvido como parte da atividade prática individual do estudo sobre interfaces de comunicação serial no RP2040, e explora o uso de interrupções, PWM, controle de LEDs e comunicação I2C. O objetivo principal é integrar hardware e software para controlar LEDs e interagir com o display OLED SSD1306 e os LEDs RGB usando um joystick e botões.

 Objetivos

    Explorar o funcionamento de interrupções e debouncing em sistemas embarcados.
    Implementar controle de LEDs RGB e PWM.
    Controlar a exibição de informações no display SSD1306 via I2C.
    Desenvolver funcionalidades de interação com botões e joystick.
    Aprender a integrar GPIOs, ADC e comunicação I2C para controlar dispositivos externos.

 Descrição do Projeto

O projeto envolve o uso dos seguintes componentes conectados à placa RP2040:

    Display OLED SSD1306 conectado via I2C (GPIO 14 e GPIO 15).
    LEDs RGB com pinos conectados às GPIOs 11, 12 e 13.
    Joystick com pinos conectados às GPIOs 22, 26 (X) e 27 (Y).
    Botão A conectado à GPIO 5.
    Botão B conectado à GPIO 6.

 Funcionalidades do Projeto
1️⃣ Controle de LEDs

    LEDs RGB controlados por PWM (com os pinos GPIO 11, 12, 13) para mostrar a intensidade de cor dependendo da leitura do joystick.
    O LEDs on/off é alternado com a pressão do botão A.

2️⃣ Controle do Display OLED SSD1306

    O projeto usa o display SSD1306 para exibir um pixel de 8x8 bits que representa sinal analógico do joystick.
    A borda do display alterna entre um círculo e um retângulo ao pressionar o botão do joystick.

3️⃣ Leitura do Joystick

    O joystick fornece entradas analógicas que são lidas através do ADC e mapeadas para controlar a posição de um quadrado no display.
    A movimentação do joystick altera a posição do quadrado no display SSD1306, e a intensidade dos LEDs RGB é controlada pela posição do joystick.

4️⃣ Interrupções e Debouncing

    O projeto usa interrupções para detectar a pressão dos botões (A e B).
    Implementação de debouncing para garantir que os botões não gerem múltiplas interrupções ao serem pressionados.

 Requisitos do Projeto

Para o desenvolvimento, devem ser seguidos os seguintes requisitos:

    Uso de interrupções: Todas as funcionalidades dos botões (A, B, Joystick) devem ser implementadas com rotinas de interrupção (IRQ).
    Debouncing: Implementar tratamento de bouncing via software para garantir que os botões não gerem múltiplas interrupções.
    Controle de LEDs: Utilizar LEDs RGB com PWM para controlar a cor dos LEDs conforme as leituras do joystick.
    Uso do Display SSD1306:
        Exibir informações sobre o status dos LEDs no display.
        Mostrar o quadrado movido pelo joystick e alterar a borda entre círculo e retângulo.
    Comunicação I2C: Demonstrar compreensão e implementação do protocolo I2C para controlar o display.
    Controle de LEDs via Joystick: O movimento do joystick deve ser refletido na posição do quadrado no display SSD1306 e na intensidade dos LEDs RGB.
