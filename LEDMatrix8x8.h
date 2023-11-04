// Author: Kostas Ragauskas, 4th course, group 2
// Description - a library, which spimplifies the process of working with MAX7219 8x8 matrix.

#ifndef LEDMATRIX8x8_H
#define LEDMATRIX8x8_H

#include <Arduino.h>
#include <String.h>

class LEDMatrix8x8 {
public:
    enum AnimationType {
        RHOMBUS = 0,
        RIGHT_ARROW = 1,
        LEFT_ARROW = 2,
        LOADING_BAR = 3,
        HEARTBEAT = 4,
        SQUARE = 5,
    };

    enum AnimationMode {
        UP,
        DOWN
    };

    enum Brightness {
        MAX = 0x0F,
        HIGH = 0x0B,
        MEDIUM = 0x07,
        LOW = 0x03,
        MINIMAL = 0x00
    };

    enum State {
        ON = true,
        OFF = false
    };

    LEDMatrix8x8(int dataPin, int clockPin, int latchPin);

	static const byte ANIMATIONS[][8];

	void begin();
	void setPixel(int x, int y, bool state);
	void displayCharacter(char ch, int duration);
	void displayText(String str, int duration);
	void displayAnimation(AnimationType animationType, AnimationMode animationMode, int duration);
	void scrollText(String text, AnimationMode animationMode, int delay);
	void clear();

private:
	int dataPin;
	int clockPin;
	int latchPin;

	byte displayBuffer[8];
	static const byte CHARACTERS[37][8];

    byte[8] getCharacterPattern(char ch);

	void sendCommand(byte address, byte data);
	void shiftPattern(byte pattern[8], AnimationMode animationMode, int shiftAmount);
	void displayPattern(byte pattern[8], int duration);
};

#endif