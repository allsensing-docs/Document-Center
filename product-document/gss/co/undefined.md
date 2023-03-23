# 디바이스 연결 방법

## Connection DIAGRAM (UART)

<figure><img src="../../../.gitbook/assets/connetion_uart_diagram.PNG" alt=""><figcaption></figcaption></figure>

## Connection DIAGRAM (I2C)

<figure><img src="../../../.gitbook/assets/CozIR-Blink_connetion_diagram_i2c.PNG" alt=""><figcaption></figcaption></figure>

###

{% tabs %}
{% tab title="아두이노우노 uart" %}
<figure><img src="../../../.gitbook/assets/cozir_lp2_arduino_uno_2.PNG" alt=""><figcaption></figcaption></figure>
{% endtab %}

{% tab title="아두우노 우노   i2c" %}
<figure><img src="../../../.gitbook/assets/CozIR-LP2_with_ESP32.PNG" alt=""><figcaption></figcaption></figure>
{% endtab %}

{% tab title="Untitled" %}
<figure><img src="../../../.gitbook/assets/cozir_lp2_with_ESP8266.PNG" alt=""><figcaption></figcaption></figure>
{% endtab %}
{% endtabs %}

### Arduino Uno와 Cozir-LP2 연결

* I2C

|  항목 | Arduino Uno | Cozir-LP2 |
| :-: | :---------: | :-------: |
| VCC |  5V or 3.3V |    VCC    |
| GND |     GND     |    GND    |
|  TX |      A5     |    SCL    |
|  RX |      A4     |    SDA    |

<figure><img src="../../../.gitbook/assets/Cozir_series_i2c_connection_with_arduino.PNG" alt=""><figcaption></figcaption></figure>

* UART

|  항목 | Arduino Uno | Cozir-LP2 |
| :-: | :---------: | :-------: |
| VCC |  5V or 3.3V |    VCC    |
| GND |     GND     |    GND    |
|  TX |      13     |     RX    |
|  RX |      12     |     TX    |

<figure><img src="../../../.gitbook/assets/Cozir_series_uart_connection_with_arduino_uno.PNG" alt=""><figcaption></figcaption></figure>

### Arduino MKR와 Cozir-LP2 연결

<figure><img src="../../../.gitbook/assets/cozir_lp2_arduino_uno_2.PNG" alt=""><figcaption></figcaption></figure>

### ESP32와 Cozir-LP2 연결

<figure><img src="../../../.gitbook/assets/CozIR-LP2_with_ESP32.PNG" alt=""><figcaption></figcaption></figure>

### ESP8266와 Cozir-LP2 연결

<figure><img src="../../../.gitbook/assets/cozir_lp2_with_ESP8266.PNG" alt=""><figcaption></figcaption></figure>
