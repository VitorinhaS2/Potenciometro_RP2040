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
    stdio_init_all();            
    adc_init();                  
    adc_gpio_init(VRX_PIN);      
    adc_select_input(1);         

    setup_display();             // Inicializa o display OLED SSD1306

    char buffer[32];             // Buffer para armazenar a string formatada da tensão

    while (true) {
        uint16_t raw = adc_read();                 // Realiza a leitura bruta do ADC (valor entre 0 e 4095)
        float voltage = raw * 3.3f / 4095;         // Converte a leitura para tensão (0V a 3.3V)

        // Formata a tensão com duas casas decimais e armazena no buffer
        snprintf(buffer, sizeof(buffer), "%.2f", voltage);

        // Cálculo para centralizar o texto no display
        int char_width = 8;                        // Largura estimada de cada caractere em pixels 
        int str_len = strlen(buffer);              // Número de caracteres na string
        int total_width = str_len * char_width;    // Largura total da string
        int x = (128 - total_width) / 2;           // Coordenada X centralizada
        int y = (64 - 8) / 2;                      // Coordenada Y centralizada

        ssd1306_fill(&display, false);             // Limpa o conteúdo anterior da tela 
        ssd1306_draw_string(&display, buffer, x, y);  // Desenha a string formatada na posição central
        ssd1306_send_data(&display);               // Envia os dados para o display

        sleep_ms(500);                             // Aguarda meio segundo antes da próxima leitura
    }
}
