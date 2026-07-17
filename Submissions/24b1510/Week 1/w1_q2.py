
a = str(input())
n = len(a)
max_substring = 0
current_substring = 1
for i in range(n-1):
    if a[i] == a[i+1]:
        current_substring += 1
        
    else:
        max_substring = max(max_substring, current_substring)
        current_substring = 1
max_substring = max(max_substring, current_substring)
print(max_substring)
 