def partition(arr, low, high):

    pivot = arr[high]  # Chọn pivot là phần tử cuối

    i = low - 1        # Chỉ số nhỏ hơn pivot

    for j in range(low, high):

        if arr[j] <= pivot:

            i += 1

            arr[i], arr[j] = arr[j], arr[i]  # Hoán đổi arr[i] và arr[j]

    arr[i+1], arr[high] = arr[high], arr[i+1]  # Hoán đổi pivot vào vị trí đúng

    return i+1


def quick_sort(arr, low, high):

    if low < high:

        p = partition(arr, low, high)  # Tìm vị trí pivot

        quick_sort(arr, low, p-1)      # Sắp xếp phần bên trái của pivot

        quick_sort(arr, p+1, high)     # Sắp xếp phần bên phải của pivot


if __name__ == "__main__":

    arr = [5, 2, 9, 1, 5, 6]

    quick_sort(arr, 0, len(arr)-1)

    print("Kết quả Quick Sort:", arr)