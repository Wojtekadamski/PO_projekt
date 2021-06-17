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
    float oil_level;
    unsigned int car_mileage;
    unsigned int fuel_usage;
public:
    void setFuelUsage(unsigned int fuelUsage);

    Engine(const std::string &vin, const std::string &productionDate, const std::string &condition, bool state,
           int engineSpeed, float oilLevel, unsigned int carMileage, unsigned int fuelUsage);


    unsigned int getFuelUsage() const;

    Engine();

    bool getState() const;

    void setState(bool state);

    int getEngineSpeed() const;

    void setEngineSpeed(int engineSpeed);

    float getOilLevel() const;

    void setOilLevel(float oilLevel);

    unsigned int getCarMileage() const;

    void setCarMileage(unsigned int carMileage);



};




#endif //PO_PROJEKT_ENGINE_H
