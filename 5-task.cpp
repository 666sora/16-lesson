#include <iostream>
#include <string>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

int main() {
    int state = 0;
    for (int i = 0; i <= 48; i++) { 
        std::cout << "Now " << (i % 24 ? (i % 12 ? i % 12 : 12) : 0) 
                  << ":00 " << (i % 24 < 12 ? "am" : "pm") << std::endl;
        std::string data;
        std::cout << "Input data(\"temperature outside\" \"temperature inside\" \"motion outside\" \"lights inside\"): " << std::endl;
        std::getline (std::cin, data);
        std::stringstream stream(data);
        int tempOutside, tempInside;
        std::string motionOutside, lightsInside;
        stream >> tempOutside >> tempInside >> motionOutside >> lightsInside;
        if (tempOutside < 0 && !(state & WATER_PIPE_HEATING)) {
            state |= WATER_PIPE_HEATING;
            std::cout << "A water pipe heaters are on" << std::endl;
        }
        else if (tempOutside > 5 && (state & WATER_PIPE_HEATING)) {
            state &= ~WATER_PIPE_HEATING;
            std::cout << "A water pipe heaters are off" << std::endl;
        }
        if ((motionOutside == "yes" && (i % 24 > 16 || i % 24 < 5)) && !(state & LIGHTS_OUTSIDE)) {
            state |= LIGHTS_OUTSIDE;
            std::cout << "A lights outside are on" << std::endl;
        }
        else if ((motionOutside == "no" || (i % 24 < 16 && i % 24 > 5)) && (state & LIGHTS_OUTSIDE)) {
            state &= ~LIGHTS_OUTSIDE;
            std::cout << "A lights outside are off" << std::endl;
        }
        if (tempInside < 22 && !(state & HEATERS)) {
            state |= HEATERS;
            std::cout << "A heaters inside are on" << std::endl;
        }
        else if (tempInside >= 25 && (state & HEATERS)) {
            state &= ~HEATERS;
            std::cout << "A heaters inside are off" << std::endl;
        }
        if (tempInside >= 30 && !(state & CONDITIONER)) {
            state |= CONDITIONER;
            std::cout << "A conditioner is on" << std::endl;
        }
        else if (tempInside <= 25 && (state & CONDITIONER)) {
            state &= ~CONDITIONER;
            std::cout << "A conditioner is off" << std::endl;
        }
        int color;
        if (i % 24 > 16 && i % 24 < 21) {
            color = 5000 - 575 * ((i % 24) % 16);
        }
        else if (i % 24 <= 16 && i % 24 >= 0) {
            color = 5000;
        }
        else if (i % 24 > 20 && i % 24 < 0) {
            color = 2700;
        } 
        if (lightsInside == "on" && !(state & LIGHTS_INSIDE)) {
            state |= LIGHTS_INSIDE;
            std::cout << "A lights inside are on with color " << color << std::endl;
        }
        else if (lightsInside == "on" && (state & LIGHTS_INSIDE)) {
            std::cout << "A lights inside have color " << color << std::endl;
        }
        else if (lightsInside == "off" && (state & LIGHTS_INSIDE)) {
            state &= ~LIGHTS_INSIDE;
            std::cout << "A lights inside are off" << std::endl;
        }
    }
}

/*
Разработайте упрощённую модель умного дома для дачи. 
Выполните симуляцию его работы на протяжении двух дней. 
Стартовое время для симуляции умного дома 00:00. Есть несколько датчиков: датчик температуры снаружи, 
датчик температуры внутри дома. В доме расположен электронный 
умный щиток с автоматами. Каждый автомат отвечает за включение и отключение определённых устройств или групп устройств: 
отключение и включение питания всего дома; 
основные розетки дома; 
свет внутри дома; 
наружный свет в саду; 
отопление в помещении; 
отопление водопровода, идущего из скважины с насосом; 
кондиционер в помещении.

Есть несколько условий по включению/отключению техники в доме и вне его.
Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода. 
Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.
Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение, 
то необходимо включить садовое освещение. Если движения нет или время не вечернее, то света снаружи быть не должно.
Если температура в помещении упала ниже 22 °С, должно включиться отопление. 
Как только температура равна или поднимается выше 25 °С, отопление автоматически отключается.
Если температура в помещении поднялась до 30 °С, включается кондиционер. 
Как только температура становится 25 °С, кондиционер отключается.
Всё освещение в доме также умное и поддерживает настройку цветовой 
температуры для комфортного нахождения. Каждый день начиная с 16:00 и до 20:00 
температура цвета должна плавно изменяться с 5000K до 2700К. Разумеется, это изменение 
должно происходить, если свет сейчас включён. В 00:00 температура сбрасывается до 5000К.
Все события по отключению и включению устройств должны выводиться в консоль явным образом. 
Если устройство не изменило своё состояние (осталось включённым или выключенным), событие 
генерироваться не должно! Если свет в доме включён, должна отображаться текущая цветовая температура.
*/