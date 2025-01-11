// const int clockPin = 5;  // Clock
// const int pwmPin = 3;    // PWM over OE Pin
// const int dataPin = 4;   // Data
// const int latchPin = 2;  // Latch

void setup() {
  DDRD |= 0b00011000;  // Set pin 3 and 4 as output
}

void loop() {
  PORTD = B00011000;    // Set pin 3 and 4 to HIGH
  PORTD = B00000000;    // Set pin 3 and 4 to LOW
}

// sets A3/Latch Pin to low, then calls "shiftOut()" to shift out contents of the variable "leds" into the shift register before setting A3/Latch Pin back to low
// void updateShiftRegister() {
//   digitalWrite(latchPin, LOW);
//   shiftOut(dataPin, clockPin, LSBFIRST, leds);
//   digitalWrite(latchPin, HIGH);
// }

// void setup() {
//   DDRD = B00011000;     // Set pin 3 and 4 as output
// }

// void loop() {
//   PORTD = B00011000;    // Set pin 3 and 4 to HIGH
//   PORTD = B00000000;    // Set pin 3 and 4 to LOW
// }
