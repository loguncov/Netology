
#include <iostream>

enum class Month : uint8_t {
    Incorrect_Month,
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

const char* month_str[] = { "Неизвестный месяц",
                            "Январь",
                            "Февраль",
                            "Март",
                            "Апрель",
                            "Май",
                            "Июнь",
                            "Июль",
                            "Август",
                            "Сентябрь",
                            "Октябрь",
                            "Ноябрь",
                            "Декабрь" };


int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите номер месяца : ";
    while (true) {
        unsigned month;
        std::cin >> month;

        if (month > static_cast<int>(Month::December)) {
            std::cout << "Неправильный номер!" << std::endl;
            continue;
        }

        if (month == static_cast<int>(Month::Incorrect_Month)) {
            std::cout << "До свидания" << std::endl;
            break;
        }

        std::cout << month_str[static_cast<int>(month)] << std::endl;
    }
}
