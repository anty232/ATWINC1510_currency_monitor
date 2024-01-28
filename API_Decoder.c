#include"API_Decoder.h"

char *API = "[{\"table\":\"A\",\"no\":\"014/A/NBP/2024\",\"effectiveDate\":\"2024-01-19\",\"rates\":[{\"currency\":\"bat (Tajlandia)\",\"code\":\"THB\",\"mid\":0.1134},{\"currency\":\"dolar ameryka?ski\",\"code\":\"USD\",\"mid\":4.0289},{\"currency\":\"dolar australijski\",\"code\":\"AUD\",\"mid\":2.6587},{\"currency\":\"dolar Hongkongu\",\"code\":\"HKD\",\"mid\":0.5153},{\"currency\":\"dolar kanadyjski\",\"code\":\"CAD\",\"mid\":2.9920},{\"currency\":\"dolar nowozelandzki\",\"code\":\"NZD\",\"mid\":2.4654},{\"currency\":\"dolar singapurski\",\"code\":\"SGD\",\"mid\":3.0052},{\"currency\":\"euro\",\"code\":\"EUR\",\"mid\":4.3846},{\"currency\":\"forint (W?gry)\",\"code\":\"HUF\",\"mid\":0.011445},{\"currency\":\"frank szwajcarski\",\"code\":\"CHF\",\"mid\":4.6388},{\"currency\":\"funt szterling\",\"code\":\"GBP\",\"mid\":5.1103},{\"currency\":\"hrywna (Ukraina)\",\"code\":\"UAH\",\"mid\":0.1074},{\"currency\":\"jen (Japonia)\",\"code\":\"JPY\",\"mid\":0.027225},{\"currency\":\"korona czeska\",\"code\":\"CZK\",\"mid\":0.1767},{\"currency\":\"korona du?ska\",\"code\":\"DKK\",\"mid\":0.5880},{\"currency\":\"korona islandzka\",\"code\":\"ISK\",\"mid\":0.029526},{\"currency\":\"korona norweska\",\"code\":\"NOK\",\"mid\":0.3850},{\"currency\":\"korona szwedzka\",\"code\":\"SEK\",\"mid\":0.3851},{\"currency\":\"lej rumu?ski\",\"code\":\"RON\",\"mid\":0.8809},{\"currency\":\"lew (Bu?garia)\",\"code\":\"BGN\",\"mid\":2.2418},{\"currency\":\"lira turecka\",\"code\":\"TRY\",\"mid\":0.1333},{\"currency\":\"nowy izraelski szekel\",\"code\":\"ILS\",\"mid\":1.0744},{\"currency\":\"peso chilijskie\",\"code\":\"CLP\",\"mid\":0.00439},{\"currency\":\"peso filipi?skie\",\"code\":\"PHP\",\"mid\":0.0720},{\"currency\":\"peso meksyka?skie\",\"code\":\"MXN\",\"mid\":0.2350},{\"currency\":\"rand (Republika Po?udniowej Afryki)\",\"code\":\"ZAR\",\"mid\":0.2125},{\"currency\":\"real (Brazylia)\",\"code\":\"BRL\",\"mid\":0.8172},{\"currency\":\"ringgit (Malezja)\",\"code\":\"MYR\",\"mid\":0.8540},{\"currency\":\"rupia indonezyjska\",\"code\":\"IDR\",\"mid\":0.00025801},{\"currency\":\"rupia indyjska\",\"code\":\"INR\",\"mid\":0.048503},{\"currency\":\"won po?udniowokorea?ski\",\"code\":\"KRW\",\"mid\":0.003022},{\"currency\":\"yuan renminbi (Chiny)\",\"code\":\"CNY\",\"mid\":0.5604},{\"currency\":\"SDR (MFW)\",\"code\":\"XDR\",\"mid\":5.3670}]}]";

char  text[9], text1[9], text2[9], text3[9];


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

void UbdateValue(const char nazwa1[3], const char nazwa2[3], const char nazwa3[3], const char nazwa4[3]){
    
    snprintf(text, sizeof(text), "%s=%s", nazwa1, CurrencyValue(nazwa1));
    
    snprintf(text1, sizeof(text1), "%s=%s", nazwa2, CurrencyValue(nazwa2));
    
    snprintf(text2, sizeof(text2), "%s=%s", nazwa3, CurrencyValue(nazwa3));
    
    snprintf(text3, sizeof(text3), "%s=%s", nazwa4, CurrencyValue(nazwa4));
    Nop();
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
                    UbdateValue("THB", "USD", "AUD", "HKD"); 
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 1:
                    UbdateValue("CAD", "NZD", "SGD", "EUR"); 
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 2:
                    UbdateValue("HUF", "CHF", "GBP", "UAH"); 
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 3:
                    UbdateValue("JYP", "CZK", "DKK", "ISK"); 
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 4:
                    UbdateValue("NOK", "SEK", "RON", "BGN"); 
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 5:
                    UbdateValue("TRY", "ILS", "CLP", "PHP"); 
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 6:
                    UbdateValue("MXN", "ZAR", "BRL", "MYR"); 
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                case 7:
                    UbdateValue("IDR", "INR", "KRW", "CNY"); 
                    DrawPage(ST7735_CYAN, text, text1, text2, text3);
                    break;
                default:
                    break;
            }
        }
        else{
            
        }
    }
    
void API_Inicialize(void){
    UbdateValue("THB", "USD", "AUD", "HKD"); 
    DrawPage(ST7735_CYAN, text, text1, text2, text3);
}

 