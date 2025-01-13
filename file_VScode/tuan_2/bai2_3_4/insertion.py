def insertion_sort(arr):

    n = len(arr)

    for i in range(1, n):

        key = arr[i]

        j = i - 1

        # Di chuyển các phần tử lớn hơn key sang phải

        while j >= 0 and arr[j] > key:

            arr[j + 1] = arr[j]

            j -= 1

        # Chèn key vào vị trí đúng

        arr[j + 1] = key


if __name__ == "__main__":

    arr = [5, 2, 9, 1, 5]

    insertion_sort(arr)

    print("Kết quả sau Insertion Sort:", arr)
    