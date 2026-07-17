n=int(input())
a=[int(x) for x in input().split()]
a.sort()
b=0
for i in range(0,n-1):
    if a[i]!=i+1:
        print(i+1)
        b=b+1
        break
if b==0:    print(n)