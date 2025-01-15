# Viết bằng Python
# Bài 7: Số cách xếp n đồ vật vào k hộp.

from math import comb # Hàm comb(n, k) tính tổ hợp chập k của n

# Có thứ tự
def distribute_with_order(n, k): # n: số đồ vật, k: số hộp 
    return k**n

# Không có thứ tự
def distribute_without_order(n, k): # n: số đồ vật, k: số hộp 
    return comb(n + k - 1, k - 1) # Tổ hợp chập k-1 của n+k-1

# Ví dụ
n, k = 5, 3
print(f"Có thứ tự: {distribute_with_order(n, k)}") # 3^5 = 243
print(f"Không có thứ tự: {distribute_without_order(n, k)}") # C(5+3-1, 3-1) = C(7, 2) = 21


# Kết quả
# Có thứ tự: 243
# Không có thứ tự: 21