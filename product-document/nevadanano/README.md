# Nevadanano

* [Nevadanano main page](https://nevadanano.com/)

{% embed url="https://nevadanano.com/downloads/v1/" %}

Nevadanano는 공기 품질 변화에서 가스 경고 시스템에 이르기까지 광범위한 응용 분야를 위한 가스 센서 및 센서 모듈을 개발, 제조 및 배포하며, Allsensing은 DD-Scientific 및 다양한 환경센서를 고객들에게 유통하고 있으며 센서에 대한 올바른 이해와 사용법을 소개하고 있음

MPS Flammable Gas Sensor (3.0 Version)

<figure><img src="../../.gitbook/assets/MPS_Main_pic.PNG" alt=""><figcaption></figcaption></figure>

## 특징

* 수소, 메탄, 프로판, 부탄 등을 포함하여 12가지가 넘는 가장 일반적인 가연성 가스를 동시에 감지
* 드리프트, 부식 또는 독성이 없으며 수명 기간 동안 유지 관리 필요 x
* 실시간으로 결함이 존재하는 지와 그 이유를 즉시 알려줌
* 실시간 환경 보상 내장
* 교정 불필요
* 자체 테스트 내장
* 저전력( 평균 29mW )
* 실시간 자동 가스 분류
* 유지보수 불필요
* 독성에 지속적으로 노출되어도 중독에 대한 면역
* 예상 수명 15년 이상(2년 보증)
* 아날로그 및 디지털 출력

## 애플리케이션

* 냉매 누출 감지( HVAC(난방, 환기, 냉방) Systems – 냉방 조절 )
* 매탄 누출 감지(천연 가스) 모니터링 장치
* 가연성 가스 감지기
* 산업재해, 산불 등 공중 연기 감지

## 사양

<figure><img src="../../.gitbook/assets/MPS_사양.PNG" alt="" width="563"><figcaption></figcaption></figure>

#### 감지 가스 목록

<figure><img src="../../.gitbook/assets/Nevadanano_감지가스표.PNG" alt=""><figcaption></figcaption></figure>

* 전체 환경 범위에서 메탄에 정확도(Accuracy) 즉 전체 범위(full scale)에서 오차범위 ±5 %LEL &#x20;

## 제품 크기 및 핀 특성

* MPS Flammable Gas Sensor (S4 series)

<figure><img src="../../.gitbook/assets/MPS_pinmap.PNG" alt=""><figcaption></figcaption></figure>

* MPS Mini Flammable Gas Sensor

<figure><img src="../../.gitbook/assets/MPS_Mini_Pinmap.PNG" alt=""><figcaption></figcaption></figure>

#### MPS sensor ISO 10156 규격과, IEC 60079-20-1 규격

※     MPS Gas sensor는 초기에 ISO 10156 기준으로 제조사에서 교정됨(ISO defualt)

※     ISO (International Organization for Standardization) 국제 표준화 기구, IEC (International Electrotechnical Commission) 국제전기기술위원회

<figure><img src="../../.gitbook/assets/MPS_IEC_ISO_표.PNG" alt=""><figcaption></figcaption></figure>

* 가연성 가스의 % Vol, % LEL, PPM 사이의 관계: 5.0 % VOL=100 % LEL=50000PPM
* 메탄(methane)의 경우 ISO 10156 규격일 경우 100 %LEL일때 5.0 % VOL = 50000PPM, IEC 60079-20-1 규격일 경우 100 %LEL일때 4.4 % VOL = 약 44014PPM , 즉 ISO 규격과 IEC 규격의 차이는 약 1.136배수 차이가 발생함( 4.4% \* 1.136 = 4.9984 = 약 5%)

ex) methane IEC, ISO 각각  50 %LEL 주입 시 농도 비교

{% tabs %}
{% tab title="ISO" %}
<figure><img src="../../.gitbook/assets/ISO_시리얼모니터.PNG" alt="" width="563"><figcaption></figcaption></figure>
{% endtab %}

{% tab title="IEC" %}
<figure><img src="../../.gitbook/assets/IEC_시리얼 모니터.PNG" alt="" width="548"><figcaption></figcaption></figure>
{% endtab %}
{% endtabs %}



#### 메탄(methane) 가스 정확도

<figure><img src="../../.gitbook/assets/Methane_주입가스농도.PNG" alt="" width="517"><figcaption></figcaption></figure>



### Analog

* 아날로그 값 범위:  0.01V\~2.9V
* 가스 농도 값 범위: 0.4 V (0 %LEL) to 2.0 V (100 %LEL)



<figure><img src="../../.gitbook/assets/가스_농도에따른 아날로그 output.PNG" alt=""><figcaption></figcaption></figure>

* 센서 상테 에러

<figure><img src="../../.gitbook/assets/센서_상태_에러.PNG" alt="" width="563"><figcaption></figcaption></figure>

* 감지기(DETECTOR)와 MPS 센서의 아날로그 출력 연결

<figure><img src="../../.gitbook/assets/연결방법.PNG" alt=""><figcaption></figcaption></figure>

* Load resistance에 따른 출력 오차율

<figure><img src="../../.gitbook/assets/출력오차율.PNG" alt=""><figcaption></figcaption></figure>

* Figure 9에서 Resistance 100kΩ 일때 출력 오차율이 1%정도 발생, 100kΩ 이상이면 오차율이 1% 이하로 감소



## MPS Sensor 디버깅

### Nevadanano 개발키트 이용

* [MPS Flammable Gas Sensor Evaluation Unit User Manual](https://nevadanano.com/wp-content/uploads/2021/11/SM-UM-0001-06-Flammable-Gas-Sensor-Evaluation-Unit-User-Manual.pdf)

<figure><img src="../../.gitbook/assets/개발키트_rere.PNG" alt="" width="563"><figcaption><p>그림 1</p></figcaption></figure>

* 그림 1의 PCB에와 mps 센서 연결,  Micro usb 연결 후  Micro usb를 pc에 연결 한 뒤 Nevadanano interface Program 실행
* [Download MPS Gas Sensor Interface Installer](https://nevadanano.com/wp-content/uploads/2022/03/MPS-Gas-Sensor-Interface.zip)

<figure><img src="../../.gitbook/assets/시리얼_프로그램.PNG" alt="" width="563"><figcaption></figcaption></figure>

### Nevadanano 개발키트 x

1. MPS 센서와 FTDI FT230x series USB-to-serial converter 를 이용하여 Nevadanano interface Program 실행

* [Sensor Testing Without the Evaluation Unit](https://nevadanano.com/wp-content/uploads/2020/06/SM-AN-0014-01-Sensor-Testing-without-the-NNTS-Evaluation-Kit.pdf)

2. MPS 센서와  USB-to-serial converter를 이용하여 Serial Program으로 디버깅( 통신 Command는 [통신프로토콜](https://app.gitbook.com/o/Kf02NeqxuSI0LF2rYZKc/s/8USAZVpjShlBinaURjim/\~/changes/85/product-document/nevadanano/undefined-1) 참고)


