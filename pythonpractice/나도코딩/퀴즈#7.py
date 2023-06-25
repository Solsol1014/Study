for i in range(1,51):
    with open('나도코딩/퀴즈7/{}주차.txt'.format(i), 'w', encoding="utf8") as report_file:
        report_file.write("-{}주차 주간보고-\n".format(i))
        report_file.write("부서 : \n이름 : \n업무 요약 : ")