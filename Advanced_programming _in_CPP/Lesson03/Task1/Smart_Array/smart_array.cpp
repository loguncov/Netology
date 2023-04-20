#include <iostream>
#include <stdexcept>

class smart_array {
private:
int* data; // указатель на массив данных
int size; // текущее количество элементов в массиве
int capacity; // размер выделенной под массив памяти

public:
smart_array(int n) : size(0), capacity(n) { // конструктор
data = new int[capacity]; // выделение памяти под массив данных
}
~smart_array() { // деструктор
    delete[] data; // освобождение выделенной памяти
}

void add_element(int value) { // функция добавления элемента в массив
    if (size >= capacity) { // проверка на переполнение массива
        throw std::out_of_range("smart_array: array index out of bounds"); // выброс исключения, если массив переполнен
    }
    data[size] = value; // добавление элемента в массив
    size++; // увеличение текущего количества элементов в массиве
}

int get_element(int index) const { // функция получения элемента массива по индексу
    if (index < 0 || index >= size) { // проверка на корректность индекса
        throw std::out_of_range("smart_array: array index out of bounds"); // выброс исключения, если индекс некорректен
    }
    return data[index]; // возврат элемента массива по индексу
}
};

int main() {
try {
smart_array arr(5); // создание объекта класса smart_array с выделением памяти на 5 элементов
arr.add_element(1); // добавление элементов в массив
arr.add_element(4);
arr.add_element(155);
arr.add_element(14);
arr.add_element(15);
std::cout << arr.get_element(1) << std::endl; // вывод в консоль значения элемента массива по индексу
}
catch (const std::exception& ex) { // обработка исключения
std::cout << ex.what() << std::endl; // вывод сообщения об ошибке в консоль
}

return 0;
}