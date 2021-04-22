//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_ENGINE_H
#define PO_PROJEKT_ENGINE_H


#include <ios>
#include <map>
#include "CarPart.h"

class Engine : public CarPart{
private:
    bool state;
    unsigned int engine_speed;
    unsigned int oil_level;
    unsigned int car_mileage;
    /*int size;
    std::string type ;
    int horse_power;
    int torque;
    std::string manufacturer;
    const char * ENGINE_TYPES[3]= {"r2", "r3","v6"};*/

public:
    Engine();

    bool getState() const;

    void setState(bool state);

    unsigned int getEnginespeed() const;

    void setEnginespeed(unsigned int enginespeed);

    unsigned int getEngineSpeed() const;

    void setEngineSpeed(unsigned int engineSpeed);

    unsigned int getOilLevel() const;

    void setOilLevel(unsigned int oilLevel);

    unsigned int getCarMileage() const;

    void setCarMileage(unsigned int carMileage);



    /*int getSize() const;

    void setSize(int size);

    const std::string &getType() const;

    void setType(const std::string &type);

    int getHorsePower() const;

    void setHorsePower(int horsePower);

    int getTorque() const;

    void setTorque(int torque);

    const std::string &getManufacturer() const;

    void setManufacturer(const std::string &manufacturer);*/




};




#endif //PO_PROJEKT_ENGINE_H
