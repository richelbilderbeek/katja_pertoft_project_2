// Goal
// 
// - When pressing a button, a first song will play until the end
// - For five times, when pressing a button,
//   a next, different, song will play until the end
// 
// Adapted from Example2-PlayNext written by Nathan Seidle

#include <Arduino.h>
#include "DYPlayerArduino.h"

// Initialise the player, it defaults to using Serial.
DY::Player player;
const int button_pin{8};
const int builtin_led_pin{13};
int current_song{1};
const int volume{30}; // Max volume is 30

void setup() {
  pinMode(button_pin, INPUT);
  pinMode(builtin_led_pin, OUTPUT);
  player.begin();
  player.setVolume(30); // 50% Volume
}

void loop() {
  if (current_song == 6) return;
  const bool button_pressed{digitalRead(button_pin)};
  if (button_pressed)
  {
    digitalWrite(builtin_led_pin, HIGH);
    player.playSpecified(current_song);
    delay(10000);
    digitalWrite(builtin_led_pin, LOW);
    ++current_song;
  }
  delay(1);    
}
