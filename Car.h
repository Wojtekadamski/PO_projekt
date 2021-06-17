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

    char turn_on_off;
    unsigned int speed = 0;
    float fuel;
public:
    GearBox gearbox;
    Engine engine;
//     GearBox getGearbox()  {
//        return gearbox;
//    }
//
//
//     Engine  getEngine()  {
//        return  engine;
//    }

    unsigned int getSpeed() const {
        return speed;
    }

    void setSpeed(unsigned int speed) {
        Car::speed = speed;
    }


    char getTurnOnOff() const;

    void setTurnOnOff(char turnOnOff);

    Car();

    Car(const GearBox& gearbox, const Engine& engine, float fuel);

    float getFuel() const;

    void setFuel(float fuel);
    //unsigned int localEnginespeed = engine.getEngineSpeed();


};

class CarView{

public:

    void checkEngine(Car &car);

};

class CarController{

    private:
    Car model;
    CarView view;
public:
    CarController(Car model, CarView view){
        this->model = model;
        this->view = view;
    }
    void start_engine();


    void accelerate();

    void brake();

    void move();
    const Car getModel() const;
};


#endif //PO_PROJEKT_CAR_H
