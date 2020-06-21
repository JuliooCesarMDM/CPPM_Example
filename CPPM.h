#ifndef CPPM_H
#define CPPM_H

#include "Arduino.h"

//SEQUENCIA DO PPM LIDO,AQUI DEVE SER ALTERADO DE ACORDO COM O MODELO SEU RECEPTOR PPM
#define CPPM_AILER_INDEX 0 //ROLL
#define CPPM_ELEV_INDEX  1 //PITCH
#define CPPM_THROT_INDEX 2 //THROTTLE
#define CPPM_RUDD_INDEX  3 //YAW
#define CPPM_AUX1_INDEX  4 //CANAL AUXILIAR 1
#define CPPM_AUX2_INDEX  5 //CANAL AUXILIAR 2
#define CPPM_AUX3_INDEX  6 //CANAL AUXILIAR 3
#define CPPM_AUX4_INDEX  7 //CANAL AUXILIAR 4
//MAPEAMENTO DOS CANAIS DO ARRAY
#define RC_THROT CPPM_Channels[CPPM_THROT_INDEX]
#define RC_AILER CPPM_Channels[CPPM_AILER_INDEX]
#define RC_ELEV  CPPM_Channels[CPPM_ELEV_INDEX]
#define RC_RUDD  CPPM_Channels[CPPM_RUDD_INDEX]
#define RC_AUX1  CPPM_Channels[CPPM_AUX1_INDEX]
#define RC_AUX2  CPPM_Channels[CPPM_AUX2_INDEX]
#define RC_AUX3  CPPM_Channels[CPPM_AUX3_INDEX]
#define RC_AUX4  CPPM_Channels[CPPM_AUX4_INDEX]
extern int16_t volatile CPPM_Channels[8];
void StartCPPM(int16_t Pin);
void CPPM_InterruptRoutine();
#endif
