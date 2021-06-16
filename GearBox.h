//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_GEARBOX_H
#define PO_PROJEKT_GEARBOX_H


#include <ios>
#include "CarPart.h"

class GearBox : public CarPart {
private:
    int TOP_GEAR;
    int current_gear;

public:
    GearBox();

    GearBox(const std::string &vin, const std::string &productionDate, const std::string &condition, const int topGear,
            int currentGear);

    int getTopGear() const;

    int getCurrentGear() const;

    void setCurrentGear(int currentGear);

    bool gearUp() {
        if (this->current_gear < this->TOP_GEAR) {
            current_gear++;
            return true;
        }
        return false;
    }

    bool gearDown() {
        if (this->current_gear > 0) {
            current_gear--;
            return true;
        }
        return false;
    }
};


#endif //PO_PROJEKT_GEARBOX_H
