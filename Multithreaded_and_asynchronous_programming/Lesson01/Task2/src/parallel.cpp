#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>

// Функция для расчета суммы векторов в заданном диапазоне
int sumRange(const std::vector<int>& vec1, const std::vector<int>& vec2, int start, int end)
{
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += vec1[i] + vec2[i];
    }
    return sum;
}

int main()
{
    int numThreads[] = { 2, 4, 8, 16 };
    int numArrays[] = { 1000, 10000, 100000, 1000000 };

    // Выводим количество доступных ядер
    int numCores = std::thread::hardware_concurrency();
    std::cout << "Количество доступных ядер: " << numCores << std::endl;

    // Создаем векторы с заданным количеством элементов
    std::vector<int> vec1;
    std::vector<int> vec2;
    for (int i = 0; i < numArrays[3]; i++)
    {
        vec1.push_back(i);
        vec2.push_back(i);
    }

    // Выводим заголовок таблицы
    std::cout << std::setw(10) << "  Потоки" << std::setw(15) << "1000" << std::setw(15) << "10000" << std::setw(15) << "100000" << std::setw(15) << "1000000" << std::endl;
    std::cout << "--------------------------------------------------------------------------" << std::endl;

    // Выполняем вычисления для разного количества потоков и размеров векторов
    for (int numThread : numThreads)
    {
        std::cout << std::setw(10) << numThread;
        for (int numArray : numArrays)
        {
            // Разбиваем вычисления на заданное количество потоков
            std::vector<std::thread> threads;
            int blockSize = numArray / numThread;
            int start = 0;
            int end = 0;

            // Запускаем потоки
            auto startTime = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < numThread; i++)
            {
                start = i * blockSize;
                end = (i == numThread - 1) ? numArray : start + blockSize;
                threads.emplace_back(sumRange, std::ref(vec1), std::ref(vec2), start, end);
            }

            // Дожидаемся завершения всех потоков
            for (auto& thread : threads)
            {
                thread.join();
            }

            // Выводим время выполнения в таблицу
            auto endTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
            double durationInSeconds = duration.count() / 1000000.0;
            std::cout << std::setw(15) << std::fixed << std::setprecision(7) << durationInSeconds;
        }
        std::cout << std::endl;
    }

    return 0;
}
