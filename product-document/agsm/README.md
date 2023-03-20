# AGSM

AGSM은 IoT(사물인터넷)와 연동되는 디바이스에 간편 적용이 가능하며 센서 값 및 환경 변화 상태를 모니터링 할 수 있는 쉬운 방법을 제공합니다.

<figure><img src="../../.gitbook/assets/agsm_main_pic (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

{% content-ref url="agsm_co/" %}
[agsm\_co](agsm\_co/)
{% endcontent-ref %}

{% content-ref url="agsm_h2s/" %}
[agsm\_h2s](agsm\_h2s/)
{% endcontent-ref %}

{% content-ref url="agsm_so2/" %}
[agsm\_so2](agsm\_so2/)
{% endcontent-ref %}

{% content-ref url="agsm_no2/" %}
[agsm\_no2](agsm\_no2/)
{% endcontent-ref %}

{% content-ref url="agsm_o3/" %}
[agsm\_o3](agsm\_o3/)
{% endcontent-ref %}

* 가스 교정(Gas Calibration)이 완료된 AGSM은 센서 농도 값(ppb)을 UART통신을 이용하여 데이터를 전송합니다.
* 빠른 응답 시간(T90<30Sec)을 요구하는 환경에 적용하기에는 적합하지 않으며 장시간 환경 변화 모니터링에 적합하도록 제작되었습니다.
* 최소 30분\~1시간 이상의 센서 안정화 시간이 필요합니다.
* 온도 보정 및 가스 센서 보정 알고리즘에 적용되어 있습니다.
* 센서 구동회로에서 출력된 센서 신호 값(raw data)을 확인 가능(23bit adc)합니다.
* Arduino및 호환 제품과 연동하여 AGSM 제품 적용이 가능합니다.
* 소형, 경량 고성능, 저전력을 요구하는 무선 가스 감지기, 휴대용 및 네트워크 솔루션들에 쉽게 통합하여 적용 가능합니다.
* AGSM은 CO, H2S, SO2, NO2, O3 개별 가스 센서가 적용된 형태로 공급됩니다.
* 센서 교정(Sensor Calibration)
  * 사용자가 교정 가스 및 테스트 환경을 보유하고 있는 경우 통신 명령어를 이용하여 Zero calibration, Span Calibration을 할 수 있습니다.
  * 6개월 주기로 가스 센서 교정(Span Calibration)을 하는 것을 권장합니다.
  * AGSM 제품은 400mL의 소형 챔버를 이용하여 센서 교정을 하였습니다.
