#include <Servo.h>

Servo rotater;
Servo leveler;
Servo driver;
Servo gripper;

void setup () {
  rotater.attach(10);
  driver.attach(9);
  leveler.attach(8);
  gripper.attach(11);

  Serial.begin(9600);
}

void loop() {

delay (1000);
int posr = 0;
int posrmin = 90;
int posrmax = 160;

int posd = 0;
int posdmin = 80;
int posdmax = 120;

int posl = 0;
int poslmin = 70;
int poslmax = 120;

int posg = 0;
int posgmin = 70;
int posgmax = 160;

int disacc = 8;
int timer = 50;
int timerinit = 20;
int stepacc = (30-6)/disacc;

driver.write(120);
leveler.write(50);
gripper.write(120);

delay(2000);

gripper.write(65);
delay(1000);
leveler.write(40);

for(posr = posrmin; posr < posrmax-disacc; posr ++){
  rotater.write(posr);
  if(timer > 6){
  timer = timer-stepacc;
  }
  else{
    timer = 6;
  }
  delay(timer);

  Serial.print(timer);
  Serial.print('\n');
}

for(posr = posrmax-disacc; posr <= posrmax; posr ++){
  rotater.write(posr);
  timer = timer + stepacc;
  delay(timer);

  Serial.print(timer);
  Serial.print('\n');
}


timer = timerinit;

for(posr = posrmax; posr > posrmin+disacc; posr --){
  rotater.write(posr);
  if(timer > 6){
  timer = timer-stepacc;
  }
  else{
    timer = 6;
  }
  delay(timer);

  Serial.print(timer);
  Serial.print('\n');
}

for(posr = posrmin+disacc; posr >= posrmin; posr --){
  rotater.write(posr);
  timer = timer + stepacc;
  delay(timer);

  Serial.print(timer);
  Serial.print('\n');
}
  while(true){}
}
