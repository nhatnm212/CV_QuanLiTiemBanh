#ifndef Drink_H
#define Drink_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream> 
#include "SanPham.h" 
#include "HoaDon.h" 
#pragma warning(disable:4996)
using namespace std;

class Drink : public SanPham {
public:
    Drink(string _maSP = " ", string _tenSP = " ", double _donGiaSP = 0, string donViTinhSP = " ", Date _ngaySXSP = Date(1,1,2000), Date _ngayHHSP = 0, double _soLuongSPTang = 0, double _soLuongSPGiam = 0, double _soLuongSPCL = 0);
    Drink(const Drink& f);
    ~Drink();
    // Nhap - Xuat: 
    friend istream& operator >> (istream& in, Drink& f);
    friend ostream& operator << (ostream& out, Drink f);
    // Ham bo tro: 
    void Doc_File_SP(ifstream& file, Drink& f);
    void Doc_File_DSSP(ifstream& file, vector<Drink>& ds_f);
    void Xuat_File_Thong_Tin_DSSP(Drink f);
    void inDSSP(vector<Drink> ds_f);
    void timKiemSP(vector<Drink> ds_f, Drink f);
    void operator + (vector<Drink>ds_f);
    void xoa1SP(vector<Drink> ds_f, Drink f);
    void MENU();
    int ChonMenu();
    void XuLyMenu(ifstream& file, vector<Drink> ds_f, Drink f);
};

#endif; 
