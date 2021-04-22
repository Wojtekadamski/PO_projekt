//
// Created by Wojtek on 22.04.2021.
//

#ifndef PO_PROJEKT_TIRE_H
#define PO_PROJEKT_TIRE_H


#include <iostream>
#include "Rims.h"



class Tire
{
private:
    int width;                                                              //szerokosc przekroju w milimetrach
    int height;                                                             //wysokosc profilu
    std::string type;                                                            //informacja o budowie opony
    int inner;                                                              //srednica osadzenia
    int index_n;                                                            //indeks nosnosci
    std::string index_v;                                                         //indeks predkosci
    int wear;                                                               //poziom zuzycia opony w zakresie od 0 do 1  (0,02 na 1000km)
    int quality;                                                            //jakosc opon od 1 do 5 (po prostu jakosc; wiecej=gorzej)


public:
    Tire(int, int, std::string, int, int, std::string, int, int);                    //konstruktor
    ~Tire();                                                               //destruktor
    void tire_size();                                                       //funkcja ktora wyswietla rozmiar opon                                                          //funkcja liczaca scieranie sie opon przez dluga jazde
    void change();                                                          //funkcja umozliwiajaca wymiane opon
};


#endif //PO_PROJEKT_TIRE_H
