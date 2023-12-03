#include "airline.h"
#include "passenger.h"
#include "flight.h"
#include "seat.h"
#include "airline.cpp"
#include "passenger.cpp"
#include "flight.cpp"
#include "seat.cpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <limits>

using namespace std;

void displayHeader();
void pressEnter();
void cleanInput();
int menu();
void flightAddPassenger();

int main(){
    displayHeader();
    Flight f;
    f.populate_flight_from_file("flight_info.txt");
    f.displaySeatMap();
    f.displayPassengers();
    // while(1){
    //     switch(menu()){
    //         case 1:
    //         cout << "Choice 1: Display Flight Seat Map"  << endl;

    //             pressEnter();
    //             break;
    //         case 2:
    //         cout << "Choice 2: Display Passengers Information" << endl;

    //             pressEnter();
    //             break;
    //         case 3: 
    //         cout << "Choice 3: Add a new Passenger" << endl;
    //             flightAddPassenger();


    //             pressEnter();
    //             break;
    //         case 4: 
    //         cout << "Choice 4: Remove an Existing Passenger" << endl;

    //             pressEnter();
    //             break;
    //         case 5: 
    //         cout << "Choice 5: Save data" << endl;

    //             pressEnter();
    //             break;
    //         case 6:
    //             cout << "Ending program";
    //             exit(1);
    //     }
    // }
}

void displayHeader(){
    cout << "Version 1.0" << endl;
    cout << "Term Project - Flight Management Program in C++" << endl;
    cout << "Produced by: John Tumacder, Noor ul Islam, Syed Waliullah" << endl;
    cout << "Year: 2023" << endl;
    pressEnter();
}
void pressEnter(){
    cout << "\nPress Enter to Continue" << endl;
    cin.ignore();
}

void cleanInput(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int menu(){
    int input = 0;
    cout << "Please select one of the following options:" << endl;
    cout << "1. Display Flight Seat Map" << endl;
    cout << "2. Display Passengers Information" << endl;
    cout << "3. Add a new Passenger" << endl;
    cout << "4. Remove an Existing Passenger" << endl;
    cout << "5. Save data" << endl;
    cout << "6. Quit" << endl << endl;
    cout << "Select option: 1, 2, 3, 4, 5, 6" << endl;
    while (!(cin >> input) || !(input >= 1) || !(input <= 6)) {
        cout << "invalid input" << endl;
        cout << "Please select one of the following options:" << endl;
        cout << "1. Display Flight Seat Map" << endl;
        cout << "2. Display Passengers Information" << endl;
        cout << "3. Add a new Passenger" << endl;
        cout << "4. Remove an Existing Passenger" << endl;
        cout << "5. Save data" << endl;
        cout << "6. Quit" << endl << endl;
        cout << "Select option: 1, 2, 3, 4, 5, 6" << endl;
        cleanInput();
        cout << input;
    }
    return input;

    
}

void flightAddPassenger(){
    string fName, lName, phone;
    char seatCol;
    int rowNum, passId;
    cout << "Enter passenger's id name";
    cin >> passId;
    cout << "Enter passenger's first name";
    cin >> fName;
    cout << "Enter passenger's last name";
    cin >> lName;
    cout << "Enter passenger's phone number ";
    cin >> phone;
    cout << "Enter passenger's seat number";
    cin >> rowNum;
    cout << "Enter passenger's row letter";
    cin >> seatCol;
}