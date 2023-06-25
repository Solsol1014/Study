import cv2 as cv
import numpy as np

def change_color(x):
    r=cv.getTrackbarPos("R", 'Image')
    g=cv.getTrackbarPos("G", 'Image')
    b=cv.getTrackbarPos("B", 'Image')
    image[:]=[b, g, r]
    cv.imshow('Image', image)

image=np.zeros((600, 400, 3), np.uint8)
cv.namedWindow("Image")

cv.createTrackbar("R", 'Image', 0, 255, change_color)
cv.createTrackbar("G", 'Image', 0, 255, change_color)
cv.createTrackbar("B", 'Image', 0, 255, change_color)

cv.imshow('Image', image)
cv.waitKey(0)