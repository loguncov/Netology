#include <iostream>
#include <string>
#include <memory>

class VeryHeavyDatabase {
public:
    std::string GetData(const std::string& key) {
        // Реализация получения данных из реальной базы данных
        // Вернуть строку "value" для ключа "key" в качестве примера
        return "value";
    }
};

class OneShotDB : public VeryHeavyDatabase {
private:
    VeryHeavyDatabase* real_object;
    size_t shots_left;

public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1) : real_object(real_object), shots_left(shots) {}

    std::string GetData(const std::string& key) {
        if (shots_left > 0) {
            shots_left--;
            return real_object->GetData(key);
        }
        return "error";
    }
};

int main() {
    VeryHeavyDatabase real_db;
    OneShotDB limit_db(&real_db, 2);

    std::cout << limit_db.GetData("key") << std::endl; // Output: value
    std::cout << limit_db.GetData("key") << std::endl; // Output: value
    std::cout << limit_db.GetData("key") << std::endl; // Output: error

    return 0;
}
