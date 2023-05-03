#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Объявляем класс big_integer
class big_integer
{
public:
    // Конструктор класса
    big_integer() = default;
    big_integer(const std::string &s)
    {
        // Проходим по строке справа налево и добавляем в вектор цифры числа
        for (auto it = s.rbegin(); it != s.rend(); ++it)
        {
            digits.push_back(*it - '0');
        }
    }

    // Конструктор перемещения
    big_integer(big_integer &&other) noexcept
        : digits(std::move(other.digits))
    {
    }

    // Оператор перемещения
    big_integer &operator=(big_integer &&other) noexcept
    {
        // Проверяем, не ссылается ли this на other
        if (this != &other)
        {
            digits = std::move(other.digits); // перемещаем вектор цифр числа из other в this
        }
        return *this;
    }

    // Оператор сложения
    big_integer operator+(const big_integer &other) const
    {
        big_integer result;
        size_t max_size = std::max(digits.size(), other.digits.size());
        result.digits.resize(max_size);
        int carry = 0; // "выносим" единицу при сложении
        for (size_t i = 0; i < max_size; ++i)
        {
            int sum = carry;
            if (i < digits.size())
            {
                sum += digits[i];
            }
            if (i < other.digits.size())
            {
                sum += other.digits[i];
            }
            result.digits[i] = sum % 10; // оставляем только младший разряд в результате
            carry = sum / 10;            // выносим единицу, если она была
        }
        if (carry)
        {
            result.digits.push_back(carry);
        }
        return result;
    }

    // Оператор умножения на целое число
    big_integer operator*(int n) const
    {
        big_integer result;
        int carry = 0;
        for (auto d : digits)
        {
            int prod = d * n + carry;           // вычисляем произведение цифры и числа n, добавляем "вынесенную" единицу
            result.digits.push_back(prod % 10); // оставляем только младший разряд в результате
            carry = prod / 10;                  // выносим единицу, если она была
        }
        if (carry)
        {
            result.digits.push_back(carry);
        }
        return result;
    }

    // Оператор вывода в поток
    friend std::ostream &operator<<(std::ostream &os, const big_integer &bi)
    {
        for (auto it = bi.digits.rbegin(); it != bi.digits.rend(); ++it)
        {
            os << *it; // выводим цифры числа справа налево
        }
        return os;
    }

private:
    std::vector<int> digits; // вектор цифр числа
};

// Основная функция программы
int main()
{

    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result << std::endl; // 193099

    result = number1 * 5;
    std::cout << result << std::endl; // 572875

    return 0;
}
