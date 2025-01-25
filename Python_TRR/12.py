# Viết bằng Python
# Bài 12: Phân tích một số thành tích các thừa số nguyên tố.

def prime_factorization(n):  # Hàm phân tích số nguyên n thành các thừa số nguyên tố
    
    factors = [] # Danh sách chứa các thừa số nguyên tố
    i = 2
    while i * i <= n:  # Duyệt từ 2 đến √n
        while n % i == 0:  # Nếu i là ước của n
            factors.append(i)
            n //= i  # Giảm n
        i += 1
    if n > 1:  # Nếu còn thừa số lớn hơn √n
        factors.append(n) # Thêm vào danh sách thừa số
    return factors

print(prime_factorization(84))  # Phân tích 84

