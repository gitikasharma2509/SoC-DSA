a=int(input())
for i in range(a):
    n, k = map(int, input().split())
    if (n%2==0):
        print("YES")
    else:
        if (k%2==0):
            print("NO")
        else:
            print("Yes")        