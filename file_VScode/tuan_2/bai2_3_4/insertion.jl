function insertion_sort!(arr)

    n = length(arr)

    for i in 2:n

        key = arr[i]

        j = i - 1

        # Di chuyển các phần tử lớn hơn key sang phải

        while j >= 1 && arr[j] > key

            arr[j + 1] = arr[j]

            j -= 1

        end

        # Chèn key vào vị trí đúng

        arr[j + 1] = key

    end

    return arr

end


# Test

arr = [5, 2, 9, 1, 5]

insertion_sort!(arr)

println("Ket qua sau Insertion Sort: ", arr)

