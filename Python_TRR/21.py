# Viết bằng Python
# Bài 21: Tìm đường đi ngắn nhất (Dijkstra).

import heapq

def dijkstra(graph, start):
    # Số đỉnh
    n = len(graph)
    # Khoảng cách từ start đến các đỉnh
    dist = {i: float('inf') for i in range(n)}
    dist[start] = 0

    # Hàng đợi ưu tiên (ưu tiên đỉnh có khoảng cách nhỏ nhất)
    pq = [(0, start)]  # (khoảng cách, đỉnh)

    while pq:
        current_dist, u = heapq.heappop(pq)  # Lấy đỉnh có khoảng cách nhỏ nhất
        if current_dist > dist[u]:  # Nếu đã tìm được đường đi ngắn hơn, bỏ qua
            continue
        for v, weight in graph[u]:  # Duyệt các đỉnh kề
            distance = current_dist + weight
            if distance < dist[v]:  # Nếu tìm được đường đi ngắn hơn, cập nhật
                dist[v] = distance
                heapq.heappush(pq, (distance, v))

    return dist  # Trả về khoảng cách từ start đến tất cả các đỉnh

# Đồ thị dưới dạng danh sách kề
graph = {
    0: [(1, 4), (2, 1)],
    1: [(3, 1)],
    2: [(1, 2), (3, 5)],
    3: []
}

print(dijkstra(graph, 0))  # {0: 0, 1: 3, 2: 1, 3: 4}
