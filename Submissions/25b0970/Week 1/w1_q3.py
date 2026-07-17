m=int(input())
for i in range(m) :
    
    n,k=map(int,input().split())
    if n % 2 == 0:
        print("YES")
    elif k % 2 == 1 and k <= n:
        print("YES")
    else:
       print("NO") 

