/*
   Arduino Voltmeter
   Joesphan Lu
   https://github.com/joesphan/Arduino-Voltmeter
   Licensed under the Non-Profit Open Software License version 3.0
*/
#define Resistance 0.10550501
#define ch1DataPin 2
//#define ch2DataPin 3
#define rxPinDDRDIR B11110011     //pin 2 and 3 input
#define rxPort PIND
#define rxDDR DDRD

#define Ch1VoltageRatio 22.101849
#define Ch1rxPinSel B00000100    //put a 1 wherever you want the pin selected (2)

#define Ch2VoltageRatio 25.537850
#define Ch2rxPinSel B00001000    //put a 1 wherever you want the pin selected (3)


#define baudrate 500

float ch1Voltage = 0;
float ch2Voltage = 0;
float ch1Current = 0;
float ch2Current = 0;
extern int data1;
extern int data0;
void setup() {
  receiver_init();
  initDisplayGFX();
}

void loop() {

  //non isolated channel
  if (readData(Ch1rxPinSel, 0)) {
    data1 = data1 & 0x3ff;
    data0 = data0 & 0x3ff;
    ch1Voltage = (((1.100000 * data1) / 1023) * Ch1VoltageRatio);
    ch1Current = ((1.100000 * data0) / (1023 * Resistance));
    updateDisplay();
  }
  //updateDebugDisplay();
  //INVERT, aka the other channel that's isolated

  if (readData(Ch2rxPinSel, 1)) {
    data1 = data1 & 0x3ff;
    data0 = data0 & 0x3ff;
    ch2Voltage = (((1.100000 * data1) / 1023) * Ch2VoltageRatio);
    ch2Current = ((1.100000 * data0) / (1023 * Resistance));
    updateDisplay();
  }
  //updateDebugDisplay();

}
