#include "SanPham.h" 

istream& operator >> (istream& in, SanPham& sp) 
{
    cout << "\n Nhap ma SP: ";               getline(in, sp.maSP);
    cout << " Nhap ten SP: ";                getline(in, sp.tenSP);
    cout << " Nhap don gia: ";               in >> sp.donGiaSP;
    cout << " Nhap so luong SP: ";           in >> sp.soLuongSPCL;
    in.ignore();
    cout << " Nhap don vi tinh: ";           getline(in, sp.donViTinhSP);
    cout << " Nhap NSX: ";                   in >> sp.ngaySXSP;
    cout << " Nhap HSD:  ";                  in >> sp.ngayHHSP;
    in.ignore();
    cout << endl;
    return in;
}

ostream& operator << (ostream& out, SanPham sp) 
{
    out << sp.maSP << ",";
    out << sp.tenSP << ",";
    out << sp.donViTinhSP << ",";
    out << sp.donGiaSP << " ";
    out << sp.soLuongSPCL << endl;
    out << sp.ngaySXSP << endl;
    out << sp.ngayHHSP << endl;
    return out;
}

void SanPham::Doc_File_SP(ifstream& file, SanPham& sp)
{
    getline(file, sp.maSP, ',');
    getline(file, sp.tenSP, ',');
    getline(file, sp.donViTinhSP, ',');
    file >> sp.donGiaSP;
    file >> sp.soLuongSPCL;
    string temp;
    file >> sp.ngaySXSP;
    file >> sp.ngayHHSP;
    getline(file, temp);
}

void SanPham::Doc_File_DSSP(ifstream& file, vector<SanPham>& ds_sp)
{
    while (file.eof() == false)
    {
        SanPham sp;
        Doc_File_SP(file, sp);
        ds_sp.push_back(sp);
    }
}

void SanPham::Xuat_File_Thong_Tin_DSSP(SanPham sp)
{
    cout << setw(15) << left << sp.maSP;
    cout << setw(30) << left << sp.tenSP;
    cout << setw(15) << left << sp.donGiaSP;
    cout << setw(10) << left << sp.soLuongSPCL;
    cout << setw(15) << left << sp.ngayHHSP << "      "; 
    cout << setw(15) << left << sp.ngayHHSP;
    cout << endl;
}

void SanPham::inDSSP(vector<SanPham> ds_sp)
{
    cout << "_________________________________________________________________________________________________ " << endl << endl; 
    cout << "                                              THUC DON                                            " << endl;  
    cout << endl;
    cout << setw(7) << left << "STT";
    cout << setw(15) << left << "MA SP";
    cout << setw(30) << left << "TEN SP";
    cout << setw(15) << left << "DON GIA";
    cout << setw(15) << left << "SL SP";
    cout << setw(15) << left << "NSX";
    cout << setw(15) << left << "HSD";
    cout << endl;
    cout << "_________________________________________________________________________________________________ " << endl << endl;
    for (int i = 0; i < ds_sp.size() - 1; i++)
    {
        cout << setw(7) << left << i + 1;
        Xuat_File_Thong_Tin_DSSP(ds_sp[i]);
    }
    cout << "_________________________________________________________________________________________________ " << endl;
}

void SanPham::timKiemSP(vector<SanPham> ds_sp, SanPham sp)
{
    ifstream file;
    file.open("DSSP.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSSP(file, ds_sp);
    string maTimKiem;
    cout << "\n Nhap ma/ten san pham can tim: ";
    cin.ignore(); 
    getline (cin, maTimKiem);
    int found = 0;
    for (int i = 0; i < ds_sp.size(); i++) {
        if (stricmp(ds_sp[i].maSP.c_str(), maTimKiem.c_str()) == 0 || stricmp(ds_sp[i].tenSP.c_str(), maTimKiem.c_str()) == 0) {
            cout << " --------------------------------------------------- " << endl;
            cout << "                     TRA CUU SAN PHAM                " << endl << endl;
            cout << "  Ten san pham: " << ds_sp[i].tenSP << endl;
            cout << "  Ma san pham: " << ds_sp[i].maSP << endl;
            cout << "  So luong hien tai: " << ds_sp[i].soLuongSPCL << endl;
            cout << "  Don gia: " << ds_sp[i].donGiaSP << endl;
            cout << "  Don vi tinh: " << ds_sp[i].donViTinhSP << endl;
            cout << "  Ngay san xuat: " << ds_sp[i].ngaySXSP << endl;
            cout << "  Ngay het han: " << ds_sp[i].ngayHHSP << endl << endl;
            cout << " --------------------------------------------------- " << endl;
            found = 1;

        }
    }
    if (found == 0) {
        cout << "\n San pham khong ton tai trong he thong!" << endl;
    }
    file.close();
}

void SanPham::capNhatSoLuongSP(vector<SanPham> ds_sp, SanPham sp) {
    ifstream file;
    file.open("DSSP.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSSP(file, ds_sp);
    cout << "\n  1. Them n so luong san pham " << endl;
    cout << "  2. Giam n so luong san pham " << endl << endl;
    int n;
    cout << "\n Nhap lua chon: ";
    cin >> n;
    cin.ignore(); 
    if (n == 1) {
        string ma;
        cout << "\n Nhap ma/ten san pham: ";
        getline(cin, ma);
        int found = 0; //  luu vet 
        for (int i = 0; i < ds_sp.size(); i++)
        {
            // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
            if (stricmp(ds_sp[i].maSP.c_str(), ma.c_str()) == 0 || stricmp(ds_sp[i].tenSP.c_str(), ma.c_str()) == 0)
            {
                cout << "\n Nhap so luong ban muon them: "; cin >> ds_sp[i].soLuongTang;
                ds_sp[i].soLuongSPCL = ds_sp[i].soLuongSPCL + ds_sp[i].soLuongTang;
                cout << endl;
                cout << "\n Cap nhat so luong san pham thanh cong! " << endl; 
                cout << endl;
                found = 1;
                ofstream ofile;
                ofile.open("DSSP.txt", ios::trunc);
                for (int i = 0; i < ds_sp.size() - 1; i++)
                    ofile << ds_sp[i];
                ofile.close();
            }
        }
        if (found == 0) {
            cout << "\n San pham khong ton tai trong he thong! " << endl;
        }
    }
    else if (n == 2) {
        string ma;
        cout << "\n Nhap ma/ten san pham: ";
        getline(cin, ma);
        int found = 0; //  luu vet 
        for (int i = 0; i < ds_sp.size(); i++)
        {
            // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
            if (stricmp(ds_sp[i].maSP.c_str(), ma.c_str()) == 0 || stricmp(ds_sp[i].tenSP.c_str(), ma.c_str()) == 0)
            {
                cout << "\n Nhap so luong ban muon giam: "; cin >> ds_sp[i].soLuongGiam;
                ds_sp[i].soLuongSPCL = ds_sp[i].soLuongSPCL - ds_sp[i].soLuongGiam;
                cout << endl;
                cout << "\n Cap nhat so luong san pham thanh cong! " << endl;
                cout << endl;
                found = 1;
                ofstream ofile;
                ofile.open("DSSP.txt", ios::trunc);
                for (int i = 0; i < ds_sp.size() - 1; i++)
                    ofile << ds_sp[i];
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

void operator + (vector<SanPham> ds_sp)
{
    SanPham spt[100];
    int n;
    cout << "\n Nhap SL san pham can them: "; cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin >> spt[i];
        ds_sp.push_back(spt[i]);
    }
    ofstream ofile;
    ofile.open("DSSP.txt", ios::app);
    for (int i = 0; i < n; i++)
        ofile << ds_sp[i];
    ofile.close();
}

void SanPham::xoa1SP(vector<SanPham> ds_sp, SanPham sp)
{
    ifstream file;
    file.open("DSSP.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSSP(file, ds_sp);
    string ma;
    cout << "\n Nhap ma san pham: ";
    cin >> ma; 
    int found = 0;
    for (int i = 0; i < ds_sp.size(); i++) {
        if (stricmp(ds_sp[i].maSP.c_str(), ma.c_str()) == 0) {
            cout << "\n Xoa san pham co ma " << ds_sp[i].maSP << " thanh cong!" << endl;
            ds_sp.erase(ds_sp.begin() + i);
            found = 1;
            cout << endl;
            ofstream ofile;
            ofile.open("DSSP.txt", ios::trunc);
            for (int i = 0; i < ds_sp.size() - 1; i++)
                ofile << ds_sp[i];
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n San pham khong ton tai trong he thong! " << endl;
    }
    file.close();
}


int SanPham::ChonMenu()
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

void SanPham::MENU()
{
    cout << "\n -------------------------------------------------------- " << endl;
    cout << " |                                                      | " << endl;
    cout << " |                   DANH MUC SAN PHAM                  | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |  1. Them thong tin san pham.                         | " << endl;
    cout << " |  2. In danh sach cac san pham.                       | " << endl;
    cout << " |  3. Cap nhat so luong san pham.                      | " << endl;
    cout << " |  4. Tim kiem thong tin san pham.                     | " << endl;
    cout << " |  5. Xoa thong tin 1 san pham.                        | " << endl;
    cout << " |                                                      | " << endl;
    cout << " -------------------------------------------------------- " << endl;
}

void SanPham::XuLyMenu(ifstream& file, vector<SanPham> ds_sp, SanPham sp)
{
    int chon = ChonMenu();
    switch (chon)
    {
    case 1:
        system("cls");
        cout << "\n Ban da chon chuc nang Them thong tin san pham! \n"; 
        +ds_sp;
        cout << "\n Them san pham thanh cong! \n"; 
        break;
    case 2:
        system("cls");
        cout << "\n Ban da chon chuc nang In danh sach cac san pham! \n";
        file.open("DSSP.txt", ios_base::in);  // mở file ra đọc
        Doc_File_DSSP(file, ds_sp);
        inDSSP(ds_sp);
        file.close(); 
        break;
    case 3:
        system("cls");
        cout << "\n Ban da chon chuc nang Cap nhat so luong san pham! \n";
        capNhatSoLuongSP(ds_sp, sp);
        break;
    case 4:
        system("cls");
        cout << "\n Ban da chon chuc nang Tim kiem thong tin san pham! \n";
        timKiemSP(ds_sp, sp);
        break;
    case 5:
      system("cls");
      cout << "\n Ban da chon chuc nang Xoa thong tin 1 san pham! \n";
      xoa1SP(ds_sp, sp);
      break;
    
    }
}

// Ham get - set, Ham KTao - huy: 
string SanPham::GETmaSP() {
    return maSP;
}
void SanPham::SETmaSP(string _maSP) {
    maSP = _maSP;
}
string SanPham::GETtenSP() {
    return tenSP;
}
void SanPham::SETtenSP(string _tenSP) {
    tenSP = _tenSP;
}
double SanPham::GETsoLuongTang() {
    return soLuongTang;
}
void SanPham::SETsoLuongTang(double _soLuongSPTang) {
    soLuongTang = _soLuongSPTang;
}
double SanPham::GETsoLuongGiam() {
    return soLuongGiam;
}
void SanPham::SETsoLuongGiam(double _soLuongSPGiam) {
    soLuongGiam = _soLuongSPGiam;
}
double SanPham::GETsoLuongSPCL() {
    return soLuongSPCL;
}
void SanPham::SETsoLuongSPCL(double _soLuongSPCL) {
    soLuongSPCL = _soLuongSPCL;
}
double SanPham::GETdonGiaSP() {
    return donGiaSP;
}
void SanPham::SETdonGiaSP(double _donGiaSP) {
    donGiaSP = _donGiaSP;
}
string SanPham::GETdonViTinhSP() {
    return donViTinhSP;
}
void SanPham::SETdonViTinhSP(string _donViTinhSP) {
    donViTinhSP = _donViTinhSP;
}
Date SanPham::GETngaySXSP() {
    return ngaySXSP;
}
void SanPham::SETngaySXSP(Date _ngaySXSP) {
    ngaySXSP = _ngaySXSP;
}
Date SanPham::GETngayHHSP() {
    return ngayHHSP;
}
void SanPham::SETngayHHSP(Date _ngayHHSP) {
    ngayHHSP = _ngayHHSP;
}
SanPham::SanPham(string _maSP, string _tenSP, double _donGiaSP, string _donViTinhSP, Date _ngaySXSP, Date _ngayHHSP, double _soLuongSPTang, double _soLuongSPGiam, double _soLuongSPCL) {
    maSP = _maSP;
    tenSP = _tenSP;
    donGiaSP = _donGiaSP;
    donViTinhSP = _donViTinhSP;
    ngaySXSP = _ngaySXSP;
    ngayHHSP = _ngayHHSP;
    soLuongTang = _soLuongSPTang;
    soLuongGiam = _soLuongSPGiam;
    soLuongSPCL = _soLuongSPCL;
}
SanPham::SanPham(const SanPham& sp) {
    maSP = sp.maSP;
    tenSP = sp.tenSP;
    donGiaSP = sp.donGiaSP;
    donViTinhSP = sp.donViTinhSP;
    ngaySXSP = sp.ngaySXSP;
    ngayHHSP = sp.ngayHHSP;
    soLuongTang = sp.soLuongTang;
    soLuongGiam = sp.soLuongGiam;
    soLuongSPCL = sp.soLuongSPCL;
}
SanPham::~SanPham() {}
