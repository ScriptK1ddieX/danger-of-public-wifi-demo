# 🚨 ESP32 Public WiFi Awareness Project

> **An IoT + Cybersecurity demo project** using ESP32 and DNS spoofing to showcase how unsafe public Wi-Fi networks can be.

---

## 🔍 Problem Statement

Most people connect to free public Wi-Fi without realizing the risks. This project is a practical awareness demo to show how attackers can redirect unencrypted (HTTP) traffic over public networks without needing victims to click any link.

---

## 🛠️ How It Works

### 🔹 ESP32 Device:
- Hosts a fake web page locally using an embedded HTML server.
- Tries to auto-connect to known Wi-Fi networks.
- If no known network is found, it creates its own Access Point for manual config.
- Once connected to the target Wi-Fi, it becomes a **node in the network**.

### 🔹 Linux Attacker System:
- Performs **ARP spoofing** to become man-in-the-middle.
- Uses **DNS spoofing** to redirect all HTTP traffic to the ESP32 IP.
- Victim sees a warning page (hosted by ESP32) alerting them they've been "hacked".

---

## ⚙️ Technologies Used

| Component      | Why it was chosen                              |
|----------------|------------------------------------------------|
| **ESP32**      | Lightweight, low-power IoT device ideal for simulating stealthy attackers in real-world scenarios |
| **Arduino IDE**| For flashing ESP32 code with embedded webserver |
| **Ettercap**   | For ARP + DNS spoofing on Linux                 |
| **Wireshark/Nmap** | For monitoring and scanning network activity |
| **HTML/CSS**   | For the fake "You've been hacked" landing page |

---

## 📂 Repository Structure
esp32-public-wifi-awareness/
├── ESP32_WebServer_Code/
│ └── esp32_wifi_webserver.ino
├── Linux_Setup_Guide/
│ └── dns_spoofing_steps.md
├── assets/
│ └── screenshots/
└── README.md


---

## 💡 Use Case: Awareness Demo

This project is NOT a malicious tool. It’s designed for:
- Technical orientation events
- Security awareness campaigns
- Educational demonstrations of real-world Wi-Fi threats

---

## 🔍 Demo Screenshot

This is how the spoofed webpage appears when a victim connects to the public Wi-Fi:

![ESP32 Webserver Demo](screenshots/webpage-demo.png)

---

## 🚫 Limitations

- Only works with **HTTP** traffic (not HTTPS)
- Requires attacker to be in the same network (local Wi-Fi)
- Needs manual config and a Linux system to run Ettercap

---

## 🔐 Ethical Disclaimer

> This project is created **purely for educational and awareness purposes**.  
> Do **NOT** use this technique on public networks or without consent.

---

## 🙋 About Me

👋 I'm **Anish Sharma**, a B.Tech CSE student passionate about cybersecurity, networks, and creative tech.  
This is a solo-built project integrating IoT with cybersec — blending hardware and real-world ethical hacking simulation.

🔗 [Connect with me on LinkedIn](https://www.linkedin.com/in/anish-sharma-547b72256)



