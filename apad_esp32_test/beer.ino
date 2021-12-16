const unsigned char p1 [] PROGMEM = { 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x78, 0x00, 0x00, 0x78, 0x06, 0x00, 0x2c, 0x04, 0x00, 0x3c,
                                      0x0c, 0x80, 0x14, 0x3c, 0x00, 0x0c, 0x39, 0x00, 0x0c, 0x50, 0x80, 0x0f, 0xe0, 0x00, 0x18, 0x31,
                                      0x00, 0x12, 0x89, 0xc0, 0x32, 0x8b, 0xe0, 0x39, 0x0a, 0x60, 0x3c, 0x12, 0x60, 0x3f, 0xe2, 0x20,
                                      0x30, 0x22, 0xa0, 0x20, 0x32, 0x20, 0x60, 0x1b, 0xc0, 0x00, 0x00, 0x00
                                    };
const unsigned char p2 [] PROGMEM = { 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x78, 0x00, 0x00, 0x78, 0x0c, 0x00, 0x2c, 0x1e, 0x00, 0x3c,
                                      0x1a, 0x00, 0x14, 0x30, 0x80, 0x0c, 0x30, 0x80, 0x0c, 0x60, 0x00, 0x0f, 0xe1, 0x00, 0x18, 0x30,
                                      0x00, 0x12, 0x89, 0xc0, 0x32, 0x8b, 0xe0, 0x39, 0x0a, 0x60, 0x3c, 0x12, 0x60, 0x3f, 0xe2, 0x20,
                                      0x30, 0x22, 0xa0, 0x20, 0x32, 0x20, 0x60, 0x1b, 0xc0, 0x00, 0x00, 0x00
                                    };
const unsigned char p3 [] PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x68, 0x00, 0x00, 0x3c,
                                      0x07, 0x00, 0x1c, 0x06, 0x00, 0x08, 0x1c, 0x40, 0x0c, 0x7f, 0x00, 0x1c, 0xf0, 0x40, 0x1f, 0xf0,
                                      0x80, 0x10, 0x09, 0xc0, 0x31, 0x2b, 0xe0, 0x38, 0x4a, 0x60, 0x3c, 0x12, 0x60, 0x3f, 0xe2, 0x20,
                                      0x30, 0x22, 0xa0, 0x20, 0x32, 0x20, 0x60, 0x1b, 0xc0, 0x00, 0x00, 0x00
                                    };

const unsigned char *pivovarki [] PROGMEM = {p1, p2, p3};

long int pivoTimers[] = {0, 0, 0, 0, 0, 0, 0, 0};

byte pivoSpeed[8] = {128, 128, 128, 128, 128, 128, 128, 128};

byte rowSpeed[2] = {128, 128};

byte pivoState[8] = {0, 0, 0, 0, 0, 0, 0, 0};

int money = 0;

const char *save_menu[] = {"Сохранение 1", "Сохранение 2", "Сохранение 3", "Новая игра"};

byte save;

void playBeer() {
  save = korobkaMenu(4, save_menu);
  if (save == 3) {
    save = korobkaMenu(3, save_menu);
    for (byte i = 0; i < 14; i++) {
      EEPROM.write(12 + i + save * 14, 128);
    }
    EEPROM.write(20 + save * 14, 128);
    EEPROM.write(21 + save * 14, 128);
    writeInt(22 + save * 14, 0);
    writeInt(24 + save * 14, 0);
    EEPROM.commit();
  }
  for (byte i = 0; i < 8; i++) {
    pivoSpeed[i] = EEPROM.read(i + save * 14 + 12);
  }
  rowSpeed[0] = EEPROM.read(20 + save * 14);
  rowSpeed[1] = EEPROM.read(21 + save * 14);
  money = readInt(22 + save * 14) * 65536 + readInt(24 + save * 14);
  message("Memory import OK!", 400);
  delay(300);
  display.clearDisplay();
  while (1) {
    drawPivo();
    drawPivoGUI();
    //display.drawRect(0, 0, 128, 64, 1);
    display.display();
    if (!digitalRead(KEYLS)) {
      delay(200);
      upgMenu();
    }
    if (!digitalRead(KEYLC)) {
      savePivo();
      while (!digitalRead(KEYRC));
      delay(200);
    }
  }

}

void drawPivo() {
  display.clearDisplay();
  for (byte i = 0; i < 8; i++) {
    if (pivoTimers[i] < millis()) {
      pivoState[i] = random(0, 3);
      pivoTimers[i] = millis() + (pivoSpeed[i] * 10) * rowSpeed[i / 4] / 128;
      money += 1;
    }
    display.drawBitmap(3 * (i % 4) + (20 * (i % 4) ), 8 * (i / 4) + 20 * (i / 4), pivovarki[pivoState[i]], 20, 20, 1);
    display.setCursor(3 + 3 * (i % 4) + (20 * (i % 4) ), 8 * (i / 4) + 20 * (i / 4) + 20);
    display.print("X");
    display.print((128 / pivoSpeed[i]) * (128 / rowSpeed[i / 4]));
  }
}

void drawPivoGUI() {
  display.setCursor(0, 56);
  display.setTextSize(1);
  display.print(money);
  display.print("$");
  display.setCursor(92, 9);
  display.print("X");
  display.print(128 / rowSpeed[0]);
  display.setCursor(92, 36);
  display.print("X");
  display.print(128 / rowSpeed[1]);
}

const char *type_menu[] = {"Улучшить пивоварки", "Улучшить ряды"};
const char *pivo_menu[] = {"Пивоварка 1", "Пивоварка 2", "Пивоварка 3", "Пивоварка 4", "Пивоварка 5", "Пивоварка 6", "Пивоварка 7", "Пивоварка 8"};
const char *row_menu[] = {"Ряд 1", "Ряд 2"};

void upgMenu() {
  if (!korobkaMenu(2, type_menu)) {
    byte place = korobkaMenu(8, pivo_menu);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println(utf8rus("Кузыл Банк"));
    display.setTextSize(1);
    display.println(utf8rus("Хотите улучшить"));
    display.print(utf8rus("Пивоварку "));
    display.println(place + 1);
    display.print(utf8rus("За "));
    display.print((512 / pivoSpeed[place]) * (512 / pivoSpeed[place]) * 10);
    display.println("$???");
    display.setCursor(0, 56);
    display.print(utf8rus("Да"));
    display.setCursor(108, 56);
    display.print(utf8rus("Нет"));
    display.display();
    bool yes = 1;
    bool no = 1;
    while (yes and no) {
      yes = digitalRead(KEYLC);
      no = digitalRead(KEYRC);
    }
    if (!yes and money >= (512 / pivoSpeed[place]) * (512 / pivoSpeed[place]) * 10) {
      message("Куплено!", 400);
      money -= (512 / pivoSpeed[place]) * (512 / pivoSpeed[place]) * 10;
      pivoSpeed[place] /= 2;
    }
    else {
      message("Отмена", 400);
    }
  }
  else {
    byte place = korobkaMenu(2, row_menu);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.println(utf8rus("Кузыл Банк"));
    display.setTextSize(1);
    display.println(utf8rus("Хотите улучшить"));
    display.print(utf8rus("Ряд "));
    display.println(place + 1);
    display.print(utf8rus("За "));
    display.print((512 / rowSpeed[place]) * (512 / rowSpeed[place]) * 50);
    display.println("$???");
    display.setCursor(0, 56);
    display.print(utf8rus("Да"));
    display.setCursor(108, 56);
    display.print(utf8rus("Нет"));
    display.display();
    bool yes = 1;
    bool no = 1;
    while (yes and no) {
      yes = digitalRead(KEYLC);
      no = digitalRead(KEYRC);
    }
    if (!yes and money >= (512 / rowSpeed[place]) * (512 / rowSpeed[place]) * 50) {
      message("Куплено!", 400);
      money -= (512 / rowSpeed[place]) * (512 / rowSpeed[place]) * 50;
      rowSpeed[place] /= 2;
    }
    else {
      message("Отмена", 400);
    }
  }
}

void savePivo() {
  for (byte i = 0; i < 8; i++) {
    EEPROM.write(i + 12  + save * 14, pivoSpeed[i]);
  }
  EEPROM.write(20 + save * 14, rowSpeed[0]);
  EEPROM.write(21 + save * 14, rowSpeed[1]);
  writeInt(22 + save * 14, money / 65536);
  writeInt(24 + save * 14, money % 65536);
  EEPROM.commit();
  message("Сохранено!", 400);
}
