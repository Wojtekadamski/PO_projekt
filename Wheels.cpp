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

Brakes Wheels::getBrakingCoeffitient() const {
    return brakes;
}

void Wheels::setBrakes(int brakes) {
    brakes = brakes;
}

Tyre Wheels::getTyreType() const {
    return tyre_type;
}

void Wheels::setTyreType(const std::string &tyre_type) {
    tyre_type = tyre_type;
}

const std::string &Wheels::getManufacturer() const {
    return manufacturer;
}

void Wheels::setManufacturer(const std::string &manufacturer) {
    Wheels::manufacturer = manufacturer;
}
