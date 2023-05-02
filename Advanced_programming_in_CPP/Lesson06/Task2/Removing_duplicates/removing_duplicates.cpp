#include <iostream>
#include <set> // подключаем библиотеку для работы с контейнером set
using namespace std;

int main() {
    cout << "[IN]:" << endl;
    int n;
    cin >> n; // считываем количество чисел
    set<int> nums; // объявляем set для хранения уникальных значений
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.insert(x); // добавляем значение в set
    }
    cout << "[OUT]:" << endl;
    // выводим значения set в обратном порядке
    for (auto it = nums.rbegin(); it != nums.rend(); it++) {
        cout << *it << endl;
    }
    return 0;
}
