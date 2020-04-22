#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define WIFI_SSID "Apollo XR"
#define WIFI_PASSWORD "Utopia123456789"
#define FIREBASE_HOST "com-pro-a93c8.firebaseio.com"
#define FIREBASE_AUTH "k4f674Bntkl9cJ2KNOecHnBGNfXveAPzVHuplYlZ"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  pinMode(D1, OUTPUT);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(D1, Firebase.getInt("Analog"));
  delay(500);

}
