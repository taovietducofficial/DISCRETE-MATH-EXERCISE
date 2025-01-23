# Viết bằng Python
# Bài 9: Sinh phân hoạch số (Integer Partition).

def integer_partition(n): # Hàm sinh phân hoạch số 
    result = []

    def backtrack(start, target, path): # Hàm quay lui sinh phân hoạch số
        # Nếu tổng đạt giá trị n, lưu kết quả
        if target == 0: 
            result.append(path) # Lưu kết quả vào mảng result
            return
        # Thử từng số từ start đến target
        for i in range(start, target + 1): # Duyệt từ start đến target
            backtrack(i, target - i, path + [i]) 
            # Gọi đệ quy với start = i, target = target - i, path = path + [i]

    backtrack(1, n, []) # Gọi hàm backtrack với start = 1, target = n, path = []
    return result 

# Ví dụ
n = 5
print(f"Các phân hoạch của {n} là:") 
for partition in integer_partition(n): # Duyệt qua các phân hoạch của n và in ra màn hình
    print(partition)
