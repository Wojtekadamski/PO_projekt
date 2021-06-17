//
// Created by Wojtek on 25.03.2021.
//

#ifndef PO_PROJEKT_CAR_H
#define PO_PROJEKT_CAR_H


#include "Wheels.h"
#include <ios>
#include "CarPart.h"
#include "iostream"
#include <ios>
#include "CarPart.h"

/**
 *
 * Klasa Silnik definiuje nam motor w samochodzie. Dziedziczy po CarPart.
 * @param bool state - przechowuje stan silnika
 * @param engine_speed - przechowuje obroty
 * @param oil_level - przechowuje aktualny stan oleju
 * @param car_mileage - przechowuje przebieg
 * @param fuel_usage - przechowuje spalanie
 *
 */
class Engine : public CarPart {
private:
    bool state;
    int engine_speed;
    float oil_level;
    double car_mileage;
    unsigned int fuel_usage;
public:
    void setFuelUsage(unsigned int fuelUsage);

    Engine(const std::string &vin, const std::string &productionDate, const std::string &condition, bool state,
           int engineSpeed, float oilLevel, double carMileage, unsigned int fuelUsage);


    unsigned int getFuelUsage() const;

    Engine();

    bool getState() const;

    void setState(bool state);

    int getEngineSpeed() const;

    void setEngineSpeed(int engineSpeed);

    float getOilLevel() const;

    void setOilLevel(float oilLevel);

    double getCarMileage() const;

    void setCarMileage(double carMileage);

    std::string  getCondition() const;

};
class EngineView{

//TODO write to string

};
/**
 *
 * Klasa GearBox definiuje skrzynię biegów w samochodzi
 *
 * @param TOP_GEAR - maksymalny bieg
 * @param current_gear - obecny bieg
 */
class GearBox : public CarPart {
private:
    int TOP_GEAR;
    int current_gear;

public:
    GearBox();

    GearBox(const std::string &vin, const std::string &productionDate, const std::string &condition, const int topGear,
            int currentGear);

    int getTopGear() const;

    int getCurrentGear() const;

    void setCurrentGear(int currentGear);

    bool gearUp(Engine *engine);

    bool gearDown(Engine *engine);

};

/**
 * @param turn_on_off - zawiera informację czy silnik działa
 * @param speed - aktualna prędkość
 * @param fuel - ilość paliwa
 * @param gearbox - kompozycja, obiekt reprezentujący skrzynię biegów
 * @param engine - kompozycja, obiekt reprezentujący silnik
 */
class Car {
private:

    char turn_on_off;
    unsigned int speed = 0;
    float fuel;


public:
    GearBox gearbox;
    Engine engine;

    unsigned int getSpeed() const {
        return speed;
    }

    void setSpeed(unsigned int speed) {
        Car::speed = speed;
    }


    char getTurnOnOff() const;

    void setTurnOnOff(char turnOnOff);

    Car();

    Car(const GearBox& gearbox, const Engine& engine, float fuel);

    float getFuel() const;

    void setFuel(float fuel);
    //unsigned int localEnginespeed = engine.getEngineSpeed();


};

class CarView{

public:

    void checkEngine(Car &car);

};
/**
 *
 * kontroler do Modelu car
 * @param model - model samochodu
 * @param view - widok samochodu
 */
class CarController{

    private:
    Car model;
    CarView view;
public:
    CarController(Car model, CarView view){
        this->model = model;
        this->view = view;
    }
    void start_engine();


    void accelerate();

    void brake();

    void move();
    const Car getModel() const;
};


#endif //PO_PROJEKT_CAR_H
