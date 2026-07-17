# So basically this algo has an array 'z' which has the max len of substring which is a prefix and suffix at the same time till that element.
# this func down calculate the z array
# Why use ? Time complexity is len(text) and not len(text) * len(pattern)
def Z_Array(s: str):
    n = len(s)
    z = [0] * n
    # left bound 'l' and right bound 'r'
    l = 0
    r = 0
    #the z box is the bounded box where the pattern repeats it-self 
    for i in range(1, n):
        # case 1 : outside the z box
        if i > r:
            l = r = i  # set up our new focus point to this location
            while (
                r < n and s[r] == s[r - l]
            ):  # check the elemnt one by one until mismatch is found
                r += 1
            z[i] = r - l
            r += -1# go back one step so to get matching box 
        else:
        #case 2: Inside the box
            k=i-l #position of the element we are checking 
            if z[k] < r - i + 1:
                # If it DOES NOT stretch past our window, we copy directly
                z[i]=z[k]
            else:
                # If it DOES stretch past our window, we copy what we can,
                l=i
                while r < n and string[r - l] == string[r]:
                    r += 1
                z[i] = r - l
                r -= 1
    return z

# Now what we do is make a new string parttern +"$"+text and use this func to get the z array . then iterate and find/count the index
# where the value equals the len(parttern)
# Why "$"? u can use any it should not be contained in the text .

def get_count(text: str, pattern: str):
    combined = pattern + "$" + text
    z = Z_Array(combined)
    count = 0
    for i in range(len(pattern) + 1, len(combined)):
        if z[i] == len(pattern):
            count += 1
    return count

text=input("Enter the text: ")
pattern=input("Enter the pattern: ")
print(get_count(text, pattern))