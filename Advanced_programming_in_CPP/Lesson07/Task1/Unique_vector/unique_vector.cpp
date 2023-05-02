#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void unique_vector(std::vector<T>& vec) {
std::sort(vec.begin(), vec.end()); // Сортировка вектора
vec.erase(std::unique(vec.begin(), vec.end()), vec.end()); // Удаление дубликатов
}

int main() {
std::vector<int> vec {1, 1, 2, 5, 6, 1, 2, 4};
unique_vector(vec);
for (auto i : vec) {
std::cout << i << " ";
}
std::cout << std::endl;
return 0;
}

