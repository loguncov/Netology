#include <iostream>
#include <mutex>
#include <thread>

class Data {
public:
    Data(int value) : data(value) {}

    int getValue() const {
        return data;
    }

    void setValue(int value) {
        data = value;
    }

    std::mutex& getMutex() {
        return mutex;
    }

private:
    int data;
    std::mutex mutex;
};

void swap_with_lock(Data& data1, Data& data2) {
    std::lock(data1.getMutex(), data2.getMutex());  // Захватываем оба мьютекса

    // Обмен данными
    int temp = data1.getValue();
    data1.setValue(data2.getValue());
    data2.setValue(temp);

    data1.getMutex().unlock();
    data2.getMutex().unlock();
}

void swap_with_scoped_lock(Data& data1, Data& data2) {
    std::scoped_lock lock(data1.getMutex(), data2.getMutex());  // Захватываем оба мьютекса автоматически

    // Обмен данными
    int temp = data1.getValue();
    data1.setValue(data2.getValue());
    data2.setValue(temp);
}

void swap_with_unique_lock(Data& data1, Data& data2) {
    std::unique_lock<std::mutex> lock1(data1.getMutex(), std::defer_lock);
    std::unique_lock<std::mutex> lock2(data2.getMutex(), std::defer_lock);
    std::lock(lock1, lock2);  // Захватываем оба мьютекса с помощью unique_lock

    // Обмен данными
    int temp = data1.getValue();
    data1.setValue(data2.getValue());
    data2.setValue(temp);
}

int main() {
    Data data1(10);
    Data data2(20);

    // Проверка функции swap с использованием lock
    std::thread thread1(swap_with_lock, std::ref(data1), std::ref(data2));
    thread1.join();
    std::cout << "Data 1: " << data1.getValue() << ", Data 2: " << data2.getValue() << std::endl;

    // Проверка функции swap с использованием scoped_lock
    std::thread thread2(swap_with_scoped_lock, std::ref(data1), std::ref(data2));
    thread2.join();
    std::cout << "Data 1: " << data1.getValue() << ", Data 2: " << data2.getValue() << std::endl;

    // Проверка функции swap с использованием unique_lock
    std::thread thread3(swap_with_unique_lock, std::ref(data1), std::ref(data2));
    thread3.join();
    std::cout << "Data 1: " << data1.getValue() << ", Data 2: " << data2.getValue() << std::endl;

    return 0;
}
