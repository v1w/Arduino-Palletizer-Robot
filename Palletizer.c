#include<Servo.h>

Servo rotater;
Servo leveler;
Servo driver;
Servo gripper;

int setposr = 90;
int setposd = 90;
int setposl = 90;
int setposg = 90;

int posr = 90;
int posd = 90;
int posl = 90;
int posg = 90;

void setup () {
  rotater.attach(10);
  driver.attach(9);
  leveler.attach(8);
  gripper.attach(11);

  rotater.write(posr);
  driver.write(posd);
  leveler.write(posl);
  gripper.write(posg);

  Serial.begin(9600);
  delay(1000);
}

void loop() {
 setposr =120;
 setposg = 130; 
 mvservo(); //旋转到指定位置,松开
 setposd = 118;
 setposl = 20;
 mvservo(); //下降
 setposd = 135;
 mvservo(); //下降
 setposg = 70; 
 mvservo(); //抓取
 setposd = 120; 
 mvservo(); //平稳上升
 setposd = 90;
 setposl = 90;
 setposr = 60;
 mvservo(); //上升2
 setposd = 180;
 setposl = 63;
 setposr = 20;
 mvservo(); //旋转,下降
 setposg = 130; 
 mvservo(); //松开
 setposd = 90;
 setposl = 90;
 mvservo(); //上升 
 setposd = 180;
 setposl = 63;
 mvservo(); //下降
 setposg = 70;
 mvservo(); //抓取
 setposd = 120; 
 mvservo(); //平稳上升
 setposd = 90;
 setposl = 90;
 setposr = 80;
 mvservo(); //上升2
 setposd = 118;
 setposl = 20;
 setposr = 120;
 mvservo(); //旋转,下降
 setposd = 135;
 mvservo();
 setposg = 130;
 mvservo(); //松开
 setposd = 90;
 setposl = 90;
 mvservo(); //上升 
 
}

void mvservo(){
  int stepleft = max(max(abs(setposr-posr),abs(setposd-posd)),max(abs(setposl-posl),abs(setposg-posg)));
  while(stepleft >= 0){
  chkrotater();chkdriver();chkleveler();chkgripper();
  stepleft--;
  }
}

void chkrotater(){
  if(posr == setposr) return;
  else if (posr < setposr){
    rotater.write(posr+1);
    posr += 1;
    delay(5);
  }
  else {
    rotater.write(posr-1);
    posr -= 1;
    delay(5);
  }
}

void chkdriver(){
  if(posd == setposd) return;
  else if (posd < setposd){
    driver.write(posd+1);
    posd += 1;
    delay(5);
  }
  else {
    driver.write(posd-1);
    posd -= 1;
    delay(5);
  }
}

void chkleveler(){
  if(posl == setposl) return;
  else if (posl < setposl){
    leveler.write(posl+1);
    posl += 1;
    delay(5);
  }
  else {
    leveler.write(posl-1);
    posl -= 1;
    delay(5);
  }
}

void chkgripper(){
  if(posg == setposg) return;
  else if (posg < setposg){
    gripper.write(posg+1);
    posg += 1;
    delay(5);
  }
  else {
    gripper.write(posg-1);
    posg -= 1;
    delay(5);
  }
}


