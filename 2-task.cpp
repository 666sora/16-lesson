#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string firstPart, secondPart;
    std::cout << "Input first part of number: ";
    std::cin >> firstPart;
    std::cout << "Input second part of number: ";
    std::cin >> secondPart;
    double number = 0;
    number += std::stod(firstPart);
    number += (std::stod(secondPart)) / pow(10, secondPart.length());
    std::cout << "Number is " << number;
}

/*
Напишите небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит пользователь, 
составьте новое число с плавающей точкой (типа double) и выведите это число обратно в консоль для проверки. 
Целая часть — это часть числа, которая находится до точки (запятой), дробная — после.
*/