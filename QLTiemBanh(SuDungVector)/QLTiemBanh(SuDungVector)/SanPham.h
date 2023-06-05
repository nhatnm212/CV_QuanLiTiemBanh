#ifndef SanPham_H
#define SanPham_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Date.h"
#pragma warning(disable:4996)
using namespace std; 

class SanPham {
private:
    string maSP;
    string tenSP;
    double soLuongSPCL;
    double soLuongTang;
    double soLuongGiam;
    double donGiaSP;
    string donViTinhSP;
    Date ngaySXSP;
    Date ngayHHSP;
public:
    // Ham get - set: 
    string GETmaSP();
    void SETmaSP(string _maSP);
    string GETtenSP();
    void SETtenSP(string _tenSP);
    double GETsoLuongSPCL();
    void SETsoLuongSPCL(double _soLuongSPCL);
    double GETsoLuongTang();
    void SETsoLuongTang(double _soLuongSPTang);
    double GETsoLuongGiam();
    void SETsoLuongGiam(double _soLuongSPGiam);
    double GETdonGiaSP();
    void SETdonGiaSP(double _donGiaSP);
    string GETdonViTinhSP();
    void SETdonViTinhSP(string _donViTinhSP);
    Date GETngaySXSP();
    void SETngaySXSP(Date _ngaySXSP);
    Date GETngayHHSP();
    void SETngayHHSP(Date _ngayHHSP);
    // Ham KTao - Huy: 
    SanPham(string _maSP = " ", string _tenSP = " ", double _donGiaSP = 0, string donViTinhSP = " ", Date _ngaySXSP = Date(1,1,2000), Date _ngayHHSP = Date(1,1,2000), double _soLuongSPTang = 0, double _soLuongSPGiam = 0, double _soLuongSPCL = 0);
    SanPham(const SanPham& sp);
    ~SanPham();
    // Nhap - Xuat: 
    friend istream& operator >> (istream& in, SanPham& sp);
    friend ostream& operator << (ostream& out, SanPham sp);
    // Ham bo tro: 
    void Doc_File_SP(ifstream& file, SanPham& sp);
    void Doc_File_DSSP(ifstream& file, vector<SanPham>& ds_sp);
    virtual void Xuat_File_Thong_Tin_DSSP(SanPham sp);
    void inDSSP(vector<SanPham> ds_sp);
    void timKiemSP(vector<SanPham> ds_sp, SanPham sp);
    void capNhatSoLuongSP(vector<SanPham> ds_sp, SanPham sp);
    void operator + (vector<SanPham>ds_sp);
    void xoa1SP(vector<SanPham> ds_sp, SanPham sp);
    virtual void MENU();
    int ChonMenu();
    void XuLyMenu(ifstream& file, vector<SanPham> ds_sp, SanPham sp);
};

#endif; 
