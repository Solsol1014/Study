coffee=10
while coffee:
    money=int(input("돈을 넣어주세요: "))
    if money>300:
        print("거스름돈을 반환합니다. %d원" %(money-300))
        print("커피를 줍니다.")
        coffee=coffee-1
        print("커피가 %d개 남았습니다." %coffee)
        money=0
    elif money==300:
        print("커피를 줍니다.")
        coffee=coffee-1
        print("커피가 %d개 남았습니다." %coffee)
    else:
        print("돈이 부족합니다. 돈을 반환합니다. %d원" %money)
        print("커피가 %d개 남았습니다." %coffee)
        money=0
print("커피가 다 떨어졌습니다. 판매를 중지합니다.")