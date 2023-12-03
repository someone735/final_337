#include "seat.h"
#include <iostream>
#include <fstream>
using namespace std;

Seat::Seat(): rowNum(0), seatNum(0){}

Seat::Seat(int row, int seat_col):rowNum(row), seatNum(seat_col){}
int Seat::get_rowNum() const{
    return rowNum;
}
int Seat::get_seatNum() const{
    return seatNum;
}
void Seat::set_rowNum(int row){
    this -> rowNum = row;
}
void Seat::set_seatNum(int seat_col){
    this -> rowNum = seat_col;
}
void Seat::seat_display() const
{
    cout << "Row: " << rowNum << ", Seat: " << char(seatNum +'A') << endl;
}