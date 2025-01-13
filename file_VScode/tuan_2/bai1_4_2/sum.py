def sum_1_to_n(n):

    s = 0

    for i in range(1, n+1):

        s += i

    return s


if __name__ == "__main__":

    n = int(input("Nhap n: "))

    result = sum_1_to_n(n)

    print("Tong 1..n =", result)
