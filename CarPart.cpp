//
// Created by Wojtek on 25.03.2021.
//

#include <iostream>
#include "CarPart.h"

const std::string &CarPart::getVin() const {
    return vin;
}







const std::string &CarPart::getCondition() const {
    return condition;
}

void CarPart::setCondition(const std::string &condition) {
    CarPart::condition = condition;
}

const std::string &CarPart::getProductionDate() const {
    return production_date;
}

CarPart::CarPart(const std::string &vin, const std::string &productionDate, const std::string &condition) : vin(vin),
                                                                                                            production_date(
                                                                                                                    productionDate),
                                                                                                            condition(
                                                                                                                    condition) {}

CarPart::CarPart() {
    std::cout << "set vin";
    std::cin >> this->vin;
    std::cout << "set production_date";
    std::cin >> this->production_date;
    std::cout << "set condition";
    std::cin >> this->condition;

}
