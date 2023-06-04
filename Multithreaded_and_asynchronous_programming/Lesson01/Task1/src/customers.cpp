#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex;
int clientCounter = 0;
const int maxClients = 10;  // Максимальное количество клиентов

// Поток, имитирующий клиента
void clientThread()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::lock_guard<std::mutex> lock(mutex);
        if (clientCounter < maxClients)
        {
            clientCounter++;
            std::cout << "Новый клиент! Всего клиентов: " << clientCounter << std::endl;
        }
        else
        {
            break;
        }
    }
}

// Поток, имитирующий операциониста
void operatorThread()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::lock_guard<std::mutex> lock(mutex);
        if (clientCounter > 0)
        {
            clientCounter--;
            std::cout << "Клиент обслужен! Всего клиентов: " << clientCounter << std::endl;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    // Создаем потоки для клиента и операциониста
    std::thread clientThreadObj(clientThread);  // Переименуйте объект в clientThreadObj
    std::thread operatorThreadObj(operatorThread);  // Переименуйте объект в operatorThreadObj

    // Ждем, пока потоки завершатся
    clientThreadObj.join();
    operatorThreadObj.join();

    return 0;
}

