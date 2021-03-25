//
// Created by Wojtek on 25.03.2021.
//

#include "CarPart.h"

const std::string &CarPart::getVin() const {
    return vin;
}

void CarPart::setVin(const std::string &vin) {
    CarPart::vin = vin;
}

int *CarPart::getProductionDate() const {
    return production_date;
}

void CarPart::setProductionDate(int *productionDate) {
    production_date = productionDate;
}

const std::string &CarPart::getCondition() const {
    return condition;
}

void CarPart::setCondition(const std::string &condition) {
    CarPart::condition = condition;
}
