import cv2 as cv

image=cv.imread('Cat03.jpg', cv.IMREAD_GRAYSCALE)

images=[]
ret, thres1=cv.threshold(image, 127, 255, cv.THRESH_BINARY)
ret, thres2=cv.threshold(image, 127, 255, cv.THRESH_BINARY_INV)
ret, thres3=cv.threshold(image, 127, 255, cv.THRESH_TRUNC)
ret, thres4=cv.threshold