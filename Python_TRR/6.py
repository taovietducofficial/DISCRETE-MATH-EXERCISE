# Viết bằng Python
# Bài 6: Sinh hoán vị của một dãy số.

# Hoán vị là cách sắp xếp lại các phần tử trong một dãy số theo thứ tự khác nhau.

from itertools import permutations # import hàm permutations từ thư viện itertools

def generate_permutations(arr): # hàm sinh hoán vị của một dãy số
    return list(permutations(arr)) # trả về danh sách các hoán vị của dãy số

# Ví dụ
arr = [1, 2, 3] # dãy số cần sinh hoán vị
print("Hoán vị của", arr, "là:") 
for perm in generate_permutations(arr): # duyệt qua từng hoán vị và in ra m
    print(perm)

# Giải thích:
# Sử dụng itertools.permutations để tạo tất cả các hoán vị.
# Kết quả trả về là một danh sách các tuple, mỗi tuple là một hoán vị của arr.