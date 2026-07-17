num = int(input())

for _ in range(num):
    flag  = False
    n, k = map(int, input().split())
    if k%2 == 0:
        if n%2 == 0:
            flag = True
    else:
        if n >= k:
            flag = True
    if flag:
        print('yES')
    else:
        print('no')