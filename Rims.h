//
// Created by Wojtek on 22.04.2021.
//

#ifndef PO_PROJEKT_RIMS_H
#define PO_PROJEKT_RIMS_H


#include <iostream>



class Rims
{
private:
    int rim_width;                                                                  //szerokosc felgi
    int rim_diameter;                                                               //srednica felgi
    std::string section_type;                                                            //typ przekroju felgi
    std::string flange_type;                                                             //typ kolnierza felgi
    int screw_amount;                                                               //ilosc srub
    int screw_spacing;                                                              //rozstaw srub
    int offset;                                                                     //offset felgi
    int inner;                                                                      //srednica otworu centralnego

public:
    Rims(int rim_width, int rim_diameter, std::string section_type, std::string flange_type, int screw_amount, int screw_spacing, int offset, int inner);                             //konstruktor
    ~Rims();                                                                        //destruktor
    std::string rim_size();                                                              //funkcja skladajaca wszystkie parametry w rozmiar

};


#endif //PO_PROJEKT_RIMS_H
