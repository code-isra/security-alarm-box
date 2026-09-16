# security-alarm-box
An Arduino-based security box that alerts users when an enclosure is tampered with or opened.
---
---

## Components Required

* 1x Arduino Uno (or compatible microcontroller)
* 1x HC-SR04 Ultrasonic Distance Sensor
* 1x 5v Passive Buzzer
* 1x LED (Red)
* 1x 220Ω Resistor (for LED)
* Breadboard & Jumper Wires
* 1x Box

---

## Technical Overview & Features

* **Proximity Detection:** Uses the HC-SR04 sensor to calculate real-time distance using ultrasonic pulse reflections.
* **Dual-Tone Siren:** Generates an alternating siren audio alert (1000 Hz and 1500 Hz) via the `tone()` function upon trigger.
* **Intrusion Trigger Zone:** Activates both the red visual LED and siren alarm when an object is detected within 1 cm to 20 cm (`distance > 0 && distance <= 20`).
* **Serial Telemetry:** Streams live distance measurements in centimeters to the Serial Monitor at 9600 baud.

---

## Pin Mapping

| Arduino Pin | Connection | Function / Description |
| :--- | :--- | :--- |
| **Pin 6** | `TRIG` (HC-SR04) | Trigger: Sends ultrasonic pulse |
| **Pin 7** | `ECHO` (HC-SR04) | Echo: Measures return pulse duration |
| **Pin 9** | `BUZZER` (+) | Audio alarm output |
| **Pin 10** | `LED` (+) | Visual alert output (Red LED) |
| **GND** | `GND` | Common Ground |
| **5V** | `VCC` | 5V Power Supply for Sensor |

---

## Setup and Running

1. Upload `src/main.ino` to your board using the Arduino IDE.
2. Wire the hardware according to the Pin Mapping table above.
3. Open the Serial Monitor at **9600 baud** to monitor distance output.
4. Test by bringing an object within 20 cm of the sensor to trigger the alarm.
