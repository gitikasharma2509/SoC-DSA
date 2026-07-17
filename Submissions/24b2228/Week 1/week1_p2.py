n=input()
rep_max=1
old_rep=1

for i in range(1,len(n)):
    
    if n[i]==n[i-1]:
        rep_max+=1
        if (i==len(n)-1) and (rep_max>old_rep):
            old_rep=rep_max
    else:
        if(rep_max>old_rep):
            old_rep=rep_max
            rep_max=1
        else:
            rep_max=1
print(old_rep)


