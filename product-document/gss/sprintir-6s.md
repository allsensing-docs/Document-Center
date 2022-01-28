# SprintIR-6S-M-5

## 1.개요

#### 1)제품 설명

특허 받은 당사 고유의 LED 기술 플랫폼 및 광학 설계가 내장 되어 있습니다.\
SprintIR-6S는 초당 최대 20회 판독을 수행하므로 높은 반복률에서 개별 측정이 필요하거나 CO₂ 농도가 빠르게 변화하는 장소에 최적화되어있습니다.\

#### 2)제품 사양

| 항목           | 내용                                                                                         |
| ------------ | ------------------------------------------------------------------------------------------ |
| 측정 범위        | <p>Type 1) 0-5%<br>Type 2) 0-10%<br>Type 3) 0-20%<br>Type 4) 0-60%<br>Type 5) 0-100% </p> |
| 센서 내부        | Solid-State                                                                 |
| 센서 응답 속도   | 초당 20회 판독(0-5%센서)                      |
| 통신 방식        | UART                                                                             |
| 전원 전압        | 3.25-5.5V                                                                                  |
| 전력 소비량       | 3.5mW                                                                                      |
| 센서 치수 및 무게   | <p>L x W x H(25mm x 40mm x 31mm)<br>Weight(16g)</p>                                    |
| 센서 내구성       | 진동 및 충격방지                                                                          |
| 센서 교정        | 자동 교정 기능 내장                                                                                |
| 센서 수명        | 15년                                                                                        |
| 센서 적용 어플리케이션 | <p>보건의료<br>식품 포장<br>스포츠 과학</p>                   |

#### 3)제품 크기

#### 4)센서 관련 문서

* Datasheet[(PDF링크)](https://cdn.shopify.com/s/files/1/0019/5952/files/SprintIR-6S\_Data\_Sheet\_Rev\_4.11.pdf)
* User Guide[(PDF링크)](https://cdn.shopify.com/s/files/1/0019/5952/files/CO2Meter-GSS-SprintIR-6S-User-Guide-Rev-4.1.pdf)

## 2.제품 구성

#### 1)필요 항목

* SprintIR-6S-M-5 CO₂ Sensor
* [SprintIR용 PCB](https://www.allsensing.com/product/detail.html?product\_no=1169\&cate\_no=65\&display\_group=1)(Allsensing 자체 제작 PCB가 있으면 작업이 더욱 수월)
* Arduino Due(3.3V)(Arduino Uno Rev3(5V)가능) -> Arduino Due 3.3V 권장

#### 2)환경 구축

![](<../../.gitbook/assets/SprintIR-6S-M-5% Sensor with connecting arduino due.jpg>)

## 3.예제 Code

```arduino
-----------------------------Software -> Arduino IDE----------------------------
-----------------------------Arduino Uno Rev3 Code------------------------------
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13); Uno Tx Rx (12 13) = mySerial

void setup() {
  Serial.begin(9600); //시리얼 통신 초기화
  mySerial.begin(9600); 
  delay(1000); 
  while(!mySerial){} //시리얼 통신 포트가 연결되기 전까지 대기
  mySerial.println("K 2\r\n"); //Polling 모드로 변경 
  delay(100);
  mySerial.println("Z");
}                              

void loop() {
 //수신받은 데이터가 0 초과, 즉 데이터가 존재한다면
 if(mySerial.available()>0) //코드수행
 { //버퍼에서 읽어드린 char의 데이터를 String 형태로 반환
  String str = mySerial.readStringUntil('\n'); 
  Serial.println(str); //CO2값 읽기 명령
  delay(100);
  mySerial.println("Z"); //CO2값 읽기 명령
 }
}
-------------------------------Arduino Due Code--------------------------------
void setup(){
  Serial.begin(9600); //시리얼 통신 초기화
   Serial1.begin(9600); //DUE Tx Rx (18 19) = Serial1
  delay(500); //0.5초 delay
  while(!Serial1){}
  Serial1.println("K 2"); //Polling 모드로 변경     
  delay(500);
   Serial1.println("Z"); //CO2값 읽기 명령
}

void loop(){
  //수신받은 데이터가 0 초과, 즉 데이터가 존재한다면
  if(Serial1.available()>0) //코드수행
  { //버퍼에서 읽어드린 char의 데이터를 String 형태로 반환
    String str = Serial1.readStringUntil('\n');
    Serial.println(str); //CO2값 읽기 명령
    delay(1000);//1초 delay
    Serial1.println("Z"); //CO2값 읽기 명령
  }
}
```

![](<../../.gitbook/assets/sprintir-6s serial monitor ex.jpg>)

Z:디지털 필터링 후 CO₂ 농도
