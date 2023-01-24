#include <fstream>
#include <iostream>

int main() {

    setlocale(LC_ALL, "Russian");

    std::ifstream fin("in.txt");
    if (!fin.is_open()) {
        std::cout << "Файл с входными данными не открыт" << std::endl;
        return 1;
    }

    const unsigned number_of_arrays = 2;
    int* arr[number_of_arrays];
    unsigned arr_sizes[number_of_arrays] = { 0, 0 };


    //считываем файл
    for (unsigned arr_x = 0; arr_x < 2; ++arr_x) {
        fin >> arr_sizes[arr_x];

        arr[arr_x] = new int[arr_sizes[arr_x]];

        for (int i = 0; i < arr_sizes[arr_x]; ++i) {
            fin >> arr[arr_x][i];
        }
    }
    fin.close();

    std::ofstream fout("out.txt");
    if (!fout.is_open()) {
        std::cout << "Файл с выходными данными не открыт" << std::endl;

        //очистка памяти 
        for (unsigned arr_x = 0; arr_x < 2; ++arr_x) {
            delete[] arr[arr_x];
        }
        return 2;
    }

    //Записываем файл
    fout << arr_sizes[1] << '\n';
    for (int i = 0; i < arr_sizes[1]; ++i) {
        fout << (arr[1][(i + arr_sizes[1] - 1) % arr_sizes[1]]) << " ";
    }
    delete[] arr[1];

    fout << '\n';

    fout << arr_sizes[0] << '\n';
    for (int i = 0; i < arr_sizes[0]; ++i) {
        fout << (arr[0][(i + 1) % arr_sizes[0]]) << " ";
    }
    delete[] arr[0];

    fout.close();

    return 0;
}