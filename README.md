# Line Follower

## 📌 Description

This repository contains the software implementation for an autonomous line follower robot. The system processes sensor inputs to detect path lines on a surface and continuously adjusts motor outputs to keep the robot on course.

---

## 🛠️ Tech Stack

| Category                    | Technology Used |
| :-------------------------- | :-------------- |
| 🌐 **Programming Language** | `C++`           |
| 🧩 **Framework**            | `Arduino`       |
| 📟 **Microcontroller**      | `ESP32`         |
| 👾 **IDE**                  | `Arduino IDE`   |

---

## ⚙️ Setup Instructions

1. **Prerequisites**
   - Git installed on your system.
   - Arduino IDE installed on your system.
   - CP210x or CH340 Drivers installed (if your computer doesn't recognize the ESP32 USB port).
   - ESP32 Development Board connected to your computer via a data-capable Micro-USB / USB-C cable.

2. **Configure Arduino IDE for ESP32**
   - Open **Arduino IDE**.
   - Go to **File** > **Preferences**.
   - Add the following URL to the **Additional Boards Manager URLs** field:
     ```text
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Open **Tools** > **Board** > **Boards Manager...**, search for `esp32` by **Espressif Systems**, and click **Install**.

3. **Clone the Repository**

```bash
git clone https://github.com/Fikri-Rouzan/line-follower.git
cd line-follower
```
