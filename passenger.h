#ifndef MY_PASSENGER_CLASS
#define MY_PASSENGER_CLASS

#include "seat.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Passenger
{
public:
    Passenger(const string &fName, const string &lName,
              const string &phone, const Seat &seat, int passengerID);
    string getFName() const;
    string getLName() const;
    string getPhone() const;
    Seat getSeat() const;
    int getPassId() const;
    void setFName(const string &fName);
    void setLName(const string &lName);
    void setPhone(const string &phone);
    void setPassSeat(const Seat &seat);
    void setPassId(int passengerID);
    void pass_display() const;
private:
    string fName;
    string lName;
    string phone;
    Seat passSeat;
    int passId;
};
#endif