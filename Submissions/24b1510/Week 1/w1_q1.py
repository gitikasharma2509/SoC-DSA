n = int(input())
a = list(map(int, input().split()))
ideal_sum = n*(n+1)//2
real_sum = sum(a)
missing_number = ideal_sum - real_sum
print(missing_number)
