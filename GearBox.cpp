//
// Created by Wojtek on 25.03.2021.
//

#include "GearBox.h"
#include "Car.h"

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
/**
 *
 * metoda zrzucająca bieg
 * @param engine
 * @return
 */
bool GearBox::gearDown(Engine *engine) {
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
/**
 * metoda wrzucająca wyższy bieg
 *
 * @param engine
 * @return bool
 */
bool GearBox::gearUp(Engine *engine) {
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






