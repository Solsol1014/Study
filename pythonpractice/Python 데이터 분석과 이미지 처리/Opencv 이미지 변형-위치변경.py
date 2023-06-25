import cv2 as cv
import numpy as np

image=cv.imread("Cat03.jpg")

height, width=image.shape[:2]

M=np.float32([[1, 0, 200], [0, 1, 10]])
dst=cv.warpAffine(image, M, (width, height))
cv.imshow('Image', dst)
cv.waitKey(0)