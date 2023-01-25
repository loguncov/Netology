
#include <iostream>

enum class Month {

    January = 1,
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

int main() {

    setlocale(LC_ALL, "Russian");

    int value = 1;

    while (value != 0) {
        std::cout << "Введите номер месяца: ";
        std::cin >> value;

        if (value > 12) {
            std::cout << "Неправильный номер!" << std::endl;
        }
        else if (value < 0) {
            std::cout << "Неправильный номер!" << std::endl;
        }

        switch (static_cast<Month>(value)) {
        case Month::January:
            std::cout << "Январь" << std::endl;
            break;
        case Month::February:
            std::cout << "Февраль" << std::endl;
            break;
        case Month::March:
            std::cout << "Март" << std::endl;
            break;
        case Month::April:
            std::cout << "Апрель" << std::endl;
            break;
        case Month::May:
            std::cout << "Май" << std::endl;
            break;
        case Month::June:
            std::cout << "Июнь" << std::endl;
            break;
        case Month::July:
            std::cout << "Июль" << std::endl;
            break;
        case Month::August:
            std::cout << "Август" << std::endl;
            break;
        case Month::September:
            std::cout << "Сентябрь" << std::endl;
            break;
        case Month::October:
            std::cout << "Октябрь" << std::endl;
            break;
        case Month::November:
            std::cout << "Ноябрь" << std::endl;
            break;
        case Month::December:
            std::cout << "Декабрь" << std::endl;
            break;
        }
    }

    std::cout << "До свидания" << std::endl;
}
