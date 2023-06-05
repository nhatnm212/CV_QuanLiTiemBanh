#ifndef CTKM_H
#define CTKM_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Date.h"
#pragma warning(disable:4996)
using namespace std;

class ChuongTrinhKhuyenMai {
private:
    string maCT;
    string tenCT;
    int slKM;
    int slKMTang;
    int slKMGiam;
    double giaTriKM;
    Date ngayKM;
    string noiDungKM;
public:
    // Ham get - set: 
    string getmaCT();
    string gettenCT();
    int getslKM();
    int getslKMTang();
    int getslKMGiam();
    double getgiaTriKM();
    Date getngayKM();
    string getnoiDungKM();
    void setmaCT(string _maCT);
    void settenCT(string _tenCT);
    void setslKM(int _slKM);
    void setslKMTang(int _slKMTang);
    void setslKMGiam(int _slKMGiam);
    void setgiaTriKM(double _giaTriKM);
    void setngayKM(Date _ngayKM);
    void setnoiDungKM(string _noiDungKM);
    // Ham KTao - Huy: 
    ChuongTrinhKhuyenMai(string _maCT = " ", string _tenCT = " ", int _slKM = 0, int _slKMTang = 0, int _slKMGiam = 0, double _giaTriKM = 0, Date _ngayKM = Date(1,1,2000), string _noiDungKM = " ");
    ChuongTrinhKhuyenMai(const ChuongTrinhKhuyenMai& ct);
    ~ChuongTrinhKhuyenMai();
    // Nhap - Xuat: 
    friend istream& operator >> (istream& in, ChuongTrinhKhuyenMai& ct);
    friend ostream& operator << (ostream& out, ChuongTrinhKhuyenMai ct);
    // Ham bo tro: 
    void Doc_File_CT(ifstream& file, ChuongTrinhKhuyenMai& ct);
    void Doc_File_DSCT(ifstream& file, vector<ChuongTrinhKhuyenMai>& ds_ct);
    void Xuat_File_Thong_Tin_DSCT(ChuongTrinhKhuyenMai ct);
    void inDanhSachChuongTrinh(vector<ChuongTrinhKhuyenMai> ds_ct);
    void operator + (vector<ChuongTrinhKhuyenMai> ds_ct);
    void capNhatChuongTrinh(vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct);
    void capNhatSoLuongKM(vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct);
    void timKiemChuongTrinh(vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct);
    void xoa1CT(vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct);
    int ChonMenu();
    void MENU();
    void XuLyMenu(ifstream& file, vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct);
    //void operator = (const ChuongTrinhKhuyenMai& ct);
};

#endif
