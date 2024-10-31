import cv2 as cv
import numpy as np

image=cv.imread('gray_image.jpg')
cv.imshow('image', image)
cv.waitKey(0)

size=10
kernel=np.ones((size, size), np.float32)/(size**2)
print(kernel)

dst=cv.filter2D(image, -1, kernel)
cv.imshow('image', dst)
cv.waitKey(0)