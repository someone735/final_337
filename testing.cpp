#include <sstream>
#include<vector>
#include<string>
#include <iostream>
#include <fstream>
#include "flight.h"
#include "airline.h"
#include "passenger.h"
#include "seat.h"
#include "airline.cpp"
#include "flight.cpp"
#include "passenger.cpp"
#include "seat.cpp"

int main(){
    Seat s(1,2);
    Passenger p("Bill William","Harris", "403-100-0000", s, 10000);
    p.pass_display();
}