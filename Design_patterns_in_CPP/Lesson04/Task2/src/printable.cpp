#include <fstream>
#include <stdexcept>

class HTMLPrintable
{
public:
    virtual std::string printAsHTML() const = 0;
};

class TextPrintable
{
public:
    virtual std::string printAsText() const = 0;
};

class JSONPrintable
{
public:
    virtual std::string printAsJSON() const = 0;
};

class DataHTML : public HTMLPrintable
{
public:
    DataHTML(std::string data) : data_(std::move(data)) {}

    std::string printAsHTML() const override
    {
        return "<html>" + data_ + "<html/>";
    }

private:
    std::string data_;
};

class DataText : public TextPrintable
{
public:
    DataText(std::string data) : data_(std::move(data)) {}

    std::string printAsText() const override
    {
        return data_;
    }

private:
    std::string data_;
};

class DataJSON : public JSONPrintable
{
public:
    DataJSON(std::string data) : data_(std::move(data)) {}

    std::string printAsJSON() const override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
};

class DataSaver
{
public:
    static void saveTo(std::ofstream &file, const HTMLPrintable &printable)
    {
        file << printable.printAsHTML();
        file << '\n'; // Вставляем перевод строки после записи данных
    }

    static void saveTo(std::ofstream &file, const TextPrintable &printable)
    {
        file << printable.printAsText();
        file << '\n'; // Вставляем перевод строки после записи данных
    }

    static void saveTo(std::ofstream &file, const JSONPrintable &printable)
    {
        file << printable.printAsJSON();
        file << '\n'; // Вставляем перевод строки после записи данных
    }
};

int main()
{
    // Пример использования:
    DataHTML htmlData("Some HTML data");
    DataText textData("Some text data");
    DataJSON jsonData("Some JSON data");

    std::ofstream outputFile("output.txt");
    DataSaver::saveTo(outputFile, htmlData);
    DataSaver::saveTo(outputFile, textData);
    DataSaver::saveTo(outputFile, jsonData);


    outputFile.close();
    return 0;
}
