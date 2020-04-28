// Motor Left
int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 9;

// Motor Right
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = 10;

// Klakson
int piezoPin = 8;

// Led 
int ledPin = 13;

// Enums
enum Direction {
  Forward = 1, Backward = 0, Stop = 2
};
enum Motor {
  Left = 1, Right = 0
};

// Globals
int pin1 = -1;
int pin2 = -1;
int speedPin = -1;

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);

  //Define L298N Dual H-Bridge Motor Controller Pins
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);

  pinMode(piezoPin, OUTPUT);

}

void loop() {  
  runMotor(Left, Forward, 160);
  runMotor(Right, Forward, 165);
  tone(piezoPin, 1000);
  
  
}

void runMotor(Motor m, Direction d) {
  runMotor(m, d, 255);
}

void runMotor(Motor m, Direction d, int spd, int dly) {
  runMotor(m, d, spd);
  delay(dly);
}

void runMotor(Motor m, Direction d, int spd) {
  pin1 = dir1PinA;
  pin2 = dir2PinA;
  speedPin = speedPinA;
  if (m == Right) {
    pin1 = dir1PinB;
    pin2 = dir2PinB;
    speedPin = speedPinB;
  }
  int valPin1 = HIGH;
  int valPin2 = LOW;
  if (d == Backward) {
    valPin1 = LOW;
    valPin2 = HIGH;
  }else if( d == Stop){
    valPin1 = LOW;
    valPin2 = LOW;
  }

  analogWrite(speedPin, spd);
  digitalWrite(pin1, valPin1);
  digitalWrite(pin2, valPin2);

  return;
}
