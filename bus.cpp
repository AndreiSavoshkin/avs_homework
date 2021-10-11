//------------------------------------------------------------------------------
// bus.cpp - содержит функции обработки автобуса
//------------------------------------------------------------------------------

#include "bus.h"

//------------------------------------------------------------------------------
// Ввод параметров автобуса из файла
void In(bus &b, FILE *fp) {
    fscanf(fp, "%hx%d%f", &b.passengersCapacity, &b.fuelCapacity, &b.fuelConsumption);
}

// Случайный ввод параметров автобуса
void InRnd(bus &b) {
    b.passengersCapacity = Random() % 20 + 1;
}

//------------------------------------------------------------------------------
// Вывод параметров автобуса в форматируемый поток
void Out(bus &b, FILE *fp) {
    fprintf(fp, "%s%d%s%d%s%.2f%s%.2f", "It is a bus: passengers capacity = ", b.passengersCapacity,
            ", fuel capacity = ", b.fuelCapacity,
            ", fuel consumption = ", b.fuelConsumption,
            ". Max distance = ", Distance(b));
}

//------------------------------------------------------------------------------
// Вычисление расстояния автобуса
double Distance(bus &b) {
    return b.fuelCapacity / b.fuelConsumption * 100;
}
