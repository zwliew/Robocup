#define TRIG_L 12
#define ECHO_L 11

#define TRIG_R 8
#define ECHO_R 9

void InitUS() {
  pinMode(TRIG_L, OUTPUT);
  pinMode(TRIG_R, OUTPUT);
  pinMode(ECHO_L, INPUT);
  pinMode(ECHO_R, INPUT);

  Serial.println("Initialized ultrasonic.");
}

int ReadLeftUS() {
  digitalWrite(TRIG_L, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_L, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_L, LOW);

  return pulseIn(ECHO_L, HIGH) * 0.034 / 2;
}

int ReadRightUS() {
  digitalWrite(TRIG_R, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_R, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_R, LOW);

  return pulseIn(ECHO_R, HIGH) * 0.034 / 2;
}

/**
 * negative value means the bot is to the left of the center
 * positive value means the bot is to the right of the center
 * value is in centimeters.
 * 
 * The field should be 182cm in width. Since the bot is 20cm in diameter,
 * the balance reading should be 61cm on both sides.
 */
int DistFromCenter() {
  int left = ReadLeftUS();
  int right = ReadRightUS();

  int distance;
  if (left + right < 160) {
    if (right > left) {
      distance = 81 - right;
    } else {
      distance = left - 81;
    }
  } else {
    distance = left - right;
  }
  return distance;
}