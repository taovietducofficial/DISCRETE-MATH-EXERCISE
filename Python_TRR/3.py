# Viết bằng Python
# Bài 3: Sinh tập con của một tập hợp.

# Giải thích: Sinh tập con là liệt kê tất cả các tập hợp con có thể từ một tập hợp cho trước.

from itertools import combinations # Sử dụng hàm combinations từ thư viện itertools.

def generate_subsets(arr): # Hàm sinh tập con. 
    n = len(arr) # Số phần tử của tập hợp.
    subsets = [] # Danh sách chứa tất cả các tập con.
    for r in range(n + 1): # Duyệt qua tất cả các số phần tử của tập con.
        subsets.extend(combinations(arr, r))
    return subsets

# Ví dụ
arr = [1, 2, 3] # Tập hợp ban đầu.
print("Tập con:") # In ra tập
for subset in generate_subsets(arr):
    print(subset)

# Kết quả
# Tập con:
# ()    
# (1,)
# (2,)
# (3,)
# (1, 2)
# (1, 3)
# (2, 3)
# (1, 2, 3)