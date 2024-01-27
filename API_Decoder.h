#ifndef _API_DECODER_H
#define _API_DECODER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
#include "mcc_generated_files/pin_manager.h"
#include "display.h"

char *CurrencyValue(const char *);

void UbdateValue(void);
void StateMachine(void);
 

#endif