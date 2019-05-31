#Question4
import random
import math
#Check random point is in circle or not
def IsInCircle(x,y):
    if (x*x + y*y <= 1):
        return 1;
    else:
        return 0;
#Make random point and count inner points
def MakePoint(t):
    InnerPoint = 0;
    for i in range(t):
        x = random.random()*2 -1;
        y = random.random()*2 -1;
        if IsInCircle(x, y):
            InnerPoint = InnerPoint + 1;
    return InnerPoint
#calculate pi number
def find(e):
    t=10;
    I = MakePoint(t);
    MyPi = 4 * I / t;
    while(abs(math.pi - MyPi)>e):
        t = t + 1;
        I = MakePoint(t)
        MyPi = 4*I/t;
    #print("number of Iterations: " + str(t))
    #print("calculated Pi: " + str(MyPi))
    #print("Error: " + str(abs(math.pi - MyPi)*100) + "%")
    return MyPi
num = int(input("Please Enter number of effort:"))
A = 0
#calculate average of pi's
for i in range(num):
    A = A + find(0.01)
print(A/num)
