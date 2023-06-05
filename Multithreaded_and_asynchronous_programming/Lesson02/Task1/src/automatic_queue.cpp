#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> clientCounter(0); // Атомарный счетчик клиентов
const int maxClients = 10;         // Максимальное количество клиентов

// Поток, имитирующий клиента
void clientThread()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (clientCounter < maxClients)
        {
            int newClientCount = clientCounter.fetch_add(1) + 1;
            std::cout << "Новый клиент! Всего клиентов: " << newClientCount << std::endl;
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

        if (clientCounter > 0)
        {
            int servedClientCount = clientCounter.fetch_sub(1) - 1;
            std::cout << "Клиент обслужен! Всего клиентов: " << servedClientCount << std::endl;
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
    std::thread clientThreadObj(clientThread);
    std::thread operatorThreadObj(operatorThread);

    // Ждем, пока потоки завершатся
    clientThreadObj.join();
    operatorThreadObj.join();

    return 0;
}
