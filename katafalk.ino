/*
void playKatafalk() {
  
  display.clearDisplay();
  display.setCursor(5, 5);
  display.setTextSize(1);
  display.print("Connecting...");
  display.drawBitmap(24, 20, WiFi_logo, 58, 40, 1);
  display.display();
  WiFi.mode(WIFI_STA);
  WiFi.begin("Bioris", "ftotheded");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  long int sendTimer = millis();
  display.clearDisplay();
  display.setCursor(5, 5);
  display.setTextSize(1);
  display.print("Connected!");
  display.drawBitmap(24, 20, WiFi_logo, 58, 40, 1);
  display.display();
  WiFi.mode(WIFI_STA);
  WiFi.begin("Bioris", "ftotheded");
  int joyX = 0;
  int joyY = 0;
  //bool lock = false;
  while(1){
    if(!digitalRead(9)){
      HTTPClient http;
      http.begin("http://192.168.4.1/music");
      http.GET();
      delay(300);
    }
    joyX = (-255 * !digitalRead(KEYLS)) + (255 * !digitalRead(KEYRS));
    joyY = (-255 * !digitalRead(KEYLC)) + (255 * !digitalRead(KEYRC));
    if(sendTimer < (millis() - 50)){
      sendData(joyX, joyY);
      sendTimer = millis();
    }
  }
  
}

void sendData(int x, int y){
    HTTPClient http;
    String serverPath = String("http://192.168.4.1/getData") + String("?x=") + String(x) + String("&y=") + String(y);
    http.begin(serverPath.c_str());
    http.GET();
}
*/