#ifndef Food_H
#define Food_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring> 
#include "SanPham.h" 
#include "HoaDon.h" 
//#pragma warning(disable:4996) 
using namespace std;

class Food : public SanPham {
public: 
    Food(string _maSP = " ", string _tenSP = " ", double _donGiaSP = 0, string donViTinhSP = " ", Date _ngaySXSP = Date(1,1,2000), Date _ngayHHSP = Date(1,1,2000), double _soLuongSPTang = 0, double _soLuongSPGiam = 0, double _soLuongSPCL = 0);
    Food(const Food& f);
    ~Food();
    // Nhap - Xuat: 
    friend istream& operator >> (istream& in, Food& f);
    friend ostream& operator << (ostream& out, Food f);
    // Ham bo tro: 
    void Doc_File_SP(ifstream& file, Food& f);
    void Doc_File_DSSP(ifstream& file, vector<Food>& ds_f);
    void Xuat_File_Thong_Tin_DSSP(Food f);
    void inDSSP(vector<Food> ds_f);
    void timKiemSP(vector<Food> ds_f, Food f);
    void capNhatSoLuongSP(vector<Food> ds_f, Food f);
    void operator + (vector<Food>ds_f);
    void xoa1SP(vector<Food> ds_f, Food f);
    void MENU(); 
    int ChonMenu();
    void XuLyMenu(ifstream& file, vector<Food> ds_f, Food f);
    //void SLSP_HD();
};

#endif; 
