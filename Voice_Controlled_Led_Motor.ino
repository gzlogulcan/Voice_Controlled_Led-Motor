#include<Servo.h>
String voice;
int RED = 2;
int GREEN = 3;
int YELLOW = 4;
int allon1[] = {2,3,4,};
Servo motor;


void RedOn(){
digitalWrite (RED, HIGH);
}

void RedOff(){
digitalWrite (RED, LOW);
}

void GreenOn(){
digitalWrite (GREEN, HIGH);
}

void GreenOff(){
digitalWrite (GREEN, LOW);
}

void YellowOn(){
digitalWrite (YELLOW, HIGH);
}

void YellowOff(){
digitalWrite (YELLOW, LOW);
}

void allon() {
digitalWrite (RED, HIGH);
digitalWrite (GREEN, HIGH);
digitalWrite (YELLOW, HIGH);
}

void alloff() {
digitalWrite (RED, LOW);
digitalWrite (GREEN, LOW);
digitalWrite (YELLOW, LOW);
}



void setup() {
Serial.begin(9600);
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(YELLOW, OUTPUT);
motor.attach(9);
}


void loop() {
while(Serial.available()) {
delay(10);
char c=Serial.read();
if(c=='#')
{break; }
voice += c;
}


if (voice.length() > 0) {
Serial.println(voice);

if (voice == "ledleri yak" || voice == "hepsini yak"){
    allon() ;
  }
else if (voice == "ledleri söndür" || voice=="hepsini söndür"){
    alloff() ;
  }
else if(voice =="kırmızıyı yak" || voice =="kırmızı"){
    RedOn();
  }
else if(voice =="kırmızıyı söndür"){
    RedOff();
  }
else if(voice =="yeşili yak" || voice =="yeşil"){
    GreenOn();
  }
else if( voice =="yeşili söndür" ){
    GreenOff();
  }
else if(voice =="sarıyı yak" || voice =="Sarı"){
    YellowOn();
  }
else if(voice =="sarıyı söndür"){
    YellowOff();
  }
else if(voice =="0"){
    motor.write(0);
  }
else if(voice =="30"){
    motor.write(30);
  }
else if(voice =="60"){
    motor.write(60);
  }
else if(voice =="90"){
    motor.write(90);
  }
else if(voice =="120"){
    motor.write(120);
  }
else if(voice =="150"){
    motor.write(150);
  }
else if(voice =="180"){ 
    motor.write(180);
  }
}

voice="";

}
