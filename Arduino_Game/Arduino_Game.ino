#include <Servo.h>
#include "LEDMatrix8x8.h"

Servo gameServo;

// Constants
const int PLAYER_1_BUTTON_PIN = 2;
const int PLAYER_2_BUTTON_PIN = 3;
const int RESET_BUTTON_PIN = 4;

const int MATRIX_DIN_PIN = 13;
const int MATRIX_CLK_PIN = 12;
const int MATRIX_CS_PIN = 11;

const int NUM_DEVICES = 1;

const int SERVO_PIN = 10;
const int PRESS_VALUE = 10;

const unsigned long DEBOUCE_DELAY = 20;

// Other variables
int servoPos;

bool gameActive = false;

volatile bool player1ButtonClicked = false;
volatile bool player2ButtonClicked = false;

volatile unsigned long last1DebounceTime = 0;
volatile unsigned long last2DebounceTime = 0;

bool prevResetState = HIGH;

LEDMatrix8x8::Brightness BRIGHTNESS = LEDMatrix8x8::B_MINIMAL;

LEDMatrix8x8 matrix(MATRIX_DIN_PIN, MATRIX_CLK_PIN, MATRIX_CS_PIN, BRIGHTNESS);

// Game reset
void reset() {
  matrix.displayAnimation(750, matrix.RHOMBUS, matrix.VERTICAL);
  
  servoPos = 90;
  gameServo.write(servoPos);

  matrix.displayAnimation(750, matrix.RHOMBUS, matrix.VERTICAL);
  showCountdownAnimation();
  
  matrix.scrollText("Go ", 40, matrix.VERTICAL);

  gameActive = true;
} 

void setup() {
  matrix.begin();

  gameServo.attach(SERVO_PIN);
  
  attachInterrupt(digitalPinToInterrupt(PLAYER_1_BUTTON_PIN), button1ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(PLAYER_2_BUTTON_PIN), button2ISR, RISING);
  
  pinMode(PLAYER_1_BUTTON_PIN, INPUT_PULLUP);
  pinMode(PLAYER_2_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RESET_BUTTON_PIN, INPUT_PULLUP);
  
  matrix.scrollText("Press reset ", 65, matrix.VERTICAL);
}

// Button interrupts
void button1ISR() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - last1DebounceTime >= DEBOUCE_DELAY) {
    player1ButtonClicked = true;
    last1DebounceTime = currentMillis;
  }
}

void button2ISR() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - last2DebounceTime >= DEBOUCE_DELAY) {
    player2ButtonClicked = true;
    last2DebounceTime = currentMillis;
  }
}

void loop() {
  int resetState = digitalRead(RESET_BUTTON_PIN);
  
  if (resetState == HIGH && prevResetState == LOW)
    reset();
  
  prevResetState = resetState;
  
  if (gameActive){
    while (true) {
      int player1Presses = 0;
      int player2Presses = 0;
      
      if (player1ButtonClicked) {
        ++player1Presses;
        
        player1ButtonClicked = false;
      }
      
      if (player2ButtonClicked) {
        ++player2Presses;
        
        player2ButtonClicked = false;
      }
      
      if (player1Presses > player2Presses)
        servoPos -= PRESS_VALUE; // Move the servo toward player 1
      else if (player2Presses > player1Presses)
        servoPos += PRESS_VALUE; // Move the servo toward player 2
      
      gameServo.write(servoPos);
      
      if (servoPos <= 0) {
        gameActive = false;

        matrix.scrollText("winner 1 ", 65, matrix.VERTICAL);

        break;
      }
      else if (servoPos >= 180){
        gameActive = false;

        matrix.scrollText("winner 2 ", 65, matrix.VERTICAL);

        break;
      }
    }
  }
}

void showCountdownAnimation() {
  matrix.displayCharacter('3', 850, matrix.VERTICAL);
  matrix.displayCharacter('2', 850, matrix.VERTICAL);
  matrix.displayCharacter('1', 850, matrix.VERTICAL);
  matrix.displayCharacter(' ', 1, matrix.VERTICAL);
}