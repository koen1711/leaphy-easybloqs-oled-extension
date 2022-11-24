#ifndef OLED_H
#define OLED_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "Converter.h"

class OLED(int SCREEN_WIDTH, int SCREEN_HEIGHT, int OLED_RESET, bool AutoUpdate) {
    OLED(); {
        // Create the display object
        Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    }
};

// register public methods

OLED::begin() {
    // Initialize the display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }
    // Clear the buffer
    display.clearDisplay();
    display.display();
}

OLED::update() {
    // Update the display
    display.display();
}

OLED::clear() {
    // Clear the buffer
    display.clearDisplay();
}

OLED::drawText(int x, int y, String text, int size) {
    // Draw the text
    display.setTextSize(size);
    display.setTextColor(WHITE);
    display.setCursor(x, y);
    display.println(text);
}

OLED::drawLine(int x0, int y0, int x1, int y1) {
    // Draw the line
    display.drawLine(x0, y0, x1, y1, WHITE);
}

OLED::drawRect(int x, int y, int w, int h) {
    // Draw the rectangle
    display.drawRect(x, y, w, h, WHITE);
}

OLED::drawCircle(int x, int y, int r) {
    // Draw the circle
    display.drawCircle(x, y, r, WHITE);
}

OLED::drawBitmap(int x, int y, int w, int h, const uint8_t *bitmap) {
    // Draw the bitmap
    display.drawBitmap(x, y, bitmap, w, h, WHITE);
}

// Must be .bmp format
OLED::drawImage(int x, int y, int w, int h, String path) {
    Image2CPP(path);
}



#endif