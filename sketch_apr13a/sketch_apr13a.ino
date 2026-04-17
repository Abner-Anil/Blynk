#define BLYNK_TEMPLATE_ID "TMPL3pQFqN0Y3"
#define BLYNK_TEMPLATE_NAME "Sample1"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "qaoFiVw4xmavgdQnwW2lq3XoazvI2Wrn";
char ssid[] = "My network";
char pass[] = "123456789";

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(LED_BUILTIN, value ? LOW : HIGH);
}

void loop() {
  Blynk.run();
}
