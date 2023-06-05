#include <iostream>
#include <cmath>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "ConNguoi.h" 
#include "NguyenLieu.h"
#include "NhanVien.h"
#include "KhachHang.h"
#include "SanPham.h"
#include "HoaDon.h"
#include "CTMK.h"
#include "Food.h" 
#include "Drink.h" 
#include "MatKhau.h" 
#pragma warning(disable:4996)
using namespace std;

int main () 
{
    MatKhau mk; 
    vector<MatKhau> ds_mk; 

    mk.soSanhMK(ds_mk, mk); 

    return 0;
}
