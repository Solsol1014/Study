class Fourcal:
    def setdata(self, first, second):
        self.first=first
        self.second=second
    
    def add(self):
        result=self.first+self.second
        return result
    
    def sub(self):
        result=self.first-self.second
        return result
    
    def mul(self):
        result=self.first*self.second
        return result

    def div(self):
        result=self.first/self.second
        return result

a=Fourcal()
b=Fourcal()

a.setdata(3, 4)
b.setdata(2, 1)

print(a.add())
print(b.add())
print(a.sub())
print(b.sub())
print(a.mul())
print(b.mul())
print(a.div())
print(b.div())

#self.객체변수(멤버변수)는 대충 클래스용 전역변수라고 생각하면 될듯. 객체마다 내가 정한대로
#설정되는데 범위는 클래스 전체인 ㅇㅇ
#근데 클래스변수 뭐 class 안에 그냥 PI=3.14같이 정의해놓는 애들은 C로 따지면 #include PI 3.14
#랑 비슷한 애인듯 그니까 얘는 내가 미리 클래스에 정해놓은 고정값인거지 객체마다 못바꾸는 ㅇㅇ 근데
#객체마다 못바꾸는거지 또 그냥 외부에서는 바꿀수있네 하긴 변수는 변수니까