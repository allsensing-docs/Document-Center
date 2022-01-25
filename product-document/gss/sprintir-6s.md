---
description: SprintIR-6S를 선택해 주셔서 감사합니다. 제품 활용 방법에 도움이 되는 모든 문서를 제공합니다.
---

# SprintIR-6S

![SprintIR-6S](../../.gitbook/assets/SprintIR6S250x250.png)

## 1.Overview

#### 1)제품 설명

: SprintIR-6S는 특허 받은 당사 고유의 LED 기술 플랫폼 및 광학 설계가 내장 되어 있습니다. 이 Solid-State 기술은 동급 최고의 속도, 전력 소비 내구성을 가능하게 합니다.

#### 2)제품 특징

* 초당 20회 판독
* 70ppm의 일반적인 측정도
* 측정 범위 최대 100%
* Solid-State NDIR LED 광학 기술
* UART 제어 및 데이터 인터페이스

#### 3)Documents

* Datasheet[(PDF링크)](https://cdn.shopify.com/s/files/1/0019/5952/files/SprintIR-6S\_Data\_Sheet\_Rev\_4.11.pdf)
* User Guide[(PDF링크)](https://cdn.shopify.com/s/files/1/0019/5952/files/CO2Meter-GSS-SprintIR-6S-User-Guide-Rev-4.1.pdf)

## 2.Quickstart

#### 1)전제 조건

: SprintIR-6S를 사용하는 각 단계를 진행하기 전에 아래 나열된 필수 항목을 준비해야 합니다. (SprintIR-6S는 Flow through adaptor가 있는 센서가 있고 막으로만 구성을 갖추고 있는 센서가 있습니다.)

**하드웨어**

* SprintIR-6S CO₂ Sensor.
* [SprintIR용 PCB](https://www.allsensing.com/product/detail.html?product\_no=1169\&cate\_no=65\&display\_group=1)(Connector 미포함으로 주문시 SprintIR용 PCB로 제작 주문 / Allsensing 자체 제작)
* Arduino Due.
* Arduino Jumper wires Female-male 20cm 4pcs.
* USB 2.0 Micro B Cable.

**소프트웨어(Arduino IDE를 통한 프로그래밍)**

* [Arduino IDE 설치](https://www.arduino.cc/en/software)
* [Arduino Due 시작하기](https://www.arduino.cc/en/Guide/ArduinoDue)
* Arduino 실행 -> Tools -> Board -> Board Manager -> Filter your search 창에 Due를 입력한 후 설치합니다.

#### 2)제품 구성

![](<../../.gitbook/assets/SprintIR-6S-M-5% Sensor with connecting arduino due.jpg>)

1. 위 그림과 같이 Arduino Due와 PCB를 연결합니다.
2. PCB와 SprintIR-6S CO₂ Sensor를 연결합니다.(단, Sensor의 Vcc, GND, Rx, Tx는 확인하고 부착)
3. Arduino Due 뒷면에서 Programming Port와 Native USB Port 중에서는 원하시는 Port에 Micro-B USB Cable을 연결하세요.(Allsensing은 Programming Port에 연결)
4. 사용자의 Board, Port를 알맞게 설정합니다.
5. 예제 Code를 넣은 후 컴파일 및 시리얼 모니터를 확인합니다.

## 3.예제 Code(Arduino Due Base)

```arduino
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
  {
    String str = Serial1.readStringUntil('\n');// 들어오는 문자열 읽기
    Serial.println(str);//CO2값 읽기 명령
    delay(1000);//1초 delay
    Serial1.println("Z");//CO2값 읽기 명령
  }
}
```

![](<../../.gitbook/assets/sprintir-6s serial monitor ex.jpg>)

Z:디지털 필터링 후 CO₂ 농도

z:디지털 필터링이 없는 즉각적인 CO₂ 농도

## 4.SprintIR-6S Monitoring

## 5.참조

* [Datasheet](https://www.co2meter.com/products/sprintir6s-5-co2-smart-sensor)
