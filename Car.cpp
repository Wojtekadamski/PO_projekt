//
// Created by Wojtek on 25.03.2021.

#define WIN32_LEAN_AND_MEAN      // Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include "Car.h"
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <synchapi.h>


void Car::start_engine() {
    std::cout << "press q to turn on the engine, press r to turn off the engine: ";
    std::cin >> this->turn_on_off;
    if (turn_on_off == 'q') {
        srand(time(NULL));

        engine.setState(true);
        engine.setEngineSpeed(1000);
        gearbox.setCurrentGear(0);
        engine.setFuelUsage(rand() % 7 + 5);
        std::cout << "\nengine is turned on, starting parameters: engine speed= " << engine.getEngineSpeed()
                  << " oil level= " << engine.getOilLevel() << "fuel usage: " << engine.getFuelUsage() << "\n";
    }
    if (turn_on_off == 'a') {
        engine.setState(false);
        std::cout << "\nengine is turned off";
    }
    if (turn_on_off != 'q' && turn_on_off != 'a') {
        std::cout << "\nwrong command, try again: ";
        std::cin >> turn_on_off;
    }
}

void Car::accelerate() {
    std::cout << "\b\b\b";
    if (speed < 300 && engine.getEngineSpeed() < 6000) {
        speed++;
        engine.setEngineSpeed(engine.getEngineSpeed() + 100);
    }                                                                                        //klikanie "w" zwieksza predkosc i obroty


    std::printf("%3d", speed);
    std::printf(reinterpret_cast<const char *>(gearbox.getCurrentGear()));
    Sleep(100);
}

void Car::brake() {
    std::cout
            << "\b\b\b";                                                                                          //klikanie "s" zmniejsza predkosc i obroty
    if (speed > 0 && engine.getEngineSpeed() > -2000) {
        speed--;
        engine.setEngineSpeed(engine.getEngineSpeed() - 100);
    }
    if (engine.getEngineSpeed() < -2000) {
        engine.setState(false);
        this->turn_on_off = 'a';
    }
    //wyswietlanie aktualnej predkosci, kasuje poprzednia wypisana predkosc i zastepuje je nowa predkoscia
    Sleep(100);
}

void Car::move() {
    while (true) {

        if (GetKeyState('W') & 0x8000) {
            accelerate();
        }
        if (GetKeyState('S') & 0x8000) {
            brake();
        }


        if (GetKeyState('Q') & 0x8000) {
            if (!gearbox.gearUp())
                std::cout << "max gear achieved" << std::endl;
        }                                                                                  //klikanie "m" konczy jazde
        if (GetKeyState('E') & 0x8000) {
            if (!gearbox.gearDown())
                std::cout << "lowest gear achieved" << std::endl;
        }

        if (GetKeyState('P') & 0x8000)
            break;


    }
}

Car::Car(const GearBox &gearbox, const Engine &engine, const Wheels &wheels) : gearbox(gearbox), engine(engine),
                                                                               wheels(wheels) {}

Car::Car() {
    this->gearbox = GearBox();
    this->engine = Engine();
    this->wheels = Wheels();

}



