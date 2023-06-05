#include "Food.h" 

Food::Food(string _maSP, string _tenSP, double _donGiaSP, string donViTinhSP, Date _ngaySXSP, Date _ngayHHSP, double _soLuongSPTang, double _soLuongSPGiam, double _soLuongSPCL) : SanPham(_maSP, _tenSP, _donGiaSP, donViTinhSP, _ngaySXSP, _ngayHHSP, _soLuongSPTang, _soLuongSPGiam, _soLuongSPCL) {}
Food::Food(const Food& f) : SanPham(f) {}
Food::~Food() {}
// Nhap - Xuat: 
istream& operator >> (istream& in, Food& f) {
    string maSP, tenSP;
    double donGiaSP, soLuongSPCL; 
    string donViTinhSP;
    Date ngaySXSP, ngayHHSP;
    cout << "\n Nhap ma SP: ";               getline(in, maSP);
    cout << " Nhap ten SP: ";                getline(in, tenSP);
    cout << " Nhap don gia: ";               in >> donGiaSP;
    cout << " Nhap so luong SP: ";           in >> soLuongSPCL;
    in.ignore();
    cout << " Nhap don vi tinh: ";           getline(in, donViTinhSP);
    cout << " Nhap NSX: ";                   in >> ngaySXSP;
    cout << " Nhap HSD:  ";                  in >> ngayHHSP;
    in.ignore();
    cout << endl;
    f = Food(maSP, tenSP, donGiaSP, donViTinhSP, ngaySXSP, ngayHHSP, 0, 0, soLuongSPCL); 
    return in;
}
ostream& operator << (ostream& out, Food f) {
    out << f.GETmaSP() << ",";
    out << f.GETtenSP() << ",";
    out << f.GETdonViTinhSP() << ",";
    out << f.GETdonGiaSP() << " ";
    out << f.GETsoLuongSPCL() << endl;
    out << f.GETngaySXSP() << endl;
    out << f.GETngayHHSP() << endl;
    return out;
}
// Ham bo tro: 
void Food::Doc_File_SP(ifstream& file, Food& f) {
    string maSP, tenSP;
    double donGiaSP, soLuongSPCL;
    string donViTinhSP;
    Date ngaySXSP, ngayHHSP;
    getline(file, maSP, ',');
    getline(file, tenSP, ',');
    getline(file, donViTinhSP, ',');
    file >> donGiaSP;
    file >> soLuongSPCL;
    string temp;
    file >> ngaySXSP;
    file >> ngayHHSP;
    getline(file, temp);
    f = Food(maSP, tenSP, donGiaSP, donViTinhSP, ngaySXSP, ngayHHSP, 0, 0, soLuongSPCL);
}
void Food::Doc_File_DSSP(ifstream& file, vector<Food>& ds_f) {
    while (file.eof() == false)
    {
        Food f;
        Doc_File_SP(file, f);
        ds_f.push_back(f);
    }
}
void Food::Xuat_File_Thong_Tin_DSSP(Food f) {
    cout << setw(7) << left << f.GETmaSP();
    cout << setw(30) << left << f.GETtenSP();
    cout << setw(10) << left << f.GETdonGiaSP();
    cout << setw(10) << left << f.GETsoLuongSPCL();
    cout << setw(15) << left << f.GETngayHHSP() << "     ";
    cout << setw(15) << left << f.GETngayHHSP();
    cout << endl;
}
void Food::inDSSP(vector<Food> ds_f) {
    cout << "_________________________________________________________________________________________________ " << endl << endl;
    cout << "                                           DANH MUC THUC AN                                       " << endl;
    cout << endl;
    cout << setw(5) << left << "STT";
    cout << setw(7) << left << "MA SP";
    cout << setw(30) << left << "TEN SP";
    cout << setw(10) << left << "DON GIA";
    cout << setw(10) << left << "SL SP";
    cout << setw(15) << left << "NSX";
    cout << setw(15) << left << "HSD";
    cout << endl;
    cout << "_________________________________________________________________________________________________ " << endl << endl;
    for (int i = 0; i < ds_f.size() - 1; i++)
    {
        cout << setw(5) << left << i + 1;
        Xuat_File_Thong_Tin_DSSP(ds_f[i]);
    }
    cout << "_________________________________________________________________________________________________ " << endl;
}
void Food::timKiemSP(vector<Food> ds_f, Food f) {
    ifstream file;
    file.open("DSFOOD.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSSP(file, ds_f); 
    string maTimKiem;
    cout << "\n Nhap ma/ten thuc an can tim: ";
    cin.ignore(); 
    getline(cin,maTimKiem);
    int found = 0;
    for (int i = 0; i < ds_f.size(); i++) {
        if (stricmp(ds_f[i].GETmaSP().c_str(), maTimKiem.c_str()) == 0 || stricmp(ds_f[i].GETtenSP().c_str(), maTimKiem.c_str()) == 0) {
            cout << " --------------------------------------------------- " << endl;
            cout << "                     TRA CUU THUC AN                 " << endl << endl;
            cout << "  Ten san pham: " << ds_f[i].GETtenSP() << endl;
            cout << "  Ma san pham: " << ds_f[i].GETmaSP() << endl;
            cout << "  So luong hien tai: " << ds_f[i].GETsoLuongSPCL() << endl;
            cout << "  Don gia: " << ds_f[i].GETdonGiaSP() << endl;
            cout << "  Don vi tinh: " << ds_f[i].GETdonViTinhSP() << endl;
            cout << "  Ngay san xuat: " << ds_f[i].GETngaySXSP() << endl;
            cout << "  Ngay het han: " << ds_f[i].GETngayHHSP() << endl << endl;
            cout << " --------------------------------------------------- " << endl;
            found = 1;

        }
    }
    if (found == 0) {
        cout << "\n San pham khong ton tai trong he thong!" << endl;
    }
    file.close();
}
void Food::capNhatSoLuongSP(vector<Food> ds_f, Food f) {
    ifstream file;
    file.open("DSFOOD.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSSP(file, ds_f);
    cout << "\n  1. Them n so luong san pham " << endl;
    cout << "  2. Giam n so luong san pham " << endl << endl;
    int n;
    cout << "\n Nhap lua chon: ";
    cin >> n;
    cin.ignore();
    if (n == 1) {
        string ma;
        cout << "\n Nhap ma/ten thuc an: ";
        getline(cin, ma);
        int found = 0; //  luu vet 
        for (int i = 0; i < ds_f.size(); i++)
        {
            // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
            if (stricmp(ds_f[i].GETmaSP().c_str(), ma.c_str()) == 0 || stricmp(ds_f[i].GETtenSP().c_str(), ma.c_str()) == 0)
            {
                double x, y; 
                cout << "\n Nhap so luong ban muon them: "; cin >> x;
                ds_f[i].SETsoLuongTang(x); 
                y = ds_f[i].GETsoLuongSPCL() + ds_f[i].GETsoLuongTang();
                ds_f[i].SETsoLuongSPCL(y);
                cout << endl;
                cout << "\n Cap nhat so luong san pham thanh cong! " << endl;
                cout << endl;
                found = 1;
                ofstream ofile;
                ofile.open("DSFOOD.txt", ios::trunc);
                for (int i = 0; i < ds_f.size() - 1; i++)
                    ofile << ds_f[i];
                ofile.close();
            }
        }
        if (found == 0) {
            cout << "\n San pham khong ton tai trong he thong! " << endl;
        }
    }
    else if (n == 2) {
        string ma;
        cout << "\n Nhap ma/ten thuc an: ";
        getline(cin, ma);
        int found = 0; //  luu vet 
        for (int i = 0; i < ds_f.size(); i++)
        {
            // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
            if (stricmp(ds_f[i].GETmaSP().c_str(), ma.c_str()) == 0 || stricmp(ds_f[i].GETtenSP().c_str(), ma.c_str()) == 0)
            {
                double x, y; 
                cout << "\n Nhap so luong ban muon giam: "; cin >> x; 
                ds_f[i].SETsoLuongGiam(x);
                y = ds_f[i].GETsoLuongSPCL() - ds_f[i].GETsoLuongGiam(); 
                ds_f[i].SETsoLuongSPCL(y); 
                cout << endl;
                cout << "\n Cap nhat so luong san pham thanh cong! " << endl;
                cout << endl;
                found = 1;
                ofstream ofile;
                ofile.open("DSFOOD.txt", ios::trunc); // Xoa du lieu trong file 
                for (int i = 0; i < ds_f.size() - 1; i++)
                    ofile << ds_f[i]; // in danh sach lai 
                ofile.close();
            }
        }
        if (found == 0) {
            cout << "\n San pham khong ton tai trong he thong! " << endl;
        }
    }
    else {
        cout << "\n Lua chon cua ban khong hop le!" << endl;
    }
    file.close();

}
void Food::operator+(vector<Food> ds_f)
{
}
void operator + (vector<Food>ds_f) {
    Food spt[100];
    int n;
    cout << "\n Nhap SL san pham can them: "; cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin >> spt[i];
        ds_f.push_back(spt[i]);
    }
    ofstream ofile;
    ofile.open("DSFOOD.txt", ios::app); // them du lieu vao cuoi mang 
    for (int i = 0; i < n; i++)
        ofile << ds_f[i];
    ofile.close();
}
void Food::xoa1SP(vector<Food> ds_f, Food f) {
    ifstream file;
    file.open("DSFOOD.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSSP(file, ds_f);
    string ma;
    cout << "\n Nhap ma san pham: ";
    cin >> ma; 
    int found = 0;
    for (int i = 0; i < ds_f.size(); i++) {
        if (stricmp(ds_f[i].GETmaSP().c_str(), ma.c_str()) == 0) {
            cout << "\n Xoa san pham co ten " << ds_f[i].GETtenSP() << " thanh cong!" << endl;
            ds_f.erase(ds_f.begin() + i);
            found = 1;
            cout << endl;
            ofstream ofile;
            ofile.open("DSFOOD.txt", ios::trunc);
            for (int i = 0; i < ds_f.size() - 1; i++)
                ofile << ds_f[i];
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n San pham khong ton tai trong he thong! " << endl;
    }
    file.close();
}

int Food::ChonMenu()
{
    int n;
    cout << "\n Nhap lua chon: ";
    cin >> n;
    if (n > 0 || n < 8) {
        return n;
    }
    else {
        return ChonMenu();
    }
}

void Food::MENU()
{
    cout << "\n -------------------------------------------------------- " << endl;
    cout << " |                                                      | " << endl;
    cout << " |                   DANH MUC THUC AN                   | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |  1. Them thong tin san pham.                         | " << endl;
    cout << " |  2. In danh sach cac san pham.                       | " << endl;
    cout << " |  3. Cap nhat so luong san pham.                      | " << endl;
    cout << " |  4. Tim kiem thong tin san pham.                     | " << endl;
    cout << " |  5. Xoa thong tin 1 san pham.                        | " << endl;
    cout << " |                                                      | " << endl;
    cout << " -------------------------------------------------------- " << endl;
}

void Food::XuLyMenu(ifstream& file, vector<Food> ds_f, Food f)
{
    int chon = ChonMenu();
    switch (chon)
    {
    case 1:
        system("cls");
        cout << "\n Ban da chon chuc nang Them thong tin san pham! \n";
        +ds_f;
        cout << "\n Them san pham thanh cong! \n";
        break;
    case 2:
        system("cls");
        cout << "\n Ban da chon chuc nang In danh sach cac san pham! \n";
        file.open("DSFOOD.txt", ios_base::in);  // mở file ra đọc
        Doc_File_DSSP(file, ds_f);
        inDSSP(ds_f);
        file.close();
        break;
    case 3:
        system("cls");
        cout << "\n Ban da chon chuc nang Cap nhat so luong san pham! \n";
        capNhatSoLuongSP(ds_f, f);
        break;
    case 4:
        system("cls");
        cout << "\n Ban da chon chuc nang Tim kiem thong tin san pham! \n";
        timKiemSP(ds_f, f);
        break;
    case 5:
        system("cls");
        cout << "\n Ban da chon chuc nang Xoa thong tin 1 san pham! \n";
        xoa1SP(ds_f, f);
        break;
    }
}

//void Food::SLSP_HD()
//{
//    vector<Food> ds_f;
//    Food f;
//    ifstream file;
//    file.open("DSFOOD.txt", ios_base::in);  // mở file ra đọc
//    Doc_File_DSSP(file, ds_f);
//    int found = 0; //  luu vet 
//    for (int i = 0; i < ds_f.size(); i++)
//    {
//        vector<HoaDon> ds_hd; 
//        HoaDon hd; 
//        file.open("DSHD.txt", ios_base::in);  // mở file ra đọc 
//        hd.Doc_File_DSHD(file, ds_hd); 
//        for (int j = 0; j < ds_hd.size(); j++) {
//            // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
//            if (stricmp(ds_hd[j].getcacSPMua().c_str(), ds_f[i].GETtenSP().c_str()) == 0)
//            {
//                double x;
//                x = ds_f[i].GETsoLuongSPCL() - ds_hd[j].getslTungSP();
//                ds_f[i].SETsoLuongSPCL(x);
//                found = 1;
//                ofstream ofile;
//                ofile.open("DSFOOD.txt", ios::trunc);
//                for (int i = 0; i < ds_f.size() - 1; i++)
//                    ofile << ds_f[i];
//                ofile.close();
//            }
//        }
//        file.close(); 
//    }
//    file.close(); 
//}
