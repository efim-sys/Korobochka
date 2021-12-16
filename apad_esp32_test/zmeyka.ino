byte lenght = 3;
byte zmeyka[][2] = {{2, 2}, {3, 2}, {4, 2}};
byte rotation = 0;

void playZmeyka(){
  
  
  while(1){
    drawZmeyka();
    display.display();
    bool goR = !digitalRead(KEYRS);
    bool goL = !digitalRead(KEYLS);
    if(goR){
      rotation += 1;
      if(rotation>3){
        rotation=0;
      }
      delay(200);
    }
    if(goL){
      rotation -= 1;
      if(rotation<0){
        rotation=3;
      }
      delay(200);
    }
    if(milllis()%1000<10){
      switch(rotation){
        case 0:
          for(byte i=0; i<lenght; i++){
            zmeyka[i][0]+=1;
            }
          break;
        case 0:
          for(byte i=0; i<lenght; i++){
            zmeyka[i][0]+=1;
            }
          break;
      }
    }
  }
}


void drawZmeyka(){
  for(byte i = 0; i < lenght; i++){
    display.fillRect(zmeyka[i][0]*8, zmeyka[i][1]*8, 8, 8, 1);
  }
}
