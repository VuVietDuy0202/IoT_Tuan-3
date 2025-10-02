#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

// Hai đối tượng LED
LED led1(LED1_PIN, LED1_ACT);
LED led2(LED2_PIN, LED2_ACT);

// Biến xác định LED nào đang được điều khiển
// true  -> điều khiển LED1
// false -> điều khiển LED2
bool controlLed1 = true;

OneButton button(BTN_PIN, !BTN_ACT);

// Đặt các hàm callback
void singleClick();
void doubleClick();
void longPress();

void setup() {
    led1.off();
    led2.off();

    button.attachClick(singleClick);
    button.attachDoubleClick(doubleClick);
    button.attachLongPressStart(longPress);
}

void loop() {
    // cập nhật trạng thái LED và xử lý nút
    led1.loop();
    led2.loop();
    button.tick();
}

// Callback: bấm 1 lần
void singleClick() {
    if (controlLed1) {
        led1.flip();      // bật/tắt LED1
        led2.on();
    }
    else {
        led2.flip();      // bật/tắt LED2
        led1.off();
    }
}

// Callback: double click => đổi LED đang điều khiển
void doubleClick() {
    controlLed1 = !controlLed1;

    // Tùy chọn: báo hiệu chuyển LED bằng cách chớp nhanh
    if (controlLed1) {
        led1.blink(100);
        led2.on();
    } else {
        led2.blink(100);
        led1.off();
    }
}

// Callback: giữ nút => LED hiện tại nhấp nháy 200 ms
void longPress() {
    if (controlLed1)
        led1.blink(200);
    else
        led2.blink(200);
}