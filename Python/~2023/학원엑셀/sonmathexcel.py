import openpyxl
import os

test=""
schoolStudentscore={}

while 1:
    exceltrue=input("불러올 엑셀 파일이 있습니까? 있다면 Y, 없다면 N을 누르고 엔터를 눌러주세요: ")
    if exceltrue=="Y":
        while 1:
            print("뒤로 돌아가려면 Q를 입력하세요")
            excelname=input("불러올 엑셀 파일을 실행파일과 같은 폴더에 넣고 해당 파일의 이름을 입력하세요 (.xlsx 미포함): ")
            if excelname=="Q":
                break
            excellocation=excelname+".xlsx"
            if os.path.isfile(excellocation):
                print("잇슴ㅇㅇ")
                break
            print("파일명을 잘못 입력했거나, 해당 파일이 존재하지 않습니다. 다시 입력해주세요.")
        if excelname=="Q":
            continue
        break
    elif exceltrue=="N":
        file=open("test.xlsx", "w")
        print("새로운 파일을 만듭니다.")
        file.close()
        break
    print("잘못 입력하셨습니다.")

while 1:
    print("1. 성적 입력\n2. 입력된 성적 확인\n3. 입력된 데이터 수정\n4. 엑셀 파일로 저장\n5. 종료\n") #딕셔너리로 {학교:애들이름 성적 딕셔너리}
    menu=input("메뉴를 선택해주세요: ")

    if menu=="1":
        if test=="":
            test=input("시험 종류를 입력해주세요 (예: 2022년 1학기 기말고사): ")

        while 1:
            print("이미 입력한 학교에 학생을 더 추가하고 싶다면 학교이름을 정확히 똑같이 써야합니다. 정확하지 않다면 확인하고 와주세요.\n")
            school=input("입력하고 싶은 학교의 이름을 입력해주세요 (예: OO중), 그만 입력하고 싶다면 엔터를 눌러주세요: ")

            if school=="":
                break

            tempstudentdic={}
            print("그만 입력하고 싶다면 이름 입력에서 엔터를 눌러주세요\n")
            while 1:
                name=input("학생의 이름을 입력해주세요: ")
                if name=="":
                    break
                while 1:
                    score=input("학생의 성적을 입력해주세요: ")
                    if score=="" or not score.isdigit():
                        print("성적을 잘못 입력하셨습니다.")
                    else:
                        score=int(score)
                        break
                tempstudentdic[name]=score
            
            if tempstudentdic:
                if school in schoolStudentscore.keys():
                    for i, j in tempstudentdic.items():
                        schoolStudentscore[school][i]=j
                else:
                    schoolStudentscore[school]=tempstudentdic

        print(schoolStudentscore)
                
    elif menu=="2":
        for i in schoolStudentscore.keys():
            print(i,"\n")
            for j, k in schoolStudentscore[i].items():
                print("{}:{}점".format(j, k))
            print("\n")
        any=input("진행하려면 엔터키를 눌러주세요")

    elif menu=="3":
        while 1:
            findschool=input("수정할 학생의 학교를 입력해주세요: ")
            if findschool in schoolStudentscore.keys():
                break
            print("해당 학교는 존재하지 않습니다. 다시 입력해주세요.")
        
        while 1:
            findname=input("수정할 학생의 이름을 입력해주세요: ")
            if findname in schoolStudentscore[findschool].keys():
                break
            print("해당 학생은 존재하지 않습니다. 다시 입력해주세요.")

        while 1:
            print("1. {} 학생 삭제\n2. 성적 수정\n".format(findname))
            findmenu=input("메뉴를 선택해주세요: ")
            if findmenu=="1":
                del schoolStudentscore[findschool][findname]
                print("{} 학생의 성적이 삭제되었습니다.")
                break
            elif findmenu=="2":
                while 1:
                    score=input("수정할 점수를 입력하세요: ")
                    if score=="" or not score.isdigit():
                        print("성적을 잘못입력하셨습니다.")
                    else:
                        score=int(score)
                        break
                schoolStudentscore[findschool][findname]=score
                print("{} 학생의 성적이 수정되었습니다.".format(findname))
                break

    #elif menu=="4":

    elif menu=="5":
        break
    else:
        print("잘못 입력하셨습니다.\n")
        continue