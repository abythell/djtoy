/**
   Thomson Halloween DJ Controller
   @author Andrew Bythell <abythell@ieee.org>
   @copyright 2017

   Arrange 8 LEDS in order in a circle (under the platter).
   Button1 starts a looping/circle effect.
   Button2 starts a random blink effect.
   Both buttons turn all LEDS on.
   Neither button turns all LEDS off.
*/

/** buttons */
#define PIN_RANDOM 11
#define PIN_RING 10

/** led pins - led1 -> led 8 */
const int pin[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int count = 8;

/** global */
const int max = pow(2, count);

void setup() {
  /** buttons are active-low */
  pinMode(PIN_RANDOM, INPUT_PULLUP);
  pinMode(PIN_RING, INPUT_PULLUP);
  /** leds */
  for (int i = 0; i < count; i++) {
    pinMode(pin[i], OUTPUT);
  }
}

/**
    Set LEDS according to bit pattern.
    eg. B0101 turns on the 1st and 3rd led
*/
void ledPattern(uint8_t pattern) {
  for (int i = 0; i < count; i++) {
    digitalWrite(pin[i], bitRead(pattern, count - i - 1) ? HIGH : LOW);
  }
}

/**
   Set LEDS to a pseudo-random pattern
*/
void randomDisplay() {
  int pattern = random(1, max - 1);
  ledPattern(pattern);
  delay(200);
}

/**
   Loop through each LED in ascending order.   
*/
void loopDisplay() {
  for (int i = 0; i < count; i++) {
    ledPattern(1 << i);
    delay(40);
  }
}

/**
   Main Loop
*/
void loop() {
  // read buttons
  byte rndom = (digitalRead(PIN_RANDOM) == LOW);
  byte ring = (digitalRead(PIN_RING) == LOW);
  // select a display
  if (rndom && ring) {    
    ledPattern(0xFF); // all on
  } else if (rndom) {
    randomDisplay();
  } else if (ring) {
    loopDisplay();
  } else {
    ledPattern(0x00); // all off
  }
}
