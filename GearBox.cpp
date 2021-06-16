//
// Created by Wojtek on 25.03.2021.
//

#include "GearBox.h"
#include <iostream>


int GearBox::getCurrentGear() const {
    return current_gear;
}

void GearBox::setCurrentGear(int currentGear) {
    current_gear = currentGear;
}

int GearBox::getTopGear() const {
    return TOP_GEAR;
}

GearBox::GearBox(const std::string &vin, const std::string &productionDate, const std::string &condition,
                 const int topGear, int currentGear) : CarPart(vin, productionDate, condition), TOP_GEAR(topGear),
                                                       current_gear(currentGear) {}

GearBox::GearBox() {
    std::cout << "set top gear" << std::endl;
    std::cin >> this->TOP_GEAR;
}






