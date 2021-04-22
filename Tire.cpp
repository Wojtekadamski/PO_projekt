//
// Created by Wojtek on 22.04.2021.
//

#include "Tire.h"

#include <iostream>
#include <cstdlib>




Tire::Tire(int width, int height=205,  std::string type="R", int ir=16, int idn=91, std::string idv="T", int we=0, int q=5)
{
    width=width;
    height=height;
    type=type;
    inner=ir;
    index_n=idn;
    index_v=idv;
    wear=we;
    quality=q;
}


void Tire::tire_size()
{
    //WIP
}

void Tire::change()
{
    int wear=0;                                     //funkcja ustawia wear na 0, co skutkuje tym, ze program liczy opony jakby byly nowiutkie swiezutkie
    //WIP
}
