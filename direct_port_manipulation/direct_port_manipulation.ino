const int clockPin = 5;  // Clock
const int pwmPin = 3;    // PWM over OE Pin
const int dataPin = 4;   // Data
const int latchPin = 2;  // Latch

byte testByte = 0b00010110;

void setup() {
  // DDRD |= 0b00011000;  // Set pin 3 and 4 as output

  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
}

void loop() {

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, testByte);
  digitalWrite(latchPin, HIGH);
  
  // PORTD = B00011000;    // Set pin 3 and 4 to HIGH
  // PORTD = B00000000;    // Set all pins to LOW

  // PORTD = B00011000;    // Set pin 3 and 4 to HIGH
  // PORTD = B00000000;    // Set all pins to LOW

  // Prepare to turn on row 1 out of 5
  // Generate 1 byte: B00000001

  // Prepare to shift 2 bytes into columns
  // Generate 1st byte: B10010101
  // Generate 2nd byte: B11100100
  // Shift 2 bytes into columns

  // Turn on row 1 - shift out
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

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
      uint8_t i;

      for (i = 0; i < 8; i++)  {
            if (bitOrder == LSBFIRST)
                  digitalWrite(dataPin, !!(val & (1 << i)));
            else      
                  digitalWrite(dataPin, !!(val & (1 << (7 - i))));
                  
            digitalWrite(clockPin, HIGH);
            digitalWrite(clockPin, LOW);            
      }
}