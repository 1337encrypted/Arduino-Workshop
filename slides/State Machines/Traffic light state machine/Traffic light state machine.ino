#define redPin 3
#define yellowPin 4
#define greenPin 5

enum states
{
  STOP = '0',
  GET_READY = '1',
  GO = '2',
  GET_READY_TO_STOP = '3'
};

states status = STOP;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  switch(status)
  {
    case STOP:
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    delay(5000);
    status = GET_READY;
    break;

    case GET_READY:
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, HIGH);
    status = GO;
    delay(2000);
    break;

    case GO:
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
    status = GET_READY_TO_STOP;
    delay(6000);
    break;

    case GET_READY_TO_STOP:
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    status = STOP;
    delay(2000);
    break;

    default:
    Serial.println("Code wont come here unless hit by a cosmic ray");
  }
}
