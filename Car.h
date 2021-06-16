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


    GearBox gearbox;
    Engine engine;
    Wheels wheels;
    char turn_on_off;
    unsigned int speed = 0;
    unsigned int localEnginespeed = engine.getEngineSpeed();

public:
    void start_engine();

    void accelerate();

    void brake();

    void check_engine();

    std::string to_string();

    std::string getFullStatus();

    void changeGear();

    Car();

    void move();

    Car(const GearBox &gearbox, const Engine &engine, const Wheels &wheels);
};


#endif //PO_PROJEKT_CAR_H
