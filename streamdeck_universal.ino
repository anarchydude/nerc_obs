#include <Keyboard.h>

// Put your *working* pins here in physical order:
// top row L->R, then bottom row L->R (excluding the dead one)
const uint8_t pins[] = {2,3,4,5,6,7,8,9,10,15};  // <-- adjust to your wiring/order

// Outputs Ctrl+Alt+Shift+1..9 (use '0' too if you have 10 buttons)
const char outKeys[] = {'1','2','3','4','5','6','7','8','9','0'};

const uint8_t N = sizeof(pins) / sizeof(pins[0]);

bool lastReading[N];
bool debouncedState[N];
unsigned long lastChange[N];
const unsigned long debounceMs = 20;

void sendChord(char k) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);    // Option on macOS, Alt on Windows
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(k);
  delay(25);
  Keyboard.releaseAll();
  delay(25);
}

void setup() {
  for (uint8_t i = 0; i < N; i++) {
    pinMode(pins[i], INPUT_PULLUP);
    lastReading[i] = digitalRead(pins[i]);
    debouncedState[i] = lastReading[i];
    lastChange[i] = 0;
  }
  Keyboard.begin();
}

void loop() {
  unsigned long now = millis();

  for (uint8_t i = 0; i < N; i++) {
    bool reading = digitalRead(pins[i]);

    if (reading != lastReading[i]) {
      lastChange[i] = now;
      lastReading[i] = reading;
    }

    if ((now - lastChange[i]) > debounceMs) {
      if (reading != debouncedState[i]) {
        debouncedState[i] = reading;

        // fire on press edge
        if (debouncedState[i] == LOW) {
          sendChord(outKeys[i]);
        }
      }
    }
  }
}
