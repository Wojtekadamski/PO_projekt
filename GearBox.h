//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_GEARBOX_H
#define PO_PROJEKT_GEARBOX_H


#include <ios>
#include "CarPart.h"
#include "Engine.h"
#include "iostream"

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

    bool gearUp(Engine *engine) {
        if (current_gear < TOP_GEAR) {
            if(engine->getEngineSpeed() < 1000 && current_gear!=0) {
                std::cout <<"can't shift up, revs too low "<<std::endl;
                return false;
            }
            current_gear++;
            if (engine->getEngineSpeed() > 4000) {
                engine->setEngineSpeed(engine->getEngineSpeed() - 3000);
            } else {
                engine->setEngineSpeed(1000);
            }

            _sleep(300);
            return true;
        }
        return false;
    }

    bool gearDown(Engine *engine) {
        if (current_gear > 0) {
            if(engine->getEngineSpeed() >5999) {
                std::cout <<"can't shift down, revs too high "<<std::endl;
                return false;
            }
            current_gear--;
            if (engine->getEngineSpeed() < 4000) {
                engine->setEngineSpeed(engine->getEngineSpeed() + 3000);
            } else {
                engine->setEngineSpeed(6000);
            }
            _sleep(300);
            return true;
        }
        return false;
    }

};


#endif //PO_PROJEKT_GEARBOX_H
