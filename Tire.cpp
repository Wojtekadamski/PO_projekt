//
// Created by Wojtek on 22.04.2021.
//

#include "Tire.h"

#include <iostream>
#include <cstdlib>


Tire::Tire(const std::string &vin, const std::string &productionDate, const std::string &condition, int diameter)
        : CarPart(vin, productionDate, condition), diameter(diameter) {}

Tire::Tire(int diameter) {

    this->diameter = diameter;
}

Tire::Tire() {
    std::cout << "set diameter of tire:" << std::endl;
    std::cin >> this->diameter;

}
