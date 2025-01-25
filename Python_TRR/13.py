# Viết bằng Python
# Bài 13: Tìm ước chung lớn nhất (GCD) và bội chung nhỏ nhất (LCM).

from math import gcd # import hàm gcd từ thư viện math

def lcm(a, b):
    return a * b // gcd(a, b) # LCM = a * b / GCD của a và b

print("GCD:", gcd(12, 18))  # GCD của 12 và 18
print("LCM:", lcm(12, 18))  # LCM của 12 và 18
