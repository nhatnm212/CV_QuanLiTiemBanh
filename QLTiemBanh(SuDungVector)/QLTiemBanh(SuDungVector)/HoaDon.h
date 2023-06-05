#ifndef HoaDon_H
#define HoaDon_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Date.h" 
#include "CTMK.h" 
#include "SanPham.h" 
#include "Food.h" 
#include "Drink.h" 
#pragma warning(disable:4996)
using namespace std;

class HoaDon : public ChuongTrinhKhuyenMai {
private:
    string maHD;
    Date ngayHD;
    string tenNV_HD; // Nguoi ban 
    string tenKH_HD; // Nguoi mua 
    string cacSPMua[20];
    int slCacSPMua;
    int slTungSP[20];
    double tienTungSP[20];
    double giamGiaHD;
    double TongTien;
    string maKM; 
public:
    // Ham get - set: 
    string getmaHD();
    Date getngayHD();
    string gettenNV_HD();
    string gettenKH_HD();
    int getslCacSPMua();
    string getmaKM(); 
    string getcacSPMua(); 
    double getTongTien(); 
    double getgiamGiaHD();
    int getslTungSP(); 
    void setmaHD(string maHD);
    void setngayHD(Date ngayHD);
    void settenNV_HD(string tenNV_HD);
    void settenKH_HD(string tenKH_HD);
    void setslCacSPMua(int slCacSPMua);
    void setgiamGiaHD(double giamGiaHD);
    void setmaKM(string maKM); 
    // Ham KTao - Huy: 
    HoaDon(string _maHD = " ", Date _ngayHD = Date(1,1,2000), string _tenNV_HD = " ", string _tenKH_HD = " ", string _cacSPMua[] = new string[1], int _slCacSPMua = 0, int _slTungSP[] = new int[1], double _tienTungSP[] = new double[1], string _maKM = " ", double _giamGiaHD = 0);
    HoaDon(const HoaDon& hd);
    ~HoaDon();
    // Nhap - Xuat: 
    friend istream& operator >> (istream& in, HoaDon& hd);
    friend ostream& operator << (ostream& out, HoaDon hd);
    // Ham bo tro: 
    void Doc_File_HD(ifstream& file, HoaDon& hd);
    void Doc_File_DSHD(ifstream& file, vector<HoaDon>& ds_hd);
    void Xuat_File_Thong_Tin_DSHD(HoaDon hd);
    void inDanhSachHoaDon(vector<HoaDon> ds_hd);
    void timKiemHoaDon(vector<HoaDon> ds_hd, HoaDon hd);
    double tinhThanhTien1HD();
    void operator + (vector<HoaDon> ds_hd);
    void xoaHoaDon(vector<HoaDon> ds_hd, HoaDon hd);
    int ChonMenu();
    void MENU();
    void XuLyMenu(ifstream& file, vector<HoaDon> ds_hd, HoaDon hd);
    double apDungMaKM();
};

#endif
