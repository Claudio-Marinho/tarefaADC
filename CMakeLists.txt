# Generated CMake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(tarefaADC C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Adicionar todos os arquivos .c ao executável
add_executable(tarefaADC 
    tarefaADC.c 
    joystick.c 
    pwm_control.c 
    display.c 
    buttons.c
)

pico_set_program_name(tarefaADC "tarefaADC")
pico_set_program_version(tarefaADC "0.1")

# Modificar para habilitar saída via UART e USB
pico_enable_stdio_uart(tarefaADC 1)
pico_enable_stdio_usb(tarefaADC 1)

# Adicionar a biblioteca padrão do Pico
target_link_libraries(tarefaADC
    pico_stdlib
    hardware_spi
    hardware_i2c
    hardware_dma
    hardware_timer
    hardware_watchdog
    hardware_clocks
    hardware_pwm     # Adicionado para controle dos LEDs via PWM
    hardware_adc     # Adicionado para leitura do joystick via ADC
    hardware_irq     # Adicionado para interrupções dos botões
)

# Incluir diretórios de cabeçalhos
target_include_directories(tarefaADC PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Gerar arquivos binários e UF2
pico_add_extra_outputs(tarefaADC)
