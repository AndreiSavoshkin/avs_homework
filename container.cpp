//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"
#include "stdio.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for(int i = 0; i < c.len; i++) {
        deleteVehicle(c.cont[i]);
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного файла
void In(container &c, FILE *fp) {
    while (!feof(fp)) {
        if((c.cont[c.len] = In(fp)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while(c.len < size) {
        if((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный файл
void Out(container &c, FILE *fp) {
    fprintf(fp, "%s%d%s", "Container contains ", c.len, " elements.\n");
    fprintf(fp, "%s%.2f%s", "Average distance = ", getAverageDistance(c), "\n");
    for(int i = 0; i < c.len; i++) {
        fprintf(fp, "%d%s", i, ": ");
        Out(*(c.cont[i]), fp);
        fprintf(fp, "%s", "\n");
    }
}

//------------------------------------------------------------------------------
// Сортировка авто по их расстояниям
container MoveAutos(container &c) {
    double averageValue = getAverageDistance(c);
    for (int j = 0; j < (c).len; ++j) {
        for (int i = 0; i < (c).len; ++i) {
            if (Distance(*(c).cont[i]) < averageValue) {
                c = MoveToEnd(c, i);
            }
        }
    }
    return c;
}

//------------------------------------------------------------------------------
// Получение среднего значения расстояния
double getAverageDistance(container &c) {
    double averageValue = 0;
    for (int i = 0; i < c.len; ++i) {
        averageValue += Distance(*c.cont[i]);
    }
    averageValue /= c.len;
    return averageValue;
}

//------------------------------------------------------------------------------
// Переместить элемент в конец массива
container MoveToEnd(container &c, int index) {
    vehicle* temp;
    for (int i = index; i < c.len - 1; ++i) {
        temp = c.cont[i];
        c.cont[i] = c.cont[i + 1];
        c.cont[i + 1] = temp;
    }
    return c;
}
