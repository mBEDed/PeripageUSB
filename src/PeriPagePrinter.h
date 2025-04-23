#ifndef PERIPAGE_USB_PRINTER_H
#define PERIPAGE_USB_PRINTER_H

#include <Usb.h>
#include <USBPrinter.h>
#include <usbhub.h>
#include <string.h>  // for strlen()

// Callback to capture the Bulk‑OUT endpoint address
class PeriPageOper : public USBPrinterAsyncOper {
public:
  uint8_t dataEndpoint = 0;
  uint8_t OnInit(USBPrinter *pPrinter) override {
    // Directly use the public epInfo[] and static epDataOutIndex
    dataEndpoint = pPrinter->epInfo[ USBPrinter::epDataOutIndex ].epAddr;
    Serial.print(F("PeriPage data EP: 0x"));
    Serial.println(dataEndpoint, HEX);
    return 0;
  }
};

class PeriPagePrinter {
public:
  USBPrinter   *prt;
  PeriPageOper  oper;
  uint8_t       ep;

  PeriPagePrinter(USB *usb) {
    prt = new USBPrinter(usb, &oper);
  }

  // Call after Usb.Task() shows the printer is ready
  bool begin() {
    if (!prt->isReady()) return false;
    ep = oper.dataEndpoint;
    reset();
    return true;
  }

  // Send the Python‑reverse‑engineered reset command
  void reset() {
    const uint8_t cmd[] = {0x10, 0xFF, 0x50, 0xF1};
    writeCmd(cmd, sizeof(cmd));
    delay(50);
  }

  

  // Print ASCII text (prefix + raw bytes)
  void printASCII(const char *str) {
    const uint8_t init[] = {0x10, 0xFF, 0xFE, 0x01};
    writeCmd(init, sizeof(init));
    writeCmd((const uint8_t*)str, strlen(str));
  }

private:
  // Split transfers into ≤64‑byte chunks
  void writeCmd(const uint8_t *buf, uint16_t len) {
    uint16_t sent = 0;
    while (sent < len) {
      // Use ternary instead of std::min<>
      uint16_t chunk = (len - sent > 64 ? 64 : len - sent);
      prt->write(buf + sent, chunk);
      sent += chunk;
    }
  }
};

#endif // PERIPAGE_USB_PRINTER_H
