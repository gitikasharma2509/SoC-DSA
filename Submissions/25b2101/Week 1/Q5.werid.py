def odd_f(x):
    return 3*x+1
def even_f(x):
    return x//2    
n=int(input())
print(n,end=" ")
while n!=1:
    if n%2==0:
        n=even_f(n)
    else:
        n=odd_f(n)
    print(n,end=" ")            