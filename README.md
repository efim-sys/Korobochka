# Korobochka
Nano size gaming console

# Korobochka features pre-installed apps:
  1. Space-Heroes
  2. Cat or Bread 2
  3. Tanchiki
  5. Study:
      1. graph calc
      2. formula
      3. text
  6. Pong
  7. Portrait of Putin.png
  8. Polish cow.mp4
  9. 3D game
  10. Beer's
  11. Wide putin walks.mp4
  12. Pocket Sitin randomizer
  13. Port of metaballs
  14. Piano
  15. Settings:
      1. Piano settings
      2. Cat or Bread delay
      3. About device
      4. Tools:
          1. MLX90614 thermometer
          2. EEPROM tool
          3. WiFi scanner
          4. I2C scanner
          5. Oscilloscope

# Setting Up programming software:

  1. Install Arduino IDE
  2. Install all required libraries to your IDE
  3. Open preferences and paste the link to "additional links":
    https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
  4. Go instruments > board > board manager and search for esp32
  5. Install ESP32 core of newest version
  6. Go instruments > board and select ESP32C3 Dev Module
  7. Go instruments > Partition Scheme and select Minimal SPIFFS
  8. Select port in Ports menu: /dev/ACM0(ESP32C3) or COM5(ESP32C3)
  9. Upload your firmware

# Libraries required:
  1. Adafruit GFX
  2. Adafruit SSD1306
  3. Adafruit MLX90614
  4. GuyverButton
  5. Arduino_JSON
  6. Arduino_Vector
  7. Adafruit BusIO
  8. Pre-installed esp32 libraries
