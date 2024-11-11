for i in range(0, 10) :
    buildingnum = int(input())
    b = input()

    heightstrlist = b.split()
    heightlist = []
    
    for j in heightstrlist :
        heightlist.append(int(j))
        
    view = 0
    
    #메모리 많이 먹으면 첫번째 if에 두개 다 박아넣기    
    for j in range(2, buildingnum-2) :
        left = 0
        right = 0
        
        if heightlist[j]>heightlist[j-1]:
            left1 = heightlist[j] - heightlist[j-1]
            
            if heightlist[j]>heightlist[j-2]:
                left2 = heightlist[j] - heightlist[j-2]
                if left1>left2:
                    left = left2
                else:
                    left = left1
                
                if heightlist[j]>heightlist[j+1]:
                    right1 = heightlist[j]-heightlist[j+1]
                    
                    if heightlist[j]>heightlist[j+2]:
                        right2 = heightlist[j]-heightlist[j+2]
                        if right1>right2:
                            right = right2
                        else:
                            right = right1
        
        if left>0 and right>0:
            if left>right:
                view += right
            else:
                view += left
    
    print(f'#{i+1} {view}')