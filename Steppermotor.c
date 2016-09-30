int dir = 5;
int stepper = 2;
int enable = 8;

void setup() {
  pinMode(dir, OUTPUT);
  pinMode(stepper, OUTPUT);
  pinMode(enable, OUTPUT);
}

void loop() {

step(false,6400);
delay(500);

}

void step(boolean d,int steps){
 digitalWrite(dir,d);
 delay(50);
 for(int i=0;i<steps;i++){
   digitalWrite(stepper, HIGH);
   delayMicroseconds(10);
   digitalWrite(stepper, LOW);
   delayMicroseconds(10);
 }
}
