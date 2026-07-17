n = int(input())

arr = [0] * n

nums = list(map(int, input().split()))

for a in nums:
    arr[a - 1] = a

for i in range(n):
    if arr[i] == 0:
        print(i + 1)
        break
