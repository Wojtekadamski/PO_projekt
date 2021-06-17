//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_ENGINE_H
#define PO_PROJEKT_ENGINE_H


#include <ios>
#include "CarPart.h"
#include "Car.h"

class Engine : public CarPart {
private:
    bool state;
    int engine_speed;
    float oil_level;
    double car_mileage;
    unsigned int fuel_usage;
public:
    void setFuelUsage(unsigned int fuelUsage);

    Engine(const std::string &vin, const std::string &productionDate, const std::string &condition, bool state,
           int engineSpeed, float oilLevel, double carMileage, unsigned int fuelUsage);


    unsigned int getFuelUsage() const;

    Engine();

    bool getState() const;

    void setState(bool state);

    int getEngineSpeed() const;

    void setEngineSpeed(int engineSpeed);

    float getOilLevel() const;

    void setOilLevel(float oilLevel);

    double getCarMileage() const;

    void setCarMileage(double carMileage);

 std::string  getCondition() const;

};
class EngineView{

//TODO write to string

};




#endif //PO_PROJEKT_ENGINE_H
