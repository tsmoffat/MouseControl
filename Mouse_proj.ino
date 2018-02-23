#define PEAKPIN1 A1
#define PEAKPIN2 A2
#define MOTOR1 3
#define MOTOR2 5

int motor1v;
int motor2v;
int peak1;
int peak2;


void setup() {
  // put your setup code here, to run once:
  pinMode(PEAKPIN1, INPUT);
  pinMode(PEAKPIN2, INPUT);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  peak1 = analogRead(PEAKPIN1);
  peak2 = analogRead(PEAKPIN2);
  analogWrite(MOTOR1, motor1v);
  analogWrite(MOTOR2, motor2v);
  if(peak1 > peak2){
    while(peak1 != peak2){
      motor2v++;
    }
  }
  else if(peak2 > peak1){
    while(peak2 != peak1){
      motor1v++;
    }
  }
  else{
    motor1v = 127;
    motor2v = 127;
  }
}
