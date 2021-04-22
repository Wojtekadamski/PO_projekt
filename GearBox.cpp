//
// Created by Wojtek on 25.03.2021.
//

#include "GearBox.h"
#include <iostream>

const std::string &GearBox::getType() const {
    return type;
}

void GearBox::setType(const std::string &type) {
    GearBox::type = type;
}

const int GearBox::getGearCount() const {
    return gear_count;
}

void GearBox::setGearCount(int gearCount) {
    switch (gearCount)
    {
        case 0:
        {
            gear_count=lack;
            break;
        }
        case 'r':
        {
            gear_count=reverse;
            break;
        }
        case 1:
        {
            gear_count=first;
            break;
        }
        case 2:
        {
            gear_count=second;
            break;
        }
        case 3:
        {
            gear_count=third;
            break;
        }
        case 4:
        {
            gear_count=fourth;
            break;
        }case 5:
        {
            gear_count=fifth;
            break;
        }
        case 6:
        {
            gear_count=sixth;
            break;
        }
        default:
        {
            std::cout<<"nie ma takiego biegu, prosze spróbować jeszcze raz: ";
            break;
        }
    }
}