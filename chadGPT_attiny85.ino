// Define the keyboard layout
#define KEYBOARD_LAYOUT_GERMAN
//#define KEYBOARD_LAYOUT_ENGLISH

#include <DigiKeyboard.h>

// Array of phrases to send
const char* phrases[] = {
  "Don't Get It, More Simple",
  "Less Words, Simple",
  "Explain Like I'm 2",
  "Shorter and Simpler",
  "Talk Monkey to Me",
  "Make It Caveman Easy",
  "Dumb It Down, Bro",
  "Easier, But Better",
  "Simplify Harder",
  "Big Words Scary",
  "Ditch the Fancy Stuff",
  "Explain It Like Pizza",
  "More Human",
  "More Slow, Less Hard"
};


const int numPhrases = sizeof(phrases) / sizeof(phrases[0]);

const int buttonPin = 0;               // Button pin
const int debounceDelay = 50;          // Debounce time in ms
unsigned long lastKeepAlive = 0;
const unsigned long KEEP_ALIVE_INTERVAL = 5000UL; // Changed from 30000 to 5000 (5 seconds)

// Track button states
int lastButtonState = HIGH;      // Previously read button state
int currentButtonState = HIGH;   // "Official" (debounced) state
unsigned long lastDebounceTime = 0;

// Optional function to force USB re-enumeration
void usbReconnect() {
  DDRB |= (1 << PB3);       // Set PB3 (D-) as output
  PORTB &= ~(1 << PB3);     // Pull D- low
  DigiKeyboard.delay(500);  // Wait 500ms to simulate disconnection
  DDRB &= ~(1 << PB3);      // Release PB3
  DigiKeyboard.delay(100);  // Short delay before continuing
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  // Read the starting button state *once* and set both variables the same
  int reading = digitalRead(buttonPin);
  lastButtonState = reading;
  currentButtonState = reading;

  // Seed the random number generator with an unconnected analog pin
  randomSeed(analogRead(A1));

  // Uncomment if USB re-enumeration is needed
  usbReconnect();

  // Let the USB settle
  DigiKeyboard.delay(1000);

  // Initialize keyboard HID
  DigiKeyboard.sendKeyStroke(0);

  // Optional: show a "ready" message
  DigiKeyboard.println("Device Ready");
}

void loop() {
  // Move the keep-alive check to the start of the loop
  if (millis() - lastKeepAlive >= KEEP_ALIVE_INTERVAL) {
    lastKeepAlive = millis();
    DigiKeyboard.sendKeyStroke(0);  // Null keystroke keep-alive
    // Add a second keep-alive action for better reliability
    DigiKeyboard.delay(50);
    DigiKeyboard.update();
  }

  int reading = digitalRead(buttonPin);

  // If the *raw* reading changes, reset the debounce timer
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  // If it's been > debounceDelay since the last change, update currentButtonState
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != currentButtonState) {
      currentButtonState = reading;

      // If the *debounced* state is LOW => button pressed
      if (currentButtonState == LOW) {
        DigiKeyboard.delay(100); // Slight delay for reliability
        int index = random(0, numPhrases);   // Pick a random phrase
        DigiKeyboard.print(phrases[index]);
        DigiKeyboard.sendKeyStroke(KEY_ENTER);
      }
    }
  }

  // Save the raw reading for next time
  lastButtonState = reading;
}

