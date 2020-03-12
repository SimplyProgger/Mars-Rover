#include <dht11.h>
#include <Wire.h>
dht11 DHT;
#define DHT11_PIN 2

int SLAVE_ADDRESS = 0x04;
int ledPin = 13;
boolean ledOn = false;

void setup() {
    Serial.begin(9600);
    Serial.print(DHT11LIB_VERSION);
    pinMode(ledPin,OUTPUT);
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(processMessage);
    Wire.onRequest(sendAnalogReading);
}

voif loop() {
    int chk;
    chk = DHT.read(DHT11_PIN);
    joys = analogRead(A1);
    switch(chk) {
        case DHTLIB_OK:
          break;
        case DHTLIB_ERROR_CHECKSUM:
          Serial.println("Checksum error,\t");
          break;
        case DHTLIB_ERROR_TIMEOUT:
          Serial.println("Time out error,\t");
          break;
        default:
          Serial.println('Unknown error,\t')
    }
    Serial.print('Humidity = ');
    Serial.print(DHT.humidity,1);
    Serial.print(", Temp = ");
    Serial.println(DHT.temperature,1);
    delay(10000);
}
void processMessage(int n) {
    char ch = Wire.read();
    if(ch == '1'){
        toggleLed();
    }
}

void toggleLed() {
    ledOn = ! ledOn
    digitalWrite(ledPin,ledOn);
}

void sendAnalogReading() {
    byte reading = DHT.temperature;
    Wire.write(reading);
}