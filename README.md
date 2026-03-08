# ESP32 SOS Blinker  
## Functional Specification Document (FSD)

---

## 1. Document Information

| Field | Value |
|-------|--------|
| Version | 1.0 |
| Status | Draft |
| Framework | Arduino (PlatformIO) |
| Target MCU | ESP32-C3 |

---

## 2. Purpose

This document defines the functional requirements for an ESP32-based system that transmits the Morse code signal **"SOS"** using the onboard LED.

The firmware is implemented in C++ using the Arduino framework.

---

## 3. Scope

The system shall:

- Blink onboard LED in Morse code pattern `... --- ...`
- Repeat continuously
- Use deterministic timing
- Operate standalone without network connectivity

---

## 4. System Overview

```mermaid
flowchart LR
    Power_Supply --> ESP32_MCU
    ESP32_MCU --> Onboard_LED
    Onboard_LED --> Observer
```

---

## 5. Hardware Spesification


| Component                  | Identifier | Description  |
|:-------------------------|:----------------------:|:-----------------------:|
| ESP32 MCU             | MCU1       | Main controller                     |
| Onboard LED           | LED_IND             | Status Indicator        |

---

## 6. Functional Requirement

- **FR-01**: System shall configure GPIO for LED output during boot.
- **FR-02**: System shall transmit Morse code pattern SOS continuously.

---

## 7. Non-Functional Requirement

- **NFR-01**: System shall run continuously.
- **NFR-02**: CPU usage shall be under 5%.
- **NFR-03**: System shall not have memory leaks
- **NFR-04**: Timing accuracy must be ±5%

---

## 8. Acceptance Criteria

- **AC-01**: LED pattern matches ... --- ...
- **AC-02**: Timing verified with oscilloscope
- **AC-03**: System runs > 1 hour without failure

---

## 9. Future Enhancement

* Add buzzer output
* Add configurable Morse message
* Add WiFi configuration
* Add OTA firmware update
* Convert to FreeRTOS task-based implementation
