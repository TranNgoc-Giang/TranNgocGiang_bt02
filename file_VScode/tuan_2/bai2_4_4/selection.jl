function selection_sort!(arr)

    n = length(arr)

    for i in 1:(n-1)

        # Tìm chỉ số của phần tử nhỏ nhất trong [i..n]

        min_index = i

        for j in (i+1):n

            if arr[j] < arr[min_index]

                min_index = j

            end

        end

        # Hoán đổi nếu min_index khác i

        if min_index != i

            arr[i], arr[min_index] = arr[min_index], arr[i]

        end

    end

    return arr

end


# Test

arr = [5, 2, 9, 1, 5]

selection_sort!(arr)

println("Ket qua sau Selection Sort: ", arr)