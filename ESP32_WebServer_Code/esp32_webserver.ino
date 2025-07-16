#include <WiFiManager.h>  // WiFiManager library
#include <WebServer.h>    // ESP32 Web Server library

// Create web server object on port 80
WebServer server(80);

// HTML content with basic styling
String html = R"rawliteral(
  <!DOCTYPE html>
<html>
<head>
  <title>Hacker Pandit Hijack</title>
  <style>
    body {
      background-color: #000;
      color: #FF0000;
      font-family: 'Courier New', Courier, monospace;
      text-align: center;
      padding: 50px;
      margin: 0;
      overflow: hidden;
    }
    h1 {
      font-size: 60px;
      text-shadow: 0 0 10px #FF0000, 0 0 20px #FF0000, 0 0 30px #FF0000, 0 0 40px #FF0000, 0 0 50px #FF0000, 0 0 60px #FF0000;
      animation: pulse 1.5s infinite;
    }
    p {
      font-size: 24px;
      margin: 20px 0;
      color: #FF0000;
    }
    a {
      color: #00FF00;
      text-decoration: none;
      font-weight: bold;
      font-size: 22px;
      border: 2px solid #00FF00;
      padding: 10px 20px;
      border-radius: 5px;
      transition: background 0.3s, color 0.3s;
    }
    a:hover {
      background: #00FF00;
      color: #000;
    }
    @keyframes pulse {
      0% { text-shadow: 0 0 10px #FF0000, 0 0 20px #FF0000, 0 0 30px #FF0000, 0 0 40px #FF0000, 0 0 50px #FF0000; }
      50% { text-shadow: 0 0 20px #FF0000, 0 0 30px #FF0000, 0 0 40px #FF0000, 0 0 50px #FF0000, 0 0 60px #FF0000; }
      100% { text-shadow: 0 0 10px #FF0000, 0 0 20px #FF0000, 0 0 30px #FF0000, 0 0 40px #FF0000, 0 0 50px #FF0000; }
    }
    @keyframes shake {
      0% { transform: rotate(-1deg); }
      50% { transform: rotate(1deg); }
      100% { transform: rotate(-1deg); }
    }
    .warning {
      font-size: 24px;
      color: #FF0000;
      border: 3px dashed #FF0000;
      padding: 20px;
      border-radius: 10px;
      background-color: rgba(0, 0, 0, 0.8);
      animation: shake 0.5s infinite;
      margin: 20px auto; /* Center the warning box and add space around it */
      max-width: 80%;
    }
  </style>
</head>
<body>
  <h1>You have been hacked!!<br> Now you can't search anything without my permission.</h1>
  <p class="warning">WARNING: This is a security breach!</p>
  <p>Your gave your device access to <strong>Anish Sharma</strong> in sake of free wifi!</p>
  <p>Be cautious next time and currently to get rid of this, connect with me on linkedin :</p>
  <a href="https://www.linkedin.com/in/anish-sharma-547b72256?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app">Connect with Anish Sharma</a>
</body>
</html>

)rawliteral";

// Function to handle the root URL "/"
void handleRoot() {
  server.send(200, "text/html", html);  // Send the HTML content
}

void setup() {
  Serial.println("ESP started..");
  Serial.begin(9600);

  // Create WiFiManager instance
  WiFiManager wifiManager;

  // Uncomment the next line to reset previously saved credentials
  // wifiManager.resetSettings();

  // Try to connect to saved Wi-Fi or open configuration portal if no credentials are saved
  if (!wifiManager.autoConnect("ESP32", "gogo1234")) {
    Serial.println("Failed to connect and hit timeout");
   // Check if it is creating an AP
        wifiManager.startConfigPortal("ESP32", "unsafe");
        Serial.println("Access Point created. Connect to it using your device."); 
  }

  Serial.println("Connected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the web server
  server.on("/", handleRoot);  // Handle requests to the root URL
  server.begin();  // Start the server
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();  // Keep the web server running
}
