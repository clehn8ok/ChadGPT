// Define the keyboard layout
#define KEYBOARD_LAYOUT_GERMAN
//#define KEYBOARD_LAYOUT_ENGLISH
//finally workinng version
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
const int buttonPin = 0;       // Button pin
const int debounceDelay = 50;  // Debounce delay

int lastButtonState = HIGH;
int currentButtonState = HIGH;
unsigned long lastDebounceTime = 0;

// Function to force USB re-enumeration
void usbReconnect() {
  DDRB |= (1 << PB3);       // Set PB3 (D-) as output
  PORTB &= ~(1 << PB3);     // Pull D- low
  DigiKeyboard.delay(500);  // Wait 500ms to simulate disconnection
  DDRB &= ~(1 << PB3);      // Release PB3
  DigiKeyboard.delay(100);  // Short delay before continuing
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Configure button pin
  lastButtonState = digitalRead(buttonPin);

  // Optional: Uncomment this if USB re-enumeration is necessary
  // usbReconnect();

  DigiKeyboard.delay(1000);       // Stabilize USB connection (adjust if needed)
  DigiKeyboard.sendKeyStroke(0);  // Initialize keyboard HID

  DigiKeyboard.println("Device Ready");  // Signal readiness
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Debounce logic
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != currentButtonState) {
      currentButtonState = reading;

      // If button pressed
      if (currentButtonState == LOW) {
        int index = random(0, numPhrases);      // Pick a random phrase
        DigiKeyboard.print(phrases[index]);     // Send phrase
        DigiKeyboard.sendKeyStroke(KEY_ENTER);  // Press Enter
      }
    }
  }

  lastButtonState = reading;
  DigiKeyboard.update();  // Update USB communication
}
