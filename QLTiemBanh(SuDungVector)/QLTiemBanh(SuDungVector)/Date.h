#ifndef Date_H
#define Date_H
#include <iostream>
#include <iomanip>
#pragma warning(disable:4996)
using namespace std;

class Date {
private:
    int d, m, y;
public:
    // Ham Get-Set: 
    int getd() { return d; }
    int getm() { return m; }
    int gety() { return y; }
    void setd(int d) { this->d = d; }
    void setm(int m) { this->m = m; }
    void sety(int y) { this->y = y; }
    // Ham khoi tao - huy: 
    Date(int _d = 0, int _m = 0, int _y = 0) {
        d = _d;         m = _m;         y = _y;
    }
    Date(const Date& date) {
        d = date.d;     m = date.m;     y = date.y;
    }
    ~Date() {}
    // Nhap - Xuat: 
    friend istream& operator >> (istream& in, Date& date) {
        in >> date.d >> date.m >> date.y;
        return in;
    }
    friend ostream& operator << (ostream& out, Date date) {
        if (date.kiemTra()) {
            out << right << setw(2) << date.d;
            out << " " << right << setw(2) << date.m;
            out << " " << right << setw(4) << date.y;
        }
        else {
            out << "Khong hop le!";
        }
        return out;
    }
    // Ham bo tro: 
    bool kiemTra() {

        if (d > 0 && d < 32 && m > 0 && m < 13 && y > 0) {
            if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31) {
                return true;
            }
            if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31) {
                return false;
            }
            if ((m == 4 || m == 6 || m == 9 || m == 11) && d <= 30) {
                return true;
            }
            if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
                return false;
            }
            if ((namNhuan() == true) && m == 2 && d <= 29) {
                return true;
            }
            if ((namNhuan() == false) && m == 2 && d <= 28) {
                return true;
            }
        }
        else {
            return false;
        }
    }
    bool namNhuan() {
        if (y % 400 == 0)
            return true;
        else if ((y % 100 != 0) && (y % 4 == 0))
            return true;
        else
            return false;
    }
};
#endif; 