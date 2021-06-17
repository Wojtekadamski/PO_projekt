//
// Created by Wojtek on 25.03.2021.

#define WIN32_LEAN_AND_MEAN      // Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include "Car.h"
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <synchapi.h>
#include <sstream>
#include <random>

using std::cout; using std::endl;
void CarController::start_engine() {
    //TODO add a loop for choice
    std::cout << "press q to turn on the engine, press r to turn off the engine: ";
    char choice;
    std::cin >> choice;
    model.setTurnOnOff(choice);
    if (model.getTurnOnOff() == 'q') {
        srand(time(NULL));

        model.engine.setState(true);
        model.engine.setEngineSpeed(1000);
        model.gearbox.setCurrentGear(0);
        //engine.setFuelUsage(rand() % 7 + 5);
        std::cout << "\nengine is turned on, starting parameters: engine speed= " << model.engine.getEngineSpeed()
                  << " oil level= " << model.engine.getOilLevel() << "fuel usage: " << model.engine.getFuelUsage() << "\n";
    }
    if (model.getTurnOnOff() == 'a') {
        model.engine.setState(false);
        std::cout << "\nengine is turned off";
    }
    if (model.getTurnOnOff() != 'q' && model.getTurnOnOff() != 'a') {
        std::cout << "\nwrong command, try again: ";
        std::cin >> choice;
    }
}

void CarController::accelerate() {
    std::cout << "\b\b\b";
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(50,100); // distribution in range [1, 6]


    if (model.getSpeed() < 300 && model.engine.getEngineSpeed() < 6000 && model.gearbox.getCurrentGear() > 0) {
        model.setSpeed(model.getSpeed()+1);
        model.engine.setEngineSpeed(model.engine.getEngineSpeed() + dist6(rng) );

    }                                                                                        //klikanie "w" zwieksza predkosc i obroty


//    std::printf("%3d", speed);
//    std::cout << "\ncurrent gear: " << gearbox.getCurrentGear();
//    std::cout << "\tcurrent revs: " << engine.getEngineSpeed() << std::endl;
    Sleep(100);
}

void CarController::brake() {
    std::cout
            << "\b\b\b";
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(50,100); // distribution in range [1, 6]
//klikanie "s" zmniejsza predkosc i obroty
    if (model.getSpeed() > 0 && model.engine.getEngineSpeed() > 0) {
        model.setSpeed(model.getSpeed()-1);
        model.engine.setEngineSpeed(model.engine.getEngineSpeed() - dist6(rng) );
    }
    if (model.engine.getEngineSpeed() < 500) {
        model.engine.setState(false);
        model.setTurnOnOff('a');
    }
//    std::printf("%3d", speed);
//    std::cout << "\ncurrent gear: " << gearbox.getCurrentGear();
//    std::cout << "\tcurrent revs: " << engine.getEngineSpeed()
//              << std::endl;//wyswietlanie aktualnej predkosci, kasuje poprzednia wypisana predkosc i zastepuje je nowa predkoscia
    Sleep(100);
}

void CarController::move() {
    while (true) {
        if(model.engine.getOilLevel() == 0 || model.getFuel()==0){
            std::cout <<"there is no fuel or gas. please check engine before next ride."<<std::endl;
            view.checkEngine(model);
            break;
        }

        if (GetKeyState('W') & 0x8000) {
            accelerate();
        }
        if (GetKeyState('S') & 0x8000) {
            brake();
        }


        if (GetKeyState('Q') & 0x8000) {
            model.gearbox.gearUp(&model.engine);
            //engine.setEngineSpeed(1000);
        }                                                                                  //klikanie "m" konczy jazde
        if (GetKeyState('E') & 0x8000) {
            model.gearbox.gearDown(&model.engine);
            std::cout << "lowest gear achieved" << std::endl;
            //engine.setEngineSpeed(6000);
        }

        if (GetKeyState('P') & 0x8000)
            break;


        if (GetKeyState('R') & 0x8000)
            view.checkEngine(model);

        std::printf("%3d", model.getSpeed());
        std::cout << "\ncurrent gear: " << model.gearbox.getCurrentGear();
        std::cout << "\tcurrent revs: " << model.engine.getEngineSpeed()
                  << std::endl;
        model.setFuel(model.getFuel() -(((float)model.engine.getFuelUsage() / 100) * (float)model.getSpeed()/10000))  ;
        model.engine.setCarMileage(model.engine.getCarMileage()+(double)model.getSpeed()/36000);
        model.getSpeed() > 0?model.engine.setOilLevel(model.engine.getOilLevel()-0.001f):model.engine.setOilLevel(model.engine.getOilLevel());

        }
    }

const Car CarController::getModel() const {
    return model;
}



Car::Car(const GearBox&  gearbox, const Engine&  engine, float fuel) {

    this->gearbox = gearbox;
    this->engine = engine;
    this->fuel = fuel;
}

Car::Car() {
    auto *gearbox1 =new GearBox();
    auto *engine1 = new Engine();
    this->gearbox = *gearbox1;
    this->engine = *engine1;

}





float Car::getFuel() const {
    return fuel;
}

void Car::setFuel(float fuel) {
    this->fuel = fuel;
}

char Car::getTurnOnOff() const {
    return turn_on_off;
}

void Car::setTurnOnOff(char turnOnOff) {
    turn_on_off = turnOnOff;
}




void CarView::checkEngine(Car &car) {
    cout <<"engine condition: "<< car.engine.getCondition()<<endl;

    cout <<"oil level: "<< car.engine.getOilLevel()<<endl;
    cout <<"mileage: "<<car.engine.getCarMileage()<<endl;
    cout <<"fuel usage: "<<car.engine.getFuelUsage()<<endl;
    cout <<"fuel level: "<<car.getFuel()<<endl;
    getchar();

}
