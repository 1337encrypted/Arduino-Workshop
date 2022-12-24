## Exercise 1: Toggle LED and Sound Buzzer with Pushbutton

- To toggle an LED and sound a buzzer with a pushbutton, you can use an if statement to check the state of the button and execute the appropriate code to turn the LED on or off, and use the `tone()` function to play a sound on the buzzer.

```
// Declare variables for LED and pushbutton pins
#define ledPin 13;
#define buttonPin 2;
#define buzzerPin 3;

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, turn on the LED and sound the buzzer
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 440);  // Play a 440 Hz tone
  }
  // If the button is not pressed, turn off the LED and stop the buzzer
  else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);  // Stop the buzzer
  }
}
```

## Exercise 2: Cycle LED Colors and Sound Different

- To cycle an RGB LED through a sequence of colors and sound different frequencies with a pushbutton, you can use a for loop to iterate over the colors and a switch statement to execute the appropriate code for each color. You can use the `analogWrite()` function to control the intensity of each color channel on the LED, and the `tone()` function to play a sound on the buzzer with a different frequency for each color.

```
const int buttonPin = 2;  // Pin connected to pushbutton
const int redPin = 11;    // Pin connected to red channel of RGB LED
const int greenPin = 10;  // Pin connected to green channel of RGB LED
const int bluePin = 9;    // Pin connected to blue channel of RGB LED
const int buzzerPin = 8;  // Pin connected to buzzer

// Enumeration for the different colors
enum Color {
  RED,
  GREEN,
  BLUE
};

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, cycle through the colors and sound different frequencies
  if (buttonState == HIGH) {
    // Iterate over the colors
    for (int i = RED; i <= BLUE; i++) {
      // Set the LED to the current color
      switch (i) {
        case RED:
          digitalWrite(redPin, HIGH);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, LOW);
          break;
        case GREEN:
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, HIGH);
          digitalWrite(bluePin, LOW);
          break;
        case BLUE:
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, LOW);
          digitalWrite(bluePin, HIGH);
          break;
      }

      // Play a sound on the buzzer with a frequency corresponding to the current color
      switch (i) {
        case RED:
          tone(buzzerPin, 262);  // Play a 262 Hz tone (middle C)
          break;
        case GREEN:
          tone(buzzerPin, 330);  // Play a 330 Hz tone (E)
          break;
        case BLUE:
          tone(buzzerPin, 392);  // Play a 392 Hz tone (G)
          break;
     }
```
## OR

```
const int buttonPin = 2;  // Pin connected to pushbutton
const int redPin = 11;    // Pin connected to red channel of RGB LED
const int greenPin = 10;  // Pin connected to green channel of RGB LED
const int bluePin = 9;    // Pin connected to blue channel of RGB LED
const int buzzerPin = 8;  // Pin connected to buzzer

int buttonState = LOW;    // Current state of the pushbutton
int previousState = LOW;  // Previous state of the pushbutton
int colorIndex = 0;       // Index of the current color
int frequency = 440;      // Frequency of the buzzer sound

// Array of colors to cycle through
int colors[][3] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}};

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  buttonState = digitalRead(buttonPin);

  // If the button has just been pressed (rising edge)
  if (buttonState == HIGH && previousState == LOW) {
    // Increment the color index
    colorIndex = (colorIndex + 1) % 3;

    // Update the frequency of the buzzer sound
    frequency = (frequency == 440) ? 880 : 440;

    // Play the new frequency on the buzzer
    tone(buzzerPin, frequency);
  }

  // Set the LED to the current color
  analogWrite(redPin, colors[colorIndex][0]);
  analogWrite(greenPin, colors[colorIndex][1]);
  analogWrite(bluePin, colors[colorIndex][2]);

  // Save the current button state for the next iteration
  previousState = buttonState;
}

```

## Exercise 3: Control LED Brightness and Buzzer Frequency with Potentiometer

- To control the brightness of an LED and the frequency of a buzzer with a potentiometer, you can use the `analogRead()` function to read the potentiometer value and the `analogWrite()` function to control the intensity of the LED and the `tone()` function to play a sound on the buzzer with a frequency that is proportional to the potentiometer's position. 

```
const int potentiometerPin = A0;  // Pin connected to potentiometer
const int ledPin = 13;            // Pin connected to LED
const int buzzerPin = 9;          // Pin connected to buzzer

void setup() {
  // Set pin modes
  pinMode(potentiometerPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the value of the potentiometer
  int potentiometerValue = analogRead(potentiometerPin);

  // Convert the potentiometer value to a brightness value for the LED
  int ledBrightness = map(potentiometerValue, 0, 1023, 0, 255);

  // Set the LED to the appropriate brightness
  analogWrite(ledPin, ledBrightness);

  // Convert the potentiometer value to a frequency value for the buzzer
  int buzzerFrequency = map(potentiometerValue, 0, 1023, 200, 2000);

  // Play the appropriate frequency on the buzzer
  tone(buzzerPin, buzzerFrequency);
}
```

## Exercise 4: Control LED and Buzzer with Potentiometer and Pushbutton

- To control an LED and a buzzer with a potentiometer and a pushbutton, you can use a state machine approach where the state of the system is determined by the values of the potentiometer and pushbutton. You can use an `if` statement to check the state of the button and execute the appropriate code to turn the LED on or off, and use the `tone()` function to play a sound on the buzzer with a frequency that is proportional to the potentiometer's position.

```
const int buttonPin = 2;          // Pin connected to pushbutton
const int potentiometerPin = A0;  // Pin connected to potentiometer
const int ledPin = 13;            // Pin connected to LED
const int buzzerPin = 9;          // Pin connected to buzzer

int buttonState = LOW;  // Current state of the pushbutton

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  buttonState = digitalRead(buttonPin);

  // If the button is pressed
  if (buttonState == HIGH) {
    // Read the value of the potentiometer
    int potentiometerValue = analogRead(potentiometerPin);

    // Convert the potentiometer value to a brightness value for the LED
    int ledBrightness = map(potentiometerValue, 0, 1023, 0, 255);

    // Set the LED to the appropriate brightness
    analogWrite(ledPin, ledBrightness);

    // Convert the potentiometer value to a frequency value for the buzzer
    int buzzerFrequency = map(potentiometerValue, 0, 1023, 200, 2000);

    // Play the appropriate frequency on the buzzer
    tone(buzzerPin, buzzerFrequency);
  }
  // If the button is not pressed
  else {
    // Turn off the LED
    analogWrite(ledPin, 0);

    // Stop the buzzer
    noTone(buzzerPin);
  }
}

```

## Exercise 5: Create a Complex State Machine Program

```
const int buttonPin = 2;        // Pin connected to pushbutton
const int potentiometerPin = A0;  // Pin connected to potentiometer
const int redPin = 11;            // Pin connected to red channel of RGB LED
const int greenPin = 10;          // Pin connected to green channel of RGB LED
const int bluePin = 9;            // Pin connected to blue channel of RGB LED
const int buzzerPin = 8;          // Pin connected to buzzer

enum State {
  IDLE,
  PLAYING,
  WAITING,
  LOSE,
  WIN
};

State state = IDLE;  // Current state of the game

// Array of colors to cycle through
int colors[][3] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}};

// Array of frequencies to play for each color
int frequencies[] = {440, 880, 220};

// Array to store the sequence of colors and sounds
int sequence[10] = {0};

// Index of the current color in the sequence
int sequenceIndex = 0;

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  int buttonState = digitalRead(buttonPin);

  // Read the value of the potentiometer
  int potentiometerValue = analogRead(potentiometerPin);

  // State machine to control the game
  switch (state) {
    // IDLE state: waiting for the user to start the game
    case IDLE:
      // If the button is pressed, start the game
      if (buttonState == HIGH) {
        state = PLAYING;
      }
      break;

    // PLAYING state: playing the sequence of colors and sounds
    case PLAYING:
      // Set the LED to the current color
      int colorIndex = sequence[sequenceIndex];
      analogWrite(redPin, colors[colorIndex][0]);
      analog

```
