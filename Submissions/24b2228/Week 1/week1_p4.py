def lucky_n(s,l):
    num=s
    old_value=0
    index_value=0
    for i in range(l-s+1):
        digit=list(map(int,str(num)))
        luck_value=max(digit)-min(digit)
        if(luck_value>=old_value):
            old_value=luck_value
            index_value=i
        num+=1
    return(s+index_value)

    

t=int(input())
output_ans=[]
for i in range(t): # for test cases
    s_l=list(map(int,input().split()))
    output_ans.append(lucky_n(s_l[0],s_l[1])) # function return luckies starship number
for i in output_ans:
    print(i)






    
