# calculate the sum of given array in recursive format
def calculate_sum(list):
    if len(list) == 0:
        return 0
    elif len(list) == 1:
        return list[0]
    sum = list.pop()
    return sum + calculate_sum(list)

print calculate_sum([0, 2, 3, 4, 8, 90, -90, 100])

