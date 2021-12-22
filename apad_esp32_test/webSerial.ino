void recvMsg(uint8_t *data, size_t len) {
  String d = "";
  for (int i = 0; i < len; i++) {
    d += char(data[i]);
  }
  WebSerial.println(d);
  if (d.startsWith("help")) {
    WebSerial.println("help - show this article");
    WebSerial.println("info - show info about this Korobochka");
    WebSerial.println("netmode [ap][client] - choose type of wifi connection to korobochka");
    WebSerial.println("savemem - saves EEPROM");
    WebSerial.println("reboot - reboots korobochka with saved parameters");
    WebSerial.println("autoreboot [0][1]- reboots korobochka with saved parameters");
  }
  if (d.startsWith("info")) {
    WebSerial.print("Korobka OS version: "); WebSerial.println(VERSION);
    WebSerial.print("Chip revision: "); WebSerial.println(ESP.getChipRevision());
    WebSerial.print("CPU frequency, MHz: "); WebSerial.println(ESP.getCpuFreqMHz());
    WebSerial.print("WiFi mode (0 - client, 1 - AP): "); WebSerial.println(EEPROM.read(64));
    WebSerial.print("Autoreboot (0 - enabled, 1 - disabled): "); WebSerial.println(EEPROM.read(65));
    WebSerial.print("WiFi ssid: "); WebSerial.println(ssid);
    WebSerial.print("WiFi password: "); WebSerial.println(password);
    WebSerial.print("AP ssid: "); WebSerial.println(APssid);
    WebSerial.print("AP password: "); WebSerial.println(APpassword);
  }
  if (d.startsWith("netmode")) {
    if (d.substring(8) == "client") {
      EEPROM.write(64, 0);
    }
    else if (d.substring(8) == "ap") {
      EEPROM.write(64, 1);
    }
  }
  if (d.startsWith("savemem")) {
    EEPROM.commit();
  }
  if (d.startsWith("autoreboot")) {
    EEPROM.write(65, byte(d.substring(10).toInt()));
  }
  if (d.startsWith("reboot")) {
    ESP.restart();
  }
}



void  playWebSerial() {
  display.setTextSize(1);
  display.setCursor(5, 5);
  display.print(" CLI interface!");
  display.setCursor(5, 45);
  if (EEPROM.read(64) == 0) {
    display.println("Connecting to ");
    display.print(ssid);
    display.display();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
    }
    IP = WiFi.localIP();
  }
  else {
    display.println("Connect to ");
    display.print(APssid);
    display.display();
    WiFi.softAP(APssid, APpassword);
    IP = WiFi.softAPIP();
  }
  display.clearDisplay();
  display.setCursor(5, 5);
  display.print(" CLI interface!");
  display.setCursor(5, 45);
  display.print("IP: ");
  display.print(IP);
  display.display();
  WebSerial.begin(&server);
  WebSerial.msgCallback(recvMsg);
  server.begin();
  while (1) {
  }
}
