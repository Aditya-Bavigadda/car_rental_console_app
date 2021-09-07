#pragma once
#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#include "string.h"
class Ferrari_Car
{
    friend std::ostream& operator << (std::ostream& output, Ferrari_Car car);
    public:
        Ferrari_Car();
        Ferrari_Car(std::string Name, std::string engine, int year, int horsepower, bool four_wheel_drive, int top_speed) :
            Name(Name),
            engine(engine),
            year(year),
            horsepower(horsepower),
            four_wheel_drive(four_wheel_drive),
            top_speed(top_speed) {}
    private:
        std::string Name;
        std::string engine;
        int year;
        int horsepower;
        bool four_wheel_drive;
        int top_speed;
        //int base_price; maybe
};
Ferrari_Car Superfast{ "Ferrari 812 Superfast", "6.5L V12", 2017, 789, false, 340};
Ferrari_Car GTS{ "Ferrari 812 GTS", "6.2L nat asp V12", 2019, 789, false, 338};
Ferrari_Car Stradale{ "Ferrari SF90 Stradale", "4.0L TT V8 + 3 electric", 2019, 989, true, 340};
Ferrari_Car SFSpider{ "Ferrari SF90 Spider", "4.0L TT V8 + 3 electric", 2020, 989, false, 340};
Ferrari_Car Tributo{ "Ferrari F8 Tributo", "3.9L twin-turbo V8", 2019, 710, false, 340};
Ferrari_Car F8Spider{ "Ferrari F8 Spider", "3.9L twin-turbo V8", 2019, 710, false, 340};
Ferrari_Car Roma{ "Ferrari Roma", "3.9L twin-turbo V8", 2020, 612, false, 320};
Ferrari_Car Portofino{ "Ferrari Portofino M", "3.9L twin-turbo V8", 2017, 612, false, 320};
Ferrari_Car MonzaSP1{ "Ferrari Monza SP1", "6.5 L nat asp V12", 2019, 810, false, 299};
Ferrari_Car MonzaSP2{ "Ferrari Monza SP2", "6.5 L nat asp V12" , 2019, 810, false, 299};

std::ostream& operator << (std::ostream& output, Ferrari_Car car); //allows us to print the car stats
void rent_car(std::vector<std::string> availablecars, std::string owner, std::vector<std::string> carlist);
void renting_process(std::string owner); //user can rent a car
void car_interaction(std::string owner); //allows user to buy or sell cars
#include "cars.cpp"
