#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
DigitalIn pin_up(D3);
DigitalIn pin_down(D6);
DigitalIn pin_sel(D5);
AnalogOut aout(D7);

float a = 0.125f;
float b = 0.25f;
float c = 0.5f;
float d = 1.0f;
float sl_rate_pre = 0.125f;
float sl_rate = 0.125f;
int T = 240;


int main()
{   
    float f = 1.0 / T;
    int i = 1;
    
    

    uLCD.printf("\nPlease Select the slew rates\n");
    uLCD.printf("%f \n", a);
    uLCD.printf("%f \n", b);
    uLCD.printf("%f \n", c);
    uLCD.printf("%f \n", d);
    

    while (1) {
        if (pin_up == 1){
            if (sl_rate_pre == 0.125) {
                sl_rate_pre = b;
                uLCD.locate(0, 8);
                uLCD.printf(" Slew rate is %f \n", sl_rate_pre);
            } else if (sl_rate_pre == 0.25){
                sl_rate_pre= c;
                uLCD.locate(0, 8);
                uLCD.printf(" Slew rate is %f \n", sl_rate_pre);
            } else if (sl_rate_pre == 0.5) {
                sl_rate_pre= d;
                uLCD.locate(0, 8);
                uLCD.printf(" Slew rate is %f \n", sl_rate_pre);
            } else {
                sl_rate_pre= d;
                uLCD.locate(0, 8);
                uLCD.printf(" Slew rate is %f \n", sl_rate_pre);
            }   
        }
        if (pin_down) {
            if (sl_rate_pre == 0.125) {
                sl_rate_pre = a;
                uLCD.locate(0, 8);
                uLCD.printf(" Slew rate is %f \n", sl_rate_pre);
            } else if (sl_rate_pre == 0.25){
                sl_rate_pre= a;
                uLCD.locate(0, 8);
                uLCD.printf(" Slew rate is %f \n", sl_rate_pre);
            } else if (sl_rate_pre == 0.5) {
                sl_rate_pre= b;
                uLCD.locate(0, 8);
                    uLCD.printf(" Slew rate is %f \n", sl_rate_pre);
            }  else {
                sl_rate_pre= c;
                uLCD.locate(0, 8);
                uLCD.printf(" Slew rate is %f \n", sl_rate_pre);
            }
        }
        if (pin_sel){
            sl_rate = sl_rate_pre;
            uLCD.printf(" Slew rate is %f \n", sl_rate);
        }

        if (sl_rate == 1) {
            if (i <= 80) aout =  i / 80.0f / 1.1;
            else if (i >= 160 ) aout = (240 - i) / 80.0f / 1.1; 
        }
        else if (sl_rate == 0.5) {
            if (i <= 40) aout =  i / 40.0f / 1.1;
            else if (i >= 200 ) aout = (240 - i) / 40.0f / 1.1; 
        }
        else if (sl_rate == 0.25) {
            if (i <= 20) aout =  i / 20.0f / 1.1;
            else if (i >= 220 ) aout = (240 - i) / 20.0f / 1.1; 
        }
        else if (sl_rate == 0.125) {
            if (i <= 10) aout =  i / 10.0f / 1.1;
            else if (i >= 230 ) aout = (240 - i) / 10.0f / 1.1; 
        }
        if (i > 240) i = 1;
        wait_us(988);
    i++;
    }
}
   
