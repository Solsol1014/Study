#실패 - 정답 봤음 2407130522

import copy

count = int(input())

times = []
for i in range(0, count):
    temp = input()
    temp1, temp2 = temp.split()
    times.append((int(temp1), int(temp2)))

schedules = []
sametime = 0
max = 0
i = 1
for time in times:
    if time[0]!=time[1]:
        if len(schedules)>0:
            appendSchedule = []
            for schedule in schedules:
                if len(schedule) + count - i + 1 > max:
                    canAppend = True
                    for confirmed in schedule:
                        if time[1] <= confirmed[0] or time[0] >= confirmed[1]:
                            canAppend = True
                        else:
                            canAppend = False
                            break
                    
                    if canAppend:
                        temp = copy.deepcopy(schedule)
                        appendSchedule.append(temp)
                        schedule.append(time)
                        if len(schedule) > max:
                            max = len(schedule)
                else:
                    schedules.pop(i-1)
            
            schedules.extend(appendSchedule)
            if max < count - i + 1:
                schedules.append([time])
        else:
            schedules.append([time])
            max = 1
    else:
        sametime += 1
    
    # for schedule in schedules:
    #     print(schedule)
    # print('---------------')
    
    i += 1

print(max+sametime)