#include "NhanVien.h"

// ham nhap 1 nv
istream& operator >> (istream& in, NhanVien& nv) {
    string maNV, hoTen, ngaySinh, soDT, chucVu, trangThai; 
    double tongLuong; 
    cout << " Ho va ten: ";         getline(in, hoTen);
    cout << " Ma nhan vien: ";      getline(in, maNV);
    cout << " Ngay sinh: ";         getline(in, ngaySinh); 
    cout << " So dien thoai: ";     getline(in, soDT);
    cout << " Chuc vu: ";           getline(in, chucVu);
    cout << " Trang thai: ";        getline(in, trangThai);
    cout << " Tong luong: ";        in >> tongLuong;
    cout << endl;
    nv = NhanVien(maNV, hoTen, ngaySinh, soDT, trangThai, chucVu, 0, 0, tongLuong, 0, 0, 0); 
    return in;
}
// ham xuat 1 nv
ostream& operator << (ostream& out, NhanVien nv) {
    out << nv.gethoTen() << "_";
    out << nv.getmaSo() << "_";
    out << nv.getngaySinh() << "_"; 
    out << nv.getsoDT() << "_";
    out << nv.chucVu << "_";
    out << nv.trangThai << "_";
    out << fixed << setprecision(0) << nv.tongLuong << endl;
    return out;
}

// hàm đọc thông tin nguyen lieu
void NhanVien::Doc_File_N(ifstream& file, NhanVien& nv)
{
    string maNV, hoTen, ngaySinh, soDT, chucVu, trangThai;
    double tongLuong;
    getline(file, hoTen, '_');
    getline(file, maNV, '_');
    getline(file, ngaySinh, '_'); 
    getline(file, soDT, '_');
    getline(file, chucVu, '_');
    getline(file, trangThai, '_');
    file >> tongLuong;  
    string temp;
    getline(file, temp);  // khắc phục lỗi xuống dòng sau khi đọc xong 1 dòng dữ liệu
    nv = NhanVien(maNV, hoTen, ngaySinh, soDT, trangThai, chucVu, 0, 0, tongLuong, 0, 0, 0); 
}

// Hàm chính đọc dữ liệu Danh sach nhan vien
void NhanVien::Doc_File_DSN(ifstream& file, vector<NhanVien>& ds_nv)
{
    while (file.eof() == false)   // doc file cho den khi ket thuc  
    {
        NhanVien nv;
        Doc_File_N(file, nv);
        ds_nv.push_back(nv);
    }
}

// xuất thông tin dạng bảng
void NhanVien::Xuat_File_Thong_Tin_DSN(NhanVien nv)
{
    cout << setw(25) << left << nv.gethoTen();
    cout << setw(15) << left << nv.getmaSo();
    cout << setw(15) << left << nv.getngaySinh();
    cout << setw(15) << left << nv.getsoDT();
    cout << setw(15) << left << nv.chucVu;
    cout << setw(12) << left << nv.soLanBanHang(); 
    cout << setw(10) << left << fixed << setprecision(0) << nv.tongLuong << " VND";
    cout << endl;
}

// ham in du lieu doc tu file
void NhanVien::inDSN(vector<NhanVien>ds_nv)
{
    cout << "_______________________________________________________________________________________________________________ " << endl << endl; 
    cout << "                                        DANH SACH CAC NHAN VIEN                                        " << endl;
    cout << endl;
    cout << setw(5) << left << "STT";
    cout << setw(25) << left << "HO VA TEN";
    cout << setw(15) << left << "MA NV";
    cout << setw(15) << left << "NGAY SINH";
    cout << setw(15) << left << "SDT";
    cout << setw(15) << left << "CHUC VU";
    cout << setw(12) << left << "SO LAN BAN"; 
    cout << setw(10) << left << "LUONG";
    cout << endl;
    cout << "_______________________________________________________________________________________________________________ " << endl << endl;
    int _max = 0, _min = 0; 
    double sum = 0; 
    for (int i = 0; i < ds_nv.size() - 1; i++)
    {
        cout << setw(5) << left << i + 1;
        Xuat_File_Thong_Tin_DSN(ds_nv[i]);
        if (ds_nv[_max].tongLuong < ds_nv[i].tongLuong) {
            _max = i; 
        }
        if (ds_nv[_min].tongLuong > ds_nv[i].tongLuong) {
            _min = i;
        }
        sum = sum + ds_nv[i].tongLuong; 
    }
    cout << "\n\n -> SUM: " << sum; 
    cout << " VND, MAX: " << ds_nv[_max].tongLuong; 
    cout << " VND, MIN: " << ds_nv[_min].tongLuong << " VND" << endl << endl;
    cout << "_______________________________________________________________________________________________________________ " << endl;
}

// hàm thêm nhan vien
void operator + (vector<NhanVien>ds_nv) {
    NhanVien nvt[100];
    int n;
    cout << "\n Nhap SL nhan vien can them: "; cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin >> nvt[i];
        ds_nv.push_back(nvt[i]);
    }
    ofstream ofile;
    ofile.open("DSNV.txt", ios::app);
    for (int i = 0; i < n; i++)
        ofile << ds_nv[i];
    ofile.close();
}

// hàm tìm kiếm nhan vien
void NhanVien::timKiemN(vector<NhanVien>ds_nv, NhanVien nv) {
    ifstream file;
    file.open("DSNV.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSN(file, ds_nv);
    string maTimKiem;
    cout << "\n Nhap ma/ten nhan vien can tim: ";
    cin.ignore(); 
    getline(cin, maTimKiem);
    int found = 0;
    for (int i = 0; i < ds_nv.size(); i++) {
        if (stricmp(ds_nv[i].getmaSo().c_str(), maTimKiem.c_str()) == 0 || stricmp(ds_nv[i].gethoTen().c_str(), maTimKiem.c_str()) == 0) {
            cout << " --------------------------------------------------- " << endl;
            cout << "                   THE NHAN VIEN                     " << endl << endl;
            cout << "  Ho va ten: " << ds_nv[i].gethoTen() << endl;
            cout << "  Ma nhan vien: " << ds_nv[i].getmaSo() << endl;
            cout << "  Ngay sinh: " << ds_nv[i].getngaySinh() << endl;
            cout << "  So dien thoai: " << ds_nv[i].getsoDT() << endl;
            cout << "  Chuc vu: " << ds_nv[i].chucVu << endl;
            cout << "  Trang Thai: " << ds_nv[i].trangThai << endl << endl;
            cout << " --------------------------------------------------- " << endl;
            found = 1;
        }
    }
    if (found == 0) {
        cout << "\n Nhan vien khong ton tai trong he thong!" << endl;
    }
    file.close();
}

// ham xoa 1 nv
void NhanVien::xoa1N(vector<NhanVien> ds_nv, NhanVien nv) {
    ifstream file;
    file.open("DSNV.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSN(file, ds_nv);
    string ma;
    cout << "\n Nhap ma nhan vien: ";
    cin >> ma;
    int found = 0;
    for (int i = 0; i < ds_nv.size(); i++) {
        if (stricmp(ds_nv[i].getmaSo().c_str(), ma.c_str()) == 0) {
            cout << "\n Xoa thong tin Nhan vien co ma " << ds_nv[i].getmaSo() << " thanh cong! " << endl;
            ds_nv.erase(ds_nv.begin() + i);
            found = 1;
            cout << endl;
            ofstream ofile;
            ofile.open("DSNV.txt", ios::trunc);
            for (int i = 0; i < ds_nv.size() - 1; i++)
                ofile << ds_nv[i];
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n Nhan vien khong ton tai trong he thong!!" << endl;
    }
    file.close();
}

// ham cham cong nhan vien
void NhanVien::chamCong(vector<NhanVien> ds_nv, NhanVien& nv) {
    ifstream file;
    file.open("DSNV.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSN(file, ds_nv);
    string ma;
    cout << "\n Nhap ma nhan vien: ";
    cin >> ma;
    int found = 0;
    for (int i = 0; i < ds_nv.size(); i++) {
        if (stricmp(ds_nv[i].getmaSo().c_str(), ma.c_str()) == 0) {
            cout << "\n *CHAM CONG CHO NHAN VIEN " << ds_nv[i].gethoTen() << " - " << ds_nv[i].chucVu << " (" << ds_nv[i].getmaSo() << "): " << endl; 
            cout << "\n  Nhap muc luong theo gio: ";                cin >> ds_nv[i].luongTheoH;
            cout << "\n  Nhap so gio lam viec trong ngay: ";        cin >> ds_nv[i].soGioLam;
            cout << "\n  Nhap so ngay lam viec trong thang: ";      cin >> ds_nv[i].soNgayLamViec;
            cout << "\n  Nhap so ngay nghi viec trong thang: ";     cin >> ds_nv[i].soNgayNghi;
            cout << "\n  Nhap so lan di tre trong thang: ";         cin >> ds_nv[i].soLanDiTre;
            tinhLuongNV(ds_nv[i]);
            found = 1;
            cout << endl;
            ofstream ofile;
            ofile.open("DSNV.txt", ios::trunc);
            for (int i = 0; i < ds_nv.size() - 1; i++)
                ofile << ds_nv[i];
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n Nhan vien khong ton tai trong he thong!" << endl;
    }
    file.close();
}

// ham tinh luong
void NhanVien::tinhLuongNV(NhanVien& nv) {
    nv.tongLuong = (nv.luongTheoH * nv.soGioLam * nv.soNgayLamViec) - (nv.luongTheoH * nv.soGioLam * nv.soNgayNghi) - (nv.luongTheoH * 0.2 * nv.soGioLam * nv.soLanDiTre);
    //// Tong luong = (Muc luong*So gio lam*So ngay lam) - (Muc luong*So gio lam*So ngay nghi) - (20% Luong 1 ngay lam) 
}

// ham check luong nv
void NhanVien::checkLuongNV(vector < NhanVien> ds_nv, NhanVien& nv) {
    ifstream file;
    file.open("DSNV.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSN(file, ds_nv);
    string ma;
    cout << "\n Nhap ma/ten nhan vien can tim: "; 
    cin.ignore(); 
    getline(cin, ma); 
    int check = 0;
    for (int i = 0; i < ds_nv.size(); i++) {
        if (stricmp(ds_nv[i].getmaSo().c_str(), ma.c_str()) == 0 || stricmp(ds_nv[i].gethoTen().c_str(), ma.c_str()) == 0) {
            cout << "\n -> Tong luong thang nay cua nhan vien " << ds_nv[i].gethoTen() << " la: "; 
            cout << fixed << setprecision(0) << ds_nv[i].tongLuong << " VND" << endl;
            cout << "\n -> So lan ban hang: " << ds_nv[i].soLanBanHang() << endl; 
            check = 1;
        }
    }
    if (check == 0) {
        cout << "\n Nhan vien khong ton tai trong he thong!" << endl;
    }
    file.close();
}

// ham cap nhat thong tin nhan vien
void NhanVien::CapnhatthongtinN(vector < NhanVien> ds_nv, NhanVien nv) {
    ifstream file;
    file.open("DSNV.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSN(file, ds_nv);
    string ma;
    cout << "\n Nhap ma nhan vien can cap nhat: ";
    cin >> ma;
    int capnhat = 0;
    cout << endl;
    for (int i = 0; i < ds_nv.size(); i++) {
        if (stricmp(ds_nv[i].getmaSo().c_str(), ma.c_str()) == 0) {

            string _hoTen, _maNV, _ngaySinh, _soDT; 

            cout <<"\n Ho va ten hien tai la: " << ds_nv[i].gethoTen()<<endl;
            cout << " Ban muon cap nhap lai Ho va ten moi la: ";
            cin.ignore();
            getline(cin,_hoTen);
            ds_nv[i].sethoTen(_hoTen);

            cout << "\n Ma nhan vien hien tai la: " << ds_nv[i].getmaSo() << endl;
            cout << " Ban muon cap nhap lai Ma nhan vien moi la: ";
            getline(cin, _maNV);
            ds_nv[i].setmaSo(_maNV);

            cout << "\n Ngay sinh hien tai la: " << ds_nv[i].getngaySinh() << endl;;
            cout << " Ban muon cap nhap lai Ngay sinh moi la: ";
            getline(cin, _ngaySinh);
            ds_nv[i].setngaySinh(_ngaySinh);

            cout << "\n So dien thoai hien tai la: " << ds_nv[i].getsoDT() << endl;;
            cout << " Ban muon cap nhap lai So dien thoai moi la: ";
            getline(cin, _soDT);
            ds_nv[i].setsoDT(_soDT);

            cout << "\n Chuc vu hien tai la: " << ds_nv[i].chucVu << endl;;
            cout << " Ban muon cap nhap lai Chuc vu moi la: ";
            getline(cin, nv.chucVu);
            ds_nv[i].chucVu = nv.chucVu;

            cout << "\n Trang thai hien tai la: " << ds_nv[i].trangThai << endl;;
            cout << " Ban muon cap nhap lai Trang thai moi la: ";
            getline(cin, nv.trangThai);
            ds_nv[i].trangThai = nv.trangThai;

            capnhat = 1;
            ofstream ofile;
            ofile.open("DSNV.txt", ios::trunc);
            for (int i = 0; i < ds_nv.size() - 1; i++)
                ofile << ds_nv[i];
            ofile.close();
        }
    }
    if (capnhat == 0) {
        cout << "\n Nhan vien khong ton tai trong he thong!" << endl;
    }
    file.close();
}

void NhanVien::MENU()
{
    cout << "\n -------------------------------------------------------- " << endl;
    cout << " |                                                      | " << endl;
    cout << " |                   DANH MUC NHAN VIEN                 | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |  1. Them nhan vien vao danh sach.                    | " << endl;
    cout << " |  2. In danh sach nhan vien.                          | " << endl;
    cout << " |  3. Cap nhat thong tin nhan vien.                    | " << endl;
    cout << " |  4. Tim kiem thong tin nhan vien.                    | " << endl;
    cout << " |  5. Cham cong nhan vien.                             | " << endl;
    cout << " |  6. Xem luong 1 nhan vien bat ky.                    | " << endl;
    cout << " |  7. Xoa 1 nhan vien trong danh sach.                 | " << endl;
    cout << " |                                                      | " << endl;
    cout << " -------------------------------------------------------- " << endl;

}
int NhanVien::ChonMenu()
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

void NhanVien::XuLyMenu(ifstream& file, vector < NhanVien> ds_nv, NhanVien& nv)
{
    int chon=ChonMenu();
    switch (chon)
    {
    case 1:
        system("cls");
        cout << "\n Ban da chon chuc nang Them nhan vien vao danh sach! \n";
        +ds_nv;
        break;
    case 2:
        system("cls");
        cout << "\n Ban da chon chuc nang In danh sach nhan vien! \n";
        file.open("DSNV.txt", ios_base::in);  // mở file ra đọc
        Doc_File_DSN(file, ds_nv);
        inDSN(ds_nv);
        file.close();
        break;
    case 3:
        system("cls");
        cout << "\n Ban da chon chuc nang Cap nhat thong tin nhan vien! \n";
        CapnhatthongtinN(ds_nv, nv);
        break;
    case 4:
        system("cls");
        cout << "\n Ban da chon chuc nang Tim kiem thong tin nhan vien! \n";
        timKiemN(ds_nv, nv);
        break;
    case 5:
        system("cls");
        cout << "\n Ban da chon chuc nang Cham cong nhan vien! \n";
        chamCong(ds_nv, nv);
        break;
    case 6:
        system("cls");
        cout << "\n Ban da chon chuc nang Xem luong 1 nhan vien bat ky! \n";
        checkLuongNV(ds_nv, nv);
        break;
    case 7:
        system("cls");
        cout << "\n Ban da chon chuc nang Xoa 1 nhan vien trong danh sach! \n";
        xoa1N(ds_nv, nv);
        break;
    }
}

// khoi toa - huy 
NhanVien::NhanVien(string _maNV, string _hoTen, string _ngaySinh, string _soDT, string _trangThai, string _chucVu, int _soLanDiTre, double _luongTheoH, double _tongLuong, int _soNgayLamViec, int _soNgayNghi, int _soGioLam) : ConNguoi(_maNV, _hoTen, _ngaySinh, _soDT) {
    trangThai = _trangThai;
    chucVu = _chucVu;
    soLanDiTre = _soLanDiTre;
    luongTheoH = _luongTheoH;
    tongLuong = _tongLuong;
    soNgayLamViec = _soNgayLamViec;
    soNgayNghi = _soNgayNghi;
    soGioLam = _soGioLam;
}
NhanVien::NhanVien(const NhanVien& nv) : ConNguoi(nv) {
    trangThai = nv.trangThai;
    chucVu = nv.chucVu;
    soLanDiTre = nv.soLanDiTre;
    luongTheoH = nv.luongTheoH;
    tongLuong = nv.tongLuong;
    soNgayLamViec = nv.soNgayLamViec;
    soNgayNghi = nv.soNgayNghi;
    soGioLam = nv.soGioLam;
}
NhanVien::~NhanVien() {}

// set- set 
string NhanVien::getchucVu() { return chucVu; }
int NhanVien::getsoLanDiTre() { return soLanDiTre; }
double NhanVien::getluongTheoH() { return luongTheoH; }
double NhanVien::gettongLuong() { return tongLuong; }
int NhanVien::getsoGioLam() { return soGioLam; }
int NhanVien::getsoNgayLamViec() { return soNgayLamViec; }
int NhanVien::getsoNgayNghi() { return soNgayNghi; }
void NhanVien::settrangThai(string trangThai) {
    this->trangThai = trangThai;
}
void NhanVien::setchucVu(string chucVu) {
    this->chucVu = chucVu;
}
void NhanVien::setsoLanDiTre(int soLanDiTre) {
    this->soLanDiTre = soLanDiTre;
}
void NhanVien::setluongTheoH(double luongTheoH) {
    this->luongTheoH = luongTheoH;
}
void NhanVien::settongLuong(double tongLuong) {
    this->tongLuong = tongLuong;
}
void NhanVien::setsoGioLam(int soGiaLam) {
    this->soGioLam = soGiaLam;
}
void NhanVien::setsoNgayLamViec(int soNgayLamViec) {
    this->soNgayLamViec = soNgayLamViec;
}
void NhanVien::setsoNgayNghi(int soNgayNghi) {
    this->soNgayNghi = soNgayNghi;
}

int NhanVien::soLanBanHang() {
    vector<HoaDon> ds_hd;
    ifstream file;
    file.open("DSHD.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSHD(file, ds_hd);
    int found = 0;
    int dem = 0;
    for (int j = 0; j < ds_hd.size(); j++) {
        if (stricmp(ds_hd[j].gettenNV_HD().c_str(), gethoTen().c_str()) == 0) {
            dem = dem + 1;
            found = 1;
        }
    }
    return dem;
    if (found == 0) {
        return 0;
    }
    file.close();
}

