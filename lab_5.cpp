#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "введите размер матрицы: ";
    cin >> n;
    int matrix[100][100];

    cout << "введите матрицу:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    //Алгоритм Флойда-Уоршелла
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix[i][j] | (matrix[i][k] && matrix[k][j]);
            }
        }
    }

    cout << "матрица достижимости:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
