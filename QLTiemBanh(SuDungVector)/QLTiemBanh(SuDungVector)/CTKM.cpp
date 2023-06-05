#include "CTMK.h"


istream& operator >> (istream& in, ChuongTrinhKhuyenMai& ct)
{
    cout << " Nhap ma CT: ";            getline(in, ct.maCT);
    cout << " Nhap ten CT: ";           getline(in, ct.tenCT);
    cout << " Gia tri KM: ";            in >> ct.giaTriKM;
    cout << " Nhap ngay KM: ";          in >> ct.ngayKM;            in.ignore();
    cout << " Nhap noi dung KM: ";      getline(in, ct.noiDungKM);
    cout << " Nhap SLKM: ";             in >> ct.slKM;
    cout << endl;
    return in;
}

ostream& operator << (ostream& out, ChuongTrinhKhuyenMai ct)
{
    out << ct.maCT << ".";
    out << ct.tenCT << ".";
    out << ct.giaTriKM << " ";
    out << ct.slKM << " ";
    out << ct.noiDungKM << ".";
    out << ct.ngayKM << endl;
    return out;
}

void ChuongTrinhKhuyenMai::Doc_File_CT(ifstream& file, ChuongTrinhKhuyenMai& ct)
{
    getline(file, ct.maCT, '.');
    getline(file, ct.tenCT, '.');
    file >> ct.giaTriKM;
    file >> ct.slKM;
    getline(file, ct.noiDungKM, '.');
    file >> ct.ngayKM;
    string temp;
    getline(file, temp);  // khắc phục lỗi xuống dòng sau khi đọc xong 1 dòng dữ liệu
}

void ChuongTrinhKhuyenMai::Doc_File_DSCT(ifstream& file, vector<ChuongTrinhKhuyenMai>& ds_ct)
{
    while (file.eof() == false)
    {
        ChuongTrinhKhuyenMai ct;
        Doc_File_CT(file, ct);
        ds_ct.push_back(ct);
    }
}

void ChuongTrinhKhuyenMai::Xuat_File_Thong_Tin_DSCT(ChuongTrinhKhuyenMai ct)
{
    cout << "   Ma CT: " << ct.maCT << endl;
    cout << "   Ten CT: " << ct.tenCT << endl;;
    cout << "   Gia tri KM: " << ct.giaTriKM << endl;
    cout << "   Ngay KM: " << ct.ngayKM << endl;
    cout << "   SLKM: " << ct.slKM << endl;
    cout << "   Noi dung KM: " << ct.noiDungKM << endl;
    cout << endl;
}

void ChuongTrinhKhuyenMai::inDanhSachChuongTrinh(vector<ChuongTrinhKhuyenMai> ds_ct)
{
    cout << "________________________________________________________________________" << endl << endl; 
    cout << "                    DANH SACH CHUONG TRINH KHUYEN MAI" << endl;
    cout << endl;
    for (int i = 0; i < ds_ct.size() - 1; i++)
    {
        cout << " " << i + 1 << "." << endl;
        Xuat_File_Thong_Tin_DSCT(ds_ct[i]);
    }
    cout << "________________________________________________________________________" << endl << endl;
}

void operator + (vector<ChuongTrinhKhuyenMai> ds_ct)
{
    ChuongTrinhKhuyenMai ctt[100];
    int n;
    cout << "\n Nhap so luong CT can them: ";       cin >> n; 
    cout << endl; 
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin >> ctt[i];
        ds_ct.push_back(ctt[i]);
    }
    ofstream ofile;
    ofile.open("DSCT.txt", ios::app);
    for (int i = 0; i < n; i++)
        ofile << ds_ct[i];
    ofile.close();
}

void ChuongTrinhKhuyenMai::capNhatChuongTrinh(vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct)
{
    ifstream file;
    file.open("DSCT.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSCT(file, ds_ct);

    string ma;
    cout << "\n Nhap Ma CT can cap nhat: "; 
    cin >> ma;

    int capnhat = 0;
    cout << endl;
    for (int i = 0; i < ds_ct.size(); i++) {
        if (stricmp(ds_ct[i].maCT.c_str(), ma.c_str()) == 0) {
            cout << "\n Ten CT hien tai la: " << ds_ct[i].tenCT << endl;
            cout << " Ban muon cap nhat lai Ten CT moi la: ";
            cin.ignore();
            getline(cin, ct.tenCT);
            ds_ct[i].tenCT = ct.tenCT;

            cout << "\n Ma CT hien tai la: " << ds_ct[i].maCT << endl;
            cout << " Ban muon cap nhat lai Ma CT moi la: ";
            getline(cin, ct.maCT);
            ds_ct[i].maCT = ct.maCT;

            cout << "\n Gia tri KM hien tai la: " << ds_ct[i].giaTriKM << endl;;
            cout << " Ban muon cap nhat lai Gia tri KM moi la : ";
            cin >> ct.giaTriKM;
            ds_ct[i].giaTriKM = ct.giaTriKM;

            cout << "\n Ngay KM hien tai la: " << ds_ct[i].ngayKM << endl;;
            cout << " Ban muon cap nhat lai Ngay KM moi la: ";
            cin >> ct.ngayKM;
            ds_ct[i].ngayKM = ct.ngayKM;

            cout << "\n Noi dung KM hien tai la: " << ds_ct[i].noiDungKM << endl;;
            cout << " Ban muon cap nhap lai Noi dung KM moi la: ";
            cin.ignore();
            getline(cin, ct.noiDungKM);
            ds_ct[i].noiDungKM = ct.noiDungKM;

            capnhat = 1;
            ofstream ofile;
            ofile.open("DSCT.txt", ios::trunc);
            for (int i = 0; i < ds_ct.size() - 1; i++)
                ofile << ds_ct[i];
            ofile.close();
        }
    }
    if (capnhat == 0) {
        cout << "\n Chuong trinh khong ton tai trong he thong!" << endl;
    }
    file.close();
}

void ChuongTrinhKhuyenMai::capNhatSoLuongKM(vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct)
{
    ifstream file;
    file.open("DSCT.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSCT(file, ds_ct);

    cout << " 1. Them n so luong CTKM " << endl;
    cout << " 2. Giam n so luong CTKM " << endl << endl;
    int n;
    cout << " Nhap lua chon: ";
    cin >> n;
    if (n == 1) {
        string ma;
        cout << "\n Nhap ma CT ban muon tang sl: ";
        cin >> ma;
        int found = 0; //  luu vet 
        for (int i = 0; i < ds_ct.size(); i++)
        {
            // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
            if (stricmp(ds_ct[i].maCT.c_str(), ma.c_str()) == 0)
            {
                cout << "\n Nhap so luong ban muon tang: "; cin >> ds_ct[i].slKMTang;
                ds_ct[i].slKM = ds_ct[i].slKM + ds_ct[i].slKMTang;
                cout << endl;
                cout << "\n CAP NHAP SO LUONG SAN PHAM THANH CONG! " << endl;
                cout << endl;
                found = 1;
                ofstream ofile;
                ofile.open("DSCT.txt", ios::trunc);
                for (int i = 0; i < ds_ct.size() - 1; i++)
                    ofile << ds_ct[i];
                ofile.close();
            }
        }
        if (found == 0) {
            cout << "\n Chuong trinh khong ton tai trong he thong!" << endl;
        }
    }
    else if (n == 2) {
        string ma;
        cout << " Nhap ma CT ban muon giam sl: ";
        cin >> ma;
        int found = 0; //  luu vet 
        for (int i = 0; i < ds_ct.size(); i++)
        {
            // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
            if (stricmp(ds_ct[i].maCT.c_str(), ma.c_str()) == 0)
            {
                cout << "\n Nhap so luong ban muon giam: ";            cin >> ds_ct[i].slKMGiam;
                ds_ct[i].slKM = ds_ct[i].slKM - ds_ct[i].slKMGiam;
                cout << endl;
                cout << "\n CAP NHAP SO LUONG SAN PHAM THANH CONG! " << endl;
                cout << endl;
                found = 1;
                ofstream ofile;
                ofile.open("DSCT.txt", ios::trunc);
                for (int i = 0; i < ds_ct.size() - 1; i++)
                    ofile << ds_ct[i];
                ofile.close();
            }
        }
        if (found == 0) {
            cout << "\n Chuong trinh khong ton tai trong he thong!" << endl;
        }
    }
    else {
        cout << "Lua chon cua ban khong hop le !" << endl;
    }
    file.close();

}

void ChuongTrinhKhuyenMai::timKiemChuongTrinh(vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct)
{
    ifstream file;
    file.open("DSCT.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSCT(file, ds_ct);
    string maTimKiem;
    cout << "\n Nhap Ma CT can tim: ";
    cin >> maTimKiem;
    int found = 0;
    for (int i = 0; i < ds_ct.size(); i++) {
        if (stricmp(ds_ct[i].maCT.c_str(), maTimKiem.c_str()) == 0) {
            cout << " ----------------------------------------------------------------- " << endl;
            cout << "                           TRA CUU CHUONG TRINH                    " << endl; 
            cout << "\n  Ma chuong trinh KM: " << ds_ct[i].maCT;
            cout << "\n  Ten chuong trinh KM: " << ds_ct[i].tenCT;
            cout << "\n  Moi KM duoc giam: " << ds_ct[i].giaTriKM << " VND"; 
            cout << "\n  Ngay KM: " << ds_ct[i].ngayKM;
            cout << "\n  Noi dung KM: " << ds_ct[i].noiDungKM;
            cout << "\n  So luong CTKM hien tai: " << ds_ct[i].slKM << endl << endl;
            cout << " ----------------------------------------------------------------- " << endl;
            found = 1;
        }
    }
    if (found == 0) {
        cout << "\n Chuong Trinh khong ton tai trong he thong!" << endl;
    }
    file.close();
}

void ChuongTrinhKhuyenMai::xoa1CT(vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct)
{
    ifstream file;
    file.open("DSCT.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSCT(file, ds_ct);
    string ma;
    cout << "\n Nhap ma CT: ";
    cin >> ma;
    int found = 0;
    for (int i = 0; i < ds_ct.size(); i++) {
        if (stricmp(ds_ct[i].maCT.c_str(), ma.c_str()) == 0) {
            cout << "\n Xoa chuong trinh co ma " << ds_ct[i].maCT << " thanh cong!" << endl;
            ds_ct.erase(ds_ct.begin() + i);
            found = 1;
            cout << endl;
            ofstream ofile;
            ofile.open("DSCT.txt", ios::trunc);
            for (int i = 0; i < ds_ct.size() - 1; i++)
                ofile << ds_ct[i];
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n Chuong trinh khong ton tai trong he thong!" << endl;
    }
    file.close();
}

int ChuongTrinhKhuyenMai::ChonMenu()
{
    int n;
    cout << "\n\n Nhap lua chon : ";
    cin >> n;
    if (n > 0 || n < 8) {
        return n;
    }
    else {
        return ChonMenu();
    }
}

void ChuongTrinhKhuyenMai::MENU()
{
    cout << "\n -------------------------------------------------------- " << endl;
    cout << " |                                                      | " << endl;
    cout << " |              DANH MUC CHUONG TRINH KHUYEN MAI        | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |  1. Them thong tin chuong trinh.                     | " << endl;
    cout << " |  2. Tim kiem thong tin chuong trinh.                 | " << endl;
    cout << " |  3. In danh sach cac chuong trinh.                   | " << endl;
    cout << " |  4. Cap nhat thong tin chuong trinh.                 | " << endl;
    cout << " |  5. Cap nhat so luong chuong trinh.                  | " << endl;
    cout << " |  6. Xoa thong tin 1 chuong trinh.                    | " << endl;
    cout << " |                                                      | " << endl;
    cout << " -------------------------------------------------------- " << endl;
}

void ChuongTrinhKhuyenMai::XuLyMenu(ifstream& file, vector<ChuongTrinhKhuyenMai> ds_ct, ChuongTrinhKhuyenMai ct)
{
    int chon = ChonMenu();
    switch (chon)
    {
    case 1:
        system("cls");
        cout << "\n Ban da chon chuc nang Them thong tin chuong trinh! \n"; 
        +ds_ct;
        break;
    case 2:
        system("cls");
        cout << "\n Ban da chon chuc nang Tim kiem thong tin chuong trinh! \n";
        timKiemChuongTrinh(ds_ct, ct);
        break;
    case 3:
        system("cls");
        cout << "\n Ban da chon chuc nang In danh sach cac chuong trinh! \n";
        file.open("DSCT.txt", ios_base::in);  // mở file ra đọc
        Doc_File_DSCT(file, ds_ct);
        inDanhSachChuongTrinh(ds_ct);
        file.close();
        break;
    case 4:
        system("cls");
        cout << "\n Ban da chon chuc nang Cap nhat thong tin chuong trinh! \n";
        capNhatChuongTrinh(ds_ct, ct);
        break;
    case 5:
        system("cls");
        cout << "\n Ban da chon chuc nang Cap nhat so luong chuong trinh! \n";
        capNhatSoLuongKM(ds_ct, ct);
        break;
    case 6:
        system("cls");
        cout << "\n Ban da chon chuc nang Xoa thong tin 1 chuong trinh! \n";
        xoa1CT(ds_ct, ct);
        break;
    }
}

// Ham get - set, Ham KTao - huy: 
string ChuongTrinhKhuyenMai::getmaCT() { return maCT; }
string ChuongTrinhKhuyenMai::gettenCT() { return tenCT; }
int ChuongTrinhKhuyenMai::getslKM() { return slKM; }
int ChuongTrinhKhuyenMai::getslKMTang() { return slKMTang; }
int ChuongTrinhKhuyenMai::getslKMGiam() { return slKMGiam; }
double ChuongTrinhKhuyenMai::getgiaTriKM() { return giaTriKM; }
Date ChuongTrinhKhuyenMai::getngayKM() { return ngayKM; }
string ChuongTrinhKhuyenMai::getnoiDungKM() { return noiDungKM; }
void ChuongTrinhKhuyenMai::setmaCT(string _maCT) { maCT = _maCT; }
void ChuongTrinhKhuyenMai::settenCT(string _tenCT) { tenCT = _tenCT; }
void ChuongTrinhKhuyenMai::setslKM(int _slKM) { slKM = _slKM; }
void ChuongTrinhKhuyenMai::setslKMTang(int _slKMTang) { slKMTang = _slKMTang; }
void ChuongTrinhKhuyenMai::setslKMGiam(int _slKMGiam) { slKMGiam = _slKMGiam; }
void ChuongTrinhKhuyenMai::setgiaTriKM(double _giaTriKM) { giaTriKM = _giaTriKM; }
void ChuongTrinhKhuyenMai::setngayKM(Date _ngayKM) { ngayKM = _ngayKM; }
void ChuongTrinhKhuyenMai::setnoiDungKM(string _noiDungKM) { noiDungKM = _noiDungKM; }
ChuongTrinhKhuyenMai::ChuongTrinhKhuyenMai(string _maCT, string _tenCT, int _slKM, int _slKMTang, int _slKMGiam, double _giaTriKM, Date _ngayKM, string _noiDungKM) {
    maCT = _maCT;
    tenCT = _tenCT;
    slKM = _slKM;
    slKMTang = _slKMTang;
    slKMGiam = _slKMGiam;
    giaTriKM = _giaTriKM;
    ngayKM = _ngayKM;
    noiDungKM = _noiDungKM;
}
ChuongTrinhKhuyenMai::ChuongTrinhKhuyenMai(const ChuongTrinhKhuyenMai& ct) {
    maCT = ct.maCT;
    tenCT = ct.tenCT;
    slKM = ct.slKM;
    slKMTang = ct.slKMTang;
    slKMGiam = ct.slKMGiam;
    giaTriKM = ct.giaTriKM;
    ngayKM = ct.ngayKM;
    noiDungKM = ct.noiDungKM;
}
ChuongTrinhKhuyenMai::~ChuongTrinhKhuyenMai() {}

