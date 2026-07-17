n=int(input())
def fun(n):
    if n==1:
        print(1,end=" ")
    elif n%2==0:
        print(n,end=" ")
        fun(n//2)
    else:       
        print(n,end=" ")
        fun(3*n+1)

fun(n)
    
    
