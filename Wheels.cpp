//
// Created by Wojtek on 25.03.2021.
//

#include "Wheels.h"

int Wheels::getDiameter() const {
    return diameter;
}

void Wheels::setDiameter(int diameter) {
    Wheels::diameter = diameter;
}

int Wheels::getWidth() const {
    return width;
}

void Wheels::setWidth(int width) {
    Wheels::width = width;
}

int Wheels::getBrakingCoeffitient() const {
    return braking_coeffitient;
}

void Wheels::setBrakingCoeffitient(int brakingCoeffitient) {
    braking_coeffitient = brakingCoeffitient;
}

const std::string &Wheels::getTyreType() const {
    return tyre_type;
}

void Wheels::setTyreType(const std::string &tyreType) {
    tyre_type = tyreType;
}

const std::string &Wheels::getManufacturer() const {
    return manufacturer;
}

void Wheels::setManufacturer(const std::string &manufacturer) {
    Wheels::manufacturer = manufacturer;
}
