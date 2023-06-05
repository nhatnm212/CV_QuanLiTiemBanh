#ifndef NhanVien_H
#define Nhanvien_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "ConNguoi.h" 
#include "HoaDon.h"
#pragma warning(disable:4996)
using namespace std;

class NhanVien : public ConNguoi, public HoaDon {
private:
    string trangThai;
    string chucVu;
    int soLanDiTre;
    double luongTheoH;
    double tongLuong;
    int soGioLam;
    int soNgayLamViec;
    int soNgayNghi;
public:
    // Ham get-set: 
    string gettrangThai();
    string getchucVu();
    int getsoLanDiTre();
    double getluongTheoH();
    double gettongLuong();
    int getsoGioLam();
    int getsoNgayLamViec();
    int getsoNgayNghi();
    void settrangThai(string trangThai);
    void setchucVu(string chucVu);
    void setsoLanDiTre(int soLanDiTre);
    void setluongTheoH(double luongTheoH);
    void settongLuong(double tongLuong);
    void setsoGioLam(int soGiaLam);
    void setsoNgayLamViec(int soNgayLamViec);
    void setsoNgayNghi(int soNgayNghi);
    // Ham khoi tao - Ham sao chep - Ham huy: 
    NhanVien(string _maNV = " ", string _hoTen = " ", string _ngaySinh = " ", string _soDT = " ", string _trangThai = " ", string _chucVu = " ", int _soLanDiTre = 0, double _luongTheoH = 0, double _tongLuong = 0, int _soNgayLamViec = 0, int _soNgayNghi = 0, int soGioLam = 0);
    NhanVien(const NhanVien& nv);
    ~NhanVien();
    // Ham nhap - xuat: 
    friend istream& operator >> (istream& in, NhanVien& nv);
    friend ostream& operator << (ostream& out, NhanVien nv);
    // Ham bo tro: 
    void Doc_File_N(ifstream& file, NhanVien& nv);
    void Doc_File_DSN(ifstream& file, vector<NhanVien>& ds_nv);
    void Xuat_File_Thong_Tin_DSN(NhanVien nv);
    void inDSN(vector<NhanVien>ds_nv);
    void operator + (vector<NhanVien>ds_nv);
    void timKiemN(vector<NhanVien>ds_nv, NhanVien nv);
    void xoa1N(vector<NhanVien> ds_nv, NhanVien nv);
    void chamCong(vector < NhanVien> ds_nv, NhanVien& nv);
    void tinhLuongNV(NhanVien& nv);
    void CapnhatthongtinN(vector < NhanVien> ds_nv, NhanVien nv);
    void checkLuongNV(vector < NhanVien> ds_nv, NhanVien& nv);
    int ChonMenu();
    void MENU();
    void XuLyMenu(ifstream& file, vector < NhanVien> ds_nl, NhanVien& nv);
    int soLanBanHang(); 
};

#endif 
