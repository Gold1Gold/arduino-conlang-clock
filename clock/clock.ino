// This code is designed to run with 74HC595 Shift Registers. It might need slight changes to run with others

const int dataPin = 2;        // DATA/SER - Data
const int oePin = 3;          // OE - Output enable pin, activates on low for 74HC595 series shift registers
const int latchPin = 4;       // STROBE/RCLK - "Latches" the bits from the data pin to the shift register memory
const int clockPin = 5;       // CP/SRCLK - Clock for shift register data
const int clearPin = 6;       // SRCLR - Clears shift register memory

const int interruptPin = 9;  // Interrupt pin or smthn idk yet

byte leds = 0;    // holds current pattern
byte output = 0;  // holds final string of bits to output to shift registers

// put your setup code here, to run once:
void setup() {
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(oePin, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  digitalWrite(clearPin, HIGH);   // SRCLR (the clear pin) should be set to high on the 74HC595 since it's active low (keepign it high is required for the shift register to function)

  setBrightness(255);
  leds = 0;
  updateShiftRegister();
  delay(50);
  for (int i = 0; i < 8; i++) {   // Turns on all LEDs one by one
    bitSet(leds, i);              // Sets bit that controls LEDs in variable "leds"
    updateShiftRegister();
    delay(100);
  }
  for (byte b = 255; b > 0; b--) {
    setBrightness(b);
    delay(10);
  }
}

// sets A3/Latch Pin to low, then calls "shiftOut()" to shift out contents of the variable "leds" into the shift register before setting A3/Latch Pin back to low
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void updateShiftRegisterOutput() {
  leds = output;
}

// generates PWM (Pulse Width Modulation) signal and writes it to OE Pin
void setBrightness(byte brightness) {  // 0 to 255
  analogWrite(oePin, 255 - brightness);
}
