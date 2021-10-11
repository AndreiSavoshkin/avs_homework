#ifndef __truck__
#define __truck__

//------------------------------------------------------------------------------
// truck.h - содержит описание грузовика
//------------------------------------------------------------------------------

using namespace std;

#include "rnd.h"
#include "vehicle.h"
#include "stdio.h"

// грузовик
struct truck: vehicle {
    int loadCapacity; // грузоподъемность
};

// Ввод параметров грузовика из файла
void In(truck &t, FILE *fp);

// Случайный ввод параметров грузовика
void InRnd(truck &t);

// Вывод параметров грузовика в файл
void Out(truck &t, FILE *fp);

// Вычисление расстояния грузовика
double Distance(truck &t);

#endif //__truck__
