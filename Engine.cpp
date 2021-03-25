//
// Created by Wojtek on 25.03.2021.
//

#include <iostream>
#include "Engine.h"

int Engine::getSize() const {
    return size;
}

void Engine::setSize(int size) {
    Engine::size = size;
}

const std::string &Engine::getType() const {

    return type;
}
/**
 *
 * @param type
 */
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
}
