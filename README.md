﻿# PeriPage A6 USB Printer Library for Arduino-Compatible Boards

This library enables direct USB communication between Arduino-compatible boards and the PeriPage A6 thermal printer using a USB Host Shield. It leverages reverse-engineered command sequences to send print data without relying on BLE or proprietary applications.

---

## Hardware Requirements

- **Arduino-Compatible Board**: Such as Arduino Uno, ESP32, or others with SPI support.
- **USB Host Shield 2.0**: Based on the MAX3421E chip.
- **PeriPage A6 Thermal Printer**: Connected via USB cable.
- **Thermal Paper Rolls**: 56–58mm width, ≤30mm diameter.
- **Micro USB Cable**: For programming the microcontroller.
- **Optional**: External 5V power supply for the printer (recommended for consistent performance).

---

## Software Requirements

### Arduino Libraries

Ensure the following libraries are installed in your Arduino IDE:

1. **USB Host Shield Library 2.0**
   - Repository: [felis/USB_Host_Shield_2.0](https://github.com/felis/USB_Host_Shield_2.0)
   - Installation:
     - Open Arduino IDE.
     - Navigate to `Sketch` > `Include Library` > `Manage Libraries...`.
     - Search for "USB Host Shield Library 2.0".
     - Click "Install".

2. **USBPrinter_uhs2**
   - Repository: [gdsports/USBPrinter_uhs2](https://github.com/gdsports/USBPrinter_uhs2)
   - Installation:
     - Download the ZIP from the repository.
     - In Arduino IDE, go to `Sketch` > `Include Library` > `Add .ZIP Library...`.
     - Select the downloaded ZIP file.

---

## Hardware Connections

### Arduino Uno

- **D13**: SCK
- **D12**: MISO
- **D11**: MOSI
- **D10**: SS

### ESP32 (using VSPI)

- **GPIO23**: MOSI
- **GPIO19**: MISO
- **GPIO18**: SCK
- **GPIO5**: SS

**For ESP32 users, make sure `#include "usbhub.h"` is added to USBPrinter.h.**

Connect the PeriPage A6 printer to the USB Host Shield's USB port using a USB cable.

---

## Usage

1. **Clone or Download the Repository**

   Place the `PeriPagePrinter.h` file in your Arduino project's directory.

2. **Upload the Sketch**

   Use the provided `helloPrint.ino` sketch or your custom sketch that includes `PeriPagePrinter.h`.

3. **Power the Setup**

   Connect your microcontroller to your computer via USB. If the printer requires more power, use an external 5V power supply.

4. **Monitor Serial Output**

   Open the Serial Monitor in Arduino IDE at 115200 baud to view status messages.

5. **Printing**

   Once the setup is complete and the printer is ready, the sketch will send a message to the printer.

---

## Troubleshooting

- **No Output on Printer**:
  - Ensure the printer is powered on and properly connected.
  - Verify that the USB Host Shield is functioning and recognized by the microcontroller.

- **Compilation Errors**:
  - Confirm that all required libraries are correctly installed.
  - Ensure that `PeriPagePrinter.h` is placed in the correct directory.
  - For ESP32 users, make sure `#include "usbhub.h"` is added to USBPrinter.h.

- **Power Issues**:
  - The printer may require more power than the microcontroller can provide via USB. Consider using an external 5V power supply.

---

## If the library was useful to you
[![](https://img.shields.io/static/v1?label=Sponsor&message=%E2%9D%A4&logo=GitHub&color=%23fe8e86)](https://github.com/sponsors/userHarpreet)

---

## References

- USB Host Shield Library 2.0: [felis/USB_Host_Shield_2.0](https://github.com/felis/USB_Host_Shield_2.0)
- USBPrinter_uhs2: [gdsports/USBPrinter_uhs2](https://github.com/gdsports/USBPrinter_uhs2)
- PeriPage A6 Reverse Engineering: [bitrate16/peripage-python](https://github.com/bitrate16/peripage-python)

---

Feel free to customize and expand upon this project to suit your specific needs, such as adding image printing capabilities or integrating with other peripherals.
