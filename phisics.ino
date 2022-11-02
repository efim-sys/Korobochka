const char *texts[] = {"Формулы", "Божественая комедия", "Графики калькулятор"};

const char *graphTypes[] = {"y=kx","y=k/x", "y=kx+b", "y=k/x+b", "y=x^2"};

void playPhisics() {
  switch (korobkaMenu(3, texts)) {
    case 0:
      display.setCursor(0, 0);
      display.setTextSize(1);
      display.println(F("A=FS N=A/t r=m/V S=Vt"));
      display.println(F("n=Apol/Azat"));
      display.println(F("(a+b)3=a3+3a2b+3ab2+b3"));
      display.println(F("a3+b3=(a+b)(a2-ab+b2)"));
      display.display();
      while(1);
      break;
    case 1:
      korobkaReader(comedy_text, 9);
      while(1);
      break;
    case 2:
      int k = 0;
      int b = 0;
      int prev[2] = {0, 0};
      byte Gtype = korobkaMenu(5, graphTypes);
      if(Gtype<2){
        message("k = ?", 1000);
        k = korobkaInput(-30, 30, 1, 0);
      }
      else if(Gtype<4){
        message("k = ?", 1000);
        k = korobkaInput(-30, 30, 1, 0);
        message("b = ?", 1000);
        b = korobkaInput(-30, 30, 1, 0);
      }
      display.clearDisplay();
      display.drawFastHLine(0, 32, 128, 1);
      display.drawFastVLine(64, 0, 64, 1);
      int x = -64;
      switch(Gtype){
          case 0:
            prev[0] = x+64; prev[1] = 32-(x*k); 
            break;
          case 1:
            prev[0] = x+64; prev[1] = 32-(k/x);
            break;
          case 2:
            prev[0] = x+64; prev[1] = 32-(x*k+b);
            break;
          case 3:
            prev[0] = x+64; prev[1] = 32-(k/x+b);  
            break;
          case 4:
            prev[0] = x+64; prev[1] = 32-(x*x);  
            break;
         }
      for(int x = -64; x < 64; x++){
         switch(Gtype){
          case 0:
            display.drawLine(prev[0], prev[1], x+64, 32-(x*k), 1); 
            break;
          case 1:
            display.drawLine(prev[0], prev[1], x+64, 32-(k/x), 1);
            break;
          case 2:
            display.drawLine(prev[0], prev[1], x+64, 32-(x*k+b), 1);
            break;
          case 3:
            display.drawLine(prev[0], prev[1], x+64, 32-(k/x+b), 1);  
            break;
          case 4:
            display.drawLine(prev[0], prev[1], x+64, 32-(x*x), 1);  
            break;
         }
         switch(Gtype){
          case 0:
            prev[0] = x+64; prev[1] = 32-(x*k); 
            break;
          case 1:
            prev[0] = x+64; prev[1] = 32-(k/x);
            break;
          case 2:
            prev[0] = x+64; prev[1] = 32-(x*k+b);
            break;
          case 3:
            prev[0] = x+64; prev[1] = 32-(k/x+b);  
            break;
          case 4:
            prev[0] = x+64; prev[1] = 32-(x*x);  
            break;
         }
      }
      display.display();
      while(1);
      break;
  }

}
