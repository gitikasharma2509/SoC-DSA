# How does this work basically it divide array into 3 sub-array one which has elements less than a pivot any number in that array, same and larger
#  then apply same func to these subarray and add them
def quick_sorter(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]

        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]

    return quick_sorter(left) + middle + quick_sorter(right)


array = [10, 52, 11, 36, 78, 12, 3, 95, 12, 12]
print(quick_sorter(array))
