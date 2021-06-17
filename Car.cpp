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
    if (speed < 300 && engine.getEngineSpeed() < 6000 && gearbox.getCurrentGear() > 0) {
        speed++;
        engine.setEngineSpeed(engine.getEngineSpeed() + 100);
    }                                                                                        //klikanie "w" zwieksza predkosc i obroty


    std::printf("%3d", speed);
    std::cout << "\ncurrent gear: " << gearbox.getCurrentGear();
    std::cout << "\tcurrent revs: " << engine.getEngineSpeed() << std::endl;
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
    std::printf("%3d", speed);
    std::cout << "\ncurrent gear: " << gearbox.getCurrentGear();
    std::cout << "\tcurrent revs: " << engine.getEngineSpeed()
              << std::endl;//wyswietlanie aktualnej predkosci, kasuje poprzednia wypisana predkosc i zastepuje je nowa predkoscia
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
            gearbox.gearUp(&engine);
            //engine.setEngineSpeed(1000);
        }                                                                                  //klikanie "m" konczy jazde
        if (GetKeyState('E') & 0x8000) {
            gearbox.gearDown(&engine);
            std::cout << "lowest gear achieved" << std::endl;
            //engine.setEngineSpeed(6000);
        }

        if (GetKeyState('P') & 0x8000)
            break;


        if (GetKeyState('R') & 0x8000)
            std::cout << check_engine<std::string>();

        fuel -= engine.getFuelUsage() / 100;
    }
}

Car::Car(const GearBox &gearbox, const Engine &engine, float fuel) : gearbox(gearbox), engine(engine), fuel(fuel) {}

Car::Car() {
    std::cout << "Gearbox configuration" << std::endl;
    this->gearbox = GearBox();
    std::cout << "engine configuration" << std::endl;
    this->engine = Engine();

}

template<class T>
std::string Car::check_engine() {
    T *state;
    state[0] = engine.getCondition();
    state[1] = engine.getOilLevel();
    state[2] = engine.getCarMileage();
    state[3] = engine.getFuelUsage();
    state[4] = this->getFuel();
    std::string result;
    for (int i = 0; i < 5; i++) {
        result += state[i] + "\t";
    }

    return result;
}

float Car::getFuel() const {
    return fuel;
}

void Car::setFuel(float fuel) {
    Car::fuel = fuel;
}




