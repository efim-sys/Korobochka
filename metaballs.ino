#define smolPI 3.14

void playMetaBalls() {
      byte bulletsNum;
      struct Player {
        float angle = 0;
        float x = 64.f;
        float y = 32.f;
        float acc = 0;
      } player;

      struct Bullet {
        float angle = 0;
        float x = 0;
        float y = 0;
      } bullet;
      Bullet enemy;
      while(1){
        
        if(!digitalRead(KEYRS)) {
          player.angle = player.angle + 0.125 * smolPI; 
          delay(20);
        }
        if(!digitalRead(KEYLS)) {
          player.angle = player.angle - 0.125 * smolPI; 
          delay(20);
        }
        if(!digitalRead(KEYLC)) {
          player.acc += 0.2f;
          if(player.acc > 3.f) player.acc = 3.f;
          player.x -= player.acc * cos(player.angle); 
          player.y -= player.acc * sin(player.angle); 
          if(player.x > 128) player.x -= 128;
          if(player.x < 0) player.x += 128;
          if(player.y > 64) player.y -= 64;
          if(player.y < 0) player.y += 64;
          delay(20);
        }
        
        if(!digitalRead(KEYRC)) {
          bullet.x = player.x;
          bullet.y = player.y;
          bullet.angle = player.angle;
        }
        
        else{
          player.acc -= 0.05f;
          if(player.acc <= 0) player.acc = 0;
          else{
            player.x -= player.acc * cos(player.angle); 
            player.y -= player.acc * sin(player.angle);
            if(player.x > 128) player.x -= 128;
            if(player.x < 0) player.x += 128;
            if(player.y > 64) player.y -= 64;
            if(player.y < 0) player.y += 64;
            delay(20);
          }
          
        }
        if(enemy.x > 128 or enemy.x < 0 or enemy.y > 64 or enemy.y < 0){
          enemy.x = random(0, 128);
          enemy.y = 64 * random(0, 2);
          enemy.angle = smolPI * 0.1 *random(0, 20);
        }
        if((enemy.x - bullet.x <= 4 and enemy.x - bullet.x >= -4) and (enemy.y - bullet.y <= 4 and enemy.y - bullet.y >= -4)){
          enemy.x = random(0, 128);
          enemy.y = 64 * random(0, 2);
          enemy.angle = smolPI * 0.1 *random(0, 20);
        }
        enemy.x -= cos(enemy.angle); 
        enemy.y -= sin(enemy.angle);
        bullet.x -= 3 * cos(bullet.angle); 
        bullet.y -= 3 * sin(bullet.angle);
        
        display.clearDisplay();
        display.drawTriangle(player.x - 2 * cos(player.angle - 0.33 * smolPI), player.y - 2 * sin(player.angle - 0.33 * smolPI), 
                             player.x - 5 * cos(player.angle), player.y - 5 * sin(player.angle),
                             player.x - 2 * cos(player.angle + 0.33 * smolPI), player.y - 2 * sin(player.angle + 0.33 * smolPI), 1);
        display.drawPixel(bullet.x, bullet.y, 1);
        display.drawBitmap(enemy.x - 4, enemy.y - 4, impostor, 8, 8, 1);
        display.display();
        }
      
  
}
/*
bool outOfBounds(Bullet obj){
  return obj.x > 128 or obj.x < 0 or obj.y > 64 or obj.y < 0;;
  
}
*/
