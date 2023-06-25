import cv2 as cv
import numpy as np

image=np.full((512, 512, 3), 255, np.uint8)
image=cv.line(image, (0,0), (255, 255), (255, 0, 0), 50)

cv.imshow('Image', image)
cv.waitKey(0)

image=np.full((512, 512, 3), 255, np.uint8)
image=cv.rectangle(image, (20, 20), (255, 255), (255, 0, 0), 3)

cv.imshow("image", image)
cv.waitKey()

image=np.full((512, 512, 3), 255, np.uint8)
image=cv.circle(image, (50, 50), 20, (0, 255, 0), 2)

cv.imshow("image",image)
cv.waitKey(0)

image=np.full((512, 512, 3), 255, np.uint8)
points=np.array([[5, 5], [12, 453], [351,300], [214,123]])
image=cv.polylines(image, [points], True, (0, 255, 255), 4)

cv.imshow("image", image)
cv.waitKey(0)

image=np.full((512, 512, 3), 255, np.uint8)
image=cv.putText(image, "Sleepy", (240, 240), cv.FONT_ITALIC, 2, (0,0,0))

cv.imshow('image', image)
cv.waitKey(0)