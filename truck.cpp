//------------------------------------------------------------------------------
// truck.cpp - содержит процедуру ввода параметров
//------------------------------------------------------------------------------

#include "truck.h"
#include "stdio.h"

//------------------------------------------------------------------------------
// Ввод параметров грузовика из файла
void In(truck &t, FILE *fp) {
    fscanf(fp, "%d%d%f", &t.loadCapacity, &t.fuelCapacity, &t.fuelConsumption);
}

// Случайный ввод параметров грузовика.
void InRnd(truck &truckVehicle) {
    truckVehicle.loadCapacity = Random() % 10 + 1;
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток.
void Out(truck &truckVehicle, FILE *fp) {
    fprintf(fp, "%s%d%s%d%s%.2f%s%.2f",
            "It is a truck: load capacity = ", truckVehicle.loadCapacity,
            ", fuel capacity = ", truckVehicle.fuelCapacity,
            ", fuel consumption = ", truckVehicle.fuelConsumption,
            ". Max distance = ", Distance(truckVehicle));
}

//------------------------------------------------------------------------------
// Вычисление расстояния грузовика.
double Distance(truck &truckVehile) {
    return truckVehile.fuelCapacity / truckVehile.fuelConsumption * 100;
}
