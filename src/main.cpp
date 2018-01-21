#include <Arduino.h>

int leds[] = {16, 5, 4, 0, 2};
int value;

void stopRun(){
    return;
}

int getValue(int value) {
    char str;
    if(Serial.available()){
        str = Serial.read();
        value = Serial.parseInt();
    }
    return value;
}

void setup() {
    for (int i = 0; i < 5; i++) {
        pinMode(leds[i], OUTPUT);
    }
    Serial.begin(9600);
}

void loop() {
    getValue(value);
    for (int i = 0; i < 5; i++) {
        digitalWrite(leds[i], HIGH);
        delay(value);
        digitalWrite(leds[i],LOW);
    }
}