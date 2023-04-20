#include <iostream>
#include <variant>
#include <string>
#include <vector>
#include <ctime>


// Функция, которая возвращает std::variant с числом, строкой или вектором чисел
std::variant<int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main() {
    // Получаем результат функции
    auto result = get_variant();

    // Обрабатываем результат в зависимости от его типа
    if (std::holds_alternative<int>(result)) {
        // Если результат содержит int, то умножаем его на 2 и выводим на экран
        int num = std::get<int>(result);
        std::cout << num * 2 << std::endl;
    }
    else if (std::holds_alternative<std::string>(result)) {
        // Если результат содержит строку, то просто выводим её на экран
        std::string str = std::get<std::string>(result);
        std::cout << str << std::endl;
    }
    else if (std::holds_alternative<std::vector<int>>(result)) {
        // Если результат содержит вектор чисел, то выводим все его элементы на экран
        std::vector<int> vec = std::get<std::vector<int>>(result);
        for (auto num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
