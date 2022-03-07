const unsigned char *catbread[2] PROGMEM = {bread, cat};

bool flipTable[4][2];
int flipSteps = 0;

byte px = 0;
bool py = 0;

void playFlip() {
  display.clearDisplay();
  display.setTextSize(1);
  for (byte x = 0; x < 4; x++) {
    flipTable[x][0] = random(0, 2);
    flipTable[x][1] = random(0, 2);
  }
  drawFlipTable();
  display.display();
  while (1) {
    while (digitalRead(KEYLS) and digitalRead(KEYLC) and digitalRead(KEYRS));
    if (!digitalRead(KEYLS)) {
      px = (px + 1) % 4;
      drawFlipTable();
      display.display();
      delay(500);
    }
    if (!digitalRead(KEYLC)) {
      py = !py;
      drawFlipTable();
      display.display();
      delay(500);
    }
    if (!digitalRead(KEYRS)) {

      for (byte x = 0; x < 4; x++){
        flipTable[x][py] = !flipTable[x][py];
      }
      flipTable[px][!py] = !flipTable[px][!py];
      flipSteps++;
      drawFlipTable();
      display.display();
      delay(500);

    }

  }
}


void drawFlipTable() {
  display.clearDisplay();
  for (byte x = 0; x < 4; x++) {
    display.drawBitmap(x * 32, 0, catbread[flipTable[x][0]], 25, 25, 1);
    display.drawBitmap(x * 32, 32, catbread[flipTable[x][1]], 25, 25, 1);
  }
  display.drawRect(px * 32, py * 32, 32, 32, 1);
  display.setCursor(0, 0);
  display.print(flipSteps);
}
