#include <iostream>
#include <vector>

using namespace std;

bool is_valid_matrix(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i].size() != n) {
            return false;
        } else {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0 && matrix[i][j] != 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool is_reflexive(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] != 1) {
            return false;
        }
    }
    return true;
}

bool is_symmetric(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool is_antisymmetric(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool is_transitive(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) {
                for (int k = 0; k < n; k++) {
                    if (matrix[j][k] && !matrix[i][k]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Введите матрицу:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    if (!is_valid_matrix(matrix, n)) {
        cout << "Некорректная матрица\n";
        return 1;
    }

    cout << "Свойства отношения:\n";
    cout << "Рефлексивность: " << (is_reflexive(matrix, n) ? "да" : "нет") << endl;
    cout << "Симметричность: " << (is_symmetric(matrix, n) ? "да" : "нет") << endl;
    cout << "Кососимметричность: " << (is_antisymmetric(matrix, n) ? "да" : "нет") << endl;
    cout << "Транзитивность: " << (is_transitive(matrix, n) ? "да" : "нет") << endl;

    return 0;
}
