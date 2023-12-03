#ifndef MY_SEAT_CLASS
#define MY_SEAT_CLASS
class Seat
{
public:
    Seat();
    Seat(int row, int seat_col);
    int get_rowNum() const;
    int get_seatNum() const;
    void set_rowNum(int row);
    void set_seatNum(int seat_col);
    void seat_display() const;
private:
    int rowNum, seatNum;
};
#endif