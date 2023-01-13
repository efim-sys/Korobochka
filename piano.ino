
int noteos[] = {261, 329, 392, 493};

void playPiano() {
  //nokia();
  int currentTone, lastTone = 0;
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
      currentTone = noteos[0];
      display.fillRoundRect((10 + 20) * 0 + 10, 25, 20, 30, 4, 1);

    }
    else if (!digitalRead(KEYLC)) {
      currentTone = noteos[1];
      display.fillRoundRect((10 + 20) * 1 + 10, 25, 20, 30, 4, 1);
    }
    else if (!digitalRead(KEYRC)) {
      currentTone = noteos[2];
      display.fillRoundRect((10 + 20) * 2 + 10, 25, 20, 30, 4, 1);
    }
    else if (!digitalRead(KEYRS)) {
      currentTone = noteos[3];
      display.fillRoundRect((10 + 20) * 3 + 10, 25, 20, 30, 4, 1);
    }
    else {
      currentTone = 0;


    }
    if(currentTone != lastTone){
      ledcWriteTone(0, currentTone);
      lastTone = currentTone;
    }
    display.display();
  }
}
/*/
void nokia() {
    ledcWriteTone(0, 659);
    delay(113.63625);
    ledcWriteTone(0, 587);
    delay(113.63625);
    ledcWriteTone(0, 369);
    delay(227.2725);
    ledcWriteTone(0, 415);
    delay(227.2725);
    ledcWriteTone(0, 554);
    delay(113.63625);
    ledcWriteTone(0, 493);
    delay(113.63625);
    ledcWriteTone(0, 293);
    delay(227.2725);
    ledcWriteTone(0, 329);
    delay(227.2725);
    ledcWriteTone(0, 493);
    delay(113.63625);
    ledcWriteTone(0, 440);
    delay(113.63625);
    ledcWriteTone(0, 277);
    delay(227.2725);
    ledcWriteTone(0, 329);
    delay(227.2725);
    ledcWriteTone(0, 440);
    delay(909.09);


}
*/