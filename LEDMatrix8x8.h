// Author: Kostas Ragauskas, 4th course, group 2
// Description - a library, which spimplifies the process of working with MAX7219 8x8 matrix.

#ifndef LEDMATRIX8x8_H
#define LEDMATRIX8x8_H

#include <Arduino.h>

#include <String.h>
#include <stdint.h>

using byte = unsigned char;

class LEDMatrix8x8 {
public:
    enum AnimationType {
      RHOMBUS = 0,
      UP_ARROW = 1,
      DOWN_ARROW = 2,
      LEFT_ARROW = 3,
      RIGHT_ARROW = 4,
      LOADING_BAR = 5,
      HEARTBEAT = 6,
      SQUARE = 7
    };

    enum AnimationMode {
      VERTICAL,
      HORIZONTAL
    };

    enum Brightness {
      B_MAX = 0x0F,
      B_HIGH = 0x0B,
      B_MEDIUM = 0x07,
      B_LOW = 0x03,
      B_MINIMAL = 0x00
    };

    enum State {
      ON = true,
      OFF = false
    };

    LEDMatrix8x8(int dataPin, int clockPin, int latchPin, LEDMatrix8x8::Brightness brightness);

    static const byte ANIMATIONS[8][8];
    static const byte CHARACTERS[37][8];

    void begin();
    void setPixel(int x, int y, LEDMatrix8x8::State state);
    void displayCharacter(char ch, int duration, AnimationMode animationMode);
    void displayText(String str, int duration, AnimationMode animationMode);
    void displayAnimation(int duration, LEDMatrix8x8::AnimationType animationType, LEDMatrix8x8::AnimationMode animationMode);
    void scrollText(String text, int delayDuration, LEDMatrix8x8::AnimationMode animationMode);
    void clear();

private:
    int dataPin;
    int clockPin;
    int latchPin;
    LEDMatrix8x8::Brightness brightness;

    byte displayBuffer[8];

    uint8_t* getCharacterPattern(char ch);

    void sendCommand(byte address, byte data);
    void shiftPattern(byte pattern[8], int shiftAmount, LEDMatrix8x8::AnimationMode animationMode);
    void displayPattern(byte pattern[8], int duration);
    void transposeByteArray(byte arr[], int size);
    void mirrorBits(byte &b);
};

#endif
