#include <ESP8266WiFi.h>

const char* ssid = "ITFORGE_UFO";
const char* password = "";

void setup() {
Serial.begin(115200);
delay(10);

// Connect to WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

WiFi.begin(ssid, password);


while (WiFi.status() != WL_CONNECTED) 
{
delay(500);
Serial.print(".");
}

Serial.println("");
Serial.println("WiFi connected");

// Print the IP address
Serial.print("IP=");
Serial.println(WiFi.localIP());
// Setup Input
// pinMode(D8, INPUT);
}

void loop() {
if ( digitalRead(D8) == LOW ) {
Line_Notify("IoT Workshop with fish Project"); //เรียกใช้ การแจ้งเตือน
delay(10000);
}
delay(1000);

}
const char* host = "maker.ifttt.com";
const char *privateKey = "..."; //แก้ เป็น key ของตัวเอง
const char *event = "..."; // แก้เป็น event ของตัวเอง
void Line_Notify(String msg) {
WiFiClientSecure client;
client.setInsecure();
const int httpPort = 443;
if (!client.connect(host, httpPort)) {
Serial.println("connection failed");
return;
}

// We now create a URI for the request
String url = "/trigger/";
url += event;
url += "/with/key/";
url += privateKey;
String message = "value1=" + String(msg);
client.print(String("POST ") + url + " HTTP/1.1\r\n" +
"Host: " + host + "\r\n" +
"Content-Type: application/x-www-form-urlencoded\r\n" +
"Content-Length: " + message.length() + "\r\n\r\n" +
message + "\r\n");

while (client.connected())
{
if (client.available())
{
String line = client.readStringUntil('\r');
Serial.print(line);
} else {
delay(50);
};

}
}
