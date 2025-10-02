#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>
// --- Khởi tạo LED ---
LED led1(LED1_PIN, LED1_ACT);
LED led2(LED2_PIN, LED2_ACT);

// --- Biến xác định LED đang điều khiển ---
bool controlLed1 = true;

// --- Khởi tạo nút ---
OneButton button(BTN_PIN, !BTN_ACT);

// --- Hàm callback ---
void singleClick();
void doubleClick();
void longPressStart();
void longPressStop();

void setup() {
    led1.off();
    led2.off();

    // Gán callback cho nút
    button.attachClick(singleClick);
    button.attachDoubleClick(doubleClick);
    button.attachLongPressStart(longPressStart);
    button.attachLongPressStop(longPressStop);
}

void loop() {
    // Cập nhật LED và nút
    led1.loop();
    led2.loop();
    button.tick();
}

// --- Callback: single click ---
void singleClick() {
    if (controlLed1) {
        led1.flip();  // bật/tắt LED1
    } else {
        led2.flip();  // bật/tắt LED2
    }
}

// --- Callback: double click ---
void doubleClick() {
    controlLed1 = !controlLed1; // đổi LED

    // Báo hiệu LED mới bằng nháy nhanh 100ms
    if (controlLed1) {
        led1.blink(100);
        led2.off();
    } else {
        led2.blink(100);
        led1.off();
    }
}

// --- Callback: giữ nút bắt đầu ---
void longPressStart() {
    if (controlLed1) {
        led1.blink(200);
    } else {
        led2.blink(200);
    }
}

// --- Callback: giữ nút kết thúc ---
void longPressStop() {
    if (controlLed1) {
        led1.off();
    } else {
        led2.off();
    }
}
