# Viết bằng Python
# Bài 10: Kiểm tra số nguyên tố (Trial Division).

import math

def is_prime(n):
    """Kiểm tra số nguyên tố"""
    if n <= 1:
        return False  # Số nhỏ hơn hoặc bằng 1 không phải số nguyên tố
    if n <= 3:
        return True  # 2 và 3 là số nguyên tố
    if n % 2 == 0 or n % 3 == 0:
        return False  # Số chia hết cho 2 hoặc 3 không phải số nguyên tố

    # Kiểm tra các số từ 5 đến √n với bước nhảy 6
    for i in range(5, int(math.sqrt(n)) + 1, 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False  # Nếu n chia hết cho i hoặc i+2 thì không phải số nguyên tố
    return True

# Ví dụ kiểm tra
num = 29
print(f"{num} là số nguyên tố: {is_prime(num)}")
