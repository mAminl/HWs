#Question3

#definition of variables:
A0 = dict(zip(('a','b','c','d','e'),('1','2','3','4','5')))
A1 = range(10)
A2 = [i for i in A1 if i in A0]
A3 = sorted(A0[i] for i in A0)
A4 = [[i,i*i] for i in A1]
def printvars():
   #
   tmp = globals().copy()
   [print(k,'  :  ',v,' type:' ,type(v)) for k,
   v in tmp.items() if not k.startswith('_') and k!='tmp' and k!='In' and k!='Out' and not hasattr(v, '__call__')]
printvars()