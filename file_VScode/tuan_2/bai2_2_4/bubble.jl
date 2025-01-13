function bubble_sort!(arr)

    n = length(arr)

    for i in 1:(n-1)

        swapped = false

        for j in 1:(n-i)

            if arr[j] > arr[j+1]

                # Hoán đổi

                arr[j], arr[j+1] = arr[j+1], arr[j]

                swapped = true

            end

        end

        # Nếu không có hoán đổi nào, mảng đã được sắp xếp

        if !swapped

            break

        end

    end

    return arr

end


# Test

arr = [5, 2, 9, 1, 5]

bubble_sort!(arr)

println("Ket qua sau Bubble Sort: ", arr)