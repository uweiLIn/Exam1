#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
//DigitalIn pin_up(D3);
//DigitalIn pin_down(D6);
//DigitalIn pin_sel(D5);
AnalogOut sig(PA_4);
InterruptIn pin_up(D3);
InterruptIn pin_down(D6);
InterruptIn pin_sel(D5);

EventQueue queue(64 * EVENTS_EVENT_SIZE);

Thread t;
float a = 0.125f;
float b = 0.25f;
float c = 0.5f;
float d = 1.0f;
float sl_rate_pre = 0.125f;
float sl_rate = 0.125f;

void add_rate()  {
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

void des_rate() {
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
    } else {
        sl_rate_pre= c;
        uLCD.locate(0, 8);
        uLCD.printf(" Slew rate is %f \n", sl_rate_pre);
    }

}
void com_rate() {
    sl_rate = sl_rate_pre;
    uLCD.printf(" Slew rate is %f \n", sl_rate);
}


int main()
{
    t.start(callback(&queue, &EventQueue::dispatch_forever));
    
    uLCD.printf("\nPlease Select the slew rates\n");
    uLCD.printf("%f \n", a);
    uLCD.printf("%f \n", b);
    uLCD.printf("%f \n", c);
    uLCD.printf("%f \n", d);
    
    pin_up.rise(queue.event(add_rate));
    pin_down.rise(queue.event(des_rate));
    pin_sel.rise(queue.event(com_rate));

    
    while (1) {
        
        
    };
}
