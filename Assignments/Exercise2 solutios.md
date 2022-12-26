## Exercise 1: Toggle LED with Pushbutton

```
#define buttonPin 2;      // Pin connected to pushbutton
#define ledPin 13;        // Pin connected to LED

void setup() 
{
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  // Read the state of the pushbutton
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, turn on the LED, pull up resistor is implemented
  if (buttonState == 0) 
  {
    digitalWrite(ledPin, HIGH);
  }
  // If the button is not pressed, turn off the LED
  else 
  {
    digitalWrite(ledPin, LOW);
  }
}
```

## Exercise 2: Control LED Brightness with Potentiometer

To control the brightness of an LED using a potentiometer, you can use the analogRead() function to read the value of the potentiometer and the analogWrite() function to control the brightness of the LED. 

```
#define potentiometerPin = A0;  // Pin connected to potentiometer
#define ledPin = 9;             // Pin connected to LED

void setup() {
  pinMode(potentiometerPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the value of the potentiometer
  int potentiometerValue = analogRead(potentiometerPin);

  // Convert the potentiometer value to a brightness value for the LED
  int ledBrightness = map(potentiometerValue, 0, 1023, 0, 255);

  // Set the LED to the appropriate brightness
  analogWrite(ledPin, ledBrightness);
}

```

## Exercise 3: Toggle LED Blink Mode with Pushbutton

This program will use the pushbutton to toggle between two modes: one where the LED blinks at a fixed rate of 1Hz (1000ms on, 1000ms off), and another where the LED blinks at a rate controlled by the position of the potentiometer.

```
const int buttonPin = 2;        // Pin connected to pushbutton
const int potentiometerPin = A0;  // Pin connected to potentiometer
const int ledPin = 13;            // Pin connected to LED

int mode = 0;  // Current mode (0 for fixed rate, 1 for potentiometer control)

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, toggle the mode
  if (buttonState == HIGH) {
    mode = !mode;
  }

  // If the mode is fixed rate
  if (mode == 0) {
    // Turn on the LED for 500ms
    digitalWrite(ledPin, HIGH);
    delay(500);

    // Turn off the LED for 500ms
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  // If the mode is potentiometer control
  else {
    // Read the value of the potentiometer
    int potentiometerValue = analogRead(potentiometerPin);

    // Convert the potentiometer value to a delay time
    int delayTime = map(potentiometerValue, 0, 1023, 100, 1000);

    // Turn on the LED for half the delay time
    digitalWrite(ledPin, HIGH);
    delay(delayTime / 2);

    // Turn off the LED for half the delay time
    digitalWrite(ledPin, LOW);
    delay(delayTime / 2);
  }
}

```

## Exercise 4: Cycle LED Colors with Pushbutton

```
const int buttonPin = 2;  // Pin connected to pushbutton
const int redPin = 11;    // Pin connected to red channel of RGB LED
const int greenPin = 10;  // Pin connected to green channel of RGB LED
const int bluePin = 9;    // Pin connected to blue channel of RGB LED

int colorIndex = 0;  // Index of the current color (0 for red, 1 for green, 2 for blue)

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, cycle to the next color
  if (buttonState == HIGH) {
    colorIndex = (colorIndex + 1) % 3;
  }

  // Set the LED to the current color
  switch (colorIndex) {
    case 0:
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      break;
    case 1:
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      break;
    case 2:
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 255);
      break;
  }
}

```

# Buzzer

## Exercise 5: Toggle LED Fade Mode with Pushbutton

This program will use the pushbutton to toggle between two modes: one where the LED fades in and out at a fixed rate of 10ms per step, and another where the LED fades in and out at a rate controlled by the position of the potentiometer.

```
const int buttonPin = 2;        // Pin connected to pushbutton
const int potentiometerPin = A0;  // Pin connected to potentiometer
const int ledPin = 9;              // Pin connected to LED

int mode = 0;  // Current mode (0 for fixed rate, 1 for potentiometer control)

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, toggle the mode
  if (buttonState == HIGH) {
    mode = !mode;
  }

  // If the mode is fixed rate
  if (mode == 0) {
    // Fade the LED in and out at a fixed rate
    for (int i = 0; i <= 255; i++) {
      analogWrite(ledPin, i);
      delay(10);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(ledPin, i);
      delay(10);
    }
  }
  // If the mode is potentiometer control
  else {
    // Read the value of the potentiometer
    int potentiometerValue = analogRead(potentiometerPin);

    // Convert the potentiometer value to a delay time
    int delayTime = map(potentiometerValue, 0, 1023, 10, 100);

    // Fade the LED in and out at the potentiometer-controlled rate
    for (int i = 0; i <= 255; i++) {
      analogWrite(ledPin, i);
      delay(delayTime);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(ledPin, i);
      delay(delayTime);
    }
  }
}

```

## Exercise 6: Play a Sound with the Buzzer

```
const int buttonPin = 2;  // Pin connected to pushbutton
const int buzzerPin = 9;  // Pin connected to buzzer

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, play a sound on the buzzer
  if (buttonState == HIGH) {
    tone(buzzerPin, 440, 1000);
  }
  // If the button is not pressed, turn off the buzzer
  else {
    noTone(buzzerPin);
  }
}

```

## Exercise 7: Control Buzzer Frequency with Potentiometer

To use a potentiometer to control the frequency of the sound played by the buzzer, you can use the analogRead() function to read the value of the potentiometer and the map() function to convert the potentiometer value to a specific frequency.

```
const int potentiometerPin = A0;  // Pin connected to potentiometer
const int buzzerPin = 9;          // Pin connected to buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the value of the potentiometer
  int potentiometerValue = analogRead(potentiometerPin);

  // Convert the potentiometer value to a frequency
  int frequency = map(potentiometerValue, 0, 1023, 262, 523);  // Range: C4 to C5

  // Play the sound on the buzzer
  tone(buzzerPin, frequency, 500);

  // Delay for 500ms
  delay(500);
}

```

## Exercise 8: Toggle Buzzer Mode with Pushbutton

```
// constants for the pushbutton pin and potentiometer pin
const int pushButtonPin = 2;
const int potentiometerPin = A0;

// variables to store the current state of the pushbutton and the potentiometer value
int pushButtonState = 0;
int potentiometerValue = 0;

void setup() {
  // set the pushbutton pin as an input
  pinMode(pushButtonPin, INPUT);

  // set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // read the state of the pushbutton
  pushButtonState = digitalRead(pushButtonPin);

  // if the pushbutton is pressed, switch to the second mode
  if (pushButtonState == HIGH) {
    // read the value of the potentiometer
    potentiometerValue = analogRead(potentiometerPin);

    // map the potentiometer value to a frequency range for the buzzer
    int buzzerFrequency = map(potentiometerValue, 0, 1023, 200, 2000);

    // play the buzzer at the specified frequency
    tone(buzzerPin, buzzerFrequency);
  } else {
    // if the pushbutton is not pressed, play a fixed sound using the buzzer
    tone(buzzerPin, 1000);
  }
}

```

## Exercise 9: Control LED Color with Potentiometer

```
const int potentiometerPin = A0;  // Pin connected to potentiometer
const int redPin = 11;           // Pin connected to red channel of RGB LED
const int greenPin = 10;         // Pin connected to green channel of RGB LED
const int bluePin = 9;           // Pin connected to blue channel of RGB LED

void setup() {
  // Set pin modes
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Read the value of the potentiometer
  int potentiometerValue = analogRead(potentiometerPin);

  // Convert the potentiometer value to a color value
  int redValue = map(potentiometerValue, 0, 1023, 0, 255);
  int greenValue = map(potentiometerValue, 0, 1023, 255, 0);
  int blueValue = map(potentiometerValue, 0, 1023, 0, 255);

  // Set the color of the LED
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

```
## Exercise 10: Control LED Brightness and Buzzer Frequency Together

```
const int buttonPin = 2;        // Pin connected to pushbutton
const int potentiometerPin = A0;  // Pin connected to potentiometer
const int ledPin = 9;              // Pin connected to LED
const int buzzerPin = 10;          // Pin connected to buzzer

int mode = 0;  // Current mode (0 for fixed rate, 1 for potentiometer control)

void setup() {
  // Set pin modes
  pinMode(buttonPin, INPUT);
  pinMode(potentiometerPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the state of the pushbutton
  int buttonState = digitalRead(buttonPin);

  // If the button is pressed, toggle the mode
  if (buttonState == HIGH) {
    mode = !mode;
  }

  // If the mode is fixed rate
  if (mode == 0) {
    // Fade the LED in and out at a fixed rate
    for (int i = 0; i <= 255; i++) {
      analogWrite(ledPin, i);
      tone(buzzerPin, 262, 10);  // C4 for 10ms
      delay(10);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(ledPin, i);
      tone(buzzerPin, 262, 10);  // C4 for 10ms
      delay(10);
    }
  }
  // If the mode is potentiometer control
  else {
    // Read the value of the potentiometer
    int potentiometerValue = analogRead(potentiometerPin);

    // Convert the potentiometer value to a delay time and frequency
    int delayTime = map(potentiometerValue, 0, 1023, 10, 100);
    int frequency =

```
