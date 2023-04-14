#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define LED LED_BUILTIN

/*Put your SSID & Password*/
const char* ssid = "iPhone de Juan";		// Enter SSID here
const char* password = "11235813";	//Enter Password here

/* Set GET link with channel ID */
const char* link = "http://172.20.10.2:8080";

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  delay(1000);

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() 
{
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // Send HTTP Request
    http.begin(client, link);

    int responseCode = http.GET();
    if (responseCode != 200) {
      Serial.println("Couldn't /GET to the API!");
      Serial.println(responseCode);
      digitalWrite(LED, HIGH);
    } else {
      Serial.print("HTTP Response code: ");
      Serial.println(responseCode);
      digitalWrite(LED, LOW);
      delay(200);
      // Serial.println(http.getString());
    }
  }

  Serial.println("Waiting…");
  delay(1000);
}