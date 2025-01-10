# Viết bằng Python
# Bài 2: Sinh chỉnh hợp (Permutation).

# Giải thích
# Chỉnh hợp (Permutation) là cách chọn ra r phần tử từ n phần tử mà có quan tâm đến thứ tự.

from itertools import permutations  # Sử dụng hàm permutations từ thư viện itertools.

def generate_permutations(arr, r): # Hàm sinh chỉnh hợp. 
    return list(permutations(arr, r)) # Trả về danh sách các chỉnh hợp.

# Ví dụ
arr = [1, 2, 3] # Tập hợp ban đầu.
r = 2 # Số phần tử của chỉnh hợp.
print("Chỉnh hợp:") 
for perm in generate_permutations(arr, r):  # Duyệt qua từng chỉnh hợp.
    print(perm)

# Kết quả
# Chỉnh hợp:
# (1, 2)
# (1, 3)
# (2, 1)
# (2, 3)
# (3, 1)
# (3, 2)
