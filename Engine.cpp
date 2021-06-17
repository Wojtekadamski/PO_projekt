//
// Created by Wojtek on 25.03.2021.
//

#include "Engine.h"


bool Engine::getState() const {
    return state;
}

void Engine::setState(bool state) {
    Engine::state = state;
}


int Engine::getEngineSpeed() const {
    return engine_speed;
}

void Engine::setEngineSpeed(int engineSpeed) {
    engine_speed = engineSpeed;
}

float Engine::getOilLevel() const {
    return oil_level;
}

void Engine::setOilLevel(float oilLevel) {
    oil_level = oilLevel;
}

double Engine::getCarMileage() const {
    return car_mileage;
}

void Engine::setCarMileage(double carMileage) {
    car_mileage = carMileage;
}

unsigned int Engine::getFuelUsage() const {
    return fuel_usage;
}

void Engine::setFuelUsage(unsigned int fuelUsage) {
    fuel_usage = fuelUsage;
}

Engine::Engine() {
    this->state = false;
    this->engine_speed = 0;
    this->oil_level = 100;
    this->car_mileage = 0;
    srand(time(NULL));
    this->fuel_usage = rand() % 6 + 5;
}

Engine::Engine(const std::string &vin, const std::string &productionDate, const std::string &condition, bool state,
               int engineSpeed, float oilLevel, double carMileage, unsigned int fuelUsage) : CarPart(vin,
                                                                                                           productionDate,
                                                                                                           condition),
                                                                                                   state(state),
                                                                                                   engine_speed(
                                                                                                           engineSpeed),
                                                                                                   oil_level(
                                                                                                           oilLevel),
                                                                                                   car_mileage(
                                                                                                           carMileage),
                                                                                                   fuel_usage(
                                                                                                           fuelUsage) {}

std::string  Engine::getCondition() const {
    std::string con;

    if(oil_level>=80)
        con="perfect";
    if(oil_level<80 && oil_level >= 60)
        con = "good";
    if(oil_level<60 && oil_level >= 30)
        con =  "bad, change oil";
    if(oil_level<30)
        con = "refill oil";

    return con;
}



