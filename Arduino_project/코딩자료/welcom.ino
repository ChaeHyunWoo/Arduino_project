#include <LiquidCrystal.h>
LiquidCrystal lcd{12,11,2,3,4,5};//RS E D4 D5 D6 D7 LCD초기화함수
//핀사용
const int TrigPin1 = 6;
const int EchoPin1 = 7;
const int TrigPin2 = 8;
const int EchoPin2 = 9;
const int TrigPin3 = 10;
const int EchoPin3 = 13;
long Duration1 = 0;
long Duration2 = 0;
long Duration3 = 0;
int value = 0;
void setup() {
lcd.begin(16,2); //16글자 2행용 LCD 시작
  pinMode(TrigPin1,OUTPUT);
  pinMode(EchoPin1,INPUT);
  pinMode(TrigPin2,OUTPUT);
  pinMode(EchoPin2,INPUT);
  pinMode(TrigPin3,OUTPUT);
  pinMode(EchoPin3,INPUT);
  Serial.begin(9600);
  
}

void loop() {

//단위출력
  long duration1, distance1;

//  digitalWrite(TrigPin1, HIGH);
//  delay(10);
//  digitalWrite(TrigPin1, LOW);
//
//  duration1 = pulseIn(EchoPin1, HIGH);
//
//  distance1 = duration1/29/2;
//
//  Serial.print(distance1);
//  Serial.print("cm-1");
//  Serial.println();
//
//  delay(100);
  
  long duration2, distance2;

  digitalWrite(TrigPin2, HIGH);
  delay(10);
  digitalWrite(TrigPin2, LOW);

  duration2 = pulseIn(EchoPin2, HIGH);

  distance2 = duration2/29/2;

  Serial.print(distance2);
  Serial.print("cm-2");
  Serial.println();

  delay(100);
    
    long duration3, distance3;

  digitalWrite(TrigPin3, HIGH);
  delay(10);
  digitalWrite(TrigPin3, LOW);

  duration3 = pulseIn(EchoPin3, HIGH);

  distance3 = duration3/29/2;

  Serial.print(distance3);
  Serial.print("cm-3");
  Serial.println();
  
  digitalWrite(8,HIGH);
delayMicroseconds(10);//마이크로세컨드 단위 10^‐6
digitalWrite(8,LOW);
long duration=pulseIn(9,HIGH);//왕복시간 구함
long distance=duration/58.2; //지금은 속도상수이용, 전에는 초음파 초속단위사용
Serial.println(distance);

if(distance2<10 && distance3<10)
{
lcd.clear();//LCD 글자 초기화
lcd.setCursor(0,0);
lcd.print("welcome");
lcd.setCursor(0,1);//열, 행위치,커서출력 두번째행에 첫번째열 출력 출력위치 5cm 커서의위 셋팅
lcd.print("no empty spot");
 }
else if(distance2<10 || distance3<10)
{
lcd.clear();//LCD 글자 초기화
lcd.setCursor(0,0);
lcd.print("welcome");
lcd.setCursor(0,1);//열, 행위치,커서출력 두번째행에 첫번째열 출력 출력위치 5cm 커서의위 셋팅
lcd.print("1 empty spot");
 }
else
{
lcd.clear();//LCD 글자 초기화
lcd.setCursor(0,0);
lcd.print("welcome");
lcd.setCursor(0,1);//열, 행위치,커서출력 두번째행에 첫번째열 출력 출력위치 5cm 커서의위 셋팅
lcd.print("2 empty spot");
 }
}

  
