function partition!(arr, low::Int, high::Int)

    pivot = arr[high]      # Chọn pivot là phần tử cuối

    i = low - 1            # Chỉ số nhỏ hơn pivot

    for j in low:(high-1)

        if arr[j] <= pivot

            i += 1

            arr[i], arr[j] = arr[j], arr[i]  # Hoán đổi arr[i] và arr[j]

        end

    end

    arr[i+1], arr[high] = arr[high], arr[i+1]  # Hoán đổi pivot vào vị trí đúng

    return i+1  # Vị trí của pivot

end


function quick_sort!(arr, low::Int, high::Int)

    if low < high

        p = partition!(arr, low, high)  # Tìm vị trí pivot

        quick_sort!(arr, low, p-1)      # Sắp xếp phần bên trái của pivot

        quick_sort!(arr, p+1, high)     # Sắp xếp phần bên phải của pivot

    end

    return arr

end


# Test

arr = [5, 2, 9, 1, 5, 6]

quick_sort!(arr, 1, length(arr))  # Julia đánh chỉ số từ 1

println("Kết quả Quick Sort: ", arr)