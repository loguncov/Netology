// Подключение необходимых заголовочных файлов
#include <iostream>
#include <sstream>

// Создание класса Counter
class Counter
{
public:
// Конструктор класса, инициализирующий переменные count_ и sum_ нулями
Counter() : count_(0), sum_(0) {}

// Оператор (), выполняющий подсчет количества и суммы чисел, делящихся на 3
void operator()(int number)
{
    if (number % 3 == 0)
    {
        count_++;
        sum_ += number;
    }
}

// Константные функции для получения суммы и количества чисел
int get_sum() const { return sum_; }
int get_count() const { return count_; }
private:
int count_; // Количество чисел, делящихся на 3
int sum_; // Сумма чисел, делящихся на 3
};

int main()
{
// Создание строки с числами
std::string input = "4 1 3 6 25 54";
// Создание объекта std::istringstream для чтения чисел из строки input
std::istringstream iss(input);

int number;          // Переменная для хранения очередного числа из строки
Counter counter;     // Создание объекта класса Counter для подсчета суммы и количества чисел
while (iss >> number) // Чтение чисел из строки, пока это возможно
{
    counter(number); // Вызов оператора () для подсчета количества и суммы чисел, делящихся на 3
}

// Вывод результата подсчета на экран
std::cout << "get_sum() = " << counter.get_sum() << std::endl;
std::cout << "get_count() = " << counter.get_count() << std::endl;

return 0;

}