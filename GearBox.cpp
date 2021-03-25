//
// Created by Wojtek on 25.03.2021.
//

#include "GearBox.h"

const std::string &GearBox::getType() const {
    return type;
}

void GearBox::setType(const std::string &type) {
    GearBox::type = type;
}

int GearBox::getGearCount() const {
    return gear_count;
}

void GearBox::setGearCount(int gearCount) {
    gear_count = gearCount;
}
