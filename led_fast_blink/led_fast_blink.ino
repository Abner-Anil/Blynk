#define BLYNK_TEMPLATE_ID "TMPL3pQFqN0Y3"
#define BLYNK_TEMPLATE_NAME "Sample1"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "qaoFiVw4xmavgdQnwW2lq3XoazvI2Wrn";
char ssid[] = "My network";
char pass[] = "123456789";

int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

// ON/OFF
BLYNK_WRITE(V0) {
  int val = param.asInt();
  digitalWrite(LED_BUILTIN, val ? LOW : HIGH);
}

// Fast blink
BLYNK_WRITE(V1) {
  if (param.asInt()) mode = 1;
  else mode = 0;
}

// Slow blink
BLYNK_WRITE(V2) {
  if (param.asInt()) mode = 2;
   else mode = 0;
}

void loop() {
  Blynk.run();

  if (mode == 1) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
  }
  else if (mode == 2) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }
}
