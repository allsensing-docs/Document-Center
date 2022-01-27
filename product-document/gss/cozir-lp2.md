# CozIR-LP2

## 1.개요

#### 1)제품 설명

최첨단 Solid-State LED 광학 기술을 이용한 초 저전력 NDIR CO₂ 센서입니다.\
높은 CO₂ 측정 정확도를 유지하면서 전력 소비를 줄일 수 있습니다.\
낮은 전력 소비는 배터리 전원 작동과 호환되므로 무선으로 연결된 장비를 포함한 다양한 어플리케이션에서 센서를 사용할 수 있습니다.

#### 2)제품 사양

| 항목           | 내용                                                                                         |
| ------------ | ------------------------------------------------------------------------------------------ |
| 측정 범위        | <p>Type 1) 0-2000ppm<br>Type 2) 0-5000ppm<br>Type 3) 0-10,000ppm<br>최대 10,000ppm 측정 가능</p> |
| 센서 내부        | Solid-State, 가열된 필라멘트 없음                                                                   |
| 통신 방식        | UART 또는 I²C                                                                                |
| 전원 전압        | 3.25-5.5V                                                                                  |
| 전력 소비량       | 3.5mW                                                                                      |
| 센서 치수 및 무게   | <p>L x W x H(31mm x 19.5mm x 8.7mm)<br>Weight(2.5g)</p>                                    |
| 센서 내구성       | 진동 및 충격에 강하고 비가열성                                                                          |
| 센서 교정        | 자동 교정 기능 내장                                                                                |
| 센서 수명        | 15년                                                                                        |
| 센서 적용 어플리케이션 | <p>IAQ(실내공기질)<br>HVAC(공기조화기술)<br>BMS(건물 관리 시스템)<br>계측, 농업, 자동차, 항공우주</p>                   |

#### 3)제품 크기

![](<../../.gitbook/assets/센서 그림 (1).jpg>)

#### 4)센서 관련 문서

* Datasheet[(PDF링크)](https://cdn.shopify.com/s/files/1/0019/5952/files/CozIR-LP2\_Data\_Sheet\_Rev\_4.10.pdf)
* 치수 도면[(PDF링크)](https://cdn.shopify.com/s/files/1/0019/5952/files/Mechanical\_Diagram\_-\_CozIR-LP2-CO2Meter.pdf)

## 2.제품 구성

#### 1)필요 항목

* CozIR-LP2 CO₂ 센서
* [CozIR용 PCB](https://www.allsensing.com/product/detail.html?product\_no=1171\&cate\_no=65\&display\_group=1)(Allsensing 제작 PCB가 있으면 작업이 더욱 수월)
* Arduino Due(3.3V)(Arduino Uno Rev3(5V)가능) -> Arduino Due 3.3V 권장
* 자체 제작 PCB가 필요 없고 센서에 Soldering을 한다면 사용 가능은 하지만, 열을 가하게 되면 센서 측정에 영향을 줄 수 있어 하루 정도 전원을 넣어주면 자동으로 교정 -> Soldering보다는 PCB 사용 권장

#### 2)환경 구축

![](<../../.gitbook/assets/CozIR LP2 Sensor with connecting arduino due (2).jpg>)

## 3.예제 Code

```arduino
-----------------------------Software -> Arduino IDE----------------------------
-----------------------------Arduino Uno Rev3 Code------------------------------
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13); //Uno Rx Tx (12 13) = mySerial

void setup() {
  Serial.begin(9600); //시리얼 통신 초기화
  mySerial.begin(9600); 
  delay(500); 
  while(!mySerial){} //시리얼 통신 포트가 연결되기 전까지 대기
  mySerial.println("K 2\r\n"); //Polling 모드로 변경
  delay(1000);
  mySerial.println("Z");
}                              

void loop() {
 //수신받은 데이터가 0 초과, 즉 데이터가 존재한다면
 if(mySerial.available()>0) //코드수행
 { //버퍼에서 읽어드린 char의 데이터를 String 형태로 반환
  String str = mySerial.readStringUntil('\n'); 
  Serial.println(str); //CO2값 읽기 명령
  delay(1000);  
  mySerial.println("Z"); //CO2값 읽기 명령
  }
 }
}
-------------------------------Arduino Due Code--------------------------------
void setup(){
  Serial.begin(9600); //시리얼 통신 초기화
   Serial1.begin(9600); //DUE Rx Tx (19 18) = Serial1
  delay(500); 
  while(!Serial1){} //시리얼 통신 포트가 연결되기 전까지 대기
  Serial1.println("K 2"); //Polling 모드로 변경     
  delay(1000);
   Serial1.println("Z"); 
}

void loop(){
  //수신받은 데이터가 0 초과, 즉 데이터가 존재한다면
  if(Serial1.available()>0) //코드수행
  { //버퍼에서 읽어드린 char의 데이터를 String 형태로 반환
    String str = Serial1.readStringUntil('\n');
    Serial.println(str); //CO2값 읽기 명령
    delay(1000); 
    Serial1.println("Z"); //CO2값 읽기 명령
  }
}
```

![](<../../.gitbook/assets/uno serial monitor.jpg>)

Z:디지털 필터링 후 CO₂ 농도

## 4.예제 CozIR-LP2 Monitoring

[![](<../../.gitbook/assets/live graph2.jpg>)](https://cayenne.mydevices.com/shared/61f0f1f73916a44bc3a05ab2)![](<../../.gitbook/assets/live graph2.jpg>)
