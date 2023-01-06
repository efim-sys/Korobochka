# Korobochka
Nano size gaming console

# Korobochka features pre-installed apps:
  1. Space-Heroes
  2. Cat or Bread
  4. Beer's
  3. Tanchiki
  5. Study:
      1. graph calc
      2. formula
      3. text
  6. Portrait of Putin.png
  7. Piano
  8. Pocket Sitin randomizer
  9. Metaballs
  10. Korobochka Tube
  11. Pong
  12. Settings:
      1. Piano settings
      2. Cat or Bread delay
      3. About device
      4. Tools:
          1. MLX90614 thermometer
          2. EEPROM tool
          3. WiFi connection manager
          4. I2C scanner
          5. Oscilloscope (beta)
          6. PWM generator (beta)
          7. Add your repository
      5. Updates
  13. 3D game
  14. Polish cow.mp4
  15. NTP web Watch
  16. Media BLE keyboard

# Setting Up programming software:

  1. Install Arduino IDE
  2. Copy all contents of libraries folder to library folder in your Arduino/libraies folder
  3. Open preferences and paste the link to "additional links":

    https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json

  4. Go instruments > board > board manager and search for esp32
  5. Install ESP32 core of newest version (It can take more than 5 mins)
  6. Go instruments > board and select ESP32C3 Dev Module
  7. Go instruments > Partition Scheme and select Minimal SPIFFS
  8. Go instruments > USB CDC on Boot and select Enabled
  9. Select port in Ports menu: /dev/ACM0(ESP32C3) or COM5(ESP32C3)
  10. Upload your firmware

  ![Right settings](https://github.com/efim-sys/Korobochka/raw/main/settings.png "Make sure yuo have same settings")

  [Unlocking USB CDC](http://efim.adior.ru/index.php/46-korobochka-usb-cdc-unlock)

# Libraries required:
  1. Adafruit GFX
  2. Adafruit SSD1306
  3. Adafruit MLX90614
  4. GuyverButton
  5. Arduino_JSON
  6. Arduino_Vector
  7. Adafruit BusIO
  8. Pre-installed esp32 libraries

# Manual flashing using esptool
  `sudo apt install python3-pip`

  `pip install esptool`

>  Now you need to re-login

  `esptool.py --chip esp32c3 --before usb_reset --baud 921600 --port /dev/ttyACM0 write_flash 0x00010000 Korobochka.ino.esp32c3.bin`