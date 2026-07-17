s=str(input())
set_dna=set({})
tmp_len=0
if len(s)==1:
    print(1)
else:
    for i in range(0,len(s)-1):
        if s[i]==s[i+1]:
            tmp_len+=1
        if s[i]!=s[i+1]:
            tmp_len=0   
        set_dna.add(tmp_len)     
    print(max(set_dna)+1)        