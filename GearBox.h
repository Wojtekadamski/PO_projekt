//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_GEARBOX_H
#define PO_PROJEKT_GEARBOX_H


#include <ios>
#include "CarPart.h"

class GearBox : public CarPart
{


public:
    const std::string &getType() const;

    void setType(const std::string &type);

    const int getGearCount() const;

    void setGearCount(int);
    enum gear
    {
        reverse=-1,
        lack=0,
        first=1,
        second=2,
        third=3,
        fourth=4,
        fifth=5,
        sixth=6
    };
private:
    std::string type;
    gear gear_count;



};


#endif //PO_PROJEKT_GEARBOX_H
