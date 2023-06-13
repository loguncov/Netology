#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>

// Функция для поиска минимального элемента в асинхронном режиме
template<typename T>
T findMinAsync(const std::vector<T>& data, std::promise<T>&& promise)
{
    T minElement = *std::min_element(data.begin(), data.end());
    promise.set_value(minElement);
    return minElement;
}

// Функция для выполнения сортировки выбором
template<typename T>
void selectionSort(std::vector<T>& data)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        // Создаем promise и future для получения значения минимального элемента
        std::promise<T> promise;
        std::future<T> future = promise.get_future();

        // Запускаем асинхронную задачу поиска минимального элемента
        std::thread thread(&findMinAsync<T>, std::vector<T>(data.begin() + i, data.end()), std::move(promise));

        // Ожидаем результат и устанавливаем минимальный элемент на текущую позицию
        T minElement = future.get();
        data[i + std::distance(data.begin() + i, std::find(data.begin() + i, data.end(), minElement))] = data[i];
        data[i] = minElement;

        // Ожидаем завершение асинхронной задачи
        thread.join();
    }
}

int main()
{
    // Создаем неупорядоченный список
    std::vector<int> data = { 7, 2, 5, 1, 9, 3 };

    // Выполняем сортировку выбором
    selectionSort(data);

    // Выводим отсортированный список
    for (const auto& element : data)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
