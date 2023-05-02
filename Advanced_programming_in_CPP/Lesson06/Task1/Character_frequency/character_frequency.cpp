#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

int main() {
    std::string text;
    std::getline(std::cin, text); // считываем строку текста с помощью функции getline

    std::unordered_map<char, int> freq; // создаем контейнер типа unordered_map для хранения частоты встречаемости символов

    // проходимся по всем символам в строке
    for (char c : text) {
        if (std::isalpha(c) || std::isspace(c) || std::ispunct(c)) { // проверяем, является ли символ буквой, пробелом или знаком препинания
            //c = std::tolower(c); // приводим символ к нижнему регистру [РАСКОМИЕНТИРОВАТЬ ПРИ НЕОБХОДИМОСТИ СЧИТАТЬ СИМВОЛЫ РАЗНЫХ РЕГИСТРОВ СОВМЕСТНО]
            freq[c]++; // увеличиваем счетчик вхождений символа в контейнере
        }
    }

    // создаем функциональный объект (лямбда-функцию) для сравнения двух пар символ-частота в порядке убывания частоты
    auto comp = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };

    // создаем вектор из пар символ-частота на основе элементов контейнера
    std::vector<std::pair<char, int>> freq_vec(freq.begin(), freq.end());

    // сортируем вектор в порядке убывания частоты символов с помощью функционального объекта comp
    std::sort(freq_vec.begin(), freq_vec.end(), comp);

    // выводим результаты подсчета частоты символов
    std::cout << "Результат подсчета частоты символов:\n";
    for (auto [c, count] : freq_vec) {
        std::cout << c << ": " << count << '\n';
    }

    return 0;
}

