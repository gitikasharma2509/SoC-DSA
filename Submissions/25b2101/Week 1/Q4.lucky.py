a=int(input())
for j in range(a):
    l, r = map(int, input().split())
    tmp=l
    max_luckyness=-1
    max_luckyness_num=0
    while tmp<=r and tmp>=l:
        luckyness=0
        max_num=0
        min_num=9
        tmp_1=tmp
        for i in range(len(str(tmp))):
            num=tmp_1%10
            min_num=min(num,min_num)    
            max_num=max(num,max_num)    
            tmp_1=tmp_1//10
        luckyness=max_num-min_num
        if luckyness==9:
            max_luckyness_num=tmp
            break
        else :
            if max_luckyness<luckyness:
                max_luckyness=luckyness
                max_luckyness_num=tmp
        tmp+=1
    print(max_luckyness_num)    