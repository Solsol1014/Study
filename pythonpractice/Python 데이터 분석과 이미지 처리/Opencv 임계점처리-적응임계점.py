import cv2 as cv

image=cv.imread('Cat03.jpg', cv.IMREAD_GRAYSCALE)

thres1=cv.adaptiveThreshold(image, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY, 21, 3)
thres2=cv.adaptiveThreshold(image, 255, cv.ADAPTIVE_THRESH_GAUSSIAN_C, cv.THRESH_BINARY, 21, 3)

cv.imshow('Image', thres1)
cv.waitKey(0)

cv.imshow('image', thres2)
cv.waitKey(0)