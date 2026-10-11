#include <Arduino.h>

/* SENSOR PINS */
#define PIN_FAR_LEFT 22
#define PIN_LEFT 25
#define PIN_CENTER 33
#define PIN_RIGHT 27
#define PIN_FAR_RIGHT 26

/* MOTOR PINS */
/* Left Motor */
#define IN1_LEFT 19
#define IN2_LEFT 18
#define ENA_PIN 14

/* Right Motor */
#define IN3_RIGHT 17
#define IN4_RIGHT 16
#define ENB_PIN 15

/* PWM CONFIGURATION */
const int PWM_FREQ = 30000;
const int PWM_RESOLUTION = 8;

/* SPEED CONFIGURATION */
int straightSpeed = 165;
int turnSpeed = 150;

/* FUNCTION PROTOTYPES */
void moveForward(int pwm);
void turnLeft(int pwm);
void turnRight(int pwm);
void stopMotors();

void setup() {
  Serial.begin(115200);

  /* Sensor Pin Setup */
  pinMode(PIN_FAR_LEFT, INPUT);
  pinMode(PIN_LEFT, INPUT);
  pinMode(PIN_CENTER, INPUT);
  pinMode(PIN_RIGHT, INPUT);
  pinMode(PIN_FAR_RIGHT, INPUT);

  /* Motor Pin Setup */
  pinMode(IN1_LEFT, OUTPUT);
  pinMode(IN2_LEFT, OUTPUT);
  pinMode(IN3_RIGHT, OUTPUT);
  pinMode(IN4_RIGHT, OUTPUT);

  /* ESP32 PWM Setup */
  ledcAttach(ENA_PIN, PWM_FREQ, PWM_RESOLUTION);
  ledcAttach(ENB_PIN, PWM_FREQ, PWM_RESOLUTION);

  stopMotors();
  delay(1000);
}

void loop() {
  /* Active LOW sensors (line detected) */
  bool farLeft = (digitalRead(PIN_FAR_LEFT) == LOW);
  bool left = (digitalRead(PIN_LEFT) == LOW);
  bool center = (digitalRead(PIN_CENTER) == LOW);
  bool right = (digitalRead(PIN_RIGHT) == LOW);
  bool farRight = (digitalRead(PIN_FAR_RIGHT) == LOW);

  /* MOVE FORWARD */
  if (center) {
    moveForward(straightSpeed);
  }
  /* TURN LEFT */
  else if (left || farLeft) {
    turnLeft(turnSpeed);
  }
  /* TURN RIGHT */
  else if (right || farRight) {
    turnRight(turnSpeed);
  }
  /* LINE LOST */
  else {
    stopMotors();
  }
}

/* MOTOR CONTROL FUNCTIONS */

void moveForward(int pwm) {
  /* Left motor forward */
  digitalWrite(IN1_LEFT, HIGH);
  digitalWrite(IN2_LEFT, LOW);
  ledcWrite(ENA_PIN, pwm);

  /* Right motor forward */
  digitalWrite(IN3_RIGHT, HIGH);
  digitalWrite(IN4_RIGHT, LOW);
  ledcWrite(ENB_PIN, pwm);
}

void turnLeft(int pwm) {
  /* Left motor forward */
  digitalWrite(IN1_LEFT, HIGH);
  digitalWrite(IN2_LEFT, LOW);
  ledcWrite(ENA_PIN, pwm);

  /* Right motor stop */
  digitalWrite(IN3_RIGHT, LOW);
  digitalWrite(IN4_RIGHT, LOW);
  ledcWrite(ENB_PIN, 0);
}

void turnRight(int pwm) {
  /* Left motor stop */
  digitalWrite(IN1_LEFT, LOW);
  digitalWrite(IN2_LEFT, LOW);
  ledcWrite(ENA_PIN, 0);

  /* Right motor forward */
  digitalWrite(IN3_RIGHT, HIGH);
  digitalWrite(IN4_RIGHT, LOW);
  ledcWrite(ENB_PIN, pwm);
}

void stopMotors() {
  digitalWrite(IN1_LEFT, LOW);
  digitalWrite(IN2_LEFT, LOW);
  ledcWrite(ENA_PIN, 0);

  digitalWrite(IN3_RIGHT, LOW);
  digitalWrite(IN4_RIGHT, LOW);
  ledcWrite(ENB_PIN, 0);
}
