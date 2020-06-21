#include "CPPM.h"

/******************************INFO**********************************/
//AUTOR:JULIO CESAR MATIAS
//DESENVOLVIDO OFICIALMENTE PARA A CONTROLADORA DE VOO JCFLIGHT
//DATA:JUNHO DE 2018
/********************************************************************/

//EXEMPLO SIMPLES PARA LEITURA DE ATÉ 8 CANAIS PPM
//UM EXEMPLO MELHOR PODE SER OBTIDO NO MEU GITHUB: https://github.com/JuliooCesarMDM/New_CPPM_Example

void setup() {
  Serial.begin(115200);
  StartCPPM(2); //ROTINA DE INTERRUPÇÃO PARA A LEITURA DOS CANAIS PPM NO PINO 2
}

void loop() {
  delay(20); //50HZ LOOP
  String SerialBuffer;
  for (uint8_t i = 0; i < 8; i++) {
    SerialBuffer += String(CPPM_Channels[i], DEC);
    SerialBuffer += '\t';
  }
  SerialBuffer += '\n';
  Serial.print(SerialBuffer);
}
