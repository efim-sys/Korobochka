int del;


void drawCats() {
  display.clearDisplay();
  for (int i = 0; i < 4; i++) {
    if (table[i] == 1) {
      display.drawBitmap(i * 30 + 6, 15, cat, 25, 25, 1);
    }
    if (table[i] == 0) {
      display.drawBitmap(i * 30 + 6, 15, bread, 25, 25, 1);
    }
  }
  display.display();
}

void buttonsCats() {
  int btn0 = !BTN;
  int btn1 = !BTN;
  int btn2 = !BTN;
  int btn3 = !BTN;
  while (table[0] == 1 or table[1] == 1 or table[2] == 1 or table[3] == 1) {
    btn0 = !BTN;
    btn1 = !BTN;
    btn2 = !BTN;
    btn3 = !BTN;
    check();
    display.setCursor(5, 50);
    display.drawRect(12, 48, 104, 14, 1);
    display.fillRect(14, 50, (millis() - timer) / 100, 10, 1);
    display.display();
    btn0 = digitalRead(KEYLS);
    btn1 = digitalRead(KEYLC);
    btn2 = digitalRead(KEYRC);
    btn3 = digitalRead(KEYRS);
    if (btn0 == BTN) {
      if (table[0] == 1 or table[0] == 2) {
        if (table[0] == 1) {
          count += catsCountK;
          display.setCursor((0 * 25) + 20, 15);
          display.print(F("10"));
          display.display();
          timer += hard;
          table[0] = 2;

        }
      }
      else {
        dead = 1;
        winCats();
      }

      drawCats();
    }

    if (btn1 == BTN) {
      if (table[1] == 1 or table[1] == 2) {
        if (table[1] == 1) {
          count += catsCountK;
          display.setCursor((1 * 25) + 20, 15);
          display.print(F("10"));
          display.display();
          timer += hard;
          table[1] = 2;

        }

      }
      else {
        dead = 0;
        winCats();
      }

      drawCats();
    }

    if (btn2 == BTN) {
      if (table[2] == 1 or table[2] == 2) {
        if (table[2] == 1) {
          count += catsCountK;
          display.setCursor((2 * 25) + 20, 15);
          display.print(F("10"));
          display.display();
          timer += hard;
          table[2] = 2;

        }
      }
      else {
        dead = 0;
        winCats();
      }

      drawCats();
    }

    if (btn3 == BTN) {
      if (table[3] == 1 or table[3] == 2) {
        if (table[3] == 1) {
          count += catsCountK;
          display.setCursor((3 * 25) + 20, 15);
          display.print(F("10"));
          display.display();
          timer += hard;
          table[3] = 2;

        }
      }
      else {
        dead = 0;
        winCats();
      }

      drawCats();
    }

  }
  delay(del);

}

void check() {
  if ((millis() - timer) > 1000000) {
    timer = millis();
  }
  if ((millis() - timer) > 10000) {
    dead = 1;
    winCats();
  }
  if ((millis() - kIncreaseTimer) > 20000) {
    catsCountK *= 2;
    kIncreaseTimer = millis();
  }
  if ((millis() - hardFallTimer) > 10000) {
    hard -= hardFall;
    hardFallTimer = millis();
  }
}

int getHiScoreCats(){
  return EEPROM.read(0)*256+EEPROM.read(1);
}

void winCats() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(15, 10);
  display.print(utf8rus("Умирай!"));
  display.setCursor(12, 30);
  display.setTextSize(1);
  display.print(utf8rus("считать коты: "));
  display.print(count);
  display.setCursor(8, 40);
  if (getHiScoreCats() < count){
    display.print(utf8rus("Высокий счетчик!")); 
    EEPROM.write(0, count/256);
    EEPROM.write(1, count%256);
    EEPROM.end();
  }
  else{
    display.print(utf8rus("Высокий счетчик:"));
    display.print(getHiScoreCats());
  }
    display.setCursor(20, 52);
  if (dead == 0) {
    display.print(utf8rus("Вы съели хлеб"));
  }
  if (dead == 1) {
    display.print(utf8rus("Работай быстрее!"));
  }
  display.drawRect(0, 0, 128, 64, 1);
  display.display();
  
  wait();
}

void mapMenu() {
  int btn0 = !BTN;
  int btn2 = !BTN;
  int btn3 = !BTN;
  int mapnum = 0;
  int enter = 0;
  while (enter == 0) {
    display.clearDisplay();
    display.setCursor(5, 5);
    display.setTextSize(2);
    display.print(utf8rus(" Фракция?"));
    display.setTextSize(1);
    display.setCursor(0, 25);
    switch (mapnum) {
      case 0:
        display.println(utf8rus(" >пекарин"));
        display.println(utf8rus("  шаурмен"));
        display.println(utf8rus("  работник фабрики"));
        display.println(utf8rus("  китайский чернораб."));
        break;
      case 1:
        display.println(utf8rus("  пекарин"));
        display.println(utf8rus(" >шаурмен"));
        display.println(utf8rus("  работник фабрики"));
        display.println(utf8rus("  китайский чернораб."));
        break;
      case 2:
        display.println(utf8rus("  пекарин"));
        display.println(utf8rus("  шаурмен"));
        display.println(utf8rus(" >работник фабрики"));
        display.println(utf8rus("  китайский чернораб."));
        break;
      case 3:
        display.println(utf8rus("  пекарин"));
        display.println(utf8rus("  шаурмен"));
        display.println(utf8rus("  работник фабрики"));
        display.println(utf8rus(" >китайский чернораб."));
        break;
    }
    display.drawRect(0, 0, 128, 64 , 1);
    display.display();
    while (btn0 == !BTN && btn2 == !BTN && btn3 == !BTN) {
      btn0 = digitalRead(KEYLS);
      btn2 = digitalRead(KEYRC);
      btn3 = digitalRead(KEYRS);
    }
    if (btn0 == BTN) {
      mapnum--;
      if (mapnum < 0) {
        mapnum = 3;
      }
      btn0 = !BTN;
      delay(200);
    }
    else {
      if (btn2 == BTN) {
        mapnum++;
        if (mapnum > 3) {
          mapnum = 0;
        }
        btn2 = !BTN;
        delay(200);
      }
      else {
        if (btn3 == BTN) {
          enter = 1;
          btn3 = !BTN;
          delay(200);
        }
      }
    }

  }
  btn0 = !BTN;
  btn2 = !BTN;
  btn3 = !BTN;
  delay(300);
  if (enter == 1) {
    if (mapnum == 0) {
      hard = 1000;
      catsCountK = 3;
      hardFall = 60;
    }
    if (mapnum == 1) {
      hard = 500;
      catsCountK = 5;
      hardFall = 40;
    }
    if (mapnum == 2) {
      hard = 350;
      catsCountK = 10;
      hardFall = 25;
    }
    if (mapnum == 3) {
      hard = 100;
      catsCountK = 25;
      hardFall = 15;
    }
  }


}


void playCats() {
  del = readInt(2);
  display.setTextSize(2);
  display.drawRect(0, 0, 128, 64, 1);
  display.setCursor(40, 8);
  display.print(utf8rus("Кошка 2"));
  display.setCursor(3, 30);
  display.print(utf8rus(" Или хлеб?"));
  display.setTextSize(1);
  display.setCursor(4, 49);
  display.print(utf8rus("Заходить нажимая"));
  display.display();
  int sht;
  sht = !BTN;
  while (sht == !BTN) {
    sht = digitalRead(KEYRS);
  }
  delay(300);
  mapMenu();
  delay(1000);
  timer = millis();
  kIncreaseTimer = millis();
  while (1) {
    for (int i = 0; i < 4; i++) {
      table[i] = random(0, 2);
    }
    if (table[0] == 0 && table[1] == 0 && table[2] == 0 && table[3] == 0) {
      table[random(0, 4)] = 1;
    }

    drawCats();
    buttonsCats();
  }
}
