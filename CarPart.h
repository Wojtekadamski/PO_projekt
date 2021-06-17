//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_CARPART_H
#define PO_PROJEKT_CARPART_H


#include <ios>

class CarPart {
public:

    const std::string &getVin() const;


    virtual std::string getCondition() const;

    void setCondition(const std::string &condition);


    const std::string &getProductionDate() const;

    CarPart(const std::string &vin, const std::string &productionDate, const std::string &condition);

    CarPart();


protected:
    std::string vin;
   std::string production_date;
    std::string condition;


};


#endif //PO_PROJEKT_CARPART_H
