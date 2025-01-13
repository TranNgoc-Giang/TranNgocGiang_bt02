def partition(arr, low, high):
    pivot = arr[high]  # Chọn phần tử cuối làm pivot
    i = low - 1  # Chỉ số của phần tử nhỏ hơn pivot
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Hoán đổi các phần tử
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Đưa pivot về đúng vị trí
    return i + 1

def insertion_sort(arr, low, high):
    for i in range(low, high + 1):
        key = arr[i]
        j = i - 1
        while j >= low and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def quick_sort_hybrid(arr, low, high):
    while low < high:
        if high - low + 1 < 10:
            insertion_sort(arr, low, high)
            break
        else:
            p = partition(arr, low, high)
            quick_sort_hybrid(arr, low, p - 1)  # Đệ quy với đoạn trái
            low = p + 1  # Tiếp tục đoạn phải (thay vì đệ quy để tối ưu stack)

# Hàm main để chạy thử
if __name__ == "__main__":
    arr = [12, 4, 5, 6, 7, 3, 1, 15, 2, 8, 10, 9]
    print("Mảng ban đầu:", arr)
    quick_sort_hybrid(arr, 0, len(arr) - 1)
    print("Mảng sau khi sắp xếp:", arr)
