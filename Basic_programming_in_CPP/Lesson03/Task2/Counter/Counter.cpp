#include <iostream>
#include <windows.h>

enum class Command {
	exit = 'x',
	increase = '+',
	decrease = '-',
	meaning = '='
};

class Counter {
private:
	int number = 1;

public:

	Counter(int number = 1) : number(number) {

	}

	void increment() {
		number += 1;
	}

	void decrement() {
		number -= 1;
	}

	int presentNum() {
		return number;
	}
};

int main() {
	
	//Руссификатор
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int number;
	std::string answer;
	bool answerBool;
	char symbol = 'y';

	std::cout << "Вы хотите указать начальное значение счетчика? Введите да или нет: ";
	std::cin >> answer;

	while (true) {
		if (answer == "да") {
			std::cout << "Введите начальное значение счетчика: ";
			std::cin >> number;
			answerBool = true;
			break;
		}
		else if (answer == "нет") {
			std::cout << "Значение счетчика = 1" << std::endl;
			number = 1;
			answerBool = false;
			break;
		}
		else {
			std::cout << "Введите пожалуйста либо да, либо нет: ";
			std::cin >> answer;
		}
	}

	Counter count = answerBool ? Counter(number) : Counter();

	while (true) {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> symbol;

		Command comm = static_cast<Command>(symbol);
		if (comm == Command::exit) {
			break;
		}

		switch (comm) {
		case Command::increase:
			count.increment();
			break;

		case Command::decrease:
			count.decrement();
			break;

		case Command::meaning:
			std::cout << count.presentNum() << std::endl;
			break;

		default:
			std::cout << "Такой команды не существует" << std::endl;
			break;
		}
	}
	std::cout << count.presentNum() << std::endl;

	std::cout << "До свидания!" << std::endl;

	return 0;
}