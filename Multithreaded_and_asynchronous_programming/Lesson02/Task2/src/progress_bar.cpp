#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <atomic>

const int numThreads = 4;
const int calculationLength = 100;

std::mutex outputMutex;
std::vector<std::atomic<int>> threadProgresses(numThreads);  // Вектор атомарных переменных для отслеживания прогресса каждого потока
std::vector<std::thread::id> threadIds(numThreads);  // Вектор идентификаторов потоков
std::vector<std::chrono::time_point<std::chrono::steady_clock>> threadStartTimes(numThreads), threadEndTimes(numThreads);  // Вектор временных точек для отслеживания времени начала и окончания выполнения каждого потока
std::atomic<bool> isRunning(true);  // Флаг для контроля выполнения программы

// Функция, выполняемая в каждом потоке для выполнения задачи
void calculationThread(int threadNumber)
{
    threadStartTimes[threadNumber - 1] = std::chrono::steady_clock::now();  // Записываем время начала выполнения потока
    threadIds[threadNumber - 1] = std::this_thread::get_id();  // Записываем идентификатор потока

    int calculationTime = std::rand() % 500 + 5000;  // Генерируем случайное время выполнения для потока
    for (int i = 0; i < calculationLength; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(calculationTime / calculationLength));  // Имитируем выполнение задачи путем задержки потока
        ++threadProgresses[threadNumber - 1];  // Увеличиваем прогресс выполнения потока
    }

    threadEndTimes[threadNumber - 1] = std::chrono::steady_clock::now();  // Записываем время окончания выполнения потока
}

// Функция, выполняющаяся в отдельном потоке для отображения прогресса выполнения
void progressBarThread()
{
    while (isRunning)
    {
        std::lock_guard<std::mutex> lock(outputMutex);
        std::cout << "\033[2J\033[1;1H";
        std::cout << "#         ID                                           Полоса прогресса                                                                    Время" << std::endl;

        for (int i = 0; i < numThreads; ++i)
        {
            int progress = threadProgresses[i];  // Получаем прогресс выполнения потока
            int progressMax = calculationLength;  // Максимальное значение прогресса

            std::chrono::duration<double, std::chrono::seconds::period> elapsed_seconds = threadEndTimes[i] == std::chrono::time_point<std::chrono::steady_clock>() ?
                                                                                        std::chrono::steady_clock::now() - threadStartTimes[i] :
                                                                                        threadEndTimes[i] - threadStartTimes[i];  // Вычисляем время выполнения потока

            double elapsed_time = elapsed_seconds.count();  // Получаем время выполнения в секундах

            std::cout << (i + 1) << "  " << threadIds[i] << "  [";  // Выводим номер потока и его идентификатор
            for (int j = 0; j < progress; ++j)
            {
                std::cout << "=";  // Выводим символы '=' для обозначения прогресса выполнения
            }
            std::cout << ">" << std::string(progressMax - progress, ' ') << "] " << progress * 100 / calculationLength << "%" << " Время выполнения: " << elapsed_time << "с" << std::endl;  // Выводим информацию о прогрессе и времени выполнения
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Задержка перед обновлением прогресса
    }
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 1; i <= numThreads; ++i)
    {
        threads.emplace_back(calculationThread, i);  // Создаем и запускаем потоки выполнения задач
    }

    std::thread progressThread(progressBarThread);  // Создаем и запускаем поток для отображения прогресса выполнения

    for (auto& thread : threads)
    {
        thread.join();  // Дожидаемся окончания выполнения всех потоков
    }

    isRunning = false;  // Устанавливаем флаг, чтобы завершить поток отображения прогресса
    progressThread.join();  // Дожидаемся окончания выполнения потока отображения прогресса

    return 0;
}
