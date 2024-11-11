import cv2 as cv

image=cv.imread('gray_image.jpg')
cv.imshow('image', image)
cv.waitKey(0)

#kernel size는 홀수여야함
dst=cv.GaussianBlur(image, (5, 5), 0)
cv.imshow('image', dst)
cv.waitKey(0)