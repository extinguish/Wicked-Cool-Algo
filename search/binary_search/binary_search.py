# the basic algorithm using to demonstrate the binary search 
def binary_search(list, target):
    value = 0;
    low = 0
    high = len(list) - 1
    while low <= high:
        mid = (low + high) / 2
        guess = list[mid]
        if guess == target:
            value = mid
            break
        if guess > target:
            high = mid -1
        else:
            low = mid + 1
    if value == 0:
        return None
    else :
        # the comment
        return value + 1 # the final value we get are the index of the element that we need to find out, and this index are human-readable format

test_list = [1, 2, 49, 79, 100, 123]

print binary_search(test_list, 79)
print binary_search(test_list, 2)
print binary_search(test_list, 129)






