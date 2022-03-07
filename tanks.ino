

PROGMEM const byte carta0[16][8] = {
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 2},
  {0, 1, 1, 0, 0, 0, 1, 0},
  {0, 1, 0, 1, 0, 1, 1, 0},
  {0, 1, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 1, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 1, 0, 0, 1},
  {0, 1, 0, 1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0, 0, 0, 1},
  {0, 1, 0, 1, 0, 0, 0, 0},
};

PROGMEM const byte carta1[16][8] = {
  {0, 0, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 1, 0, 0, 0, 1},
  {0, 0, 1, 1, 0, 1, 0, 0},
  {1, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 1, 0, 0},
  {1, 0, 0, 1, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 1, 0, 1, 0, 0},
};

PROGMEM const byte carta2[16][8] = {
  {0, 0, 0, 1, 1, 1, 1, 0},
  {0, 0, 0, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 0, 1},
  {1, 0, 1, 1, 2, 1, 0, 1},
  {1, 0, 0, 1, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 0, 0, 1, 1, 0, 1},
  {2, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 0},
  {1, 2, 1, 1, 1, 0, 0, 0},
  {2, 1, 1, 1, 1, 1, 0, 0},
};


PROGMEM const byte carta3[16][8] = {
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 1, 1, 1, 1, 1},
  {0, 1, 1, 0, 1, 1, 0, 1},
  {0, 1, 1, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 2, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 0, 1, 0, 1, 0, 1},
  {1, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 1, 0, 1, 1, 1, 0, 1},
  {1, 1, 0, 1, 1, 0, 0, 0},
};


void playTanks() {
  display.setTextSize(2);
  display.drawRect(0, 0, 128, 64, 1);
  display.setCursor(17, 8);
  digitalWrite(2, 0);
  display.print(utf8rus("Танчики"));
  display.setTextSize(1);
  display.setCursor(45, 26);
  display.print(F("v. 1.5 "));
  display.setCursor(4, 37);
  display.print(F("(korobochka edition)"));
  display.setCursor(4, 49);
  display.print(utf8rus("Заходить нажимая"));
  display.display();
  while (shtbtn == 1) {
    shtbtn = digitalRead(15);
  }
  shtbtn = 1;
  delay(200);
  TanksMapMenu();
  while (1) {
    drawMap();
    drawBlack(gxb, gyb, grb);
    drawWhite(gxw, gyw, grw);
    fwdbtn = digitalRead(KEYLC);
    rbtnr = digitalRead(KEYRC);
    rbtnl = digitalRead(KEYLS);
    shtbtn = digitalRead(KEYRS);
    checkBlack();
    fwdbtn = 1;
    rbtnr = 1;
    rbtnl = 1;
    shtbtn = 1;
    delay(200);
    fwdbtn = digitalRead(KEYLC);
    rbtnr = digitalRead(KEYRC);
    rbtnl = digitalRead(KEYLS);
    shtbtn = digitalRead(KEYRS);
    checkWhite();
    fwdbtn = 1;
    rbtnr = 1;
    rbtnl = 1;
    shtbtn = 1;
    delay(200);
  }
}


void TanksMapMenu() {
  int mapnum = 0;
  int enter = 0;
  while (enter == 0) {
    display.clearDisplay();
    display.setCursor(5, 5);
    display.setTextSize(2);
    display.print(utf8rus("Выбрать карту"));
    display.setTextSize(1);
    display.setCursor(0, 25);
    switch (mapnum) {
      case 0:
        display.println(F("   > highway"));
        display.println(F("     forest"));
        display.println(F("     old mine"));
        display.println(F("     dead town"));
        break;
      case 1:
        display.println(F("     highway"));
        display.println(F("   > forest"));
        display.println(F("     old mine"));
        display.println(F("     dead town"));
        break;
      case 2:
        display.println(F("     highway"));
        display.println(F("     forest"));
        display.println(F("   > old mine"));
        display.println(F("     dead town"));
        break;
      case 3:
          display.println(F("     highway"));
          display.println(F("     forest"));
          display.println(F("     old mine"));
          display.println(F("   > dead town"));
          break;
        }
    display.drawRect(0, 0, 128, 64 , 1);
    display.display();
    while (rbtnl == 1 && rbtnr == 1 && shtbtn == 1) {
      rbtnr = digitalRead(KEYRC);
      rbtnl = digitalRead(KEYLS);
      shtbtn = digitalRead(KEYRS);
    }
    if (rbtnl == 0) {
      mapnum--;
      if (mapnum < 0) {
        mapnum = 3;
      }
      rbtnl = 1;
      delay(200);
    }
    else {
      if (rbtnr == 0) {
        mapnum++;
        if (mapnum > 3) {
          mapnum = 0;
        }
        rbtnr = 1;
        delay(200);
      }
      else {
        if (shtbtn == 0) {
          enter = 1;
          shtbtn = 1;
          delay(200);
        }
      }
    }

  }
  rbtnl = 1;
  rbtnr = 1;
  shtbtn = 1;
  delay(300);
  chooseMap(mapnum);
}

void chooseMap(int mnum) {
  switch (mnum) {
    case 0:
      for (int i = 0; i < 8; i++) {
        for (int g = 0; g < 16; g++) {
          carta[g][i] = pgm_read_word(&carta0[g][i]);
        }
      }
      break;
    case 1:
      for (int i = 0; i < 8; i++) {
        for (int g = 0; g < 16; g++) {
          carta[g][i] = pgm_read_word(&carta1[g][i]);;
        }
      }
      break;
    case 2:
      for (int i = 0; i < 8; i++) {
        for (int g = 0; g < 16; g++) {
          carta[g][i] = pgm_read_word(&carta2[g][i]);;
        }
      }
      break;
    case 3:
      for (int i = 0; i < 8; i++) {
        for (int g = 0; g < 16; g++) {
          carta[g][i] = pgm_read_word(&carta3[g][i]);;
        }
      }
      break;
  }
}

void drawBullet(int x, int y) {

  display.drawPixel((x * 8) + 4, (y * 8) + 4, 1);
  display.drawPixel((lastx * 8) + 4, (lasty * 8) + 4, 0);
  display.display();
  lastx = x;
  lasty = y;
  delay(50);
}

void drawMap() {
  display.clearDisplay();
  for (int x = 0; x < 17; x++) {
    for (int y = 0; y < 9; y++) {
      if (carta[x - 1][y - 1] == 1) {
        display.drawRect((x * 8) - 8, (y * 8) - 8, 8, 8, 1);
      }
      if (carta[x - 1][y - 1] == 2) {
        display.fillCircle((x * 8) - 8 + 4, (y * 8) - 8 + 4, 3, 1);
        display.drawLine((x * 8) - 8 + 4, (y * 8) - 8 + 2, (x * 8) - 8 + 4, (y * 8) - 8 + 6, 0);
        display.drawLine((x * 8) - 8 + 2, (y * 8) - 8 + 4, (x * 8) - 8 + 6, (y * 8) - 8 + 4, 0);
      }
    }
  }
  display.drawRect(0, 0, 128, 64, 1);
  display.display();
}
void drawBlack(int xb, int yb, int rb) {
  if (rb == 1) {
    display.drawTriangle((xb * 8) + 1, (yb * 8) + 7, (xb * 8) + 1, (yb * 8) + 1, (xb * 8) + 6, (yb * 8) + 4, 1);
  }
  if (rb == 2) {
    display.drawTriangle((xb * 8) + 1, (yb * 8) + 1, (xb * 8) + 7, (yb * 8) + 1, (xb * 8) + 4, (yb * 8) + 6, 1);
  }
  if (rb == 3) {
    display.drawTriangle((xb * 8) + 7, (yb * 8) + 1, (xb * 8) + 7, (yb * 8) + 7, (xb * 8) + 1, (yb * 8) + 4, 1);
  }
  if (rb == 4) {
    display.drawTriangle((xb * 8) + 1, (yb * 8) + 7, (xb * 8) + 7, (yb * 8) + 7, (xb * 8) + 4, (yb * 8) + 1, 1);
  }
  display.display();
}

void drawWhite(int xb, int yb, int rb) {
  if (rb == 1) {
    display.fillTriangle((xb * 8) + 1, (yb * 8) + 7, (xb * 8) + 1, (yb * 8) + 1, (xb * 8) + 6, (yb * 8) + 4, 1);
  }
  if (rb == 2) {
    display.fillTriangle((xb * 8) + 1, (yb * 8) + 1, (xb * 8) + 7, (yb * 8) + 1, (xb * 8) + 4, (yb * 8) + 6, 1);
  }
  if (rb == 3) {
    display.fillTriangle((xb * 8) + 7, (yb * 8) + 1, (xb * 8) + 7, (yb * 8) + 7, (xb * 8) + 1, (yb * 8) + 4, 1);
  }
  if (rb == 4) {
    display.fillTriangle((xb * 8) + 1, (yb * 8) + 7, (xb * 8) + 7, (yb * 8) + 7, (xb * 8) + 4, (yb * 8) + 1, 1);
  }
  display.display();
}


void shootWhite(int range) {

  if (grw == 1) {
    for (int i = 0; i < range; i++) {
      drawBullet(gxw + i, gyw);
      if (gxw + i == gxb and gyw == gyb) {

        winWhite();
        i = range;
      }
      if (carta[gxw + i][gyw] == 1) {
        carta[gxw + i][gyw] = 0;
        i = range;
      }
    }
  }
  if (grw == 2) {
    for (int i = 0; i < range; i++) {
      drawBullet(gxw, gyw + i);
      if (gyw + i == gyb and gxw == gxb) {

        winWhite();
        i = range;
      }
      if (carta[gxw][gyw + i] == 1) {
        carta[gxw][gyw + i] = 0;
        i = range;
      }
    }
  }
  if (grw == 3) {
    for (int i = 0; i < range; i++) {
      drawBullet(gxw - i, gyw);
      if (gxw - i == gxb and gyw == gyb) {

        winWhite();
        i = range;
      }
      if (carta[gxw - i][gyw] == 1) {
        carta[gxw - i][gyw] = 0;
        i = range;
      }
    }
  }
  if (grw == 4) {
    for (int i = 0; i < range; i++) {
      drawBullet(gxw, gyw - i);
      if (gyw - i == gyb and gxw == gxb) {

        winWhite();
        i = range;
      }
      if (carta[gxw][gyw - i] == 1) {
        carta[gxw][gyw - i] = 0;
        i = range;
      }
    }
  }
}





void shootBlack(int range) {

  if (grb == 1) {
    for (int i = 0; i < range; i++) {
      drawBullet(gxb + i, gyb);
      if (gxb + i == gxw and gyb == gyw) {

        winBlack();
        i = range;
      }
      if (carta[gxb + i][gyb] == 1) {
        carta[gxb + i][gyb] = 0;
        i = range;
      }
    }
  }
  if (grb == 2) {
    for (int i = 0; i < range; i++) {
      drawBullet(gxb, gyb + i);
      if (gyb + i == gyw and gxb == gxw) {

        winBlack();
        i = range;
      }
      if (carta[gxb][gyb + i] == 1) {
        carta[gxb][gyb + i] = 0;
        i = range;
      }
    }
  }
  if (grb == 3) {
    for (int i = 0; i < range; i++) {
      drawBullet(gxb - i, gyb);
      if (gxb - i == gxw and gyb == gyw) {
        winBlack();
        i = range;
      }
      if (carta[gxb - i][gyb] == 1) {
        carta[gxb - i][gyb] = 0;
        i = range;
      }
    }
  }
  if (grb == 4) {
    for (int i = 0; i < range; i++) {
      drawBullet(gxb, gyb - i);
      if (gyb - i == gyw and gxb == gxw) {

        winBlack();
        i = range;
      }
      if (carta[gxb][gyb - i] == 1) {
        carta[gxb][gyb - i] = 0;
        i = range;
      }
    }
  }
}

void checkWhite() {
  digitalWrite(2, 1);
  while (fwdbtn == 1 and rbtnr == 1 and rbtnl == 1 and shtbtn == 1) {

    fwdbtn = digitalRead(KEYLC);
    rbtnr = digitalRead(KEYRC);
    rbtnl = digitalRead(KEYLS);
    shtbtn = digitalRead(KEYRS);
    if (fwdbtn == 0) {
      delay(200);
      fwdw();
    }
    if (rbtnr == 0) {
      delay(200);
      rotw(0);
    }
    if (rbtnl == 0) {
      delay(200);
      rotw(1);

    }
    if (shtbtn == 0) {
      delay(200);
      shootWhite(rngw);
    }

  }
  drawMap();
  drawBlack(gxb, gyb, grb);
  drawWhite(gxw, gyw, grw);
  steps++;
}

void checkBlack() {
  digitalWrite(2, 0);
  while (fwdbtn == 1 and rbtnr == 1 and rbtnl == 1 and shtbtn == 1) {

    fwdbtn = digitalRead(KEYLC);
    rbtnr = digitalRead(KEYRC);
    rbtnl = digitalRead(KEYLS);
    shtbtn = digitalRead(KEYRS);
    if (fwdbtn == 0) {
      delay(200);
      fwdb();
    }
    if (rbtnr == 0) {
      delay(200);
      rotb(0);
    }
    if (rbtnl == 0) {
      delay(200);
      rotb(1);

    }
    if (shtbtn == 0) {
      delay(200);
      shootBlack(rngb);
    }

  }
  drawMap();
  drawBlack(gxb, gyb, grb);
  drawWhite(gxw, gyw, grw);
}

void winBlack() {
  display.fillRect((gxw * 8), (gyw * 8), 8, 8, 1);
  display.display();
  delay(200);
  display.fillRect((gxw * 8), (gyw * 8), 8, 8, 0);
  display.display();
  delay(200);
  display.fillRect((gxw * 8), (gyw * 8), 8, 8, 1);
  display.display();
  delay(200);
  display.fillRect((gxw * 8), (gyw * 8), 8, 8, 0);
  display.display();
  delay(500);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(8, 10);
  display.print(utf8rus("   Черный!"));
  display.setCursor(30, 30);
  display.setTextSize(1);
  display.print(utf8rus("Шаги: "));
  display.print(steps);
  display.drawRect(0, 0, 128, 64, 1);
  display.display();
  delay(5000);
 wait();
}

void winWhite() {
  display.fillRect((gxb * 8), (gyb * 8), 8, 8, 1);
  display.display();
  delay(200);
  display.fillRect((gxb * 8), (gyb * 8), 8, 8, 0);
  display.display();
  delay(200);
  display.fillRect((gxb * 8), (gyb * 8), 8, 8, 1);
  display.display();
  delay(200);
  
  display.fillRect((gxb * 8), (gyb * 8), 8, 8, 0);
  display.display();
  delay(500);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(8, 10);
  display.print(utf8rus("   Белый!"));
  display.setCursor(30, 30);
  display.setTextSize(1);
  display.print(utf8rus("Шаги: "));
  display.print(steps);
  display.drawRect(0, 0, 128, 64, 1);
  display.display();
  delay(5000);
  wait();
}

void fwdb() {
  int wall = 0;
  if (grb == 1) {
    wall = carta[gxb + 1][gyb];

    if (wall == 0) {
      gxb++;
    }
    if (wall == 2) {
      gxb++;
      rngb = 10;
      carta[gxb][gyb] = 0;
    }
  }


  if (grb == 2) {
    wall = carta[gxb][gyb + 1];

    if (wall == 0) {
      gyb++;
    }
    if (wall == 2) {
      gyb++;
      rngb = 10;
      carta[gxb][gyb] = 0;
    }
  }


  if (grb == 3) {
    wall = carta[gxb - 1][gyb];

    if (wall == 0) {
      gxb--;
    }
    if (wall == 2) {
      gxb--;
      rngb = 10;
      carta[gxb][gyb] = 0;
    }
  }


  if (grb == 4) {
    wall = carta[gxb][gyb - 1];

    if (wall == 0) {
      gyb--;
    }
    if (wall == 2) {
      gyb--;
      rngb = 10;
      carta[gxb][gyb] = 0;
    }
  }
}

void fwdw() {
  int wall = 0;
  if (grw == 1) {
    wall = carta[gxw + 1][gyw];

    if (wall == 0) {
      gxw++;
    }
    if (wall == 2) {
      gxw++;
      rngw = 10;
      carta[gxw][gyw] = 0;
    }
  }


  if (grw == 2) {
    wall = carta[gxw][gyw + 1];

    if (wall == 0) {
      gyw++;
    }
    if (wall == 2) {
      gyw++;
      rngw = 10;
      carta[gxw][gyw] = 0;
    }
  }
  if (grw == 3) {
    wall = carta[gxw - 1][gyw];

    if (wall == 0) {
      gxw--;
    }
    if (wall == 2) {
      gxw--;
      rngw = 10;
      carta[gxw][gyw] = 0;
    }

  }
  if (grw == 4) {
    wall = carta[gxw][gyw - 1];

    if (wall == 0) {
      gyw--;
    }
    if (wall == 2) {
      gyw--;
      rngw = 10;
      carta[gxw][gyw] = 0;
    }
  }
}

void rotb(int rst) {
  if (rst == 0) {
    grb++;
  }
  if (rst == 1) {
    grb--;
  }
  if (grb == 5) {
    grb = 1;
  }
  if (grb == 0) {
    grb = 4;
  }
}

void rotw(int rst) {
  if (rst == 0) {
    grw++;
  }
  if (rst == 1) {
    grw--;
  }
  if (grw == 5) {
    grw = 1;
  }
  if (grw == 0) {
    grw = 4;
  }
}
