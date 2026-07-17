n = int(input())

def score(num):
    digits = [int(d) for d in str(num)]
    return max(digits) - min(digits)

for _ in range(n):

    a, b = map(int, input().split())

    best = a
    best_score = score(a)

    # check only limited range
    start = max(a, b - 100)

    for i in range(b, start - 1, -1):

        s = score(i)

        if s > best_score:
            best_score = s
            best = i

        if best_score == 9:
            break

    print(best)