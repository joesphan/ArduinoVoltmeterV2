

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1


extern float ch1Voltage;
extern float ch2Voltage;
extern float ch1Current;
extern float ch2Current;

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void initDisplayGFX() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
}
void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(" ");
  display.setCursor(0, 16);
  display.println("CH1:");
  display.setCursor(0, 48);
  display.println("CH2:");
  display.setTextSize(2);
  display.setCursor(112, 0);
  display.println("V");
  display.setCursor(112, 16);
  display.println("A");
  display.setCursor(112, 32);
  display.println("V");
  display.setCursor(112, 48);
  display.println("A");
  /*
    //ch2Value = ch2Value * 10;   //debug test
    //ch1Value = ch1Value * 10;   //debug test
    char ch1VoltageConverted[8];
    char ch2VoltageConverted[8];
    dtostrf(ch1Voltage, 7, 4, ch1VoltageConverted);
    dtostrf(ch2Voltage, 7, 4, ch2VoltageConverted);

    char ch1CurrentConverted[8];
    char ch2CurrentConverted[8];
    dtostrf(ch1Current, 7, 4, ch1CurrentConverted);
    dtostrf(ch2Current, 7, 4, ch2CurrentConverted);
    if (ch1Voltage == 0) {
      digitalWrite(13, HIGH);
    }
  */
  /*
    display.setTextSize(2);
    display.setCursor(24, 0);
    display.println(ch1VoltageConverted);
    display.setCursor(24, 16);
    display.println(ch1CurrentConverted);
    display.setCursor(24, 32);
    display.println(ch2VoltageConverted);
    display.setCursor(24, 48);
    display.println(ch2CurrentConverted);
  */
  display.setTextSize(2);
  display.setCursor(24, 0);
  display.println(String(ch1Voltage, 3));
  display.setCursor(24, 16);
  display.println(String(ch1Current, 3));
  display.setCursor(24, 32);
  display.println(String(ch2Voltage, 3));
  display.setCursor(24, 48);
  display.println(String(ch2Current, 3));
  display.display();
}
void updateDebugDisplay() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(24, 0);
  display.println(data1);
  display.setCursor(24, 16);
  display.println(data0);
  display.setCursor(24, 32);
  //display.println(String(ch2Voltage, 3));
  display.setCursor(24, 48);
  //display.println(String(ch2Current, 3));
  display.display();
}
