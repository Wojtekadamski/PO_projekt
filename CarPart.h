//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_CARPART_H
#define PO_PROJEKT_CARPART_H


#include <ios>

class CarPart {
public:

    const std::string &getVin() const;

    void setVin(const std::string &vin);

    int *getProductionDate() const;

    void setProductionDate(int *productionDate);

    const std::string &getCondition() const;

    void setCondition(const std::string &condition);


private:
    std::string vin;
    int* production_date;
    std::string condition;


};


#endif //PO_PROJEKT_CARPART_H
