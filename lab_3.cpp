#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int sizeA, sizeB;
    set<string> setA, setB;

    cout << "введите кол-во элементов множества A: ";
    cin >> sizeA;
    cout << "введите элементы множества A:\n";
    for (int i = 0; i < sizeA; ++i) {
        string element;
        cin >> element;
        setA.insert(element);
    }


    cout << "введите кол-во элементов множества B: ";
    cin >> sizeB;
    cout << "введите элементы множества B:\n";
    for (int i = 0; i < sizeB; ++i) {
        string element;
        cin >> element;
        setB.insert(element);
    }


    int n;
    cout << "введите количество пар в отношении: ";
    cin >> n;

    map<string, string> relation;
    bool isFunction = true;

    cout << "введите пары отношения (через пробел):\n";

    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;

        if (!setA.count(a) || !setB.count(b)) {
            cout << "ошибка!!! пара " << a << " " << b << " содержит элемент вне заданных множеств.\n";
            isFunction = false;
            break;
        }

        if (relation.count(a)) {
            if (relation[a] != b) {
                isFunction = false;
            }
        } else {
            relation[a] = b;
        }
    }

    for (auto& element : setA) {
        if (!relation.count(element)) {
            cout << "Ошибка!!! элемент " << element << " из множества A не имеет соответствующего элемента в B.\n";
            isFunction = false;
            break;
        }
    }
    

    if (isFunction) {
        cout << "функция.\n";
    } else {
        cout << "не функция.\n";
    }
    return 0;
}
