def age(dogage):
    return 24+(dogage-2)*4

dogage=int(input("Put dog's age: "))

print(str(dogage)+' dog years is equivalent to '+str(age(dogage))+' human years.')
