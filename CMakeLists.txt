cmake_minimum_required(VERSION 3.17)
project(PO_projekt)

set(CMAKE_CXX_STANDARD 14)

add_executable(PO_projekt main.cpp CarPart.cpp CarPart.h GearBox.cpp GearBox.h Engine.cpp Engine.h Car.cpp Car.h Wheels.cpp Wheels.h Rims.cpp Rims.h Tire.cpp Tire.h)