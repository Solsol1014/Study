import cv2 as cv
import time

# image=cv.imread('Cat03.jpg')
# #픽셀 수 및 이미지 크기 확인
# print(image.shape)
# print(image.size)

# px=image[500, 500]
# print(px)
# print(px[2])

image=cv.imread('Cat03.jpg')

#요부분은 특정 범위 픽셀 변경
# start_time=time.time()
# for i in range(0, 100):
#     for j in range(0, 100):
#         image[i,j]=[143, 23, 231]
# print("{}seconds".format(time.time()-start_time))

# start_time=time.time()
# image[0:100, 0:100]=[2, 2, 156]
# print("{0:0.20f}seconds".format(time.time()-start_time))

#roi 추출 및 복사 부분
# face=image[250:1050, 400:1250]

# cv.imshow('face', face)
# cv.waitKey(0)

# image[0:800, 0:850]=face

#픽셀별로 색상다루기 부분
cv.imshow('Image', image[:, :, 1])
cv.waitKey(0)

image[:, :, 2]=0

cv.imshow('Image', image)
cv.waitKey(0)