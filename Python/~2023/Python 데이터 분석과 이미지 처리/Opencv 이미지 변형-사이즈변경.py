import cv2 as cv
from numpy import imag

image=cv.imread('Cat03.jpg')
cv.imshow('image', image)
cv.waitKey(0)

expand=cv.resize(image, None, fx=1.5, fy=1.5, interpolation=cv.INTER_CUBIC)
cv.imshow('Image', expand)
cv.waitKey(0)

cv.destroyAllWindows()

shrink=cv.resize(image, None, fx=0.5, fy=0.5, interpolation=cv.INTER_AREA)
cv.imshow('Shrink', shrink)
cv.waitKey(0)

shrinkexpand=cv.resize(shrink, None, fx=2, fy=2, interpolation=cv.INTER_AREA)
cv.imshow('shrinkexpand', shrinkexpand)
cv.waitKey(0)

cv.destroyAllWindows()

for i in range(500):
    shrink=cv.resize(shrinkexpand, None, fx=0.5, fy=0.5, interpolation=cv.INTER_AREA)
    shrinkexpand=cv.resize(shrink, None, fx=2, fy=2, interpolation=cv.INTER_AREA)

cv.imshow('shrinkexpand', shrinkexpand)
cv.waitKey(0)
cv.imshow('original', image)
cv.waitKey(0)