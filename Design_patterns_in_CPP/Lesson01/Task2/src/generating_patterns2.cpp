#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

class SqlSelectQueryBuilder {
public:
    // Добавить столбец в запрос. Возвращает ссылку на объект для цепочечных вызовов
    SqlSelectQueryBuilder& AddColumn(const std::string& column) {
        columns.push_back(column);
        return *this;
    }
    
    // Добавить имя таблицы, из которой выбираем. Возвращает ссылку на объект для цепочечных вызовов
    SqlSelectQueryBuilder& AddFrom(const std::string& table) {
        from = table;
        return *this;
    }

    // Добавить условие WHERE в запрос. Возвращает ссылку на объект для цепочечных вызовов
    SqlSelectQueryBuilder& AddWhere(const std::string& key, const std::string& value) {
        whereClauses.push_back(key + "=" + value);
        return *this;
    }

    // Построить SQL-запрос в виде строки
    std::string BuildQuery() {
        std::ostringstream query;
        query << "SELECT ";

        // Если столбцы не добавлены, то выбираем все (*)
        if (columns.empty()) {
            query << "* ";
        } else {
            // иначе добавляем все столбцы в запрос
            for (size_t i = 0; i < columns.size(); ++i) {
                query << columns[i] << (i < columns.size() - 1 ? ", " : " ");
            }
        }

        query << "FROM " << from << " ";

        // Если есть условия WHERE, добавляем их в запрос
        if (!whereClauses.empty()) {
            query << "WHERE ";
            for (size_t i = 0; i < whereClauses.size(); ++i) {
                query << whereClauses[i] << (i < whereClauses.size() - 1 ? " AND " : "");
            }
        }

        // Завершаем запрос символом ;
        query << ";";
        return query.str();
    }

    // Добавить несколько условий WHERE в запрос
    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept {
        for (const auto& pair : kv) {
            whereClauses.push_back(pair.first + "=" + pair.second);
        }
        return *this;
    }

    // Добавить несколько столбцов в запрос
    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept {
        this->columns = columns;
        return *this;
    }

private:
    std::vector<std::string> columns; // Вектор столбцов, которые будут добавлены в запрос
    std::string from; // Имя таблицы, из которой будет производиться выборка
    std::vector<std::string> whereClauses; // Вектор условий WHERE, которые будут добавлены в запрос
};

int main() {
    SqlSelectQueryBuilder query_builder;
    
    // Добавляем несколько столбцов
    std::vector<std::string> selectedColumns = {"name", "phone", "email"};
    query_builder.AddColumns(selectedColumns);
    
    query_builder.AddFrom("students");
    
    // Добавляем несколько условий WHERE
    std::map<std::string, std::string> whereConditions = {
        {"id", "42"},
        {"name", "John"}
    };
    query_builder.AddWhere(whereConditions);
    
    std::cout << query_builder.BuildQuery() << std::endl;

    return 0;
}
