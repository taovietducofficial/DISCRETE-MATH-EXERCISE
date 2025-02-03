// Viết bằng C
// Bài 21: Tìm đường đi ngắn nhất (Dijkstra).

#include <stdio.h>
#include <limits.h>

#define INF INT_MAX // Định nghĩa INF = INT_MAX 
#define V 4 // Định nghĩa V = 4 

int minDistance(int dist[], int visited[])  // Hàm tìm đường đi ngắn nhất
{
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) 
        {
            min = dist[v], min_index = v;
        }
    return min_index;
}

void dijkstra(int graph[V][V], int src)  // Hàm Dijkstra 
{
    int dist[V], visited[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INF; // Khởi tạo dist[i] = INF 
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)  // Vòng lặp từ 0 đến V - 1 
    {
        int u = minDistance(dist, visited); // Gán u = minDistance(dist, visited)
        visited[u] = 1;

        for (int v = 0; v < V; v++)  // Vòng lặp từ 0 đến V 
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])  
            // Nếu không visited[v] và graph[u][v] và dist[u] != INF và dist[u] + graph[u][v] < dist[v]
            {
                dist[v] = dist[u] + graph[u][v]; // Gán dist[v] = dist[u] + graph[u][v]
            }
        }
    }

    for (int i = 0; i < V; i++) // Vòng lặp từ 0 đến V 
        printf("Khoảng cách từ %d đến %d: %d\n", src, i, dist[i]);
}

int main()  
{
    int graph[V][V] = 
    {
        {0, 4, 1, 0},
        {0, 0, 2, 1},
        {0, 0, 0, 5},
        {0, 0, 0, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
