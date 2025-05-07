#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>


using namespace std;

// Определение структуры для хранения элемента множества
struct Element {
    char letter;        // буква
    char digit1;        // любая цифра
    char digit2;        // любая цифра
    char digit3;        // четная цифра
};

bool isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    if (c >= 'А' && c <= 'Я') {
        return true;
    }
    if (c >= 'а' && c <= 'я') {
        return true;
    }
    return false;
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isEvenDigit(char c) {
    return isDigit(c) && ((c - '0') % 2 == 0);
}

//ввод
void inputSet(vector<Element>& set, int size, const string& setName) {
    for (int i = 0; i < size; ++i) {
        Element elem;
        string input;
        bool valid = false;

        while (!valid) {
            cout << "Введите элемент " << setName << " (формат буква, цифра, цифра, четная цифра) номер " << i + 1 << ": ";
            cin >> input;

            if (input.length() == 4) {
                if (isLetter(input[0]) &&
                    isDigit(input[1]) &&
                    isDigit(input[2]) &&
                    isEvenDigit(input[3])) {

                    elem.letter = input[0];
                    elem.digit1 = input[1];
                    elem.digit2 = input[2];
                    elem.digit3 = input[3];
                    valid = true;
                }
            }

            if (!valid) {
                cout << "Ошибка ввода\n";
            }
        }

        set.push_back(elem);
    }
}
//вывод
void printSet(const vector<Element>& set, const string& setName) {
    cout << "Множество " << setName << ":\n";
    for (size_t i = 0; i < set.size(); ++i) {
        cout << set[i].letter << set[i].digit1 << set[i].digit2 << set[i].digit3 << " ";
    }
    cout << endl;
}

//равенство элементов
bool areElementsEqual(const Element& a, const Element& b) {
    return a.letter == b.letter &&
        a.digit1 == b.digit1 &&
        a.digit2 == b.digit2 &&
        a.digit3 == b.digit3;
}
//удаление дубликатов
void removeDuplicates(vector<Element>& set) {
    vector<Element> uniqueSet;

    for (size_t i = 0; i < set.size(); ++i) {
        bool isDuplicate = false;

        for (size_t j = 0; j < uniqueSet.size(); ++j) {
            if (areElementsEqual(set[i], uniqueSet[j])) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            uniqueSet.push_back(set[i]);
        }
    }

    set = uniqueSet;
}

//объединение
vector<Element> unionSets(const vector<Element>& setA, const vector<Element>& setB) {
    vector<Element> result = setA;

    for (size_t i = 0; i < setB.size(); ++i) {
        bool isDuplicate = false;

        for (size_t j = 0; j < result.size(); ++j) {
            if (areElementsEqual(setB[i], result[j])) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            result.push_back(setB[i]);
        }
    }

    return result;
}

//пересечение
vector<Element> intersectSets(const vector<Element>& setA, const vector<Element>& setB) {
    vector<Element> result;


    for (size_t i = 0; i < setA.size(); ++i) {
        for (size_t j = 0; j < setB.size(); ++j) {
            if (areElementsEqual(setA[i], setB[j])) {
                bool isDuplicate = false;

                for (size_t k = 0; k < result.size(); ++k) {
                    if (areElementsEqual(setA[i], result[k])) {
                        isDuplicate = true;
                        break;
                    }
                }

                if (!isDuplicate) {
                    result.push_back(setA[i]);
                }
                break;
            }
        }
    }

    return result;
}

//дополнение
vector<Element> complementSets(const vector<Element>& setA, const vector<Element>& setB) {
    vector<Element> result;

    for (size_t i = 0; i < setA.size(); ++i) {
        bool isInB = false;

        for (size_t j = 0; j < setB.size(); ++j) {
            if (areElementsEqual(setA[i], setB[j])) {
                isInB = true;
                break;
            }
        }

        if (!isInB) {
            result.push_back(setA[i]);
        }
    }

    return result;
}

//симметрическая разность
vector<Element> symmetricDifference(const vector<Element>& setA, const vector<Element>& setB) {
    vector<Element> AminusB = complementSets(setA, setB);
    vector<Element> BminusA = complementSets(setB, setA);

    return unionSets(AminusB, BminusA);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int sizeA, sizeB;
    vector<Element> setA, setB;

    cout << "Введите размер множества A: ";
    cin >> sizeA;
    inputSet(setA, sizeA, "A");

    cout << "Введите размер множества B: ";
    cin >> sizeB;
    inputSet(setB, sizeB, "B");

    removeDuplicates(setA);
    removeDuplicates(setB);

    printSet(setA, "A");
    printSet(setB, "B");

    vector<Element> unionAB = unionSets(setA, setB);
    vector<Element> intersectAB = intersectSets(setA, setB);
    vector<Element> complementAB = complementSets(setA, setB);
    vector<Element> complementBA = complementSets(setB, setA);
    vector<Element> symDiffAB = symmetricDifference(setA, setB);

    printSet(unionAB, "Объединение A и B");
    printSet(intersectAB, "Пересечение A и B");
    printSet(complementAB, "Дополнение A \\ B");
    printSet(complementBA, "Дополнение B \\ A");
    printSet(symDiffAB, "Симметрическая разность A и B");

    return 0;
}
