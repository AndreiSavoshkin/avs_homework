//------------------------------------------------------------------------------
// vehicle.cpp - содержит процедуры связанные с обработкой транспортных средств
// и создания произвольного транспортного средства
//------------------------------------------------------------------------------

#include "bus.h"
#include "car.h"
#include "truck.h"
#include "stdio.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного траснпортного средства из файла
vehicle* In(FILE *fp) {
    int k;
    fscanf(fp, "%d", &k);
    bus *bp;
    car *cp;
    truck *tp;
    switch(k) {
        case 1:
            bp = new bus;
            bp->k = vehicle::BUS;
            In(*bp, fp);
            return bp;
        case 2:
            cp = new car;
            cp->k = vehicle::CAR;
            In(*cp, fp);
            return cp;
        case 3:
            tp = new truck;
            tp->k = vehicle::TRUCK;
            In(*tp, fp);
            return tp;
        default:
            return 0;
    }
}

// Случайный ввод транспортного средства
vehicle *InRnd() {
    auto k = rand() % 3 + 1;
    int fuelCapacity = 45 + rand() % 55;
    double fuelConsumption = 2.5 - (rand() % 125) / 100.0;
    bus *bp;
    car *cp;
    truck *tp;
    switch(k) {
        case 1:
            bp = new bus;
            bp->k = vehicle::BUS;
            bp->fuelCapacity = fuelCapacity;
            bp->fuelConsumption = fuelConsumption;
            InRnd(*bp);
            return bp;
        case 2:
            cp = new car;
            cp->k = vehicle::CAR;
            cp->fuelCapacity = fuelCapacity;
            cp->fuelConsumption = fuelConsumption;
            InRnd(*cp);
            return cp;
        case 3:
            tp = new truck;
            tp->k = vehicle::TRUCK;
            tp->fuelCapacity = fuelCapacity;
            tp->fuelConsumption = fuelConsumption;
            InRnd(*tp);
            return tp;
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего транспортного средства в файл
void Out(vehicle &s, FILE *fp) {
    switch(s.k) {
        case vehicle::BUS:
            Out(*((bus*)&s), fp);
            break;
        case vehicle::CAR:
            Out(*((car*)&s), fp);
            break;
        case vehicle::TRUCK:
            Out(*((truck*)&s), fp);
            break;
        default:
            fprintf(fp, "%s", "Incorrect auto!");
    }
}

//------------------------------------------------------------------------------
// Вычисление расстояния транспортного средства
double Distance(vehicle &s) {
    switch(s.k) {
        case vehicle::BUS:
            return Distance(*reinterpret_cast<bus*>(&s));
        case vehicle::CAR:
            return Distance(*reinterpret_cast<car*>(&s));
        case vehicle::TRUCK:
            return Distance(*reinterpret_cast<truck*>(&s));
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Удаление траснпортного средства
void deleteVehicle(vehicle *s) {
   switch(((vehicle*)s)->k) {
       case vehicle::BUS:
            delete (bus*)s;
            break;
       case vehicle::CAR:
            delete (car*)s;
            break;
       case vehicle::TRUCK:
            delete (truck*)s;
            break;
       default:
            break;
    }
}
