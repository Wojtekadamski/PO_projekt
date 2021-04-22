//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_CAR_H
#define PO_PROJEKT_CAR_H


#include "GearBox.h"
#include "Engine.h"
#include "Wheels.h"

class Car {
private:


    GearBox gearBox;
    Engine engine;
    Wheels wheels;

    public:
    void start_engine();
    void accelerate();
    void brake();
    void check_engine();
    std::string to_string();
    std::string getFullStatus();
    void changeGear();


};


#endif //PO_PROJEKT_CAR_H
