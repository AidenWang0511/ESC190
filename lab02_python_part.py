def binary_search_deluxe(L, target):
    r_ans = None
    l_ans = None

    if target not in L:
        return "No answers, does not exist in list"

    #Finding first occurance
    left = 0
    right = len(L) - 1

    while left <= right:
        mid = (left + right)//2
        if L[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    l_ans = left

    #Finding last occurance
    left = l_ans
    right = len(L) - 1

    while left < right:
        mid = (left + right)//2

        if L[mid] == target and L[mid + 1] != target:
            return [l_ans, mid]
        elif L[mid] <= target:
            left = mid + 1
        else:
            right = mid - 1

    r_ans = right

    return [l_ans, r_ans]

binary_search_deluxe([1, 2, 3, 10, 10, 10,12, 12], 12)
