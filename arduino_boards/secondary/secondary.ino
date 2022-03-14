/**
 * Code for the secondary Arduino Uno board that stores and plays the last three songs.
 * March 1, 2022
 */

// buzzer pin
#define buzzer 10
 
// communication pins with the other boards
#define com0 2 
#define com1 3
#define com2 4

// notes required for the last three songs
#define rest 0 
#define C2 65
#define CS2 69
#define D2 73
#define DS2 78
#define E2 82
#define F2 87
#define FS2 93
#define G2 98
#define GS2 104
#define A2 110
#define AS2 117
#define B2 123
#define C3 131
#define CS3 139
#define D3 147
#define DS3 156
#define E3 165
#define F3 175
#define FS3 185
#define G3 196
#define GS3 208
#define A3 220
#define AS3 233
#define B3 247
#define C4 262
#define CS4 277
#define D4 294
#define DS4 311
#define E4 330
#define F4 349
#define FS4 370
#define G4 392
#define GS4 415
#define A4 440
#define AS4 466
#define B4 494
#define C5 523
#define CS5 554
#define D5 587
#define DS5 622
#define E5 659
#define F5 698
#define FS5 741
#define G5 784
#define GS5 831
#define A5 880
#define AS5 932
#define B5 988

/**
 * Setup function that creates input pins from the keypad board and output pin for the buzzer
 */
void setup() {
  pinMode(buzzer, OUTPUT); //setup buzzers
  pinMode(com0, INPUT); //set up pins for comunication
  pinMode(com1, INPUT);
  pinMode(com2, INPUT);
}
