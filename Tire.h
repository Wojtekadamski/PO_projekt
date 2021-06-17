//
// Created by Wojtek on 22.04.2021.
//

#ifndef PO_PROJEKT_TIRE_H
#define PO_PROJEKT_TIRE_H


#include <iostream>
#include "Rims.h"
#include "CarPart.h"


class Tire : public CarPart {
private:
    int diameter;                                                            //jakosc opon od 1 do 5 (po prostu jakosc; wiecej=gorzej)


public:
    explicit Tire(int diameter);

    Tire();//konstruktor


    Tire(const std::string &vin, const std::string &productionDate, const std::string &condition, int diameter);
    //destruktor
    //funkcja umozliwiajaca wymiane opon
};


#endif //PO_PROJEKT_TIRE_H
