# Viết bằng Python
# Bài 4: Tính giai thừa bằng đệ quy.

def factorial(n): # Đệ quy là một kỹ thuật lập trình mà một hàm gọi chính nó.
    if n == 0 or n == 1: # Điều kiện dừng của đệ quy.
        return 1 # Giai thừa của 0 và 1 là 1.
    return n * factorial(n - 1) # Gọi đệ quy để tính giai thừa của n.

# Ví dụ
n = 5
print(f"Giai thừa của {n} là: {factorial(n)}") 

# Kết quả
# Giai thừa của 5 là: 120