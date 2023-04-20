#include <iostream>
#include <vector>

template <typename T>
class Table
{
public:
    // Конструктор, создающий таблицу заданного размера
    Table(size_t rows, size_t cols) : data_(rows, std::vector<T>(cols)) {}

    // Неконстантная версия оператора [] для изменения значений в таблице
    std::vector<T>& operator[](size_t row)
    {
        return data_[row];
    }

    // Константная версия оператора [] для чтения значений из таблицы
    const std::vector<T>& operator[](size_t row) const
    {
        return data_[row];
    }

    // Константная функция для получения размера таблицы
    std::pair<size_t, size_t> Size() const
    {
        return {data_.size(), data_[0].size()};
    }

private:
    std::vector<std::vector<T>> data_;
};

int main()
{
    // Создаем таблицу размером 2 на 3 и выводим ее размер на экран
    Table<int> table(2, 3);
    std::cout << "Размер таблицы: " << table.Size().first << "x" << table.Size().second << std::endl;

    // Меняем значение ячейки и выводим его на экран
    table[0][0] = 4;
    std::cout << "Значение ячейки [0][0]: " << table[0][0] << std::endl;

    return 0;
}
