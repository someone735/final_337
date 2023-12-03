#include "passenger.h"
#include "seat.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
Passenger::Passenger(const string &input_fName, const string &input_lName,
                     const string &input_phone, const Seat &input_seat, int input_passID)
    : fName(input_fName), lName(input_lName), phone(input_phone),
      passSeat(input_seat), passId(input_passID) {}

string Passenger::getFName() const { 
    return fName; 
    }
string Passenger::getLName() const { 
    return lName; 
    }
string Passenger::getPhone() const { 
    return phone; 
    }
Seat Passenger::getSeat() const { 
    return passSeat; 
    }
int Passenger::getPassId() const { 
    return passId; 
    }

void Passenger::setFName(const string &input_fName) { 
    fName = input_fName; 
    }
void Passenger::setLName(const string &input_lName) { 
    lName = input_lName; 
    }
void Passenger::setPhone(const string &input_phone) { 
    phone = input_phone; 
    }
void Passenger::setPassSeat(const Seat &input_seat) { 
    passSeat = input_seat; 
    }
void Passenger::setPassId(int input_passID){ 
    passId = input_passID; 
    }

void Passenger::pass_display() const
{
    int spaces = 21-fName.size();
    cout << fName;
    while(spaces>0){
        cout << ' ';
        spaces--;
    }
    spaces = 21 - fName.size();
    cout << lName;
    while(spaces>0){
        cout << ' ';
        spaces--;
    }
    spaces = 21 - fName.size();
    cout << phone;
    while(spaces>0){
        cout << ' ';
        spaces--;
    }
    cout <<passSeat.get_rowNum()<<char(passSeat.get_seatNum()+'A') 
        << ' ' <<passId;
}
