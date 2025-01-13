function sum_1_to_n(n)

    s = 0

    for i in 1:n

        s += i

    end

    return s

end


println("Nhap n:")

n = parse(Int, readline())

result = sum_1_to_n(n)

println("Tong 1..n = ", result)