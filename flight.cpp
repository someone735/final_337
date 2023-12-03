// Implementation for Flight class
#include "passenger.h"
#include "flight.h"
#include "seat.h"
using namespace std;

Flight::Flight(): flightID(), rows(0), seatsPR(0){}

Flight::Flight(const string &flightNo, int row, int seats)
    : flightID(flightNo), rows(row), seatsPR(seats) {}

void Flight::populate_flight_from_file(const string &fileName)
{
    ifstream file("flight_info.txt");

    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    // Read flight number, rows, and seats per row
    file >> flightID >> rows >> seatsPR;
    createSeatMap(); // Initialize the seat map

    string line;
    getline(file, line); // Skip to the next line
    while (getline(file, line))
    {
        istringstream iss(line);
        char fntest[21], lntest[21], phtest[21];
        string fName, lName, phone;
        int row, passId;
        char passSeat;
        iss.get(fntest, 21, '\n');
        iss.get(lntest, 21, '\n');
        iss.get(phtest, 21, '\n');
        fName = fntest;
        lName = lntest;
        phone = phtest;
        if (!(iss >> row >> passSeat >> passId))
        {
            break;
        }

        Seat new_seat(row, passSeat);
        Passenger new_passenger(fName, lName, phone, new_seat, passId);
        passengers.push_back(new_passenger);
    }

    file.close();
}

void Flight::displayPassengers() const
{
    for (const auto &passenger : passengers)
    {
        passenger.pass_display();
    }
}

void Flight::addPassenger(const Passenger &passenger)
{
    passengers.push_back(passenger);
}

void Flight::removePassenger(int id)
{
    passengers.erase(
        remove_if(passengers.begin(), passengers.end(),
                       [id](const Passenger &p)
                       { return p.getPassId() == id; }),
        passengers.end());
}

void Flight::saveDataToFile(const string &fileName)
{
    ofstream file("flight_info.txt");

    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    for (const auto &passenger : passengers)
    {
        Seat seat = passenger.getSeat();
        file << passenger.getFName() << " "
             << passenger.getLName() << " "
             << passenger.getPhone() << " "
             << seat.get_rowNum() << seat.get_seatNum() << " "
             << passenger.getPassId() << endl;
    }

    file.close();
}

void Flight::createSeatMap()
{
    for (int i = 1; i <= rows; i++)
    {
        vector<Seat> rowSeats;
        for (char j = 'A'; j < 'A' + seatsPR; j++)
        {
            rowSeats.emplace_back(i, j);
        }
        seatMap[i] = rowSeats;
    }
}

void Flight::displaySeatMap() const
{
    cout << "\n Seat Map for Flight: " << flightID << "\n";
    cout << "     Aircraft Seat Map\n";
    cout << "     ";
    for (int i = 0; i < seatsPR; i++){
        cout<<char('A' + i)<< "   ";
    }
    cout<< endl;
    for (const auto &row : seatMap)
    {
        cout << "   ";
        for (int i = 0; i < seatsPR; i++){
            cout<<"+---";
        }
        cout <<"+"<< endl << "   |";
        for (const auto &seat : row.second)
        {
            bool isOccupied = any_of(passengers.begin(), passengers.end(),
                                          [&](const Passenger &p)
                                          { return p.getSeat().get_rowNum() == seat.get_rowNum() &&
                                                   p.getSeat().get_seatNum() == seat.get_seatNum(); });
            cout << (isOccupied ? " X |" : "   |");
        }
        cout << " Row " << row.first << endl;
    }
}