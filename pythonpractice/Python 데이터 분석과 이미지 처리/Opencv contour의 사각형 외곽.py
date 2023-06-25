import cv2 as cv

image=cv.imread("digit_image.png")
image_gray=cv.cvtColor(image, cv.COLOR_BGR2GRAY)
ret, thresh=cv.threshold(image_gray, 230, 255, 0)
thresh=cv.bitwise_not(thresh)
cv.imshow('image', thresh)
cv.waitKey(0)

contours, hierarchy=cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
image=cv.drawContours(image, contours, -1, (0, 0, 255), 4)
cv.imshow('image', image)
cv.waitKey(0)

contour=contours[0]
x, y, w, h=cv.boundingRect(contour)
image=cv.rectangle(image, (x, y), (x+w, y+h), (0, 0, 255), 3)
cv.imshow('image', image)
cv.waitKey(0)