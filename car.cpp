//------------------------------------------------------------------------------
// car.cpp - содержит функции обработки легкового автомобиля
//------------------------------------------------------------------------------

#include "car.h"
#include "stdio.h"

//------------------------------------------------------------------------------
// Ввод параметров автомобиля из файла
void In(car &t, FILE *fp) {
    fscanf(fp, "%hd%d%f", &t.maxSpeed, &t.fuelCapacity, &t.fuelConsumption);
}

// Случайный ввод параметров автомобиля
void InRnd(car &t) {
    t.maxSpeed = Random() + 90;
}

//------------------------------------------------------------------------------
// Вывод параметров автомобился в файл
void Out(car &t, FILE *fp) {
    fprintf(fp, "%s%d%s%d%s%.2f%s%.2f", "It is a car: max speed = ", t.maxSpeed,
            ", fuel capacity = ", t.fuelCapacity,
            ", fuel consumption = ", t.fuelConsumption,
            ". Max distance = ", Distance(t));
}

//------------------------------------------------------------------------------
// Вычисление маскимального расстояния
double Distance(car &t) {
    return t.fuelCapacity / t.fuelConsumption * 100;
}
