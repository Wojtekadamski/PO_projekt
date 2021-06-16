//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_ENGINE_H
#define PO_PROJEKT_ENGINE_H


#include <ios>
#include "CarPart.h"

class Engine : public CarPart {
private:
    bool state;
    int engine_speed;
    unsigned int oil_level;
    unsigned int car_mileage;
    unsigned int fuel_usage;
public:
    void setFuelUsage(unsigned int fuelUsage);


    unsigned int getFuelUsage() const;

    Engine();

    bool getState() const;

    void setState(bool state);

    int getEngineSpeed() const;

    void setEngineSpeed(int engineSpeed);

    unsigned int getOilLevel() const;

    void setOilLevel(unsigned int oilLevel);

    unsigned int getCarMileage() const;

    void setCarMileage(unsigned int carMileage);



};




#endif //PO_PROJEKT_ENGINE_H
