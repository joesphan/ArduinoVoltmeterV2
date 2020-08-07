#define delaytime (1000000 / baudrate)    //delay with cpu cycle compensation
#define startBitDelayTime ((250000 / baudrate) + 1)   //slight clock skew


void transmitter_init() {
  txDDR = txDDR | B00000001;          //PB0 on the attiny13
  fastWrite(LOW);
}

void transmitBuffered(int data1, int data0) {
  bool dataout[32];
  //load the buffer
  //B1
  for (int i = 15; i > -1; i--) {
    dataout[i + 16] = bitRead(data1, i);
  }
  //B0
  for (int i = 15; i > -1; i--) {
    dataout[i] = bitRead(data0, i);
  }
  //start bit
  startBit();
  for (int i = 31; i >= 0 ; i--) {
    fastWrite(dataout[i]);
    delayMicroseconds(delaytime);
  }
  fastWrite(LOW);
  delayMicroseconds(delaytime);
}

void transmitUnBuffered(int data1, int data0) {
  //start bit
  startBit();
  //B1
  for (int i = 15; i > -1; i--) {
    fastWrite(bitRead(data1, i));
    delayMicroseconds(delaytime);
  }
  //B0
  for (int i = 15; i > -1; i--) {
    fastWrite(bitRead(data0, i));
    delayMicroseconds(delaytime);
  }
  fastWrite(LOW);
  delayMicroseconds(delaytime);
}
void startBit() {
  fastWrite(HIGH);
  delayMicroseconds(startBitDelayTime);
  fastWrite(LOW);
  delayMicroseconds(startBitDelayTime);
  fastWrite(HIGH);
  delayMicroseconds(startBitDelayTime);
  fastWrite(LOW);
  delayMicroseconds(startBitDelayTime);
}
void fastWrite(int level) {
  switch (level) {
    case HIGH:
      txPort = txPort | txHIGH;
      break;
    case LOW:
      txPort = txPort & txLOW;
      break;
  }
}
