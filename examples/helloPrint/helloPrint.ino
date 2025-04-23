#include <SPI.h>
#include "PeriPagePrinter.h"

USB        Usb;               // USB Host core
USBHub     Hub(&Usb);         // If your shield has a hub
PeriPagePrinter peri(&Usb);   // Our PeriPage wrapper

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(1);

  if (Usb.Init() == -1) {
    Serial.println(F("ERROR: USB Host init failed"));
    while (1) delay(1);
  }
  Serial.println(F("USB Host Shield Initialized"));
}

void loop() {
  Usb.Task();  // Poll USB bus

  // When printer enumerates and isReady():
  if (peri.begin()) {
    Serial.println(F("PeriPage A6 Ready → Printing"));
    peri.printASCII("Hello, PeriPage A6!\n");
    while (1) delay(1);
  }
}
