# LEDMatrix8x8 Library
The LEDMatrix8x8 library provides an easy way to control an 
8x8 LED matrix using the MAX7219 driver. This library allows you to 
initialize the matrix, set individual pixels, display letters, words and sentences, 
and even show text or pattern animations with customizable durations.


## Installation


To use this library, download the `LEDMatrix8x8.cpp` and `LEDMatrix8x8.h` files and place them in your Arduino libraries folder.


## Getting Started


### Constructor
```
LEDMatrix8x8::LEDMatrix8x8(int dataPin, int clockPin, int latchPin, Brightness brightness);
```

Create an instance of the LEDMatrix8x8 class by providing:
- Data pin number
- Clock pin number
- Latch pin number
- Brightness level


### Initialization
```
void LEDMatrix8x8::begin();
```

Initialize the 8x8 matrix and set up communication with the MAX7219 driver. 
This method must be called before using other functions of the library.


### Predefined data types
- **AnimationType:** \
- RHOMBUS:\
![RHOMBUS](./Pictures/Rhombus.png)

- UP_ARROW:\
![UP_ARROW](./Pictures/Up_arrow.png)

- DOWN_ARROW:\
![DOWN_ARROW](./Pictures/Down_arrow.png)

- LOADING_BAR:\
![LOADING_BAR](./Pictures/Loading_bar.png)

- HEARTBEAT:\
![HEARTBEAT](./Pictures/Heartbeat.png)

- SQUARE:\
![SQUARE](./Pictures/Square.png)
  
- **AnimationMode:**
  - UP
  - DOWN
  
- **Brightness:**
  - MINIMAL
  - LOW
  - MEDIUM
  - HIGH
  - MAX
  
- **State:**
  - ON
  - OFF


## Setting Pixels
```
void LEDMatrix8x8::setPixel(int x, int y, State state);
```

Set the state of a pixel at the specified position (x, y). State can be either ON or OFF.


## Clearing the Display
```
void LEDMatrix8x8::clear();
```

Clear the entire display matrix, turning off all pixels (setting the state to OFF).


## Displaying Characters
```
void LEDMatrix8x8::displayCharacter(char ch, int duration);
```

Display an ASCII character on the screen for the specified duration.


## Displaying Text
```
void LEDMatrix8x8::displayText(String text, int delay);
```

Display a block of text on the screen, letter by letter, at the provided intervals. The delay parameter specifies the time interval (in milliseconds) between displaying each character.


## Displaying Animations
```
void LEDMatrix8x8::displayAnimation(AnimationType animationType, AnimationMode animationMode, int duration);
```

Display an animation on the screen for the specified direction and duration.


## Scrolling Text
```
void LEDMatrix8x8::scrollText(String text, int delay);
```

Display the provided text as a scrolling animation with the specified delay between frames.


## Example Usage
```
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
    // Displaying individual characters
    matrix.displayCharacter('A', 2000);
    matrix.displayCharacter('B', 2000);
    matrix.displayCharacter('C', 2000);

    // Displaying animation (RHOMBUS)
    matrix.displayAnimation(matrix.RHOMBUS, matrix.DOWN, 5000);

    // Displaying animation (LOADING_BAR)
    matrix.displayAnimation(matrix.LOADING_BAR, matrix.UP, 6000);

    // Displaying text for some amount of time
    matrix.displayText("HELLO", 500);

    // Scrolling text with 100ms interval between frames
    matrix.scrollText("WORLD", 100);
}
```

## Contributing
If you find any issues or have suggestions for improvements, please create an issue or a pull request on GitHub.

## License
This project is licensed under the MIT License
