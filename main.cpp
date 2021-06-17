
#include "Car.h"


int main() {

   //Car car = Car();
   Car car2 = Car(GearBox("2137", "20-11-2010", "good", 4, 0), Engine("2137","22.11.2010", "good", false, 1000, 100,0,9), 90 );
    car2.start_engine();
    car2.move();
    return 0;
}

