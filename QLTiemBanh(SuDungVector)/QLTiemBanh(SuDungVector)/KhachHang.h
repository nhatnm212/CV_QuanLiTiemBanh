#ifndef KhachHang_H
#define KhachHang_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Date.h"
#include "ConNguoi.h" 
#include "HoaDon.h" 
#pragma warning(disable:4996)
using namespace std;

class KhachHang : public ConNguoi, public HoaDon {
private:
    Date ngayDKTheKH;
    double soDiemKH;
    double diemCongKH;
public:
    // Ham get - set: 
    void setNgDangKyThe(int x);
    void setNgDangKyThe(Date x);
    void setNgDKTheKH(Date x);
    Date getNgDangKyThe();
    void setSoDiem(double x);
    double getSoDiem();
    void setDiemC(double x);
    double getDiemC();
    // Ham khoi tao - huy: 
    KhachHang(string _maKH = " ", string _hoTen = " ", string _ngaySinh = " ", string _soDT = " ", Date _ngayDKTheKH = Date(1,1,2022), double _soDiemKH = 0);
    KhachHang(const KhachHang& kh);
    ~KhachHang();
    // Nhap - Xuat: 
    friend istream& operator>>(istream& in, KhachHang& kh);
    friend ostream& operator<<(ostream& out, KhachHang kh);
    // Ham bo tro: 
    void Doc_File_N(ifstream& file, KhachHang& kh);
    void Doc_File_DSN(ifstream& file, vector<KhachHang>& ds_kh);
    void Xuat_File_Thong_Tin_DSN(KhachHang kh);
    void inDSN(vector<KhachHang>ds_kh);
    void capNhatN(vector < KhachHang> ds_kh, KhachHang kh);
    void xoa1N(vector<KhachHang> ds_kh, KhachHang kh);
    void operator + (vector<KhachHang> ds_kh);
    void timKiemN(vector<KhachHang> ds_kh, KhachHang kh);
    void xepHangKH(KhachHang kh);
    void congdiemKH(vector<KhachHang> ds_kh, KhachHang kh);
    int ChonMenu();
    void MENU();
    void XuLyMenu(ifstream& file, vector<KhachHang> ds_kh, KhachHang kh);
    int soLanMuaHang(); 
};

#endif 
