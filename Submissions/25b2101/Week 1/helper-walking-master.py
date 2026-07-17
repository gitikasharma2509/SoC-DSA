n=int(input())
for i in range(n):
    a,b,c,d=map(int,input().split())
    y=d-b
    x=y-(c-a)
    if(y<0 or x<0):
        print("-1")
    else :
        print(x+y)    