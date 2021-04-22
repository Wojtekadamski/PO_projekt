#include <iostream>
#include "Engine.h"
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>
#include "GearBox.h"

void turnonoff();
void oilusagecheck();
void ride();
Engine engine;
GearBox gearbox;

int main() {

    turnonoff();
    ride();
    return 0;
}

void turnonoff()
{                                                                                                                           //wlaczanie/ wylaczanie silnika
    char turn_on_off;
    std::cout<<"press q to turn on the engine, press r to turn off the engine: ";
    std::cin>>turn_on_off;
    if (turn_on_off=='q')
    {
        engine.setState(true);
        engine.setEngineSpeed(1000);
        std::cout<<"\nengine is turned on, starting parameters: engine speed= "<<engine.getEngineSpeed()<<" oil level= "<<engine.getOilLevel()<<"\n";
    }
    if (turn_on_off=='a')
    {
        engine.setState(false);
        std::cout<<"\nengine is turned off";
    }
    if (turn_on_off!='q' && turn_on_off!='r')
    {
        std::cout<<"\nwrong command, try again: ";
        std::cin>>turn_on_off;
    }
}

void oilusagecheck()                                                                                                        //sprawdzanie poziomu oleju
{
    static unsigned int temporary_mileage=engine.getCarMileage();
    static unsigned int temporary_oillevel=engine.getOilLevel();
    if((engine.getCarMileage()-temporary_mileage)>=1000)
    {

        engine.setOilLevel(temporary_oillevel--);
        if (engine.getOilLevel()==0)
            std::cout<<"lack of oil, seized engine, car stopped";
        if (engine.getOilLevel()==30)
            std::cout<<"low oil level!";

    }

}

void ride()
{
    unsigned short int gearcount=0;                                                                                        //zmienne tymczasowe
    if (engine.getState())
    {
        srand(time(NULL));
        unsigned int speed = 0, localEnginespeed=engine.getEngineSpeed();
        std::cout <<"speed:  "<<"\t";
        while (true)
        {

            if (GetKeyState('W') & 0x8000)
            {
                std::cout<<"\b\b\b";
                if (speed<300)                                                                                              //klikanie "w" zwieksza predkosc i obroty
                    speed++;
                if(localEnginespeed<5870)
                    engine.setEngineSpeed(localEnginespeed+=(100+rand()%30));                                         //wyswietlanie aktualnej predkosci, kasuje poprzednia wypisana predkosc i zastepuje je nowa predkoscia
                std::printf("%3d", speed);
                Sleep(100);
            }
            if (GetKeyState('S') & 0x8000)
            {
                std::cout<<"\b\b\b";                                                                                          //klikanie "s" zmniejsza predkosc i obroty
                if (speed>0)
                    speed--;
                if (engine.getEngineSpeed()>1130)
                    engine.setEngineSpeed(localEnginespeed-=(100+rand()%30));
                std::printf("%3d", speed);                                                                                      //wyswietlanie aktualnej predkosci, kasuje poprzednia wypisana predkosc i zastepuje je nowa predkoscia
                Sleep(100);
            }
            if (GetKeyState('T') & 0x8000)
            {
                std::cin>>gearcount;                                                                                        //klikniecie "t" + wcisniecie 1-6 lub "r" zmienia bieg
                gearbox.setGearCount(gearcount);

            }

            if (GetKeyState('M') & 0x8000)                                                                                    //klikanie "m" konczy jazde
                break;


        }
    }
    else
        std::cout<<"turn on the engine first\n";
}
