# SSD1306 OLED Driver for STM32F446RE

Bare-metal SSD1306 OLED driver for the STM32F446RE using SPI communication, developed from scratch.


---

## Features

- Bare-metal STM32F446RE implementation
- SSD1306 OLED (128×64) support
- SPI communication
- Polling-based SPI transfers
- DMA-based SPI transfers
- OLED initialization sequence
- Command/Data transmission support
- Framebuffer implementation
- Pixel-level drawing
- Character rendering
- String rendering
- Full display refresh

---

## Hardware Used

- STM32F446RE Nucleo Board
- SSD1306 OLED Display (128×64)
- Jumper Wires

---

## Pin Connections

| OLED Pin | STM32F446RE Pin |
|-----------|----------------|
| VCC | 3.3V |
| GND | GND |
| SCK | PA5 |
| MOSI | PA7 |
| CS | PA4 |
| DC | PA8 |
| RESET | PA9 |

> The display is configured in SPI mode.

---

## Project Structure

```text
SSD1306-OLED-driver-for-STM32F446RE/
│
├── Core/
│   ├── Inc/
│   │   ├── SPI.h
│   │   ├── Image.h
│   │   ├── Display.h
│   │   ├── OLED.h
│   │   └── fonts.h
│   │
│   └── Src/
│       ├── SPI.c
│       ├── Image.c
│       ├── Display.c
│       ├── OLED.c
│       ├── fonts.c
│       └── main.c
│
└── README.md
```

---

## Driver Architecture

### SPI Driver

The SPI peripheral is configured entirely through STM32 registers.

Implemented functionality:

- GPIO configuration for SPI pins
- SPI peripheral initialization
- Data transmission

---

### DMA Integration

The display framebuffer can be transferred to the OLED using DMA instead of CPU-driven polling.

Benefits include:

- Reduced CPU utilization
- Faster display refreshes
- Improved application responsiveness
- Better scalability for graphics applications

---

## Development Environment

- STM32F446RE
- STM32CubeIDE
- ARM GCC Toolchain
- Bare-Metal C


## Author

**Mudit Goyal**

Embedded Systems Enthusiast
