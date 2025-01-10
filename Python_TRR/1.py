# Viết bằng Python
# Bài 1: VSinh tổ hợp (Combination).

# Giải thích: Tổ hợp (Combination) là cách chọn ra r phần tử từ n phần tử mà không quan tâm đến thứ tự.

from itertools import combinations # Sử dụng hàm combinations từ thư viện itertools.

def generate_combinations(arr, r): # Hàm sinh tổ hợp. 
    return list(combinations(arr, r)) # Trả về danh sách các tổ hợp.

# Ví dụ sử dụng
arr = [1, 2, 3, 4] # Tập hợp ban đầu.
r = 2 # Số phần tử của tổ hợp.
print("Tổ hợp:")
for comb in generate_combinations(arr, r):
    print(comb)

# Kết quả
# Tổ hợp:
# (1, 2)
# (1, 3)
# (1, 4)
# (2, 3)
# (2, 4)
# (3, 4)