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
    char turn_on_off;
    unsigned int speed = 0;
    float fuel;
public:
    float getFuel() const;

    void setFuel(float fuel);
    //unsigned int localEnginespeed = engine.getEngineSpeed();

    void start_engine();
    Car(const GearBox &gearbox, const Engine &engine, float fuel);
    void accelerate();

    void brake();

    template <class T>
    std::string check_engine();





    Car();

    void move();

};


#endif //PO_PROJEKT_CAR_H
