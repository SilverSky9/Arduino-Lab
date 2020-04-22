#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJSON.h>
#define WIFI_SSID "Apollo XR"
#define WIFI_PASSWORD "Utopia123456789"
#define FIREBASE_HOST "cp62-ef74e.firebaseio.com"
#define FIREBASE_AUTH "Thq49nSBoTU3urL5ifgBsVdDEWyDZUBe0gPP9Jiv"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
    }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.pushInt("analog", 0);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  double Vol, Rtem;
  double temp, B, BB ,R0, T0;
  B = 4050;
  R0 = 10000;
  T0 = 298.15;
  Vol = (val * 3.3)/1023;
  Rtem = (18000 * (3.3 - Vol)) / Vol;
  temp = B/log(Rtem/(R0 * exp(-B/T0)));
  temp = temp - 273.15;
  Serial.println(temp);
//  Firebase.pushInt("analog", temp);
  //
  DynamicJsonBuffer jsonBuffer;
//  JsonObject& timeStampObject = jsonBuffer.createObject();
//  timeStampObject[".sv"] = "timestamp";
//  Firebase.push("time", timeStampObject);
  //
  JsonObject& temperatureObject = jsonBuffer.createObject();
  JsonObject& tempTime = temperatureObject.createNestedObject("timestamp");
  temperatureObject["temperatura"] = temp;
  tempTime[".sv"] = "timestamp";

  Firebase.push("analog", temperatureObject);

  delay(10000);

}
