//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_WHEELS_H
#define PO_PROJEKT_WHEELS_H


#include <ios>
#include "CarPart.h"
#include "Tire.h"

class Brakes : public CarPart {

};

class Wheels : public CarPart {
public:

    Wheels(Tire tyreType);

    Wheels();

private:

    Brakes brakes;
    Tire tyre_type;


};


#endif //PO_PROJEKT_WHEELS_H
