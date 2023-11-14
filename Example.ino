#include "LEDMatrix8x8.h"

const int MATRIX_DIN_PIN = 13;
const int MATRIX_CLK_PIN = 12;
const int MATRIX_CS_PIN = 11;

LEDMatrix8x8::Brightness BRIGHTNESS = LEDMatrix8x8::B_MINIMAL;

LEDMatrix8x8 matrix(MATRIX_DIN_PIN, MATRIX_CLK_PIN, MATRIX_CS_PIN, BRIGHTNESS);

void setup() {
    matrix.begin();
}

void loop() {
    // Displaying individual characters, horizontally.
    matrix.displayCharacter('A', 2000, matrix.HORIZONTAL);
    matrix.displayCharacter('B', 2000, matrix.HORIZONTAL);
    matrix.displayCharacter('C', 2000, matrix.HORIZONTAL);


    // Displaying animation (RHOMBUS, horizontal orientation)
    matrix.displayAnimation(3000, matrix.RHOMBUS, matrix.HORIZONTAL);

    // Displaying animation (LOADING_BAR, vertical orientation)
    matrix.displayAnimation(3000, matrix.LOADING_BAR, matrix.VERTICAL);

    // Displaying animation (UP_ARROW, vertical orientation)
    matrix.displayAnimation(3000, matrix.UP_ARROW, matrix.VERTICAL);

    // Displaying animation (LEFT_ARROW, horizontal orientation)
    matrix.displayAnimation(3000, matrix.LEFT_ARROW, matrix.HORIZONTAL);


    // Displaying text for some amount of time, horizontally.
    matrix.displayText("HELLO ", 500, matrix.HORIZONTAL);

    // Scrolling text with 100ms interval between frames, vertically.
    matrix.scrollText("WORLD ", 100, matrix.VERTICAL);

    // Scrolling text with 100ms interval between frames, horizontally.
    matrix.scrollText("ARDUINO ", 100, matrix.HORIZONTAL);
}
