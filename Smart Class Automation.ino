#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
#include <DHT.h>
#define dht_pin 4
#define Type DHT11
DHT HT(dht_pin,Type);
float T;
int light=2;
int fan=3;
int ir=5;
int ldr=A0;
void setup() {
 lcd.begin(16,2);
 Serial.begin(9600);
 HT.begin();
 pinMode(light,OUTPUT);
 pinMode(fan,OUTPUT);
 pinMode(ir,INPUT);
 pinMode(ldr,INPUT);
 lcd.clear();
 lcd.print("SMART CLASS");
 lcd.setCursor(0,1);
 lcd.print("AUTOMATION..");
 delay(1000);
}
void loop() {
 T=HT.readTemperature();
 Serial.println("T="+String(T));
 lcd.clear();
 lcd.print("T="+String(T));
 lcd.setCursor(0,1);
 lcd.print("ldrval="+String(analogRead(ldr)));
 delay(1000);
 if(digitalRead(ir)==LOW)
 {
 lcd.clear();
 lcd.print("STUDENT DETECTED");
 delay(1000);
 if(T>35.0)
 {
 digitalWrite(fan,HIGH);
 delay(6000);
 digitalWrite(fan,LOW);
 }
 int ldrval=analogRead(ldr);
 Serial.println("ldrval="+String(ldrval));
 delay(500);
 if(ldrval>700)
 {
 digitalWrite(light,HIGH);
 }
 }
 else
 {
 digitalWrite(light,LOW);
 }
  }
