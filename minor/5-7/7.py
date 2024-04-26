from math import trunc
c=int(input('podaj c:'))
print(-1 if c<=0 else (0 if c<10 else (1 if c<100 else (2 if trunc(c/100)%2==0 else 3))))