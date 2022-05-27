import cv2
import os

import numpy as np

from tkinter import Tk
from tkinter.filedialog import askdirectory, askopenfilename

Tk().withdraw()


def minmax(v):
    if v > 255:
        v = 255
    if v < 0:
        v = 0
    return v

def dithering_gray(inMat, samplingF):
    h = inMat.shape[0]
    w = inMat.shape[1]
    for y in range(0, h-1):
        for x in range(1, w-1):
            old_p = inMat[y, x]
            new_p = np.round(samplingF * old_p/255.0) * (255/samplingF)
            inMat[y, x] = new_p
            quant_error_p = old_p - new_p
            inMat[y, x+1] = minmax(inMat[y, x+1] + quant_error_p * 7 / 16.0)
            inMat[y+1, x-1] = minmax(inMat[y+1, x-1] + quant_error_p * 3 / 16.0)
            inMat[y+1, x] = minmax(inMat[y+1, x] + quant_error_p * 5 / 16.0)
            inMat[y+1, x+1] = minmax(inMat[y+1, x+1] + quant_error_p * 1 / 16.0)
    return inMat


useDitering = True

print("Выберите выходной файл:")
txt_filename=askopenfilename()
print("Выберите папку с картинками: ")
picdirectory=askdirectory()
print("Введите количество кадров в видео или 1 для картинки: ")
frames=int(input())
print("Введите название массива: ")
aname=input()
file=open(txt_filename,  "w")

cv2.namedWindow("Работаем...", cv2.WINDOW_NORMAL)
cv2.resizeWindow("Работаем...", 800, 400)

for i in range(frames):
  imgfile = picdirectory+"/"+str(i+1).rjust(4, "0") + ".png"
  print("Processing: "+imgfile)
  image = cv2.imread(imgfile)
  gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
  threshold_image = dithering_gray(gray_image.copy(), 1)
  #ret, threshold_image = cv2.threshold(gray_image, 127, 255, 0)
  cv2.imshow("Работаем...", threshold_image)
  width=threshold_image.shape[1]
  height=threshold_image.shape[0]

  outbyte = "0b"

  file.write("const unsigned char ball"+str(i)+" [] PROGMEM {\n")
  for x in range(height):
      for y in range(width):
          outbyte += str(int(threshold_image[x][y]/255))
          if len(outbyte) == 10:
              file.write(outbyte)
              file.write(", ")
              outbyte = "0b"
  file.seek(file.tell() - 2, os.SEEK_SET)
  file.write('')
  file.write("};\n")

file.write("const unsigned char *ball [120] PROGMEM {")
for i in range(frames):
    file.write(aname + str(i) + ", ")
file.seek(file.tell() - 2, os.SEEK_SET)
file.write('')
file.write("};\n")


cv2.waitKey(0)
cv2.destroyAllWindows()
