#ifndef MY_FLIGHT_CLASS
#define MY_FLIGHT_CLASS
#include "passenger.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
class Flight
{
private:
    string flightID;
    int rows;
    int seatsPR;
    vector<Passenger> passengers;
    map<int, vector<Seat>> seatMap;

public:
    Flight();
    Flight(const string &flightID, int row, int seats);
    void populate_flight_from_file(const string &fileName);
    void displayPassengers() const;
    void addPassenger(const Passenger &passenger);
    void removePassenger(int id);
    void saveDataToFile(const std::string &fileName);
    void createSeatMap();
    void displaySeatMap() const;
};
#endif