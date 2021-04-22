//
// Created by Wojtek on 25.03.2021.
//

#include "Engine.h"

Engine::Engine() : CarPart(vin,
                           production_date,
                           condition),
                   state(false),
                   engine_speed(
                                                                                                                  0),
                   oil_level(
                                                                                                                  100) {

}

bool Engine::getState() const {
    return state;
}

void Engine::setState(bool state) {
    Engine::state = state;
}


unsigned int Engine::getEnginespeed() const {
    return engine_speed;
}

void Engine::setEnginespeed(unsigned int engine_speed) {
    Engine::engine_speed = engine_speed;
}

unsigned int Engine::getEngineSpeed() const {
    return engine_speed;
}

void Engine::setEngineSpeed(unsigned int engineSpeed) {
    engine_speed = engineSpeed;
}

unsigned int Engine::getOilLevel() const {
    return oil_level;
}

void Engine::setOilLevel(unsigned int oilLevel) {
    oil_level = oilLevel;
}

unsigned int Engine::getCarMileage() const {
    return car_mileage;
}

void Engine::setCarMileage(unsigned int carMileage) {
    car_mileage = carMileage;
}

/*int Engine::getSize() const {
    return size;
}

void Engine::setSize(int size) {
    Engine::size = size;
}

const std::string &Engine::getType() const {

    return type;
}

void Engine::setType(const std::string &type) {

    std::cout<<"Select engine type from the list:\n";
    for (std::string x : ENGINE_TYPES){
        std::cout<<x;
    }
    int choice = 0;
    std::cin>>choice;
    Engine::type = ENGINE_TYPES[choice];
}

int Engine::getHorsePower() const {
    return horse_power;
}

void Engine::setHorsePower(int horsePower) {
    horse_power = horsePower;
}

int Engine::getTorque() const {
    return torque;
}

void Engine::setTorque(int torque) {
    Engine::torque = torque;
}

const std::string &Engine::getManufacturer() const {
    return manufacturer;
}

void Engine::setManufacturer(const std::string &manufacturer) {
    Engine::manufacturer = manufacturer;
} */
