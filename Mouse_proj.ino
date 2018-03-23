#define PEAKPIN1 A1
#define PEAKPIN2 A2
#define MOTOR1 3
#define MOTOR2 5
#define Kp 0.1
#define Kd 4
#define maxSpeed 255
#define baseSpeed 255

#define speedTurn 180

int peak1;
int peak2;


void setup() {
  // put your setup code here, to run once:
  pinMode(PEAKPIN1, INPUT);
  pinMode(PEAKPIN2, INPUT);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  Serial.begin(9600);
}

int lastError = 0;
int error = 0;

void loop() {
  // put your main code here, to run repeatedly:
  peak1 = analogRead(PEAKPIN1);
  peak2 = analogRead(PEAKPIN2);
  Serial.println(peak1);
  Serial.println(peak2);
  error = (peak2 - peak1);
  int motorspeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = baseSpeed + motorspeed;
  int leftMotorSpeed = baseSpeed - motorspeed;

  if (rightMotorSpeed > maxSpeed) rightMotorSpeed = maxSpeed;
  if (leftMotorSpeed > maxSpeed) leftMotorSpeed = maxSpeed;
  if (rightMotorSpeed < 0) rightMotorSpeed = 0;
  if (leftMotorSpeed < 0) leftMotorSpeed = 0;

  analogWrite(MOTOR2, leftMotorSpeed);
  analogWrite(MOTOR1, rightMotorSpeed);
  
}
