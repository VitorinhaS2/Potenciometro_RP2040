**CONVERSORES A/D E INTERFACE DE COMUNCAÇÃO I2C NO RP2040**

Este repositório contém o código-fonte e o diagrama referentes a 3º atividade da disciplina de Microcontroladores. O código consiste em utilizar o microcontrolador Raspberry Pi Pico W, um joystick e um display para obter os valores de tensão do eixo X e plotar esses valores no display, integrando hardware e software.

**COMPONENTES UTILIZADOS**

Neste projeto foram utilizados os seguintes componentes:

- Microcontrolador Raspberry pi pico w.
- Display SSD1306: Conectado via I2C nas GPIOs 14 e 15.
- Joystick: Conectado às GPIOS 26 e 27.

**FUNCIONALIDADES IMPLEMENTADAS**

1. Inicialização e Configuração do Display OLED SSD1306:  
- Comunicação via barramento I2C utilizando os pinos GPIO14 (SDA) e GPIO15 (SCL).
- Inicialização do display com envio dos comandos de configuração padrão.
- Limpeza da tela e atualização do conteúdo a partir de um buffer de memória local.  

2. Leitura Analógica do eixo X do Joystick:
- Leitura contínua da tensão analógica no pino GPIO27 (canal ADC1).
- Conversão do valor lido do ADC (0–4095) para uma tensão real (0.00V a 3.30V).
- Amostragem com intervalo de 500 ms entre cada leitura.  

3. Exibição da Tensão no Display OLED:
- Valor de tensão convertido é formatado com duas casas decimais.
- A string contendo o valor é centralizada automaticamente no display de 128x64 pixels.

## Organização da Equipe
- **Líder de Projeto:** [VITÓRIA CAVALCANTI] — responsável pelo gerenciamento do repositório, estrutura do código e revisão dos pull requests.
- **Desenvolvedor 1:** [LÁISA BIANCA] — responsável pela estrutura e configuração do display.
- **Desenvolvedor 2:** [LAÍSE CAFÉ] — responsável por integrar o valor obtido do sinal do eixo x do joystick e integrar ao display.


**VÍDEO EXPLICATIVO**   

[Link do vídeo explicativo](https://www.canva.com/design/DAGs_zHaqMg/DqLZE-9tVf2aB3n2NR3vXw/watch?utm_content=DAGs_zHaqMg&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h98cab553fc)

## Licença
Este projeto é destinado exclusivamente para fins acadêmicos na disciplina **ELET0021 — Microcontroladores e Microprocessadores**.
