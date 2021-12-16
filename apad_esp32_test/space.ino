


void drawImpostor(int x, int y, int b) {
  switch (b) {
    case 0:
      display.drawBitmap(x, y, impostor, 8, 8, 1);
      break;
    case 1:
      switch (blowNum) {
        case 1:
          display.drawBitmap(x, y, blow, 8, 8, 1);
          break;

        case 2:
          display.drawBitmap(x, y, blow1, 8, 8, 1);
          break;
      }

      if (killDelay < millis()) {
        reborn();
      }
      break;
  }
}


void drawGun(int x, int y, int b) {
  switch (b) {
    case 0:
      display.drawBitmap(x, y, gunlet, 8, 8, 1);
      break;
    case 1:
      display.drawBitmap(x, y, gunlet1, 8, 8, 1);

      break;
  }
}


void think() {
  impostorY++;
  if (impostorY > 16) {
    doorFrame = 0;
    if (impostorX <= fighterX and impostorX > 1) {
      impostorX--;
    }
    else {
      if (impostorX > fighterX and impostorX < 120) {
        impostorX++;
      }
    }
  }

}

void reborn() {
  blown = 0;
  impostorY = 0;
  spawnImpostor();
}

void fighterShoot() {
  if (millis() > cooldown) {
    display.drawLine(fighterX, 52, fighterX, 0, 1);
    display.display();
    display.drawLine(fighterX + 7, 52, fighterX + 7, 0, 1);
    display.display();
    cooldown = millis() + 1000;
    if (((fighterX > impostorX and fighterX < impostorX + 7) or (fighterX + 7 > impostorX and fighterX + 7 < impostorX + 7)) and impostorY <= 58) {
      killDelay = millis() + 800;
      blown = 1;
      blowNum = random(1, 3);
      score++;
      rocketScore++;
    }
  }
}




void buttonsSpace() {
  int left = 1;
  int right = 1;
  int shoot = 1;
  int rocket = 1;
  left = digitalRead(KEYLS);
  right = digitalRead(KEYRS);
  shoot = digitalRead(KEYRC);
  rocket = digitalRead(KEYLC);
  if (left == 0 and fighterX > -4) {
    fighterX -= 1;
  }
  if (right == 0 and fighterX < 124) {
    fighterX += 1;
  }
  if (shoot == 0) {
    fighterShoot();
    shootY = 52;

  }
  if (rocket == 0 and gamemode == 1 and rockets > 0 and (millis() - laserTimer) > 2000) {
    laserX = fighterX + 4;
    laserTime = 0;
    display.fillRect(laserX, 0, 2, 64, 1);
    if ((fighterX + 4 >= 10 and fighterX + 4 <= 18)) {
      gun1State = 1;
    }
    if (fighterX + 4 >= 60 and fighterX + 4 <= 68) {
      gun2State = 1;
    }
    if (fighterX + 4 >= 118 and fighterX + 4 <= 126) {
      gun3State = 1;
    }
    rockets--;
    laserTimer = millis();
  }

}

void impostorCheck() {
  if (blown == 0 and (millis() % 60) <= 20 ) {
    think();
  }
  if (impostorY > 65) {
    reborn();
    rocketScore = 0;
    gone++;
  }
}



void drawBase() {
  display.fillRect(0, 0, 128, 16, 0);
  display.drawRect(-1, -1, 130, 17, 1);
  drawGun(10, 4, gun1State);
  drawGun(60, 4, gun2State);
  drawGun(118, 4, gun3State);
}



void torpeda(int n) {
  switch (n) {
    case 1:
      if (gun1State == 0) {
        torpedaX = 14;
        torpedaY = 12;
        torpedaUpd();
      }
      break;
    case 2:
      if (gun2State == 0) {
        torpedaX = 64;
        torpedaY = 12;
        torpedaUpd();
      }
      break;
    case 3:
      if (gun3State == 0) {
        torpedaX = 122;
        torpedaY = 12;
        torpedaUpd();
      }
      break;
  }
}



void torpedaUpd() {
  if (gamemode == 1 and laserTime < 25) {
    display.fillRect(laserX, 0, 2, 64, 1);
    laserTime++;
  }
  if (torpedaY < 64) {
    if ((torpedaX >= fighterX and torpedaX < fighterX + 7) and (torpedaY + 4 > 50 and torpedaY < 58)) {
      loose();
      score = 0;
      rocketScore = 0;
      atackTimer = millis();
    }
    display.drawLine(torpedaX, torpedaY, torpedaX, torpedaY + 4, 1);
    if (millis() % 70 <= 30) {
      torpedaY++;
    }
  }
  else {
    torpeda(random(1, 4));
  }
}


void door(int n) {
  switch (n) {
    case 1:
      display.drawLine(28, 17, 40, 17, 1);
      break;
    case 2:
      display.drawLine(58, 17, 70, 17, 1);
      break;
    case 3:
      display.drawLine(88, 17, 100, 17, 1);
      break;

  }
}


void spawnImpostor() {
  doorFrame = 1;
  impostorExit = random(1, 4);
  impostorX = impostorExit * 30;
}


void drawSpaceGUI() {
  display.setTextSize(1);
  display.setCursor(75, 4);
  display.print((millis() - atackTimer) / 1000);
  display.print(F("/60"));
  display.setCursor(107, 4);
  display.print(rockets);
  display.setCursor(20, 4);
  display.print(gone);
  display.setCursor(35, 4);
  display.print(rocketScore);
  display.print(F("/5"));
}


void playSpace() {
  display.setTextSize(2);
  display.setTextColor(1, 0);
  display.setCursor(0, 20);
  display.print(utf8rus("  космо -"));
  display.setCursor(20, 37);
  display.print(utf8rus("Герои 2"));
  display.setTextSize(1);
  display.setCursor(10, 56);
  display.print(utf8rus("Зайти нажав"));
  drawBase();
  display.display();
  int left = 1;
  int right = 1;
  int shoot = 1;
  int rocket = 1;
  while (left == 1 and right == 1 and shoot == 1 and rocket == 1) {
    left = digitalRead(KEYLS);
    right = digitalRead(KEYRS);
    shoot = digitalRead(KEYRC);
    rocket = digitalRead(KEYLC);
  }
  spawnImpostor();
  torpeda(3);
  atackTimer = millis();

  while (1) {
    if (rocketScore >= 5) {
      rocketScore = 0;
      rockets++;
    }
    if (gone > 15) {
      loose();
    }

    if (gun1State == 1 and gun2State == 1 and gun3State == 1) {
      win();
    }

    if (millis() - atackTimer > 60000) {
      atackTimer = millis();
      gamemode = 1;

    }
    if (millis() - atackTimer > 10000 and gamemode == 1) {
      gamemode = 0;
      atackTimer = millis() - 100;
    }



    if (doorFrame == 1) {
      door(impostorExit);
    }

    if (gamemode == 1) {
      display.setTextSize(1);
      display.setCursor(40, 56);
      display.print(utf8rus("Атака!"));
    }

    display.drawBitmap(fighterX, 50, fighter, 8, 8, 1);
    drawImpostor(impostorX, impostorY, blown);
    drawBase();
    torpedaUpd();
    drawSpaceGUI();
    impostorCheck();
    display.display();
    buttonsSpace();
    display.clearDisplay();
  }
}


void loose() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(15, 10);
  display.print(utf8rus("   Вы"));
  display.setCursor(15, 30);
  display.print(utf8rus("Проиграли"));
  display.setTextSize(1);
  display.setCursor(10, 50);
  display.print(utf8rus("считать буржуи: "));
  display.print(score);
  display.drawRect(0, 0, 128, 64, 1);
  display.display();
  delay(3000);
  digitalWrite(9, 0);
  wait();
}


void win() {
  drawImpostor(10, 4, 1);
  drawImpostor(60, 4, 1);
  drawImpostor(118, 4, 1);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(15, 10);
  display.print(utf8rus("   Вы"));
  display.setCursor(10, 30);
  display.print(utf8rus("Выйграли!"));
  display.setTextSize(1);
  display.setCursor(10, 50);
  display.print(utf8rus("считать буржуи: "));
  display.print(score);
  display.drawRect(0, 0, 128, 64, 1);
  display.display();
  delay(3000);
  wait();
}
