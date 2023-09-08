#define BLYNK_TEMPLATE_ID "TMPL3-xke6CQs"
#define BLYNK_TEMPLATE_NAME "DHT IOT SENSOR"
#define BLYNK_AUTH_TOKEN "FG4Um6tIC_2WWrqbIl3-TazORyyYgXKY"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 // Data pin is connected to D2 on ESP
#define DHTTYPE DHT11 // Name the sensor as an object
char auth[]="FG4Um6tIC_2WWrqbIl3-TazORyyYgXKY";
char ssid[]="OnePlus 9R";
char pass[]="Feb250205";
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");
  Blynk.begin(auth,ssid,pass);
  Serial.println("Blynk Connected successfully");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intended.");
    return; 
  }
  Serial.println("Humidity: ");
  Serial.print(h);
Serial.print("%");
  Serial.println("Temperature \n");
  Serial.print(t);
  Serial.print("\n degrees celsius.");
	delay(2000);
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  delay(1000);
}