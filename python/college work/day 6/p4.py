def calculate_mean(lst):
    return sum(lst) / len(lst)
def calculate_median(lst):
    sorted_lst = sorted(lst)
    n = len(sorted_lst)
    mid = n // 2
    if n % 2 == 0:
        return (sorted_lst[mid - 1] + sorted_lst[mid]) / 2
    else:
        return sorted_lst[mid]
def calculate_mode(lst):
    frequency = {}
    for item in lst:
        frequency[item] = frequency.get(item, 0) + 1
    max_freq = max(frequency.values())
    mode = [key for key, val in frequency.items() if val == max_freq]
    return mode
L = [4, 1, 4, 10, 7, 6, 2, 6, 10, 3, 10, 1, 4, 5, 10, 7, 1, 8, 6, 5]
print("List is:", L)
print("Mean / Average is:", calculate_mean(L))
print("Median is:", calculate_median(L))
print("Mode is:", calculate_mode(L))