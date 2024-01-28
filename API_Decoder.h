#ifndef _API_DECODER_H
#define _API_DECODER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
#include "mcc_generated_files/pin_manager.h"
#include "display.h"

char *CurrencyValue(const char *);

void UbdateValue(const char [3], const char [3], const char [3], const char [3]);
void StateMachine(void);
void API_Inicialize(void);

#endif