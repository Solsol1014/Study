import os

print(os.path.isfile("학원엑셀/df.xlsx"))
print(os.getcwd()+"\\df.xlsx")
print(os.path.isfile("E:\\프로그래밍\\pythonpractice\\test.txt"))
print(os.path.exists(os.getcwd()+"\\test.txt"))
# file=open("학원엑셀/excel/test.xlsx", "w")
# file.close()
print(os.path.isfile("학원엑셀/test.xlsx"))
for i in range(1, 11):
    print("-{} 주차 업무 보고".format(i))