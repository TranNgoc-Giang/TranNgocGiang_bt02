def insertion_sort(arr, left, right):
    for i in range(left, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge(arr, left, mid, right):
    # Tạo hai mảng con từ mảng chính
    left_part = arr[left:mid + 1]
    right_part = arr[mid + 1:right + 1]

    i = j = 0  # Chỉ số cho mảng con trái và phải
    k = left   # Chỉ số cho mảng chính

    # Trộn hai mảng con
    while i < len(left_part) and j < len(right_part):
        if left_part[i] <= right_part[j]:
            arr[k] = left_part[i]
            i += 1
        else:
            arr[k] = right_part[j]
            j += 1
        k += 1

    # Sao chép các phần tử còn lại (nếu có) từ mảng trái
    while i < len(left_part):
        arr[k] = left_part[i]
        i += 1
        k += 1

    # Sao chép các phần tử còn lại (nếu có) từ mảng phải
    while j < len(right_part):
        arr[k] = right_part[j]
        j += 1
        k += 1

def merge_sort_hybrid(arr, left, right):
    if right - left + 1 < 10:
        insertion_sort(arr, left, right)
    elif left < right:
        mid = (left + right) // 2
        merge_sort_hybrid(arr, left, mid)
        merge_sort_hybrid(arr, mid + 1, right)
        merge(arr, left, mid, right)

# Hàm main để chạy thử
if __name__ == "__main__":
    arr = [12, 4, 5, 6, 7, 3, 1, 15, 2, 8, 10, 9]
    print("Mảng ban đầu:", arr)
    merge_sort_hybrid(arr, 0, len(arr) - 1)
    print("Mảng sau khi sắp xếp:", arr)
