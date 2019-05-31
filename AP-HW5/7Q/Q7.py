import math
a = list(map(int,input(). split()))
print(a)
strings = [x for x in a if x%6==0 and (a.index(x)+1)%6==0]
print(sorted(set(strings)))

