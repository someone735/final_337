#include "flight.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

#ifndef AIRLINE_H
#define AIRLINE_H

#include "Flight.h"

class Airline
{
public:
    Airline();
    const Flight& getFlight() const;

private:
    Flight flight;
};

#endif // AIRLINE_H

