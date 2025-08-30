#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDR 0x3C
#define OLED_W 128
#define OLED_H 64
#define SDA_PIN 9
#define SCL_PIN 8

#define SOIL_PIN 1   // analog pin for moisture sensor

Adafruit_SSD1306 display(OLED_W, OLED_H, &Wire, -1);

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) while (1);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Soil Sensor Ready");
  display.display();
  delay(2000);
}

void loop() {
  int raw = analogRead(SOIL_PIN);     // read raw analog value (0–4095 on ESP32-S2)
  
  // Optional: map to percentage (calibrate min/max in dry/wet soil!)
  int percent = map(raw, 3600, 8000, 100, 1);  
  if (percent < 0) percent = 0;
  if (percent > 100) percent = 100;

  Serial.printf("Raw: %d | Moisture: %d%%\n", raw, percent);

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Soil Moisture");
  display.print("Raw: "); display.println(raw);
  display.print("Moist: "); display.print(percent); display.println("%");
  display.display();

  delay(1000);
}
