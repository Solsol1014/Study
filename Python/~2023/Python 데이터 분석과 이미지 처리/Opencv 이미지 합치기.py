import cv2 as cv
from numpy import imag

image1=cv.imread('bling.jpeg')
print(image1.shape)
image2=cv.imread('Cat03.jpg')

add2=image2[500:840, 300:781]
cv.imshow('add2', add2)
cv.waitKey(0)
cv.imshow('image1', image1)
cv.waitKey(0)

cv.destroyAllWindows()

result=cv.add(add2, image1)
cv.imshow('add', result)
cv.waitKey(0)