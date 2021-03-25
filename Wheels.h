//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_WHEELS_H
#define PO_PROJEKT_WHEELS_H


#include <ios>
#include "CarPart.h"

class Wheels : public CarPart {
private:
public:
    int getDiameter() const;

    void setDiameter(int diameter);

    int getWidth() const;

    void setWidth(int width);

    int getBrakingCoeffitient() const;

    void setBrakingCoeffitient(int brakingCoeffitient);

    const std::string &getTyreType() const;

    void setTyreType(const std::string &tyreType);

    const std::string &getManufacturer() const;

    void setManufacturer(const std::string &manufacturer);

private:
    int diameter;
    int width;
    int braking_coeffitient;
    std::string tyre_type;
    std::string manufacturer;



};


#endif //PO_PROJEKT_WHEELS_H
