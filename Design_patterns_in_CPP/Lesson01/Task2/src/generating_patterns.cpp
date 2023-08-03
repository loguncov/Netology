#include <string>
#include <vector>
#include <sstream>
#include <iostream>

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

private:
    std::vector<std::string> columns; // Вектор столбцов, которые будут добавлены в запрос
    std::string from; // Имя таблицы, из которой будет производиться выборка
    std::vector<std::string> whereClauses; // Вектор условий WHERE, которые будут добавлены в запрос
};

int main() {
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    
    std::cout << query_builder.BuildQuery() << std::endl;

    return 0;
}
