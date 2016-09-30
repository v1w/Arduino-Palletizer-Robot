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

float X = 0;
float Y = 0;
float Z = 0;

void setup () {
  rotater.attach(10);
  driver.attach(9);
  leveler.attach(8);
  gripper.attach(11);

  rotater.write(posr);
  driver.write(posd);
  leveler.write(posl);
  gripper.write(posg);
  delay(1000);

  Serial.begin(9600);


}

void loop(){
 int i = 0;
  topos(0,90,0,5);
  //loose();
  delay(30000);
  grab();
  delay(1000);
  topos(0,90,-3,5);
  delay(400);
  topos(0,120,-3,20);
  topos(0,120,5,20);
  topos(15,90,5,20);
  topos(15,90,-3,20);
  delay(300);
  topos(15,120,-3,20);
  topos(15,120,5,20);
  topos(15,100,5,20);
  topos(15,100,-3,20);
  delay(500);
  topos(-5,100,-3,20);
  topos(-5,100,20,20);

  
  topos(30,90,20,20);
  topos(30,90,-3,20);
  delay(500);
  topos(30,95,-3,20);
  topos(30,95,5,20);
  topos(30,103,5,20);
  topos(30,103,-3,20);
  delay(500);
  topos(30,120,-3,20);
  
  topos(30,120,20,20);
  topos(0,90,20,20);

}

void topos(float xx, float yy, float zz, int v){
  calangle(xx,yy,zz);
  mvservo(v);
}

void calangle(float xx, float yy, float zz){
  float tmp1 = asin(sqrt(xx*xx+yy*yy+zz*zz)/160)*57.32;
  float tmp2 = 0;
  if (zz >=0 ) tmp2 = (1.57 + atan(zz/sqrt(xx*xx+yy*yy)))*57.32;
  else tmp2 = (1.57-atan((-zz)/sqrt(xx*xx+yy*yy)))*57.32;
  setposr = atan(xx/yy)*57.32 + 90;
  setposd = 170 - tmp2 + tmp1;
  setposl = tmp1 + tmp2 - 90;
/*
  Serial.print("\n r:");
  Serial.print(setposr);
  Serial.print("\n d:");
  Serial.print(setposd);
  Serial.print("\n l:");
  Serial.print(setposl);
  */
}

void mvservo(int v){
  int stepleft = max(max(abs(setposr-posr),abs(setposd-posd)),max(abs(setposl-posl),abs(setposg-posg)));
  while(stepleft >= 0){
  chkrotater(v);chkdriver(v);chkleveler(v);chkgripper(v);
  stepleft--;
  }
}

void chkrotater(int v){
  if(posr == setposr) return;
  else if (posr < setposr){
    rotater.write(posr+1);
    posr += 1;
    delay(v);
  }
  else {
    rotater.write(posr-1);
    posr -= 1;
    delay(v);
  }
}

void chkdriver(int v){
  if(posd == setposd) return;
  else if (posd < setposd){
    driver.write(posd+1);
    posd += 1;
    delay(v);
  }
  else {
    driver.write(posd-1);
    posd -= 1;
    delay(v);
  }
}

void chkleveler(int v){
  if(posl == setposl) return;
  else if (posl < setposl){
    leveler.write(posl+1);
    posl += 1;
    delay(v);
  }
  else {
    leveler.write(posl-1);
    posl -= 1;
    delay(v);
  }
}

void chkgripper(int v){
  if(posg == setposg) return;
  else if (posg < setposg){
    gripper.write(posg+1);
    posg += 1;
    delay(v);
  }
  else {
    gripper.write(posg-1);
    posg -= 1;
    delay(v);
  }
}

void grab(){
  setposg = 60;
  mvservo(5);
}

void loose(){
  setposg = 130;
  mvservo(5);
}




