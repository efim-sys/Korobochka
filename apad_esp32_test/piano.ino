/*
int noteos[] = {261, 329, 392, 493};

void playPiano() {
  for(byte i = 0; i<4; i++){
    noteos[i]=readInt(i*2+4);
  }
  message("Import!", 400);
  display.clearDisplay();
  display.setTextSize(2);
  while (1) {
    display.clearDisplay();
    display.setCursor(20, 4);
    display.print(utf8rus("Пианино"));
    for (byte i = 0; i < 4; i++) {
      display.drawRoundRect((10 + 20)*i + 10, 25, 20, 30, 4, 1);
    }
    if (!digitalRead(KEYLS)) {
      tone(TONEPIN, noteos[0]);
      display.fillRoundRect((10 + 20) * 0 + 10, 25, 20, 30, 4, 1);

    }
    else if (!digitalRead(KEYLC)) {
      tone(TONEPIN, noteos[1]);
      display.fillRoundRect((10 + 20) * 1 + 10, 25, 20, 30, 4, 1);
    }
    else if (!digitalRead(KEYRC)) {
      tone(TONEPIN, noteos[2]);
      display.fillRoundRect((10 + 20) * 2 + 10, 25, 20, 30, 4, 1);
    }
    else if (!digitalRead(KEYRS)) {
      tone(TONEPIN, noteos[3]);
      display.fillRoundRect((10 + 20) * 3 + 10, 25, 20, 30, 4, 1);
    }
    else {
      noTone(TONEPIN);


    }
    display.display();
  }
}
*/
