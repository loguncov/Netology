#include <iostream> // для ввода-вывода в консоль
#include <functional> // для std::function
#include <cmath> // для функций sin и cos
#include <vector> // для работы с векторами

int main() {
std::vector<double> angles; // создаем вектор углов, который будем заполнять
int n;
std::cout << "Введите количество углов: ";
std::cin >> n;
// заполняем вектор углами, переведенными в радианы
for (int i = 0; i < n; i++) {
    double angle;
    std::cout << "Введите угол " << i+1 << " в градусах: ";
    std::cin >> angle;
    angles.push_back(angle * 3.1415926 / 180);
}

// создаем вектор лямбда-функций, которые принимают угол и выводят в консоль sin и cos этого угла
std::vector<std::function<void(double)>> functions = {
    [](double angle) { std::cout << "sin: " << std::sin(angle) << " "; },
    [](double angle) { std::cout << "cos: " << std::cos(angle) << " "; }
};

// цикл по всем углам
for (const auto& angle : angles) {
    std::cout << angle << ": ";
    // цикл по всем лямбда-функциям
    for (const auto& function : functions)
        function(angle); // вызываем каждую лямбда-функцию, передавая ей текущий угол
    std::cout << std::endl; // переходим на следующую строку
}

return 0;

}