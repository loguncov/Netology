#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

template <typename Iterator, typename Function>
void parallel_for_each(Iterator first, Iterator last, Function&& f) {
    const size_t container_size = std::distance(first, last);
    const size_t block_size = 1000; // Размер блока, который будет обрабатываться одной задачей

    if (container_size <= block_size) {
        // Если размер контейнера достаточно мал, выполняем обработку синхронно
        std::for_each(first, last, std::forward<Function>(f));
    } else {
        // Рекурсивно разделяем контейнер на блоки и запускаем задачи для каждого блока
        Iterator block_start = first;
        Iterator block_end = std::next(first, block_size);

        while (block_end < last) {
            // Запускаем задачу для текущего блока
            std::future<void> future = std::async(std::launch::async, [&f, block_start, block_end]() {
                std::for_each(block_start, block_end, std::forward<Function>(f));
            });

            // Переходим к следующему блоку
            block_start = block_end;
            block_end = std::next(block_end, block_size);
        }

        // Обрабатываем последний блок
        std::for_each(block_start, last, std::forward<Function>(f));
    }
}

void print_square(int x) {
    std::cout << x * x << " ";
}

int main() {
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    parallel_for_each(nums.begin(), nums.end(), print_square);

    return 0;
}
