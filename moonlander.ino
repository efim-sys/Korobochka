

void playMoonlander() {
  display.clearDisplay();
  int terrainx=0;
  while(1) {
    terrainx+=10;
    byte terrain[128];
    for(int i = 0; i < 128; i += 1){
      display.drawLine(i-1, 64-int(10*SmoothNoise2(terrainx, i-1)), i, 64-int(10*SmoothNoise2(terrainx, i)), 1);
    }
    display.display();
    delay(100);
  }
}


float Noise2(float x, float y)
{
  long noise;
  noise = x + y * 57;
  noise = pow(noise << 13,noise);
  return ( 1.0 - ( long(noise * (noise * noise * 15731L + 789221L) + 1376312589L) & 0x7fffffff) / 1073741824.0);
}

float SmoothNoise2(float x, float y)
{
  float corners, sides, center;
  corners = ( Noise2(x-1, y-1)+Noise2(x+1, y-1)+Noise2(x-1, y+1)+Noise2(x+1, y+1) ) / 16;
  sides   = ( Noise2(x-1, y)  +Noise2(x+1, y)  +Noise2(x, y-1)  +Noise2(x, y+1) ) /  8;
  center  =  Noise2(x, y) / 4;
  return (corners + sides + center);
}
