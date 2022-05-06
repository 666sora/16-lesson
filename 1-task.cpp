#include <iostream>
#include <string>
#include <cstdio>

bool compare(float speed, float extremum) {
    float epsilon = 0.01;
    return (speed >= extremum - epsilon) && (speed <= extremum + epsilon);
}

int main() {
    float speed_value = 0.0;
    do {
        float delta_value;
        do {
            std::cout << "Input delta value: ";
            std::cin >> delta_value;
            if (speed_value + delta_value > 150) {
                std::cout << "Invalid input" << std::endl;
            }
        } while (speed_value + delta_value > 150);
        speed_value += delta_value;
        char speed_str[5];
        std::sprintf(speed_str, "%.1f", speed_value);
        std::cout << speed_str << std::endl;
    } while (!compare(speed_value, 0));
}

/*
Реализуйте цифровой спидометр автомобиля.
Сама модель автомобиля, которую нужно будет
воссоздать, весьма проста. Начальная скорость
— 0 км/ч. Пользователь вводит в стандартный ввод
разницу (дельту) в скорости, и результирующая скорость
показывается на спидометре в стандартный вывод.
Так происходит до той поры, пока машина снова не остановится,
то есть пока скорость не станет меньше или равна нулю (сравнение
должно происходить с дельтой в 0,01). Диапазон возможных значений
скорости машины от 0 до 150 км/ч. Сам показатель спидометра вместе
с единицами измерения требуется записывать в отдельную строку-буфер,
которая потом и будет показываться на экране. Точность отображения
скорости — до 0,1 км/ч.
*/