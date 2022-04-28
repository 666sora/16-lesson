#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string buffer;
    std::cout << "Input operation: ";
    std::cin >> buffer;
    std::stringstream buffer_stream(buffer);
    double a, b;
    char operation;
    buffer_stream >> a >> operation >> b;
    if (operation == '+') std::cout << a + b; 
    else if (operation == '-') std::cout << a - b;
    else if (operation == '*') std::cout << a * b;
    else if (operation == '/') std::cout << a / b;
}

/*
Создайте небольшую программу для вычисления простых действий с числами. 
При запуске программа ожидает пользовательского ввода во временную переменную строку. 
После ввода строки она распарсивается на отдельные члены. Строка записывается в форме “<число-1><действие><число-2>” 
(без пробелов). Оба числа — это значения с плавающей точкой, 
повышенной точности (double). Действие может быть одним из: +, −, /, *. Результат действия выводится в стандартный вывод cout.
*/