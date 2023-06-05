#ifndef NguyenLieu_H
#define NguyenLieu_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#pragma warning(disable:4996)
using namespace std;

class NguyenLieuTrongKho {
private:
    string tenNL;
    string maNL;
    int slNhap;
    int slXuat;
    int slTon;
    string dvTinh; 
public:
    // Get-Set: 
    void settenNL(string x);
    string gettenNL();
    void setmaNL(string x);
    string getmaNL();
    void setslNhap(int x);
    int getslNhap();
    void setslXuat(int x);
    int getslxuat();
    void setslTon(int x);
    int getslTon();
    void setdvTinh(string x); 
    string getdvTinh(); 
    // Khoitao-Huy: 
    NguyenLieuTrongKho(string _tenNL = " ", string _maNL = " ", int _slNhap = 0, int _slXuat = 0, int _slTon = 0, string _dvTinh = " ");
    NguyenLieuTrongKho(const NguyenLieuTrongKho& nl);
    ~NguyenLieuTrongKho();
    // Nhap-Xuat: 
    friend istream& operator>>(istream& in, NguyenLieuTrongKho& nl);
    friend ostream& operator<<(ostream& out, NguyenLieuTrongKho nl);
    // Ham bo tro: 
    void Doc_File_NL(ifstream& file, NguyenLieuTrongKho& nl);
    void Doc_File_DSNL(ifstream& file, vector<NguyenLieuTrongKho>& ds_nl);
    void Xuat_File_Thong_Tin_DSNL(NguyenLieuTrongKho nl);
    void inDSNL(vector<NguyenLieuTrongKho>ds_nl);
    void operator + (vector<NguyenLieuTrongKho>ds_nl);
    void TimKiemNL(vector<NguyenLieuTrongKho>ds_nl, NguyenLieuTrongKho nl);
    void CapnhatsoluongNL(vector<NguyenLieuTrongKho>ds_nl, NguyenLieuTrongKho nl);
    void XoaNL(vector<NguyenLieuTrongKho>ds_nl, NguyenLieuTrongKho nl);
    void MENU();
    int ChonMenu();
    void XuLyMenu(ifstream& file, vector < NguyenLieuTrongKho > ds_nl, NguyenLieuTrongKho& nl);
};

#endif 
