/* This is the code for the first Arduino board.
 * The code here is for controlling the keypad, sending signals to the other boards and playing crabrave, lovestory, and never gonna give you up
 * Feb 23, 2022 - Feb 25 2022
*/
#define buzzer 6 // buzzer pin
#define row0 7 // top row on keypad
#define row1 8 // second row on keypad
#define row2 9 // third row on keypad
#define row3 10 // fourth row on keypad
#define column0 11 // left column on keypad
#define column1 12 // center column on keypad
#define column2 13 // right column on keypad
#define com0 2 // set comunication pins between boards
#define com1 3
#define com2 4

//defining all note frequencies required for the three songs
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

//The index of the current song
byte song = 0;

// Sets up the buzzer and keypad control pins
void setup() {
  pinMode(buzzer, OUTPUT); // Set buzzer
  pinMode(row0, OUTPUT); // Set rows on keypad to output to enable looping through the keypad to check for input change
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(column0, INPUT); // Set columns as input to read the column of the keypad checked
  pinMode(column1, INPUT);
  pinMode(column2, INPUT);
  digitalWrite(row0, LOW); // write all row outputs to low to initiate default state.
  digitalWrite(row1, LOW);
  digitalWrite(row2, LOW);
  digitalWrite(row3, LOW);
  pinMode(com0, OUTPUT); // Set communication pins
  pinMode(com1, OUTPUT);
  pinMode(com2, OUTPUT);
}



//Set the comunication outputs and play a song if it is stored on this Arduino
void loop() {
  // Plays crabrave and outputs to the other boards that crabrave has been selected.
  if (song == 0) { 
    digitalWrite(com0, LOW);
    digitalWrite(com1, LOW);
    digitalWrite(com2, LOW);
    crabRave(song);
  }
  // plays love story
  else if (song == 1) {
    digitalWrite(com0, HIGH);
    digitalWrite(com1, LOW);
    digitalWrite(com2, LOW);
    loveStory(song);
  }
  // plays never gonna give you up
  else if (song == 2) {
    digitalWrite(com0, LOW);
    digitalWrite(com1, HIGH);
    digitalWrite(com2, LOW);
    rickRoll(song);
  }
  // plays the wii sports theme song
  else if (song == 3) {
    digitalWrite(com0, HIGH);
    digitalWrite(com1, HIGH);
    digitalWrite(com2, LOW);
    update_song(song);
  }
  // plays all star by smash mouth
  else if (song == 4) {
    digitalWrite(com0, LOW);
    digitalWrite(com1, LOW);
    digitalWrite(com2, HIGH);
    update_song(song);
  } // plays running in the 90s
  else if (song == 5) {
    digitalWrite(com0, HIGH);
    digitalWrite(com1, LOW);
    digitalWrite(com2, HIGH);
    update_song(song);
  } // command for looping through all the dance moves sequentially
  else if (song == 6) {
    digitalWrite(com0, LOW);
    digitalWrite(com1, HIGH);
    digitalWrite(com2, HIGH);
    update_song(song);
  }
}

// Buzzer frequency sequence for the first three songs 
void crabRave(byte &song){ //Plays crab rave
  short crab_rave[][2] = {{D5, 240},
                        {AS5, 240},
                        {G5, 240},
                        {G5, 120},
                        {D5, 240},
                        {D5, 120},
                        {A5, 240},
                        {F5, 240},
                        {F5, 120},
                        {D5, 240},
                        {D5, 120},
                        {A5, 240},
                        {F5, 240},
                        {A5, 120},
                        {C5, 240},
                        {C5, 240},
                        {E5, 240},
                        {E5, 120},
                        {F5, 240},
                        {D5, 240},
                        {AS5, 240},
                        {G5, 240},
                        {G5, 120},
                        {D5, 240},
                        {D5, 120},
                        {A5, 240},
                        {F5, 240},
                        {F5, 120},
                        {D5, 240},
                        {D5, 120},
                        {A5, 240},
                        {F5, 240},
                        {F5, 120},
                        {C5, 240},
                        {C5, 240},
                        {E5, 240},
                        {E5, 120},
                        {F5, 240}};
    for (auto &pair : crab_rave) { // iterates through each tone and exits out of the sequence once a song switch is detected
      tone(buzzer, pair[0]);
      delay(pair[1]);
      tone(buzzer, rest);
      if (update_song(song)) {
        break;
      }
    }
}

void loveStory(byte &song) { //plays love story
  short love_story[][2] = {{D5, 250},
                         {D5, 250},
                         {G5, 500},
                         {FS5, 500},
                         {D5, 500},
                         {D5, 250},
                         {E5, 250},
                         {E5, 250},
                         {D5, 250},
                         {FS5, 250},
                         {D5, 250},
                         {E5, 500},
                         {D5, 500},
                         {E5, 500},
                         {FS5, 500},
                         {E5, 500},
                         {D5, 250},
                         {E5, 250},
                         {E5, 250},
                         {D5, 250},
                         {FS5, 250},
                         {D5, 250},
                         {E5, 500},
                         {D5, 500},
                         {E5, 250},
                         {D5, 250},
                         {FS5, 500},
                         {E5, 500},
                         {D5, 500},
                         {E5, 250},
                         {D5, 250},
                         {FS5, 500},
                         {E5, 500},
                         {D5, 250},
                         {D5, 250},
                         {E5, 500},
                         {FS5, 250},
                         {E5, 250},
                         {FS5, 500},
                         {FS5, 250},
                         {E5, 250},
                         {FS5, 500},
                         {FS5, 500},
                         {D5, 500}};
    for (auto &pair : love_story) { // iterates through each tone and exits from the sequence if a song change is detected
      tone(buzzer, pair[0]);
      delay(pair[1]);
      tone(buzzer, rest);
      if (update_song(song)) {
        break;
      }
    }
}

void rickRoll(byte &song) { // plays never gonna give you up
  short rick_roll[][2] = {{F4, 398},
                        {F4, 398},
                        {DS4, 531},
                        {rest, 265},
                        {GS3, 132},
                        {AS3, 132},
                        {C4, 132},
                        {AS3, 132},
                        {DS4, 398},
                        {DS4, 398},
                        {CS4, 132},
                        {C3, 132},
                        {AS3, 398},
                        {GS3, 132},
                        {AS3, 132},
                        {CS4, 132},
                        {AS3, 132},
                        {CS4, 398},
                        {DS4, 398},
                        {C3, 132},
                        {AS3, 398},
                        {GS3, 265},
                        {rest, 132},
                        {GS3, 265},
                        {DS4, 531},
                        {CS4, 531},
                        {rest, 531},
                        {GS3, 132},
                        {AS3, 132},
                        {CS4, 132},
                        {AS3, 132},
                        {F4, 398},
                        {F4, 398},
                        {DS4, 663},
                        {rest, 132},
                        {GS3, 132},
                        {AS3, 132},
                        {C4, 132},
                        {AS3, 132},
                        {GS4, 398},
                        {C4, 398},
                        {CS4, 265},
                        {C4, 132},
                        {AS3, 398},
                        {GS3, 132},
                        {AS3, 132},
                        {C4, 132},
                        {AS3, 132},
                        {CS4, 398},
                        {DS4, 398},
                        {C4, 398},
                        {AS3, 132},
                        {GS3, 265},
                        {rest, 265},
                        {GS3, 265},
                        {DS4, 265},
                        {CS4, 265},
                        {CS4, 531},
                        {rest, 1061}};
    for (auto &pair : rick_roll) {  // iterates through each tone and exits from the sequence if a song change is detected
      tone(buzzer, pair[0]);
      delay(pair[1]);
      tone(buzzer, rest);
      if (update_song(song)) {
        break;
      }
    }
}

// Updates the current song if there is a new key presed on the keypad and returns true when an update happens and false otherwise
bool update_song(byte &song) { 
  byte out = key_pad();
  if (out) {
    song = out - 1;
    return true;
  }
  return false;
}

// receives input from the key pad for 1-6 and returns 0 otherwise
byte key_pad(){ 
  byte out = 0;
  digitalWrite(row1, HIGH);   // reads the second row for any pressed keypads
  delay(5);
  if (digitalRead(column0)) {
    out = 4;
  }
  if (digitalRead(column1)) {
    out = 5;
  }
  if (digitalRead(column2)) {
    out = 6;
  }
  digitalWrite(row1, LOW);
  
  digitalWrite(row0, HIGH);   // reads the first row for any pressed keypads
  delay(5);
  if (digitalRead(column0)) {
    out = 1;
  }
  if (digitalRead(column1)) {
    out = 2;
  }
  if (digitalRead(column2)) {
    out = 3;
  }
  digitalWrite(row0, LOW);
  
  digitalWrite(row2, HIGH);   // reads the third row for any pressed keypads
  delay(5);
  if (digitalRead(column0)) {
    out = 7;
  }
  if (digitalRead(column1)) {
    out = 8;
  }
  if (digitalRead(column2)) {
    out = 9;
  }
  digitalWrite(row2, LOW);
  return out;
}t
