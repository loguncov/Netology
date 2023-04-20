#include <iostream>
#include <exception>
class smart_array {
private:
int* data;
int size;
public:
// конструктор с одним параметром - размер массива
smart_array(int s) {
size = s;
data = new int[size];
}
// конструктор копирования
smart_array(const smart_array& other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

// оператор присваивания
smart_array& operator=(const smart_array& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

// деструктор
~smart_array() {
    delete[] data;
}

// функция добавления элемента в массив
void add_element(int element) {
    if (size == 0) {
        data = new int[1];
        size = 1;
        data[0] = element;
    }
    else if (size > 0) {
        int* new_data = new int[size + 1];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        new_data[size] = element;
        size++;
        delete[] data;
        data = new_data;
    }
}

// функция получения элемента по индексу
int get_element(int index) const {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
};

// пример использования
int main() {
try {
smart_array arr(5);
arr.add_element(1);
arr.add_element(4);
arr.add_element(155);
    smart_array new_array(2);
    new_array.add_element(44); 
    new_array.add_element(34);

    arr = new_array;

    std::cout << arr.get_element(0) << std::endl; // 44
    std::cout << arr.get_element(1) << std::endl; // 34
    std::cout << arr.get_element(2) << std::endl; // Index out of range
}
catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
}
return 0;
}