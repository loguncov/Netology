#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

const int numThreads = 4;    // Количество потоков
const int calculationLength = 100;  // Длина расчета

std::mutex outputMutex;  // Мьютекс для синхронизации вывода в консоль

// Функция, имитирующая расчет в потоке
void calculationThread(int threadNumber)
{
    // Генерируем случайное время для имитации расчета
    int calculationTime = std::rand() % 500 + 500;

    // Заполняющийся индикатор (прогресс-бар)
    int progress = 0;
    int progressMax = calculationLength;

    // Получаем идентификатор потока
    std::thread::id threadId = std::this_thread::get_id();

    // Засекаем время начала работы потока
    auto startTime = std::chrono::steady_clock::now();

    // Имитация расчета
    for (int i = 0; i < calculationLength; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(calculationTime / calculationLength));

        {
            std::lock_guard<std::mutex> lock(outputMutex);

            // Вывод информации о потоке и прогрессе
            std::cout << "Поток " << threadNumber << " (ID: " << threadId << "): [";
            for (int j = 0; j < progress; ++j)
            {
                std::cout << "=";
            }
            std::cout << ">" << std::string(progressMax - progress, ' ') << "] " << progress * 100 / calculationLength << "%" << std::endl;

            ++progress;
        }
    }

    // Засекаем время окончания работы потока
    auto endTime = std::chrono::steady_clock::now();

    // Вычисляем суммарное время работы потока
    auto totalTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    {
        std::lock_guard<std::mutex> lock(outputMutex);
        // Вывод суммарного времени работы потока
        std::cout << "Поток " << threadNumber << " (ID: " << threadId << ") завершил работу. Время работы: " << totalTime.count() << " мс" << std::endl;
    }
}


int main()
{
    std::vector<std::thread> threads;

    // Запуск потоков
    for (int i = 1; i <= numThreads; ++i)
    {
        threads.emplace_back(calculationThread, i);
    }

    // Ожидание завершения потоков
    for (auto& thread : threads)
    {
        thread.join();
    }

    return 0;
}
