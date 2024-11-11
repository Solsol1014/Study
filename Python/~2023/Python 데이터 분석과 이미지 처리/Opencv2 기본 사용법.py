import cv2 as cv

img_basic=cv.imread('Cat03.jpg', cv.IMREAD_COLOR)
cv.imshow('Image Basic', img_basic)
cv.waitKey(0)
cv.imwrite('result1.png', img_basic)

cv.destroyAllWindows()

img_gray=cv.cvtColor(img_basic, cv.COLOR_BGR2GRAY)
cv.imshow('Image Gray', img_gray)
cv.waitKey(0)
cv.imwrite('result2.png', img_gray)