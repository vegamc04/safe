
[Inglês](https://github.com/vegamc04/safe/blob/master/README.md)

[Espanhol](https://github.com/vegamc04/safe/blob/master/readme_config/versions/readme_es.md)

![arduino](../media/svg/arduino_icon.svg)

# Cofre

Projeto desenvolvido com [Arduino](https://www.arduino.cc/)

## Componentes utilizados

- Arduino UNO R3
- Contêiner (tamanho de preferência)
- Placa de ensaios (tamanho de preferência)
- Resistores 220 Ω - Quantidade: **3**
- KY-017 (sensor de inclinação de mercúrio)
- Buzzer ativo
- Led - Quantidade: **3**
- Teclado matricial 4x4
- Cabo dupont fêmea-macho - Quantidade: **11**
- Cabo dupont macho-macho - Quantidade: **10**
- Cabo USB A para USB B (para Arduino)

## Instruções de inicialização

1. Instale a biblioteca "Arduino AVR Boards" do Arduino no seu ambiente de desenvolvimento preferido (recomenda-se o Arduino IDE) através do Gerenciador de Placas.

2. Navegue até o arquivo [arduino.ino](./arduino.ino) e conecte seu Arduino Uno ao seu computador usando o cabo USB, carregue o código e depois reinicie-o.

## Funcionamento

|Tecla|Ação|
|:--------|:--------|
|A|Desarmar|
|B|Definir senha e ( Alterar senha )|
|C|[ Rearmar ]|
|D|( Resetar )|
**( )** A ação requer confirmação de senha antes da execução.
**[ ]** A ação requer que o cofre esteja desarmado antes da execução.

|Led|Estado|Ação|
|:--------|:--------|:------|
|Azul|Ligado|Serviço em funcionamento|
|Azul|Uma piscada|Solicitação de alteração de memória|
|Verde|Uma piscada|Operação concluída com sucesso|
|Verde|Duas piscadas|Solicitação de alteração de senha aceita|
|Vermelho|Uma piscada|Operação falhou|
|Azul + Vermelho|Uma piscada|Tecla inativa|

Diagrama geral de conexão, projeto completo no [Tinkercad](https://www.tinkercad.com/things/jaSxoWvyj15-safe)

## Fotografias

![first_photograph](../media/webp/first_photograph.webp)

![second_photograph](../media/webp/second_photograph.webp)

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
