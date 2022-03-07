/*1
#define BUFFER_SIZE 128

byte thermoBuffer[BUFFER_SIZE];

float shotTermo = 0;

void playThermometer() {
  mlx.begin(0x5A, &Wire1);
  mlx.writeEmissivity(0.98);
  for (byte n = BUFFER_SIZE; n > 0; n--) {
    thermoBuffer[n] =20;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(15, 5);
  display.print(F("IR therometer 1.0"));
  if(thermo_type){
  while (1) {
    graphThermometer();
  }
  }
  else{
  while (1) {
    normalThermometer();
  }
  }
}

void normalThermometer() {
  if (millis() % 100 <= 3) {
    display.setTextSize(3);
    display.fillRect(0, 18, 128, 46, 0);
    display.setCursor(0, 18);
    display.print(mlx.readObjectTempC());
    display.print(F("C"));
    display.setTextSize(2);
    display.setCursor(25, 45);
    display.print(shotTermo);
    display.print(F(" C"));
    display.display();
  }
  else if (!digitalRead(KEYRS)) {
    shotTermo = mlx.readObjectTempC();
  }
}

void graphThermometer() {
  int min = 100;
  int max = -100;
  for (byte n = BUFFER_SIZE; n > 0; n--) {
    thermoBuffer[n] = thermoBuffer[n - 1];
    if (thermoBuffer[n] < min) min = thermoBuffer[n];
    if (thermoBuffer[n] > max) max = thermoBuffer[n];
  }
  thermoBuffer[0] = byte(mlx.readObjectTempC());
  if (thermoBuffer[0] < min) min = thermoBuffer[0];
  if (thermoBuffer[0] > max) max = thermoBuffer[0];
  display.clearDisplay();
  for (byte c = 0; c < BUFFER_SIZE - 1; c++) {
    display.drawLine(c, 64 + min - 5 - thermoBuffer[c], c + 1, 64 + min - 5 - thermoBuffer[c + 1], 1);
  }
  display.setCursor(0, 0);
  display.print(utf8rus("Щас: "));
  display.print(thermoBuffer[0]);
  display.print("C");
  display.setCursor(70, 0);
  display.print(utf8rus("Макс: "));
  display.print(max);
  display.print("C");
  display.display();
  delay(350);
}
*/
