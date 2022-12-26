# LEDs   

## Exercise 1: Blink an LED with `digitalWrite`

```
void setup() {
    pinMode(5, OUTPUT);                                       // initialize the LED pin as an output:
}

void loop() {
    digitalWrite(5, HIGH);                                    // turn on the LED
    delay(500);                                               // wait for 500 milliseconds
    digitalWrite(5, LOW);                                     // turn off the LED
    delay(500);                                               // wait for 500 milliseconds
}
```

## Exercise 2 Solution: Fade an LED with `analogWrite`

```
int i=0;
void setup() {
    pinMode(5, OUTPUT);                                       // initialize the LED pin as an output
}

void loop() {
    analogWrite(5, i);                                      // set the LED brightness
    delay(10);                                              // wait for 10 milliseconds
    i=i+1;  
}

```

## Exercise 3 solution: Use preprocessor Macro `ledPin`   

```
#define ledPin 5

void setup() {
    pinMode(ledPin, OUTPUT);                                  // initialize the LED pin as an output:
    Serial.begin(9600);                                       // initialize the serial port:
}

void loop() {
    digitalWrite(ledPin, HIGH);                               // turn on the LED
    delay(500);                                               // wait for 500 milliseconds
    Serial.println("Led is on");                              // print "Led is on"
    digitalWrite(ledPin, LOW);                                // turn off the LED
    delay(500);                                               // wait for 500 milliseconds
    Serial.println("Led is off");                             // print "Led is off"
}
```

## Exercise 4 Solution: Control multiple LEDs with digitalWrite

```
#define ledPin1 3
#define ledPin2 4
#define ledPin3 5

void setup() {
    pinMode(ledPin1, OUTPUT);                               // initialize the LED pin1 as output
    pinMode(ledPin2, OUTPUT);                               // initialize the LED pin2 as output
    pinMode(ledPin3, OUTPUT);                               // initialize the LED pin3 as output
}

void loop() {
    digitalWrite(ledPin1, HIGH);                            // turn on the LED
    delay(1000);                                            // wait for 1 second
    digitalWrite(ledPin1, LOW);                             // turn off the LED
        
    digitalWrite(ledPin2, HIGH);                            // turn on the LED
    delay(1000);                                            // wait for 1 second
    digitalWrite(ledPin2, LOW);                             // turn off the LED

    digitalWrite(ledPin3, HIGH);                            // turn on the LED
    delay(1000);                                            // wait for 1 second
    digitalWrite(ledPin3, LOW);                             // turn off the LED
}
```

## Exercise 5 Solution: Create a traffic light effect   

```
#define redLed 3
#define yellowLed 4
#define greenLed 5

void setup() {
    pinMode(redLed, OUTPUT);                                // initialize the Ledpin1 as output
    pinMode(yellowLed, OUTPUT);                             // initialize the Ledpin2 as output
    pinMode(greenLed, OUTPUT);                              // initialize the Ledpin3 as output
}

void loop() {

    // red light:

    Serial.println("STOP");
    digitalWrite(redLed, HIGH);                               // turn on the red LED
    digitalWrite(yellowLed, LOW);                             // turn off the yellow LED
    digitalWrite(greenLed, LOW);                              // turn off the green LED
    delay(3000);                                              // wait for 3 seconds

    // red and yellow lights:

    Serial.println("GET READY");
    digitalWrite(redLed, HIGH);                               // turn on the red LED
    digitalWrite(yellowLed, HIGH);                            // turn on the yellow LED
    digitalWrite(greenLed, LOW);                              // turn off the green LED
    delay(2000);                                              // wait for 2 seconds

    // green light:

    Serial.println("GO");
    digitalWrite(redLed, LOW);                                // turn off the red LED
    digitalWrite(yellowLed, LOW);                             // turn off the yellow LED
    digitalWrite(greenLed, HIGH);                             // turn on the green LED
    delay(3000);  // wait for 3 seconds

    // yellow light:

    Serial.println("GET READY TO STOP");
    digitalWrite(redLed, LOW);                                // turn off the red LED
    digitalWrite(yellowLed, HIGH);                            // turn on the yellow LED
    digitalWrite(greenLed, LOW);                              // turn off the green LED
    delay(2000);                                              // wait for 2 seconds
}

```

## Exercise 6 Solution: 4 bit binary counter

```
const int ledPins[] = {12, 10, 8, 6};  

void setup() {
  // initialize the LED pins as outputs:
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // count from 0 to 15 in binary:
  for (int i = 0; i < 16; i++) {
    // set the state of each LED according to the current count:
    digitalWrite(ledPins[0], i & 1);  // least significant bit
    digitalWrite(ledPins[1], i & 2);  // second least significant bit
    digitalWrite(ledPins[2], i & 4);  // third least significant bit
    digitalWrite(ledPins[3], i & 8);  // most significant bit
    delay(1000);  // wait for 1 second
  }
}

```
