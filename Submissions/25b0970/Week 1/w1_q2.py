n=input()
a=len(n)
c=0
i=0
j=0
while i<a:
    b=1
    j=i+1
    while j<a:
 
        if n[i]==n[j]:
            b=b+1 
            c=max(c,b)
            j=j+1
            
        else:
            c=max(c,b)
            break
    i=j
    if a==1:
        c=1
print(c)
