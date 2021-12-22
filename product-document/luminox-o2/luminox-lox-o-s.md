---
description: LuminOx(LOX-O₂-S)를 선택해 주셔서 감사합니다. 제품 활용 방법에 도움이 되는 모든 문서를 제공하였습니다.
---

# LuminOx(LOX-O₂-S)

![LuminOx(LOX-O₂-S)](../../.gitbook/assets/lox-o2-s250x250.png)

## 1.Overview

#### 1)제품 설명

:LuminOx는 내장형 압력 센서, 디지털 출력이 있는 형광 기반의 소형 산소 센서입니다.

#### 2)제품 특징

* 저전력 센서
* 내부의 센서를 통한 온도, 압력 및 고도 보정
* 다른 가스에 대한 Cross Sensitivity 거의 없음(산소에 대한 선택적 감지)
* RoHs 및 REACH 준수
* 3.3V UART(디지털 출력)
* 명령어를 통한 제어 가능

#### 3)Documents

* Datasheet[(PDF링크)](https://sstsensing.com/wp-content/uploads/2018/01/DS0144rev2\_LOX-02-S.pdf)
* User Guide[(PDF링크)](https://14core.com/wp-content/uploads/2017/10/LuminOx-UserGuide\_rev1.pdf)

## 2.Quickstart

#### 1)전제 조건

:LuminOx(LOX-O₂-S)를 사용하는 각 단계를 진행하기 전에 아래 나열된 필수 항목을 준비해야 합니다.

**하드웨어**

* LuminOx(LOX-O₂-S) Sensor.
* [산소센서용 PCB](https://allsensing.com/product/detail.html?product\_no=1171\&cate\_no=65\&display\_group=1)(필수 옵션에서 산소센서용 선택 후 주문 / Allsensing 자체 제작)
* Arduino Due.
* Arduino Jumper wires Female-male 20cm 4pcs.
* USB 2.0 Micro B Cable.

**소프트웨어(Arduino IDE를 통한 프로그래밍)**

* [Arduino IDE 설치](https://www.arduino.cc/en/software)
* [Arduino Due 시작하기](https://www.arduino.cc/en/Guide/ArduinoDue)
* Arduino 실행 -> Tools -> Board -> Board Manager -> Filter your search 창에 Due를 입력한 후 설치합니다.

#### 2)제품 구성

![](<../../.gitbook/assets/LuminOx(lox-o2-s) Sensor with connecting arduino due.jpg>)

1. 위 그림과 같이 Arduino Uno와 PCB를 연결합니다.
2. PCB와 LuminOx(LOX-O₂-S)를 연결합니다.(단, Sensor의 Vcc, GND, Rx, Tx는 확인하고 부착)
3. Arduino Uno와 USB 2.0 Cable Type A/B를 연결하세요.
4. 사용자의 Board, Port를 알맞게 설정합니다.
5. 예제 Code를 넣은 후 컴파일 및 시리얼 모니터를 확인합니다.

## 3.예제 Code(Arduino Due Base)

```arduino
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600); //Arduino Due Rx Tx
}

void loop() {
//수신받은 데이터가 0 초과, 즉 데이터가 존재한다면           
 if (Serial1.available())  {  //코드수행   
    Serial.write(Serial1.read());
    }
}
```

![](<../../.gitbook/assets/LuminOx(lox-o2-s) 시리얼 모니터.jpg>)

* O = 현재 산소분압(PPO₂)값
* T = 현재 온도값
* P = 현재 기압값
* % = 현재 O₂ 퍼센트 값
* e = 센서 상태("e 0000" = 센서상태 좋음, "e xxxx" = [SST sensing](https://sstsensing.com)에 문의)

## 4.LuminOx(LOX-O₂-S) Monitoring

![](broken-reference)

## 5.참조

* [Sensor Datasheet](https://sstsensing.com/product/luminox-sealed-optical-oxygen-sensor/)
