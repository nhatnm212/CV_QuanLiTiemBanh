#ifndef ConNguoi_H
#define ConNguoi_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#pragma warning(disable:4996)
using namespace std;

class ConNguoi {
private:
	string maSo;
	string hoTen;
	string ngaySinh;
	string soDT;
public:
	// Ham get-set: 
	string getmaSo();
	string gethoTen();
	string getngaySinh();
	string getsoDT();
	void setmaSo(string _maSo);
	void sethoTen(string _hoTen);
	void setngaySinh(string _ngaySinh);
	void setsoDT(string _soDT);
	
	// Ham khoi tao - Huy: 
	ConNguoi(string _maSo = " ", string _hoTen = " ", string _ngaySinh = " ", string _soDT = " ");
	ConNguoi(const ConNguoi& n);
	~ConNguoi();
	// Nhap - Xuat: 
	friend istream& operator >> (istream& in, ConNguoi& n);
	friend ostream& operator << (ostream& out, ConNguoi n);
	// Ham bo tro: 
	//void Doc_File_N(ifstream& file, ConNguoi& n);
	//void Doc_File_DSN(ifstream& file, vector<ConNguoi>& ds_n);
	//void Xuat_File_Thong_Tin_DSN(ConNguoi n);
	//void inDSN(vector<ConNguoi>ds_n);
	//void operator + (vector<ConNguoi>ds_n);
	//void timKiemN(vector<ConNguoi>ds_n, ConNguoi n);
	//void xoa1N(vector<ConNguoi> ds_n, ConNguoi n);
	//void CapnhatthongtinN(vector<ConNguoi> ds_n, ConNguoi n);
	int ChonMenu();
	virtual void MENU(); 
	void XuLyMenu(ifstream& file, vector<ConNguoi> ds_n, ConNguoi& n);
};

#endif; 
