# My idea is that if the difference of r-l > 100, the luckiest number has luckiness 9,
# else luckiness needs to be found.
# However, since r-l < 100 in that case I am not caring about time complexity
def luckiness(num):
    num = str(num)
    max = 0
    min = 9
    for i in num:
        if int(i) > max:
            max = int(i)
        if int(i) < min:
            min = int(i)
        if max == 9 and min == 0:
            return 9
    return max-min

n = int(input())
for _ in range(n):
    l, r = map(int, input().split())
    if r-l>100:
        for i in range(100):
            if luckiness(l+i) == 9:
                print(l+i)
                break
    else:
        max_luck = 0
        for i in range(l, r+1):
            if luckiness(i) > max_luck:
                max_luck = luckiness(i)
                luckiest = i
        print(luckiest)
