import cv2 as cv

image=cv.imread('Cat03.jpg')

height, width=image.shape[:2]

M=cv.getRotationMatrix2D((width/2, height/2), 45, 0.7)
dst=cv.warpAffine(image, M, (width, height))
cv.imshow('Image', dst)
cv.waitKey(0)