def std_weight(height, gender): #남자 0 여자 1
    return height*height*(22-gender)

height=int(input("계산할 키를 입력하세요: "))
if height>3:
    height=height*0.01

while 1:
    gender=int(input("성별을 고르세요 (남자는 0, 여자는 1): "))
    if gender==1 or gender==0:
        break
    print("잘못 입력하셨습니다.")

print("키 {0}cm {1}의 표준 체중은 {2:0.2f}kg 입니다.".format(height*100, "남자" if gender==0 else "여자", std_weight(height, gender)))