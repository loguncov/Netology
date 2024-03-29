#include <iostream>

template <typename T>
class MyVector {
private:
    T* m_data;          // указатель на начало выделенной памяти
    size_t m_size;      // количество элементов, содержащихся в контейнере
    size_t m_capacity;  // количество элементов, которое может содержаться в контейнере без перевыделения памяти

public:
    // конструктор по умолчанию
    MyVector() : m_data(nullptr), m_size(0), m_capacity(0) {}

    // деструктор
    ~MyVector() {
        if (m_data) {
            delete[] m_data;
        }
    }
    
    // конструктор копирования
MyVector(const MyVector& other) : m_data(nullptr), m_size(0), m_capacity(0) {
    // копируем данные из other
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new T[m_capacity];
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

// оператор присваивания
MyVector& operator=(const MyVector& other) {
    if (this != &other) {
        // освобождаем текущую память
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;

        // копируем данные из other
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}


    // функция доступа к элементу по индексу
    T& at(size_t index) {
        if (index < m_size) {
            return m_data[index];
        } else {
            throw std::out_of_range("Index is out of range");
        }
    }

    // функция добавления элемента в конец контейнера
    void push_back(const T& value) {
        // если контейнер пустой, выделяем память на 1 элемент
        if (!m_data) {
            m_data = new T[1];
            m_capacity = 1;
        }

        // если места хватает, просто добавляем элемент в конец
        if (m_size < m_capacity) {
            m_data[m_size] = value;
            ++m_size;
        } else {  // иначе перевыделяем память
            m_capacity *= 2;
            T* new_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                new_data[i] = m_data[i];
            }
            new_data[m_size] = value;
            ++m_size;

            // освобождаем старую память и перенаправляем указатель на новую
            delete[] m_data;
            m_data = new_data;
        }
    }

    // функция получения количества элементов в контейнере
    size_t size() const {
        return m_size;
    }

    // функция получения текущей вместимости контейнера
    size_t capacity() const {
        return m_capacity;
    }
};

int main() {
    // создаем контейнер и добавляем элементы
    MyVector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    // выводим элементы на экран
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1.at(i) << " ";
    }
    std::cout << std::endl;

    // создаем второй контейнер и присваиваем ему значения первого контейнера
    //MyVector<int> vec2;
    //vec2 = vec1;
    MyVector<int> vec2(vec1);

    // выводим элементы второго контейнера на экран
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
