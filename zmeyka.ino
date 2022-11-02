/*

byte lenght = 3;
byte zmeyka[129][2];

byte rotation = 0;

void playZmeyka() {
  for(byte i = 0; i < 3; i++){
    zmeyka[i][0] = 2 + i;
    zmeyka[i][1] = 4;
  }

  while (1) {
    drawZmeyka();
    display.display();
    delay(1000);
    moveArray(1);
  }



}

void moveArray(byte dir){
  for(byte i = lenght-1; i >= 0; i++){
    zmeyka[i][0]=zmeyka[i+1][0];
    zmeyka[i][1]=zmeyka[i+1][1];
  }
  switch(dir){
    case 0:
      zmeyka[0][0]+=1;
      break;
    case 1:
      zmeyka[0][1]+=1;
      break;
    case 2:
      zmeyka[0][0]-=1;
      break;
    case 3:
      zmeyka[0][1]-=1;
      break;
  }
}


void drawZmeyka() {
  for (byte i = 0; i < lenght; i++) {
    display.fillRect(zmeyka[i][0] * 8, zmeyka[i][1] * 8, 8, 8, 1);
  }
}
*/
