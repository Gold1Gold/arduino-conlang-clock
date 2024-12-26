const int clockPin = 5;   // Clock
const int pwmPin = 3;     // PWM over OE Pin
const int dataPin = 4;    // Data
const int latchPin = 2;   // Latch

byte leds = 0;      // holds current pattern

// put your setup code here, to run once:
void setup() {
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  setBrightness(0);
  leds = 0;
  updateShiftRegister();
  delay(50);
  for (int i = 0; i < 8; i++) {     // Turns on all LEDs one by one
    bitSet(leds, i);                // Sets bit that controls LEDs in variable "leds"
    updateShiftRegister();
    delay(100);
  } 
  for (byte b = 0; b < 255; b++) {
    setBrightness(b);
    delay(10);
  }
  

  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
}

// sets A3/Latch Pin to low, then calls "shiftOut()" to shift out contents of the variable "leds" into the shift register before setting A3/Latch Pin back to low
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

// generates PWM (Pulse Width Modulation) signal and writes it to OE Pin
void setBrightness(byte brightness) {     // 0 to 255
  analogWrite(pwmPin, 255 - brightness);
}
