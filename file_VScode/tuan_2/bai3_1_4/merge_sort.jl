function merge!(arr, left::Int, mid::Int, right::Int)

    n1 = mid - left + 1

    n2 = right - mid

    L = Array{eltype(arr)}(undef, n1)

    R = Array{eltype(arr)}(undef, n2)


    for i in 1:n1

        L[i] = arr[left + i - 1]

    end

    for j in 1:n2

        R[j] = arr[mid + j]

    end


    i, j = 1, 1

    k = left

    while i <= n1 && j <= n2

        if L[i] <= R[j]

            arr[k] = L[i]

            i += 1

        else

            arr[k] = R[j]

            j += 1

        end

        k += 1

    end


    while i <= n1

        arr[k] = L[i]

        i += 1

        k += 1

    end

    while j <= n2

        arr[k] = R[j]

        j += 1

        k += 1

    end

end


function merge_sort!(arr, left::Int, right::Int)

    if left < right

        mid = div(left + right, 2)

        merge_sort!(arr, left, mid)

        merge_sort!(arr, mid+1, right)

        merge!(arr, left, mid, right)

    end

    return arr

end


# Test

using Random

Random.seed!(0)


arr = [5, 2, 9, 1, 5, 6]

merge_sort!(arr, 1, length(arr))

println("Kết quả Merge Sort: ", arr)

