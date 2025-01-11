void setup() {
  DDRD = B00011000;     // Set pin 3 and 4 as output
}

void loop() {
  PORTD = B00011000;    // Set pin 3 and 4 to HIGH
  
  PORTD = B00000000;    // Set pin 3 and 4 to LOW
}
