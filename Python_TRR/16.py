# Viết bằng Python
# Bài 16: Tính lũy thừa nhanh (Fast Exponentiation).    

def fast_exponentiation(a, b, mod):
    result = 1
    while b > 0:
        if b % 2 == 1:
            result = (result * a) % mod  # Nếu b lẻ, nhân thêm a
        a = (a * a) % mod  # Bình phương a
        b //= 2  # Chia b cho 2
    return result

print(fast_exponentiation(2, 10, 1000))  # Output: 24
