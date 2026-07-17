# Two solution one by sorting and other by sum (sum is better)
n=int(input())
arr=list(map(int, input().split()))
# arr.sort()
# found=False
# for i in range(0,len(arr)):
#     if (arr[i] != i + 1):
#         print(i+1)
#         break
#     if not found and i == len(arr) - 1:
#         print(n)
sum=0
for i in range(0, len(arr)):
    sum += arr[i]
print((n * (n + 1)) // 2 - sum)