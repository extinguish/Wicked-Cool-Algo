# implement the selection sort
# the method of which using to find out the smallest elements from the given list
def find_smallest(arr):
    smallest_index = 0
    samllest = arr[0]
    print len(arr)
    for i in range(1, len(arr)):
        if arr[i] < samllest:
            smallest = arr[i]
            smallest_index = i
            # print smallest_index
            # print smallest
    
    return smallest_index

def selection_sort(arr):
    sorted_arr = []
    for i in range(0, len(arr)):
        smallest = find_smallest(arr)
        # print smallest
        sorted_arr.append(arr.pop(smallest))
    
    return sorted_arr

# the test procdure
print selection_sort([5, 3, 6, 2, 10, -1, 100])