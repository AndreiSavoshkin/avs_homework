#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "vehicle.h"
#include "stdio.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    vehicle *cont[max_len];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из файла
void In(container &c, FILE *fp);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в файл
void Out(container &c, FILE *fp);

// Сортировка авто по их расстояниям
container MoveAutos(container &c);

// Получение среднего значения расстояния
double getAverageDistance(container &c);

// Переместить элемент в конец массива
container MoveToEnd(container &c, int index);

#endif //__container__