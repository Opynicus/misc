import random

import cv2
import time

HH = 490  # header Height
BH = 440
MBH = 120
own = cv2.imread("./own.jpg")

header = own[0:HH, 0:own.shape[1]]

bottom = own[own.shape[0] - MBH: own.shape[0], 0: own.shape[1]]

other = cv2.imread("./other.jpg")

if other.shape != own.shape:
    other = cv2.resize(other, dsize=(own.shape[1], own.shape[0]), fx=1, fy=1, interpolation=cv2.INTER_LINEAR)

y = True
bias = 0
while y:
    banner = other[HH + bias * 10:other.shape[0] - MBH + bias * 10, 0: other.shape[1]]
    img = cv2.vconcat([header, banner, bottom])
    cv2.waitKey()
    img = cv2.resize(img, dsize=(own.shape[1], own.shape[0]), fx=1, fy=1, interpolation=cv2.INTER_LINEAR)
    cv2.imshow("img", img)
    cv2.waitKey()
    # cv2.destroyWindow('img')
    fin = input("Finish?(y/n):")
    if fin == 'y' or fin == 'Y':
        y = False
    else:
        bias += 1
    if bias == 10:
        print("Try another pic...")

now = time.localtime(time.time())
imgName = "Screenshot_" + str(now.tm_year) + "-" + str(now.tm_mon) + "-" + str(now.tm_mday) + "-" + str(
    now.tm_hour) + "-" + str(
    now.tm_min) + "-" + str(now.tm_sec) + "-" + str(random.randint(
    0, 1000)) + "_com.tencent.mm.jpg"

print("Finish!")
cv2.imwrite(imgName, img)
