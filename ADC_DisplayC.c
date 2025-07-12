// Inclusão das bibliotecas necessárias
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "./lib/ssd1306.h"
#include "./lib/font.h"

// Definições dos pinos e perifericos
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define DISPLAY_ADDR 0x3C
#define VRX_PIN 27  // Eixo X do joystick (ADC1)

ssd1306_t display;

// Estrutura de configuração do display - Láisa Bianca
void setup_display() {
    
}

// Função principal, integrando ADC e SSD1306 - Laíse Café
int main() {
 
}