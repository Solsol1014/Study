sub_score={}

while(1):
    subject=input("과목을 입력하세요: ")
    score=int(input("해당 과목의 성적을 입력하세요: "))

    sub_score[subject]=score
    # list_subjects=list(sub_score.keys())
    list_scores=list(sub_score.values())

    # i=0

    # while(i<len(list_subjects)):
    #     print(list_subjects[i], "-", list_scores[i])
    #     i+=1
    for (key, value) in list(sub_score.items()):
        print(key, "-", value)

    exit=input("입력한 과목들의 평균을 구하려면 q를 누르세요, 계속하려면 아무키나 누르세요: ")
    if (exit=='q'):
        break

sum=0
while(list_scores):
    sum+=list_scores.pop()

average=sum/len(list(sub_score.keys()))

print("입력한 과목들의 평균 점수는 %.2f점 입니다." %average)