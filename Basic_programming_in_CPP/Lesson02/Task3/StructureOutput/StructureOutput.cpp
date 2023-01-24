
#include <iostream>
#include <windows.h>

	//Структура адреса
struct address {
	std::string country = "Россия";
	std::string town = "Москва";
	std::string street = "Ленина";
	int houseNumber = 4;
	int apartmentNumber = 34;
	int index = 342567;
};

void outputStruct(address& addr) {
	
	//Вывод структуры
	std::cout << "Страна: " << addr.country << std::endl;
	std::cout << "Город: " << addr.town << std::endl;
	std::cout << "Улица: " << addr.street << std::endl;
	std::cout << "Номер дома: " << addr.houseNumber << std::endl;
	std::cout << "Номер квартиры: " << addr.apartmentNumber << std::endl;
	std::cout << "Индекс: " << addr.index << std::endl;
}

int main() {
	
	//Руссификатор
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	address addr;
	outputStruct(addr);
}