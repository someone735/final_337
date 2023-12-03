#include "airline.h"

Airline::Airline() : flight("WJ1045", 20, 5) {}

const Flight& Airline::getFlight() const
{
    return flight;
}
