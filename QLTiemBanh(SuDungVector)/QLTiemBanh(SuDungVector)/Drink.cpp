#include "Drink.h" 

Drink::Drink(string _maSP, string _tenSP, double _donGiaSP, string donViTinhSP, Date _ngaySXSP, Date _ngayHHSP, double _soLuongSPTang, double _soLuongSPGiam, double _soLuongSPCL) : SanPham(_maSP, _tenSP, _donGiaSP, donViTinhSP, Date(1, 1, 2000), Date(1, 1, 2000), 0, 0, 0) {}
Drink::Drink(const Drink& f) : SanPham(f) {}
Drink::~Drink() {}
// Nhap - Xuat: 
istream& operator >> (istream& in, Drink& f) {
    string maSP, tenSP;
    double donGiaSP;
    string donViTinhSP;
    Date ngaySXSP, ngayHHSP;
    cout << "\n Nhap ma SP: ";               getline(in, maSP);
    cout << " Nhap ten SP: ";                getline(in, tenSP);
    cout << " Nhap don gia: ";               in >> donGiaSP;
    in.ignore();
    cout << " Nhap don vi tinh: ";           getline(in, donViTinhSP);
    in.ignore();
    cout << endl;
    f = Drink(maSP, tenSP, donGiaSP, donViTinhSP, Date(1,1,2000), Date(1,1,2000), 0, 0, 0);
    return in;
}
ostream& operator << (ostream& out, Drink f) {
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
void Drink::Doc_File_SP(ifstream& file, Drink& f) {
    string maSP, tenSP;
    double donGiaSP, soLuongSPCL;
    string donViTinhSP;
    Date ngaySXSP, ngayHHSP;
    getline(file, maSP, ',');
    getline(file, tenSP, ',');
    getline(file, donViTinhSP, ',');
    file >> donGiaSP;
    file >> soLuongSPCL;
    file >> ngaySXSP;
    file >> ngayHHSP;
    string temp;
    getline(file, temp);
    f = Drink(maSP, tenSP, donGiaSP, donViTinhSP, ngaySXSP, ngayHHSP, 0, 0, soLuongSPCL);
}
void Drink::Doc_File_DSSP(ifstream& file, vector<Drink>& ds_f) {
    while (file.eof() == false)
    {
        Drink f;
        Doc_File_SP(file, f);
        ds_f.push_back(f);
    }
}
void Drink::Xuat_File_Thong_Tin_DSSP(Drink f) {
    cout << setw(7) << left << f.GETmaSP() << "\t   ";
    cout << setw(15) << left << f.GETtenSP() << "\t";
    cout << setw(15) << left << f.GETdonGiaSP() << "\t";
    cout << endl;
}
void Drink::inDSSP(vector<Drink> ds_f) {
    cout << "_________________________________________________________________________________________________ " << endl << endl;
    cout << "                                           DANH MUC NUOC UONG                                     " << endl;
    cout << endl;
    cout << setw(7) << left << "STT";
    cout << setw(15) << left << "MA SP";
    cout << setw(17) << left << "TEN SP";
    cout << setw(15) << left << "DON GIA";
    cout << endl;
    cout << "_________________________________________________________________________________________________ " << endl << endl;
    for (int i = 0; i < ds_f.size() - 1; i++)
    {
        cout << setw(7) << left << i + 1;
        Xuat_File_Thong_Tin_DSSP(ds_f[i]);
    }
    cout << "_________________________________________________________________________________________________ " << endl;
}
void Drink::timKiemSP(vector<Drink> ds_f, Drink f) {
    ifstream file;
    file.open("DSDRINK.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSSP(file, ds_f);
    string maTimKiem;
    cout << "\n Nhap ma/ten nuoc uong can tim: ";
    cin.ignore(); 
    getline(cin,maTimKiem);
    int found = 0;
    for (int i = 0; i < ds_f.size(); i++) {
        if (stricmp(ds_f[i].GETmaSP().c_str(), maTimKiem.c_str()) == 0 || stricmp(ds_f[i].GETtenSP().c_str(), maTimKiem.c_str()) == 0) {
            cout << " --------------------------------------------------- " << endl;
            cout << "                     TRA CUU NUOC UONG               " << endl << endl;
            cout << "  Ten san pham: " << ds_f[i].GETtenSP() << endl;
            cout << "  Ma san pham: " << ds_f[i].GETmaSP() << endl;
            cout << "  Don gia: " << ds_f[i].GETdonGiaSP() << endl;
            cout << "  Don vi tinh: " << ds_f[i].GETdonViTinhSP() << endl;
            cout << " --------------------------------------------------- " << endl;
            found = 1;
        }
    }
    if (found == 0) {
        cout << "\n San pham khong ton tai trong he thong!" << endl;
    }
    file.close();
}
void operator + (vector<Drink>ds_f) {
    Drink spt[100];
    int n;
    cout << "\n Nhap SL san pham can them: "; cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin >> spt[i];
        ds_f.push_back(spt[i]);
    }
    ofstream ofile;
    ofile.open("DSDRINK.txt", ios::app);
    for (int i = 0; i < n; i++)
        ofile << ds_f[i];
    ofile.close();
}
void Drink::xoa1SP(vector<Drink> ds_f, Drink f) {
    ifstream file;
    file.open("DSDRINK.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSSP(file, ds_f);
    string ma;
    cout << "\n Nhap ma san pham: ";
    cin >> ma; 
    int found = 0;
    for (int i = 0; i < ds_f.size(); i++) {
        if (stricmp(ds_f[i].GETmaSP().c_str(), ma.c_str()) == 0) {
            cout << "\n Xoa san pham co ma " << ds_f[i].GETmaSP() << " (" << ds_f[i].GETtenSP() << ") thanh cong!" << endl;
            ds_f.erase(ds_f.begin() + i);
            found = 1;
            cout << endl;
            ofstream ofile;
            ofile.open("DSDRINK.txt", ios::trunc);
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
int Drink::ChonMenu()
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
void Drink::MENU()
{

    cout << "\n -------------------------------------------------------- " << endl;
    cout << " |                                                      | " << endl;
    cout << " |                   DANH MUC NUOC UONG                 | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |  1. Them thong tin san pham.                         | " << endl;
    cout << " |  2. In danh sach cac san pham.                       | " << endl;
    cout << " |  3. Tim kiem thong tin san pham.                     | " << endl;
    cout << " |  4. Xoa thong tin 1 san pham.                        | " << endl;
    cout << " |                                                      | " << endl;
    cout << " -------------------------------------------------------- " << endl;

}
void Drink::XuLyMenu(ifstream& file, vector<Drink> ds_f, Drink f)
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
        file.open("DSDRINK.txt", ios_base::in);  // mở file ra đọc
        Doc_File_DSSP(file, ds_f);
        inDSSP(ds_f);
        file.close();
        break;
    case 3:
        system("cls");
        cout << "\n Ban da chon chuc nang Tim kiem thong tin san pham! \n";
        timKiemSP(ds_f, f);
        break;
    case 4:
        system("cls");
        cout << "\n Ban da chon chuc nang Xoa thong tin 1 san pham! \n";
        xoa1SP(ds_f, f);
        break;
    }
}
