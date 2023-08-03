#include <iostream>
#include <string>
#include <algorithm> // Для использования std::reverse

class Text {
public:
    Text(const std::string& text) : text_(text) {}
    std::string getText() const {
        return text_;
    }

private:
    std::string text_;
};

// Базовый класс декоратора
class TextDecorator {
public:
    TextDecorator(Text* text) : text_(text) {}
    virtual ~TextDecorator() {}
    virtual std::string render() = 0;

protected:
    Text* text_;
};

// Декоратор для обычного текста
class Paragraph : public TextDecorator {
public:
    using TextDecorator::TextDecorator;
    std::string render() override {
        return "<p>" + text_->getText() + "</p>";
    }
};

// Декоратор для разворота текста
class Reversed : public TextDecorator {
public:
    using TextDecorator::TextDecorator;
    std::string render() override {
        std::string reversed_text = text_->getText();
        std::reverse(reversed_text.begin(), reversed_text.end());
        return reversed_text;
    }
};

// Декоратор для создания ссылки
class Link : public TextDecorator {
public:
    Link(Text* text, const std::string& url) : TextDecorator(text), url_(url) {}
    std::string render() override {
        return "<a href=\"" + url_ + "\">" + text_->getText() + "</a>";
    }

private:
    std::string url_;
};

int main() {
    Text* text = new Text("Hello world");

    // Декорируем текст различными классами
    TextDecorator* paragraph = new Paragraph(text);
    TextDecorator* reversed = new Reversed(text);
    TextDecorator* link = new Link(text, "netology.ru");

    // Выводим результаты
    std::cout << paragraph->render() << std::endl;
    std::cout << reversed->render() << std::endl;
    std::cout << link->render() << std::endl;

    // Освобождаем память
    delete paragraph;
    delete reversed;
    delete link;
    delete text;

    return 0;
}
