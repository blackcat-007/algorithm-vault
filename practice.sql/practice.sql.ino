#include <Servo.h>
#include <Wire.h>
#include <MPU6050.h>

// =====================================
// ULTRASONIC SENSOR
// =====================================

#define TRIG_PIN 2
#define ECHO_PIN 3

// =====================================
// SERVO
// =====================================

#define SERVO_PIN 4

// =====================================
// L298N MOTOR DRIVER
// RIGHT SIDE -> OUT1 OUT2
// LEFT SIDE  -> OUT3 OUT4
// =====================================

#define ENA 5
#define IN1 6
#define IN2 7

#define IN3 8
#define IN4 9
#define ENB 10

// =====================================
// OBJECTS
// =====================================

Servo scannerServo;
MPU6050 mpu;

// =====================================
// VARIABLES
// =====================================

int obstacleLimit = 20;

// =====================================
// SETUP
// =====================================

void setup() {

  Serial.begin(9600);

  // ---------------- MOTOR PINS ----------------

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // ---------------- ULTRASONIC ----------------

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // ---------------- SERVO ----------------

  scannerServo.attach(SERVO_PIN);
  scannerServo.write(90);

  // ---------------- MPU6050 ----------------

  Wire.begin();
  mpu.initialize();

  // ---------------- ENABLE MOTORS ----------------

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  // ---------------- STOP ROBOT INITIALLY ----------------

  stopRobot();

  Serial.println("================================");
  Serial.println("AUTONOMOUS ROBOT STARTED");
  Serial.println("MPU6050 INITIALIZED");
  Serial.println("================================");

  delay(1000);
}

// =====================================
// MAIN LOOP
// =====================================

void loop() {

  readTerrainData();

  int frontDistance = getDistance();

  Serial.print("Front Distance: ");
  Serial.println(frontDistance);

  // ---------------- MOVE / OBSTACLE ----------------

  if (frontDistance > obstacleLimit || frontDistance <= 0) {

    moveForward();
  } else {

    Serial.println("Obstacle Detected!");

    stopRobot();

    delay(200);

    chooseDirection();
  }

  Serial.println("--------------------------------");

  delay(30);
}

// =====================================
// DISTANCE FUNCTION
// =====================================

int getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // NO ECHO

  if (duration == 0) {

    return 200;
  }

  int distance = duration * 0.034 / 2;

  return distance;
}

// =====================================
// TERRAIN ANALYSIS
// =====================================

void readTerrainData() {

  int16_t ax, ay, az;

  mpu.getAcceleration(&ax, &ay, &az);

  int vibration = abs(az - 16384);

  float tiltX = ax / 16384.0;
  float tiltY = ay / 16384.0;

  Serial.print("AX: ");
  Serial.print(ax);

  Serial.print(" AY: ");
  Serial.print(ay);

  Serial.print(" AZ: ");
  Serial.println(az);

  // ---------------- TERRAIN ----------------

  if (vibration < 1000) {

    Serial.println("Terrain: Smooth");
  } else if (vibration < 4000) {

    Serial.println("Terrain: Moderate");
  } else {

    Serial.println("Terrain: Rough");
  }

  // ---------------- TILT ----------------

  if (abs(tiltX) > 0.7 || abs(tiltY) > 0.7) {

    Serial.println("Dangerous Tilt Detected");
  }

  Serial.print("Vibration: ");
  Serial.println(vibration);
}

// =====================================
// MOVE FORWARD
// =====================================


void moveForward() {

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  // RIGHT SIDE FORWARD

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // LEFT SIDE FORWARD

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("Moving Forward");
}

// =====================================
// STOP ROBOT
// =====================================

void stopRobot() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println("Robot Stopped");
}

// =====================================
// TURN LEFT
// =====================================

void turnLeft() {

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  // RIGHT SIDE FORWARD

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // LEFT SIDE BACKWARD

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  Serial.println("Turning Left");

  delay(350);

  stopRobot();

  delay(100);
}

// =====================================
// TURN RIGHT
// =====================================

void turnRight() {

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  // RIGHT SIDE BACKWARD

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // LEFT SIDE FORWARD

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("Turning Right");

  delay(350);

  stopRobot();

  delay(100);
}

// =====================================
// CHOOSE DIRECTION
// =====================================

void chooseDirection() {

  int leftDistance;
  int rightDistance;

  // ---------------- LOOK LEFT ----------------

  scannerServo.write(150);

  delay(400);

  leftDistance = getDistance();

  // ---------------- LOOK RIGHT ----------------

  scannerServo.write(30);

  delay(400);

  rightDistance = getDistance();

  // ---------------- CENTER ----------------

  scannerServo.write(90);

  delay(150);

  Serial.print("Left Distance: ");
  Serial.print(leftDistance);

  Serial.print(" Right Distance: ");
  Serial.println(rightDistance);

  // ---------------- DECISION ----------------

  if (leftDistance > rightDistance) {

    turnLeft();
  } else {

    turnRight();
  }
}