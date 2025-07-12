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

    // Inicializa a comunicação I2C com velocidade de 400 kHz no barramento definido por I2C_PORT
    i2c_init(I2C_PORT, 400 * 1000);

    // Define os pinos GPIO conectados ao SDA e SCL para a função de I2C.
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);

    // Ativa resistores de pull-up internos nos pinos SDA e SCL
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);  
    
    // Inicializa a estrutura de controle do display
    ssd1306_init(&display, WIDTH, HEIGHT, false, DISPLAY_ADDR, I2C_PORT);

    // Configura o display com as definições padrão da biblioteca
    ssd1306_config(&display);

    // Limpa a tela preenchendo-a com pixels desligados
    ssd1306_fill(&display, false);

    // Envia os dados para o display, atualizando-o com a tela limpa
    ssd1306_send_data(&display);
    
}

// Função principal, integrando ADC e SSD1306 - Laíse Café
int main() {
 
}