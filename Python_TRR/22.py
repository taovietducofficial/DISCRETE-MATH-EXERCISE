# Viết bằng Python
# Bài 22: Thuật toán Bellman-Ford

def bellman_ford(graph, V, E, src): 
# V: số đỉnh, E: danh sách các cạnh (u, v, w) với u, v là đỉnh đầu, cuối, w là trọng số
    dist = [float('inf')] * V # Khoảng cách từ src đến các đỉnh
    dist[src] = 0 # Khoảng cách từ src đến chính nó là 0

    # Lặp V-1 lần
    for _ in range(V - 1): # V-1 lần lặp để cập nhật khoảng cách từ src đến các đỉnh
        for u, v, w in E: # Duyệt qua tất cả các cạnh
            if dist[u] != float('inf') and dist[u] + w < dist[v]: 
            # Nếu tìm được đường đi ngắn hơn, cập nhật
                dist[v] = dist[u] + w

    # Kiểm tra chu trình âm
    for u, v, w in E: # Duyệt qua tất cả các cạnh để kiểm tra chu trình âm
        if dist[u] != float('inf') and dist[u] + w < dist[v]: 
            print("Đồ thị chứa chu trình âm")
            return

    return dist # Trả về khoảng cách từ src đến tất cả các đỉnh

V = 5
edges = [(0, 1, -1), (0, 2, 4), (1, 2, 3), (1, 3, 2), (1, 4, 2), (3, 2, 5), (3, 1, 1), (4, 3, -3)]
print(bellman_ford({}, V, edges, 0))
