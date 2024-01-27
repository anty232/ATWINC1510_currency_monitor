#include"API_Decoder.h"

char *API = "[{\"table\":\"A\",\"no\":\"014/A/NBP/2024\",\"effectiveDate\":\"2024-01-19\",\"rates\":[{\"currency\":\"bat (Tajlandia)\",\"code\":\"THB\",\"mid\":0.1134},{\"currency\":\"dolar ameryka?ski\",\"code\":\"USD\",\"mid\":4.0289},{\"currency\":\"dolar australijski\",\"code\":\"AUD\",\"mid\":2.6587},{\"currency\":\"dolar Hongkongu\",\"code\":\"HKD\",\"mid\":0.5153},{\"currency\":\"dolar kanadyjski\",\"code\":\"CAD\",\"mid\":2.9920},{\"currency\":\"dolar nowozelandzki\",\"code\":\"NZD\",\"mid\":2.4654},{\"currency\":\"dolar singapurski\",\"code\":\"SGD\",\"mid\":3.0052},{\"currency\":\"euro\",\"code\":\"EUR\",\"mid\":4.3846},{\"currency\":\"forint (W?gry)\",\"code\":\"HUF\",\"mid\":0.011445},{\"currency\":\"frank szwajcarski\",\"code\":\"CHF\",\"mid\":4.6388},{\"currency\":\"funt szterling\",\"code\":\"GBP\",\"mid\":5.1103},{\"currency\":\"hrywna (Ukraina)\",\"code\":\"UAH\",\"mid\":0.1074},{\"currency\":\"jen (Japonia)\",\"code\":\"JPY\",\"mid\":0.027225},{\"currency\":\"korona czeska\",\"code\":\"CZK\",\"mid\":0.1767},{\"currency\":\"korona du?ska\",\"code\":\"DKK\",\"mid\":0.5880},{\"currency\":\"korona islandzka\",\"code\":\"ISK\",\"mid\":0.029526},{\"currency\":\"korona norweska\",\"code\":\"NOK\",\"mid\":0.3850},{\"currency\":\"korona szwedzka\",\"code\":\"SEK\",\"mid\":0.3851},{\"currency\":\"lej rumu?ski\",\"code\":\"RON\",\"mid\":0.8809},{\"currency\":\"lew (Bu?garia)\",\"code\":\"BGN\",\"mid\":2.2418},{\"currency\":\"lira turecka\",\"code\":\"TRY\",\"mid\":0.1333},{\"currency\":\"nowy izraelski szekel\",\"code\":\"ILS\",\"mid\":1.0744},{\"currency\":\"peso chilijskie\",\"code\":\"CLP\",\"mid\":0.00439},{\"currency\":\"peso filipi?skie\",\"code\":\"PHP\",\"mid\":0.0720},{\"currency\":\"peso meksyka?skie\",\"code\":\"MXN\",\"mid\":0.2350},{\"currency\":\"rand (Republika Po?udniowej Afryki)\",\"code\":\"ZAR\",\"mid\":0.2125},{\"currency\":\"real (Brazylia)\",\"code\":\"BRL\",\"mid\":0.8172},{\"currency\":\"ringgit (Malezja)\",\"code\":\"MYR\",\"mid\":0.8540},{\"currency\":\"rupia indonezyjska\",\"code\":\"IDR\",\"mid\":0.00025801},{\"currency\":\"rupia indyjska\",\"code\":\"INR\",\"mid\":0.048503},{\"currency\":\"won po?udniowokorea?ski\",\"code\":\"KRW\",\"mid\":0.003022},{\"currency\":\"yuan renminbi (Chiny)\",\"code\":\"CNY\",\"mid\":0.5604},{\"currency\":\"SDR (MFW)\",\"code\":\"XDR\",\"mid\":5.3670}]}]";
char Test[9];

char  text[9], text1[9], text2[9], text3[9];
char  text4[9], text5[9], text6[9], text7[9];
char  text8[9], text9[9], text10[9], text11[9];
char  text12[9], text13[9], text14[9], text15[9];
char  text16[9], text17[9], text18[9], text19[9];
char  text20[9], text21[9], text22[9], text23[9];
char  text24[9], text25[9], text26[9], text27[9];
char  text28[9], text29[9], text30[9], text31[9];

 uint8_t State =0;



char *CurrencyValue(const char *Waluta) {
    char *Walue = strstr(API, Waluta);
    
    if (Walue != NULL) {
        Walue = strstr(Walue, "mid");
        if (Walue != NULL) {
            Walue = Walue + strlen("mid") + 2;
            return Walue;
        }
    }
    
    return "Brak warto?ci"; // Warto?? domy?lna lub warto?? oznaczaj?ca b??d
}

void UbdateValue(void){
    
    // PAGE 1
    
    snprintf(Test, sizeof(Test), "%s=%s","THB", CurrencyValue("THB"));
    strncpy(text, Test, sizeof(text) - 1);
    text[sizeof(text) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","USD", CurrencyValue("USD"));
    strncpy(text1, Test, sizeof(text1) - 1);
    text1[sizeof(text1) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","AUD", CurrencyValue("AUD"));
    strncpy(text2, Test, sizeof(text2) - 1);
    text2[sizeof(text2) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","HKD", CurrencyValue("HKD"));
    strncpy(text3, Test, sizeof(text3) - 1);
    text3[sizeof(text3) - 1] = '\0';
    
    //  PAGE 2
    
    snprintf(Test, sizeof(Test), "%s=%s","CAD", CurrencyValue("CAD"));
    strncpy(text4, Test, sizeof(text4) - 1);
    text4[sizeof(text4) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","NZD", CurrencyValue("NZD"));
    strncpy(text5, Test, sizeof(text5) - 1);
    text5[sizeof(text5) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","SGD", CurrencyValue("SGD"));
    strncpy(text6, Test, sizeof(text6) - 1);
    text6[sizeof(text6) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","EUR", CurrencyValue("EUR"));
    strncpy(text7, Test, sizeof(text7) - 1);
    text7[sizeof(text7) - 1] = '\0';
    
    //PAGE 3
    
    snprintf(Test, sizeof(Test), "%s=%s","HUF", CurrencyValue("HUF"));
    strncpy(text8, Test, sizeof(text8) - 1);
    text8[sizeof(text8) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","CHF", CurrencyValue("CHF"));
    strncpy(text9, Test, sizeof(text9) - 1);
    text9[sizeof(text9) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","GBP", CurrencyValue("GBP"));
    strncpy(text10, Test, sizeof(text10) - 1);
    text10[sizeof(text10) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","UAH", CurrencyValue("UAH"));
    strncpy(text11, Test, sizeof(text11) - 1);
    text11[sizeof(text11) - 1] = '\0';
    
    //PAGE 4
    
    snprintf(Test, sizeof(Test), "%s=%s","JPY", CurrencyValue("JPY"));
    strncpy(text12, Test, sizeof(text12) - 1);
    text12[sizeof(text12) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","CZK", CurrencyValue("CZK"));
    strncpy(text13, Test, sizeof(text13) - 1);
    text13[sizeof(text13) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","DKK", CurrencyValue("DKK"));
    strncpy(text14, Test, sizeof(text14) - 1);
    text14[sizeof(text14) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","ISK", CurrencyValue("ISK"));
    strncpy(text15, Test, sizeof(text15) - 1);
    text15[sizeof(text15) - 1] = '\0';
    
    // PAGE 5
    
    snprintf(Test, sizeof(Test), "%s=%s","NOK", CurrencyValue("NOK"));
    strncpy(text16, Test, sizeof(text16) - 1);
    text16[sizeof(text16) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","SEK", CurrencyValue("SEK"));
    strncpy(text17, Test, sizeof(text17) - 1);
    text17[sizeof(text17) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","RON", CurrencyValue("RON"));
    strncpy(text18, Test, sizeof(text18) - 1);
    text18[sizeof(text18) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","BGN", CurrencyValue("BGN"));
    strncpy(text19, Test, sizeof(text19) - 1);
    text19[sizeof(text19) - 1] = '\0';
    
    //  PAGE 6
    
    snprintf(Test, sizeof(Test), "%s=%s","TRY", CurrencyValue("TRY"));
    strncpy(text20, Test, sizeof(text20) - 1);
    text20[sizeof(text20) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","ILS", CurrencyValue("ILS"));
    strncpy(text21, Test, sizeof(text21) - 1);
    text21[sizeof(text21) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","CLP", CurrencyValue("CLP"));
    strncpy(text22, Test, sizeof(text22) - 1);
    text22[sizeof(text22) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","PHP", CurrencyValue("PHP"));
    strncpy(text23, Test, sizeof(text23) - 1);
    text23[sizeof(text23) - 1] = '\0';
    
    //  PAGE 7
    
    snprintf(Test, sizeof(Test), "%s=%s","MXN", CurrencyValue("MXN"));
    strncpy(text24, Test, sizeof(text24) - 1);
    text24[sizeof(text24) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","ZAR", CurrencyValue("ZAR"));
    strncpy(text25, Test, sizeof(text25) - 1);
    text25[sizeof(text25) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","BRL", CurrencyValue("BRL"));
    strncpy(text26, Test, sizeof(text26) - 1);
    text26[sizeof(text26) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","MYR", CurrencyValue("MYR"));
    strncpy(text27, Test, sizeof(text27) - 1);
    text27[sizeof(text27) - 1] = '\0';
    
    // PAGE 8
    
    snprintf(Test, sizeof(Test), "%s=%s","IDR", CurrencyValue("IDR"));
    strncpy(text28, Test, sizeof(text28) - 1);
    text28[sizeof(text28) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","INR", CurrencyValue("INR"));
    strncpy(text29, Test, sizeof(text29) - 1);
    text29[sizeof(text29) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","KRW", CurrencyValue("KRW"));
    strncpy(text30, Test, sizeof(text30) - 1);
    text30[sizeof(text30) - 1] = '\0';
    
    snprintf(Test, sizeof(Test), "%s=%s","CNY", CurrencyValue("CNY"));
    strncpy(text31, Test, sizeof(text31) - 1);
    text31[sizeof(text31) - 1] = '\0';
    
    
    DrawPage(ST7735_CYAN, text, text1, text2, text3);
}

 
    void GetButton(void){
        if(SW_0_GetValue()==0){
            __delay_ms(10);
            if(SW_0_GetValue()==0){
                State--;
                State= State %8;
                while(SW_0_GetValue()==0){
                    Nop();
                }
            }
            else{
                State = State;
            }
        } 
        else if(SW_1_GetValue()==0){
                __delay_ms(10);
            if(SW_1_GetValue()==0){
                State++;
                State = State %8;
                while(SW_1_GetValue()==0){
                    Nop();
                }
            }
            else{
                    State = State;
            }
        } 
        else {
            State = State;
        }

    }
    
    void StateMachine(void){
        uint8_t State2 =0;
        State2 = State;
        GetButton();
        if(State2!=State){
            switch(State){
                case 0:
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 1:
                    DrawPage(ST7735_CYAN, text4, text5, text6, text7);
                    break;
                case 2:
                    DrawPage(ST7735_CYAN, text8, text9, text10, text11);
                    break;
                case 3:
                    DrawPage(ST7735_CYAN, text12, text13, text14, text15);
                    break;
                case 4:
                    DrawPage(ST7735_CYAN, text16, text17, text18, text19);
                    break;
                case 5:
                    DrawPage(ST7735_CYAN, text20, text21, text22, text23);
                    break;
                case 6:
                    DrawPage(ST7735_CYAN, text24, text25, text26, text27);
                    break;
                case 7:
                    DrawPage(ST7735_CYAN, text28, text29, text30, text31);
                    break;
                default:
                    break;
            }
        }
        else{
            
        }
    }

 