#include <avr/wdt.h>

int32_t cur = 0;
void setup() {
 Serial.begin(9600);
 Serial.println("Reset");
 wdt_enable(WDTO_2S);
}

void loop() {
  Serial.print("res = ");
  Serial.println(cur);
  delay(500);
  if (Serial.available() > 0) {
    wdt_reset();
    cur += Serial.parseInt(SKIP_ALL);
  }
}
