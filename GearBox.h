//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_GEARBOX_H
#define PO_PROJEKT_GEARBOX_H


#include <ios>
#include "CarPart.h"

class GearBox : public CarPart {


public:
    const std::string &getType() const;

    void setType(const std::string &type);

    int getGearCount() const;

    void setGearCount(int gearCount);

private:
    std::string type;
    int gear_count;


};


#endif //PO_PROJEKT_GEARBOX_H
