// Viết bằng C
// Bài 22: Thuật toán Bellman-Ford

#include <stdio.h>
#include <limits.h>

#define INF INT_MAX // Khai báo vô cùng
#define V 5 // số đỉnh của đồ thị   
#define E 8 // số cạnh  của đồ thị

void bellmanFord(int graph[E][3], int src) 
{
    int dist[V]; // Khoảng cách ngắn nhất từ src đến các đỉnh
    for (int i = 0; i < V; i++) dist[i] = INF; // Khởi tạo khoảng cách từ src đến các đỉnh là vô cùng
    dist[src] = 0; // Khoảng cách từ chính nó đến chính nó là 0

    for (int i = 0; i < V - 1; i++)  // Lặp V-1 lần
    {
        for (int j = 0; j < E; j++)  // Duyệt qua tất cả các cạnh
        {
            int u = graph[j][0], v = graph[j][1], w = graph[j][2];
            if (dist[u] != INF && dist[u] + w < dist[v])  // Nếu có cách đi ngắn hơn
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++)  // Kiểm tra chu trình âm
    {
        int u = graph[j][0], v = graph[j][1], w = graph[j][2];
        if (dist[u] != INF && dist[u] + w < dist[v])  // Nếu có cách đi ngắn hơn
        {
            printf("Đồ thị chứa chu trình âm\n");
            return;
        }
    }

    for (int i = 0; i < V; i++)  // In ra khoảng cách từ src đến các đỉnh
    {
        printf("Khoảng cách từ %d đến %d: %d\n", src, i, dist[i]);
    }
}

int main() 
{
    int edges[E][3] = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    bellmanFord(edges, 0);
    return 0;
}
