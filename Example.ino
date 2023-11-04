#include "LEDMatrix8x8.h"

const int MATRIX_DIN_PIN = 13;
const int MATRIX_CLK_PIN = 12;
const int MATRIX_CS_PIN = 11;

LEDMatrix8x8 matrix(MATRIX_DIN_PIN, MATRIX_CLK_PIN, MATRIX_CS_PIN);

void setup() {
    matrix.begin();
}

void loop() {
    // matrix.displayCharacter('A', 2000);
    // matrix.displayCharacter('B', 2000);
    // matrix.displayCharacter('C', 2000);
    // matrix.displayCharacter('9', 2000);

    // matrix.displaySentence("bb11256 45", 1000);

    matrix.displayAnimation(matrix.TYPE_ONE, matrix.RIGHT, 5000);

    matrix.displaySentence("HELLO WORLD", 500); // Display "HELLO WORLD" with a delay of 500ms between characters

    matrix.ScrollText("HELLO WORLD", 500);
}
