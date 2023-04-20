#include <iostream>
#include <vector>

// Шаблонная функция для возведения в квадрат простых чисел
template <typename T>
T square(T x)
{
    return x * x;
}

// Шаблонная функция для возведения в квадрат векторов чисел
template <typename T>
std::vector<T> square(std::vector<T> vec)
{
    std::vector<T> result;
    for (const auto& x : vec)
    {
        result.push_back(x * x);
    }
    return result;
}

int main()
{
    // Используем шаблонную функцию для возведения в квадрат простого числа
    int x = 5;
    std::cout << "Квадрат числа " << x << " равен " << square(x) << std::endl;

    // Используем шаблонную функцию для возведения в квадрат вектора чисел
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Исходный вектор: ";
    for (const auto& x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    vec = square(vec);
    std::cout << "Вектор, возведенный в квадрат: ";
    for (const auto& x : vec)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
