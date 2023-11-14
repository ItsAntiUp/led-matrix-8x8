// Author: Kostas Ragauskas, 4th course, group 2
// Description - a library, which spimplifies the process of working with MAX7219 8x8 matrix.

#include "LEDMatrix8x8.h"

#include <String.h>
#include <stdint.h>

using byte = unsigned char;


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
    B01111100,
    B00000010,
    B00000010,
    B00111100,
    B01000000,
    B01000000,
    B00111110,
    B00000000
    }, // 2

    {
    B01111100,
    B00000010,
    B00000010,
    B01111110,
    B00000010,
    B00000010,
    B01111100,
    B00000000
    }, // 3

    {
    B00001000,
    B00011000,
    B00101000,
    B01001000,
    B01111110,
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
    B01111110,
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
    B01000010,
    B01100110,
    B01011010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00000000
    }, // M

    {
    B01000010,
    B01000010,
    B01100010,
    B01010010,
    B01001010,
    B01000110,
    B01000010,
    B00000000
    }, // N

    {
    B00111100,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B00111100,
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
    B01000010,
    B00111100,
    B00000010
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
    B01000010,
    B00100100,
    B00011000,
    B00000000
    }, // V

    {
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01011010,
    B01100110,
    B01000010,
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
    B00000010,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B01111110,
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


const byte LEDMatrix8x8::ANIMATIONS[8][8] = {
    {
    B00011000,
    B00111100,
    B01100110,
    B11000011,
    B11000011,
    B01100110,
    B00111100,
    B00011000
    }, // Rhombus

    {
    B00000000,
    B00011000,
    B00111100,
    B01111110,
    B00011000,
    B00011000,
    B00011000,
    B00000000
    }, // Up_Arrow

    {
    B00000000,
    B00011000,
    B00011000,
    B00011000,
    B01111110,
    B00111100,
    B00011000,
    B00000000,
    }, // Down_Arrow

    {
    B00000000,
    B00010000,
    B00110000,
    B01111110,
    B01111110,
    B00110000,
    B00010000,
    B00000000
    }, // Left_Arrow

    {
    B00000000,
    B00001000,
    B00001100,
    B01111110,
    B01111110,
    B00001100,
    B00001000,
    B00000000
    }, // Right_Arrow

    {
    B11110000,
    B11111000,
    B11111100,
    B11111110,
    B11111110,
    B11111100,
    B11111000,
    B11110000
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
LEDMatrix8x8::LEDMatrix8x8(int dataPin, int clockPin, int latchPin, LEDMatrix8x8::Brightness brightness) {
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
    sendCommand(0x09, 0x00);                // Decode Mode: No decoding
    sendCommand(0x0A, this->brightness);    // Intensity: Set to maximum brightness (0x00 to 0x0F)
    sendCommand(0x0B, 0x07);                // Scan Limit: Display digits 0 to 7
    sendCommand(0x0C, 0x01);                // Shutdown: Normal operation (0x01 for normal, 0x00 for shutdown)
    sendCommand(0x0F, 0x00);                // Display Test: Disable display test pattern

    clear();
}


// Purpose: Changes the state of a single pixel on the board (specified by x, y and state)
void LEDMatrix8x8::setPixel(int x, int y, LEDMatrix8x8::State state) {
    bitWrite(displayBuffer[y], x, state);
}


// Purpose: Clears the display matrix
void LEDMatrix8x8::clear() {
    for (int i = 0; i < 8; ++i)
        displayBuffer[i] = 0;
}


// Purpose: Displays provided text on a screen, letter by letter, at provided delay and animation mode
void LEDMatrix8x8::displayText(String text, int delay, LEDMatrix8x8::AnimationMode animationMode) {
    int len = text.length();

    for (int i = 0; i < len; ++i) {
        char ch = text.charAt(i);

        displayCharacter(ch, delay, animationMode);
        displayCharacter(' ', 250, animationMode);
    }
}


// Purpose: Displays an ascii character on the screen for the provided duration and animation mode
void LEDMatrix8x8::displayCharacter(char ch, int duration, LEDMatrix8x8::AnimationMode animationMode) {
    memcpy(displayBuffer, getCharacterPattern(ch), sizeof(displayBuffer));

    if (animationMode == LEDMatrix8x8::VERTICAL)
        LEDMatrix8x8::transposeByteArray(displayBuffer, 8);

    displayPattern(displayBuffer, duration);
}


// Purpose: Displays an animation on the screen, for the wanted duration and animation mode
void LEDMatrix8x8::displayAnimation(int duration, LEDMatrix8x8::AnimationType animationType, LEDMatrix8x8::AnimationMode animationMode) {
    int currentDuration = 0;
    byte animation[8];

    memcpy(animation, ANIMATIONS[animationType], sizeof(animation));

    if (animationMode == LEDMatrix8x8::HORIZONTAL) {
      for (int i = 0; i < 8; ++i)
        LEDMatrix8x8:mirrorBits(animation[i]);

      LEDMatrix8x8::transposeByteArray(animation, 8);
    }

    while (currentDuration < duration) {
        for (int shiftAmount = 0; shiftAmount <= 8; ++shiftAmount) {
            shiftPattern(animation, shiftAmount, animationMode);

            delay(100);
            currentDuration += 100;
        }
    }
}


// Purpose: Displays the provided text as a scrolling animation with the specified delay and animation mode
void LEDMatrix8x8::scrollText(String text, int delayDuration, LEDMatrix8x8::AnimationMode animationMode) {
    int len = text.length();

    const int patternSize = 8;
    const int totalPatterns = len * patternSize;

    byte combinedPattern[totalPatterns];

    // Concatenate character patterns
    for (int i = 0; i < len; ++i) {
        char currentChar = text[i];
        byte charPattern[8];

        memcpy(charPattern, LEDMatrix8x8::getCharacterPattern(currentChar), sizeof(charPattern));

        if (animationMode == LEDMatrix8x8::VERTICAL) {
          for (int i = 0; i < 8; ++i)
            LEDMatrix8x8:mirrorBits(charPattern[i]);

          LEDMatrix8x8::transposeByteArray(charPattern, 8);
        }

        for (int j = 0; j < patternSize; ++j)
            combinedPattern[i * patternSize + j] = charPattern[j];
    }

    // Scroll the combined pattern
    for (int i = 0; i < totalPatterns - 7; ++i) {
        byte columnPattern[8];

        if (animationMode == LEDMatrix8x8::VERTICAL) {
            for (int j = 0; j < 8; ++j)
              columnPattern[j] = combinedPattern[i + 7 - j];
        }
        else {
            for (int j = 0; j < 8; ++j)
                columnPattern[j] = combinedPattern[i + j];
        }

        LEDMatrix8x8::displayPattern(columnPattern, delayDuration);
    }
}


// Private (internal methods)


// Purpose: Gets an appropriate pattern for a provided ASCII character
uint8_t* LEDMatrix8x8::getCharacterPattern(char ch) {
    int charIndex = 36;

    if (ch >= '0' && ch <= '9')
        charIndex = ch - '0';
    else if (ch >= 'A' && ch <= 'Z')
        charIndex = ch - 'A' + 10;
    else if (ch >= 'a' && ch <= 'z')
        charIndex = ch - 'a' + 10;

    return LEDMatrix8x8::CHARACTERS[charIndex];
}


// Purpose: Sends a command to the 8x8 matrix
void LEDMatrix8x8::sendCommand(byte address, byte data) {
    digitalWrite(latchPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, address);
    shiftOut(dataPin, clockPin, MSBFIRST, data);

    digitalWrite(latchPin, HIGH);
}


// Purpose: Shifts a certain pattern by the specified number of places
void LEDMatrix8x8::shiftPattern(byte pattern[8], int shiftAmount, LEDMatrix8x8::AnimationMode animationMode) {
    byte shiftedPattern[8];

    for (int i = 0; i < 8; ++i) {
        int shiftIndex = animationMode == HORIZONTAL ? (i + shiftAmount) % 8 : (i - shiftAmount + 8) % 8;
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

// Purpose: Mirrors the byte array
void LEDMatrix8x8::mirrorBits(byte &b) {
    b = ((b & 0x01) << 7) |    // Bit 0 goes to Bit 7
        ((b & 0x02) << 5) |    // Bit 1 goes to Bit 6
        ((b & 0x04) << 3) |    // Bit 2 goes to Bit 5
        ((b & 0x08) << 1) |    // Bit 3 goes to Bit 4
        ((b & 0x10) >> 1) |    // Bit 4 goes to Bit 3
        ((b & 0x20) >> 3) |    // Bit 5 goes to Bit 2
        ((b & 0x40) >> 5) |    // Bit 6 goes to Bit 1
        ((b & 0x80) >> 7);     // Bit 7 goes to Bit 0
}

// Purpose: Transposes the byte array
void LEDMatrix8x8::transposeByteArray(byte arr[], int size) {
    byte rotatedArr[size];

    for (int i = 0; i < size; ++i) {
        rotatedArr[i] = 0;

        for (int j = 0; j < 8; ++j)
            rotatedArr[i] |= ((arr[j] >> i) & 0x01) << (7 - j);
    }

    for (int i = 0; i < size; ++i)
        arr[i] = rotatedArr[i];
}
