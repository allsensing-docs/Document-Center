# LuminOx(LOX-O₂-S)

## 1.개요

#### 1)제품 설명

LuminOx는 내장형 압력 센서, 디지털 출력이 있는 형광 기반의 소형 산소 센서입니다.

#### 2)제품 사양

| 항목     | 내용                                |
| ------ | --------------------------------- |
| 측정 범위  | 0-25% O₂                          |
| 센서 감지  | 다른 가스에 대한 Cross Sensitivity 거의 없음 |
| 통신 방식  | 3.3V UART                         |
| 전원 전압  | 4.5-5.5VDC                        |
| 센서 치수  | L x W x H(20mm x 20mm x 19.7mm)   |
| 센서 수명  | 5년                                |
| 센서 디자인 | RoHS 및 REACH 준수                   |

#### 3)제품 크기

#### 4)센서 관련 문서

* Datasheet[(PDF링크)](https://sstsensing.com/wp-content/uploads/2018/01/DS0144rev2\_LOX-02-S.pdf)
* User Guide[(PDF링크)](https://14core.com/wp-content/uploads/2017/10/LuminOx-UserGuide\_rev1.pdf)

## 2.제품 구성

#### 1)필요 항목

* [LuminOx(LOX-02-S) Sensor](https://allsensing.com/product/lox-02-s-%EA%B4%91%ED%95%99%EC%8B%9D-%EB%94%94%EC%A7%80%ED%83%88-%EC%82%B0%EC%86%8C%EC%84%BC%EC%84%9C/1174/)
* [산소센서용 PCB](https://allsensing.com/product/detail.html?product\_no=1171\&cate\_no=65\&display\_group=1)(Allsensing 자체 제작 PCB가 있으면 작업이 더욱 수월)
* Arduino Uno Rev3(5V)

#### 2)환경 구축

![](<../../.gitbook/assets/LOX-02-S Sensor with connecting arduino uno rev3.jpg>)

## 3.예제 Code

```arduino
-----------------------------Software -> Arduino IDE----------------------------
-----------------------------Arduino Uno Rev3 Code------------------------------
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); //Uno Rx Tx (12, 13) = mySerial
}

void loop() {
//수신받은 데이터가 0 초과, 즉 데이터가 존재한다면           
 if (mySerial.available())  {  //코드수행   
    Serial.write(mySerial.read());
    }
}
```

![](<../../.gitbook/assets/uno serial monitor (1) (1).jpg>)

* O = 현재 산소분압(PPO₂)값
* T = 현재 온도값
* P = 현재 기압값
* % = 현재 O₂ 퍼센트 값
* e = 센서 상태("e 0000" = 센서상태 좋음, "e xxxx" = [SST sensing](https://sstsensing.com)에 문의)
