#include "C:\\Users\\Koen\\OneDrive\\ProgramStuff\\C++\\OLED-Extension\\leaphy-easybloqs-oled-extension\\src\\Converter.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Set oled on analog pins 4 and 5

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);



void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.clearDisplay();


    // Test converter
    unsigned char * a = Image2CPP("logo.jpg");

    // draw a on display

    display.drawBitmap(0, 0, a, 128, 64, 1);

    display.display();
}

void loop() {
    // put your main code here, to run repeatedly:

}