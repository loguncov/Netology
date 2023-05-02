#include <iostream>
#include <vector>
#include <memory>

template <typename T>
void move_vectors(std::vector<T> &source, std::vector<T> &destination)
{
    destination = std::move(source);
}

int main()
{
    {
        std::vector<std::string> one = {"test_string1", "test_string2"};
        std::vector<std::string> two;
        move_vectors(one, two);
        for (const auto &elem : two)
        {
            std::cout << elem << '\n';
        }
    }

    return 0;
}
