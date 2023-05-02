#include <iostream>
#include <vector>
#include <list>
#include <set>

// Шаблонная функция для печати содержимого контейнера
template<typename Container>
void print_container(const Container& c) {
    // Используем auto для определения типа элементов контейнера
    for (auto it = c.begin(); it != c.end(); ++it) {
        // Печатаем текущий элемент с разделителем
        std::cout << *it;
        // Печатаем разделитель, если это не последний элемент
        if (std::next(it) != c.end()) {
            // В качестве разделителя используем запятую и пробел
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Пример использования функции для различных контейнеров
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    
    std::cout << "set: ";
    print_container(test_set);

    std::cout << "vector: ";
    print_container(test_vector);

    std::cout << "list: ";
    print_container(test_list);
    
    return 0;
}
