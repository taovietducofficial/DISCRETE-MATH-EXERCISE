# Viết băng Python
# Bài 11: Thuật toán Sàng Eratosthenes.

def sieve_of_eratosthenes(n):
    """Tìm tất cả các số nguyên tố nhỏ hơn hoặc bằng n."""
    primes = [True] * (n + 1)  # Tạo mảng đánh dấu, mặc định là True
    primes[0] = primes[1] = False  # 0 và 1 không phải số nguyên tố

    p = 2
    while p * p <= n:
        if primes[p]:  # Nếu p là số nguyên tố
            for i in range(p * p, n + 1, p):  # Đánh dấu các bội số của p
                primes[i] = False
        p += 1

    # Trả về danh sách các số nguyên tố
    return [i for i in range(n + 1) if primes[i]]

print(sieve_of_eratosthenes(30))  # Ví dụ: Tìm số nguyên tố <= 30