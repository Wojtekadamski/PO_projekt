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
private:
public:


private:
    int diameter;
    int width;
    Brakes brakes;
    Tire tyre_type;
    std::string manufacturer;



};


#endif //PO_PROJEKT_WHEELS_H
