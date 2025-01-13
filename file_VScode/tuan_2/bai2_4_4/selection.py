def selection_sort(arr):

    n = len(arr)

    for i in range(n - 1):

        # Tìm chỉ số của phần tử nhỏ nhất trong [i..n-1]

        min_index = i

        for j in range(i + 1, n):

            if arr[j] < arr[min_index]:

                min_index = j

        # Hoán đổi nếu min_index khác i

        if min_index != i:

            arr[i], arr[min_index] = arr[min_index], arr[i]


if __name__ == "__main__":

    arr = [5, 2, 9, 1, 5]

    selection_sort(arr)

    print("Kết quả sau Selection Sort:", arr)