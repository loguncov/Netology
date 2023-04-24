#include <iostream>

class Smart_Array
{
private:
    int amount = 0; // размер выделенной памяти для хранения массива
    int logical_size = 0; // текущий размер массива
    int* smart_array; // указатель на выделенную память для массива

public:
    // конструктор принимает размер массива
    Smart_Array(int sum) : amount(sum)
    {
        smart_array = new int[amount]; // выделение памяти под массив
    }

    // конструктор копирования
    Smart_Array(const Smart_Array& other)
    {
        amount = other.amount; // копируем размер выделенной памяти
        logical_size = other.logical_size; // копируем размер текущего массива

        smart_array = new int[amount](); // выделяем память для копии массива и заполняем нулями

        // копируем элементы из оригинального массива в копию
        for (int i = 0; i < logical_size; i++)
        {
            smart_array[i] = other.smart_array[i];
        }
    }

    // деструктор освобождает выделенную память
    ~Smart_Array()
    {
        delete[] smart_array;
    }

    // добавление элемента в массив
    void add_element(int element)
    {
        smart_array[logical_size] = element;
        logical_size += 1;
    }

    // получение элемента массива по индексу
    int get_element(int index)
    {
        int element = smart_array[index];
        return element;
    }

    // оператор присваивания
    Smart_Array operator=(const Smart_Array& other)
    {
        logical_size = other.logical_size; // копируем размер текущего массива
        amount = other.amount; // копируем размер выделенной памяти
        delete[] smart_array; // удаляем старую выделенную память
        smart_array = new int[amount]; // выделяем новую память
        for (int i = 0; i < logical_size; ++i)
        {
            smart_array[i] = other.smart_array[i]; // копируем элементы из оригинального массива в новый
        }

        return *this;
    }

};

int main()
{
    Smart_Array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    Smart_Array newArr(2);
    newArr.add_element(44);
    newArr.add_element(34);

    arr = newArr; // присваиваем массиву arr значения массива newArr

    std::cout << arr.get_element(0) << std::endl; // 44
    std::cout << arr.get_element(1) << std::endl; // 34
    std::cout << arr.get_element(2) << std::endl; // Индекс вне диапазона

}
