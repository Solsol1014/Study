#답보고 - 2407142241
import sys

count = int(sys.stdin.readline().strip())

times = []
for i in range(0, count):
    temp = sys.stdin.readline().strip()
    temp1, temp2 = temp.split()
    times.append((int(temp1), int(temp2)))

times.sort(key=lambda x : (x[1], x[0]))

max = 1
end = times[0][1]
times.pop(0)

for time in times:
    if time[0]>=end:
        end = time[1]
        max += 1

print(max)