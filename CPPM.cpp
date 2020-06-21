#include "CPPM.h"

uint8_t           CPPM_Count        = 0;
int16_t volatile  CPPM_Channels[8]  = {0, 0, 0, 0, 0, 0, 0, 0};
uint32_t          CPPM_TimePrevious = 0;

void StartCPPM(int16_t Pin) {
  pinMode(Pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(Pin), CPPM_InterruptRoutine, RISING);
}

void CPPM_InterruptRoutine() {
  static uint8_t CPPM_Pointer = 0;
  int16_t        CPPM_Pulse   = int16_t(micros() - CPPM_TimePrevious); //TEMPO DE ATUALIZAÇÃO DO PULSO PPM
  CPPM_TimePrevious           = micros();
  if (CPPM_Pulse < 2600) {                    //PULSO PPM DENTRO DO PADRÃO 2600uS
    CPPM_Pointer &= B00000111;                //EVITA TRANSBORDAÇÃO DE VALORES SE A LEITURA FOR RUIM
    CPPM_Channels[CPPM_Pointer] = CPPM_Pulse; //OBTÉM O VALOR DO PULSO PPM DE CADA CANAL
    CPPM_Count |= (1UL << (CPPM_Pointer));    //NOVO VALOR LIDO DO PULSO PPM
    CPPM_Pointer++;                           //CONTADOR DE CANAIS PPM
  } else CPPM_Pointer = 0;                    //CASO CONTRARIO?PULSO PPM EM MÁ CONDIÇÕES
}
