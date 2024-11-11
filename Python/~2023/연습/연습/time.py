second=int(input())

days= second//86400
hour= second%86400//3600
minute=second%3600//60
second_f=second%60

print("%d days %d:%d:%02d" %(days, hour, minute, second_f)) 