def possible(k,n):
    x=0
    while x<=(n/2):
        if (n-(2*x))%k==0:
            return True
        else:
            x+=1
    return False


t=int(input())
arr_ans=[]
for i in range(t):
    n_k=list(map(int,input().split()))
    if(possible(n_k[1],n_k[0])):
        arr_ans.append('YES')
    else:
        arr_ans.append("NO")
for i in arr_ans:
    print(i)
