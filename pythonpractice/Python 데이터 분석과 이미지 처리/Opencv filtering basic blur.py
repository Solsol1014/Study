import cv2 as cv

image=cv.imread('gray_image.jpg')
cv.imshow('image', image)
cv.waitKey(0)

dst=cv.blur(image, (4, 4))
cv.imshow('image', dst)
cv.waitKey(0)