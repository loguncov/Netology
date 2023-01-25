
#include <iostream>
#include <windows.h>

	//Структура адреса
struct address {
	std::string country;
	std::string town;
	std::string street;
	int houseNumber;
	int apartmentNumber;
	int index;
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
		 
	struct address Address1 { "Россия", "Москва", "Ленина", 4, 13, 432652 };
	struct address Address2 { "Россия", "Новосибирск", "Ленина", 4, 13, 723821 };

	outputStruct(Address1);
	outputStruct(Address2);

}