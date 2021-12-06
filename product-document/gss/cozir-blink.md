---
description: CozIR-Blink를 선택해 주셔서 감사합니다. 고객님이 시작하는 데 도움이 되는 모든 문서를 제공하였습니다📜
---

# CozIR-LP2

![CozIR-LP2](../../.gitbook/assets/CozIR-LP2.jpg)

## 1.Overview

#### 1)제품 설명

: CozIR-LP2 센서는 최첨단 Solid-State LED 광학 기술을 이용한 초 저전력 NDIR CO₂ 센서입니다.

#### 2)제품 특징

* 최대 1% CO₂ 농도 측정
* Solid state, 움직이는 부품 없음, 가열된 필라멘트 없음
* 진동 및 충격에 강하고 비가열성
* 디지털(UART) 및 I2C 출력
* 일반 NDIR CO₂ 센서보다 최대 50배 낮은 전력
* 간편한 계측 통합을 위한 작은 크기
* 긴 수명, 낮은 유지 보수
* 무선, 휴대용, 웨어러블 및 배터리에 이상적
* 에너지 효율적인 스마트 홈 환경 지원
* IAQ, HVAC, 빌딩 자동화, 계측, 농업, MAP, 자동차, 항공우주 및 안전과 같은 애플리케이션에 쉽게 통합

#### 3)Datasheet

* [Datasheet](https://cdn.shopify.com/s/files/1/0019/5952/files/CozIR-LP2_Data_Sheet_Rev_4.10.pdf)
* [User Guide](https://cdn.shopify.com/s/files/1/0019/5952/files/CO2Meter-GSS-COZIR-LP2-User-Guide-Rev-4.0.pdf)
* [치수 도면](https://cdn.shopify.com/s/files/1/0019/5952/files/Mechanical_Diagram_-_CozIR-LP2-CO2Meter.pdf)

## 2.Quickstart

#### 1)전제 조건

: CozIR-LP2를 사용하는 각 단계를 진행하기 전에 아래 나열된 필수 항목을 준비해야 합니다. (CozIR-LP2 CO₂ Sensor 중에 Pin이 부착되어 있는 센서는 Allsensing에서 자체 제작한 PCB가 같이 있으면 작업이 더욱 수월합니다.)

**하드웨어**

* CozIR-LP2 CO₂ Sensor.
* CozIR용 PCB(Connector 포함 / Allsensing 자체 제작)
* Arduino Due.
* Arduino Jumper Cable Female-male 20cm 4pcs.
* Micro-B USB Cable

**소프트웨어(Arduino IDE를 통한 프로그래밍)**

* [Arduino IDE 설치](https://www.arduino.cc/en/software)
* [Arduino Due 시작하기](https://www.arduino.cc/en/Guide/ArduinoDue)
* Arduino 실행 -> Tools -> Board -> Board Manager -> Filter your search 창에 Due를 입력한 후 설치합니다.

#### 2)제품 구성



1. 위 그림과 같이 Arduino Due와 PCB를 연결합니다.(1번:Vcc 2번:GND 24번:Rx 25번:Tx)
2. PCB와 CozIR CO₂ Sensor를 연결합니다.(단, Sensor의 Vcc, GND, Rx, Tx는 확인하고 부착)
3. Arduino Due 뒷면에서 Programming Port와 Native USB Port 중에 Native USB Port에 Micro-B USB Cable을 연결하세요.
4. 사용자 님의 Board, Port를 알맞게 설정합니다.
5. 예제 Code를 넣은 후 컴파일 및 시리얼 모니터를 확인합니다.

## 3. 예제 Code(Arduino Base)

```arduino
void setup(){
  SerialUSB.begin(115200);
  while(!SerialUSB){} //USB native-serial 초기화 시간 필요


  Serial.begin(9600);//Serial:0(Rx),1(Tx), Serial1:19(Rx),18(Tx)
  delay(500); //센서에서 High 구간 인식할 시간 필요
  while(!Serial){}
  Serial.println("K 2\r\n");//센서를 Polling mode로 변경
  delay(500);
   Serial.println("Z"); CO2값 읽기 명령
}

void loop(){
  if(Serial.available()>0)//데이터가 들어오기 시작
  {
    String str = Serial.readStringUntil('\n');//LF가 들어올 때까지 읽고
    SerialUSB.println(str);//모든 내용을 시리얼 모니터로 보냄
    delay(1000);//1초간 대기
     Serial.println("Z");//CO2값 읽기 명령
  }
}
```

![](<../../.gitbook/assets/serial monitor ex) (1).jpg>)
