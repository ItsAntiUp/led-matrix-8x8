// Author: Kostas Ragauskas, 4th course, group 2
// Description - a library, which spimplifies the process of working with MAX7219 8x8 matrix.

#include "LEDMatrix8x8.h"
#include <String.h>


const byte LEDMatrix8x8::CHARACTERS[37][8] = {
    {
    B00111100,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00111100,
    B00000000
    }, // '0'

    {
    B00001000,
    B00011000,
    B00101000,
    B01001000,
    B00001000,
    B00001000,
    B01111110,
    B00000000
    }, // 1

    {
    B01111110,
    B00000010,
    B00000010,
    B01111110,
    B01000000,
    B01000000,
    B01111110,
    B00000000
    }, // 2

    {
    B01111110,
    B00000010,
    B00000010,
    B01111110,
    B00000010,
    B00000010,
    B01111110,
    B00000000
    }, // 3

    {
    B00011000,
    B00101000,
    B01001000,
    B10001000,
    B11111110,
    B00001000,
    B00001000,
    B00000000
    }, //4

    {
    B01111110,
    B01000000,
    B01000000,
    B01111100,
    B00000010,
    B00000010,
    B01111100,
    B00000000
    }, //5

    {
    B00011100,
    B00100000,
    B01000000,
    B01111100,
    B01000010,
    B01000010,
    B00111100,
    B00000000
    }, //6

    {
    B01111110,
    B00000010,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B01000000,
    B00000000
    }, //7

    {
    B00111100,
    B01000010,
    B01000010,
    B00111100,
    B01000010,
    B01000010,
    B00111100,
    B00000000
    }, //8

    {
    B00111100,
    B01000010,
    B01000010,
    B00111110,
    B00000010,
    B00000010,
    B00111100,
    B00000000
    }, //9

    {
    B00111100,
    B01000010,
    B01000010,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B00000000
    }, //A

    {
    B01111100,
    B01000010,
    B01000010,
    B01111100,
    B01000010,
    B01000010,
    B01111100,
    B00000000
    }, //B

    {
    B00011110,
    B00100000,
    B01000000,
    B01000000,
    B01000000,
    B00100000,
    B00011110,
    B00000000
    }, //C

    {
    B01111000,
    B01000100,
    B01000010,
    B01000010,
    B01000010,
    B01000100,
    B01111000,
    B00000000
    }, //D

    {
    B01111110,
    B01000000,
    B01000000,
    B01111110,
    B01000000,
    B01000000,
    B01111110,
    B00000000
    }, // E

    {
    B01111110,
    B01000000,
    B01000000,
    B01111110,
    B01000000,
    B01000000,
    B01000000,
    B00000000
    }, // F

    {
    B00111100,
    B01000010,
    B01000000,
    B01001110,
    B01000010,
    B01000010,
    B00111100,
    B00000000
    }, // G

    {
    B01000010,
    B01000010,
    B01000010,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B00000000
    }, // H

    {
    B01111110,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B01111110,
    B00000000
    }, // I

    {
    B00111110,
    B00000100,
    B00000100,
    B00000100,
    B00000100,
    B01000100,
    B00111000,
    B00000000
    }, // J

    {
    B01000100,
    B01001000,
    B01010000,
    B01100000,
    B01010000,
    B01001000,
    B01000100,
    B00000000
    }, // K

    {
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01111110,
    B00000000
    }, // L

    {
    B10000001,
    B11000011,
    B10100101,
    B10011001,
    B10000001,
    B10000001,
    B10000001,
    B00000000
    }, // M

    {
    B10000001,
    B11000001,
    B10100001,
    B10010001,
    B10001001,
    B10000101,
    B10000011,
    B00000000
    }, // N

    {
    B00111100,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00111100,
    B00000000,
    B00000000
    }, // O

    {
    B01111100,
    B01000010,
    B01000010,
    B01111100,
    B01000000,
    B01000000,
    B01000000,
    B00000000
    }, // P

    {
    B00111100,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00111100,
    B00000010,
    B00000000
    }, // Q

    {
    B01111100,
    B01000010,
    B01000010,
    B01111100,
    B01001000,
    B01000100,
    B01000010,
    B00000000
    }, // R

    {
    B00111100,
    B01000000,
    B01000000,
    B00111100,
    B00000010,
    B00000010,
    B01111100,
    B00000000
    }, // S

    {
    B01111110,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00000000
    }, // T

    {
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00111100,
    B00000000
    }, // U

    {
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00100100,
    B00011000,
    B00000000,
    B00000000
    }, // V

    {
    B10000001,
    B10000001,
    B10000001,
    B10011001,
    B10100101,
    B11000011,
    B10000001,
    B00000000
    }, // W

    {
    B01000010,
    B01000010,
    B00100100,
    B00011000,
    B00100100,
    B01000010,
    B01000010,
    B00000000
    }, // X

    {
    B01000010,
    B01000010,
    B01000010,
    B00100100,
    B00011000,
    B00011000,
    B00011000,
    B00000000
    }, // Y

    {
    B01111110,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B01111110,
    B00000000,
    B00000000
    },  // Z

    {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
    }, // Empty space
};


const byte LEDMatrix8x8::ANIMATIONS[][8] = {
    {
    B00011000,
    B00111100,
    B01100110,
    B11000011,
    B01100110,
    B00111100,
    B00011000,
    B00000000
    }, // Rhombus

    {
    B00000000,
    B00001000,
    B00000100,
    B11111110,
    B11111110,
    B00000100,
    B00001000,
    B00000000
    }, // Right_Arrow

    {
    B00000000,
    B00100000,
    B01000000,
    B11111111,
    B11111111,
    B01000000,
    B00100000,
    B00000000
    }, // Left_Arrow

    {
    B00000000,
    B10000000,
    B11000000,
    B11100000,
    B11110000,
    B11111000,
    B11111100,
    B11111110
    }, // Loading_Bar

    {
    B00011000,
    B00011000,
    B00011000,
    B11111111,
    B11111111,
    B00011000,
    B00011000,
    B00011000
    }, // Heartbeat

    {
    B00000000,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01111110,
    B00000000
    } // Square
};


// Constructor
LEDMatrix8x8::LEDMatrix8x8(int dataPin, int clockPin, int latchPin, Brightness brightness) {
    this->dataPin = dataPin;
    this->clockPin = clockPin;
    this->latchPin = latchPin;
    this->brightness = brightness;
}


// Purpose: Initializes the 8x8 matrix.
void LEDMatrix8x8::begin() {
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);

    // Initialize MAX7219
    sendCommand(0x09, 0x00);        // Decode Mode: No decoding
    sendCommand(0x0A, brightness);  // Intensity: Set to maximum brightness (0x00 to 0x0F)
    sendCommand(0x0B, 0x07);        // Scan Limit: Display digits 0 to 7
    sendCommand(0x0C, 0x01);        // Shutdown: Normal operation (0x01 for normal, 0x00 for shutdown)
    sendCommand(0x0F, 0x00);        // Display Test: Disable display test pattern

    clear();
}


// Purpose: Changes the state of a single pixel on the board (specified by x, y and state)
void LEDMatrix8x8::setPixel(int x, int y, State state) {
    bitWrite(displayBuffer[y], x, state);
}


// Purpose: Clears the display matrix
void LEDMatrix8x8::clear() {
    for (int i = 0; i < 8; ++i)
        displayBuffer[i] = 0;
}


// Purpose: Displays provided text on a screen, letter by letter, at provided delay
void LEDMatrix8x8::displayText(String text, int delay) {
    int len = text.length();

    for (int i = 0; i < len; ++i) {
        char ch = text.charAt(i);

        displayCharacter(ch, delay);
        displayCharacter(' ', 250);
    }
}


// Purpose: Displays an ascii character on the screen for the provided duration
void LEDMatrix8x8::displayCharacter(char ch, int duration) {
    memcpy(displayBuffer, getCharacterPattern(ch), sizeof(displayBuffer));
    displayPattern(displayBuffer, duration);
}


// Purpose: Displays an animation on the screen, for the wanted direction and duration
void LEDMatrix8x8::displayAnimation(AnimationType animationType, AnimationMode animationMode, int duration) {
    int currentDuration = 0;

    for (int shiftAmount = 0; shiftAmount <= 8; ++shiftAmount) {
        shiftPattern(ANIMATIONS[animationType], animationMode, shiftAmount);

        delay(100);
        currentDuration += 100;

        if (currentDuration >= duration)
            break;
    }
}


// Purpose: Displays the provided text as a scrolling animation with the specified direction and delay
void scrollText(String text, AnimationMode animationMode, int delay) {
    int len = text.length();

    for (int i = 0; i < len + 1; ++i) {
        for (int j = 0; j < 8; ++j) {
            byte columnPattern = 0;

            for (int k = 0; k < 8; ++k) {
                char currentChar;

                if (animationMode == UP)
                    currentChar = text[(i + k) % len];
                else (animationMode == DOWN)
                    currentChar = text[(len - i + k) % len];

                const byte* charPattern = getCharacterPattern(currentChar);
                columnPattern |= ((charPattern[k] >> j) & 1) << (7 - k);
            }

            displayPattern(columnPattern);
            delay(delay);
        }
    }
}


// Private (internal methods)


// Purpose: Gets an appropriate pattern for a provided ASCII character
byte[8] LEDMatrix8x8::getCharacterPattern(char ch) {
    int charIndex = 36;

    if (ch >= '0' && ch <= '9')
        charIndex = ch - '0';
    else if (ch >= 'A' && ch <= 'Z')
        charIndex = ch - 'A' + 10;
    else if (ch >= 'a' && ch <= 'z')
        charIndex = ch - 'a' + 10;

    return CHARACTERS[charIndex];
}


// Purpose: Shifts a certain pattern by the specified number of places to the right
void LEDMatrix8x8::sendCommand(byte address, byte data) {
    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, address);
    shiftOut(dataPin, clockPin, MSBFIRST, data);

    digitalWrite(latchPin, HIGH);
}


// Purpose: Shifts a certain pattern by the specified number of places to the left
void LEDMatrix8x8::shiftPattern(byte pattern[8], AnimationMode animationMode, int shiftAmount) {
    byte shiftedPattern[8];

    for (int i = 0; i < 8; ++i) {
        int shiftIndex = animationMode == UP ? (i + shiftAmount) % 8 : (i - shiftAmount + 8) % 8;
        shiftedPattern[i] = pattern[shiftIndex];
    }

    for (int i = 0; i < 8; ++i)
        sendCommand(i + 1, shiftedPattern[i]);
}


// Purpose: Displays a certain pattern for a specified duration (milliseconds)
void LEDMatrix8x8::displayPattern(byte pattern[8], int duration) {
    unsigned long startTime = millis();

    while (millis() - startTime < duration) {
        for (int row = 0; row < 8; ++row)
            sendCommand(row + 1, pattern[row]);
    }
}
