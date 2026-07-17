# So bascially there what we do is campare the elemnt which are far apart not gap of 1 directly instaed bigger number and then decreasing i t
#  once we do the swap it checks if this number that is swap is samller than the one 'gap' index back
#  Until gap==1
def shellsorter(arr):
    n=len(arr)
    gap=n//2
    while gap>0:
        for i in range(gap,n):
            temp=arr[i]
            j=i
            while j>=gap and arr[j-gap]>temp:
                arr[j]=arr[j-gap]
                j=j-gap
            arr[j]=temp
        gap//=2
    return arr             

array=[10, 52, 11, 36, 78, 12, 3, 95, 12, 12]
print(shellsorter(array))