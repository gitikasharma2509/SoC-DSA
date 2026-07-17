def weird_algo(n):
    if n==1:
        return n
    else:
        if n%2==0:
            n=n/2 
            return n
        else:
            n=(3*n)+1
            return n


n=int(input())
print(n,end=' ')

while n!=1:
    n=weird_algo(n)
    print(int(n),end=' ')

    


