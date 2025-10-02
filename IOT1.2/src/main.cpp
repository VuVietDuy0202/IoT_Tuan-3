#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led(LED_PIN, LED_ACT);

void btnPush();
void btnDoubleClick();
OneButton button(BTN_PIN, !BTN_ACT);

void setup()
{
    led.off();
    button.attachClick(btnPush);            // single click = ON/OFF
    button.attachDoubleClick(btnDoubleClick); // double click = Blink
}

void loop()
{
    led.loop();
    button.tick();
}

void btnPush()
{
    led.flip();  // đảo trạng thái LED
}

void btnDoubleClick()
{
    led.blink(200);  // LED nhấp nháy
}
