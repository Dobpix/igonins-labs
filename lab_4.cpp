#include <iostream>
using namespace std;


int main() {
    
    int n;
    cout << "Введите количество вершин: ";
    cin >> n;
    int graph[100][100];
    int dist[100][100];
    int next[100][100];//для восстановления пути

    cout << "Введите матрицу смежности (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                dist[i][j] = 1000000;
                next[i][j] = -1;
            } else {
                dist[i][j] = graph[i][j];
                next[i][j] = j;
            }
        }
    }

    // Алгоритм Флойда–Уоршелла
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    int start, end;
    cout << "Введите начальную вершину (0 - " << n - 1 << "): ";
    cin >> start;
    cout << "Введите конечную вершину (0 - " << n - 1 << "): ";
    cin >> end;


    if (next[start][end] == -1) {
        cout << "Путь не существует.\n";
        return 0;
    }


    cout << "Кратчайший путь: ";
    int v = start;
    while (v != end) {
        cout << v << " -> ";
        v = next[v][end];
    }
    cout << end << "\n";

    cout << "Суммарная стоимость пути: " << dist[start][end] << "\n";

    return 0;
}