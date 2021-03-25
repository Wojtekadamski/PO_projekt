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
    int size;
    std::string type ;
    int horse_power;
    int torque;
    std::string manufacturer;
    const char * ENGINE_TYPES[3]= {"r2", "r3","v6"};
public:
    int getSize() const;

    void setSize(int size);

    const std::string &getType() const;

    void setType(const std::string &type);

    int getHorsePower() const;

    void setHorsePower(int horsePower);

    int getTorque() const;

    void setTorque(int torque);

    const std::string &getManufacturer() const;

    void setManufacturer(const std::string &manufacturer);


};


#endif //PO_PROJEKT_ENGINE_H
