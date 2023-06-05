#include "HoaDon.h" 

istream& operator >> (istream& in, HoaDon& hd) 
{
    cout << "\n Nhap ma HD: ";                  getline(in, hd.maHD);
    cout << " Nhap ngay HD: ";                  in >> hd.ngayHD;                in.ignore();
    cout << " Nhap ten NV: ";                   getline(in, hd.tenNV_HD);
    cout << " Nhap ten KH: ";                   getline(in, hd.tenKH_HD);
    cout << " Nhap ma KM: ";                    getline(in, hd.maKM);
    cout << " Nhap so luong san pham mua: ";    in >> hd.slCacSPMua;
    for (int j = 1; j <= hd.slCacSPMua; j++) {
        in.ignore();
        cout << "\n Ten san pham " << j << ": ";  getline(in, hd.cacSPMua[j]);
        cout << " Gia SP: ";                    in >> hd.tienTungSP[j];
        cout << " So luong mua: ";              in >> hd.slTungSP[j];
    }
    cout << endl;
    return in; 
}

ostream& operator << (ostream& out, HoaDon hd) 
{
    hd.TongTien = hd.tinhThanhTien1HD();
    out << hd.maHD << ".";
    out << hd.tenNV_HD << ".";
    out << hd.tenKH_HD << ".";
    out << hd.maKM << ".";
    out << hd.slCacSPMua << " ";
    for (int j = 1; j <= hd.slCacSPMua; j++) {
        out << hd.cacSPMua[j] << ".";
        out << hd.slTungSP[j] << " ";
        out << hd.tienTungSP[j] << " ";
    }
    out << hd.TongTien << " ";
    out << hd.ngayHD << endl;
    return out;
}

void HoaDon::Doc_File_HD(ifstream& file, HoaDon& hd)
{
    hd.TongTien = hd.tinhThanhTien1HD();
    getline(file, hd.maHD, '.');
    getline(file, hd.tenNV_HD, '.');
    getline(file, hd.tenKH_HD, '.');
    getline(file, hd.maKM, '.');
    file >> hd.slCacSPMua;
    for (int j = 1; j <= hd.slCacSPMua; j++) {
        getline(file, hd.cacSPMua[j], '.');
        file >> hd.slTungSP[j];
        file >> hd.tienTungSP[j];
    }
    file >> hd.TongTien;
    file >> hd.ngayHD;
    string temp;
    getline(file, temp);  // khắc phục lỗi xuống dòng sau khi đọc xong 1 dòng dữ liệu
}

void HoaDon::Doc_File_DSHD(ifstream& file, vector<HoaDon>& ds_hd)
{
    while (file.eof() == false)
    {
        HoaDon hd;
        Doc_File_HD(file, hd);
        ds_hd.push_back(hd);
    }
}

void HoaDon::Xuat_File_Thong_Tin_DSHD(HoaDon hd)
{
    hd.TongTien = hd.tinhThanhTien1HD();
    cout << setw(7) << left << hd.maHD;
    cout << setw(15) << left << hd.ngayHD << "      "; 
    cout << setw(20) << left << hd.tenNV_HD;
    cout << setw(20) << left << hd.tenKH_HD;
    cout << setw(10) << left << hd.slCacSPMua;
    cout << setw(10) << left << hd.maKM;
    cout << setw(10) << left << hd.TongTien;
    cout << endl; 
}

void HoaDon::inDanhSachHoaDon(vector<HoaDon> ds_hd)
{
    cout << "_________________________________________________________________________________________________________" << endl << endl; 
    cout << "                                              DANH SACH CAC HOA DON                                      " << endl;
    cout << endl;
    cout << setw(5) << left << "STT";
    cout << setw(7) << left << "MA HD";
    cout << setw(15) << left << "NGAY HD";
    cout << setw(20) << left << "TEN NV";
    cout << setw(20) << left << "TEN KH";
    cout << setw(10) << left << "SL MUA";
    cout << setw(10) << left << "MA KM";
    cout << setw(10) << left << "TONG TIEN";
    cout << endl;
    cout << "_________________________________________________________________________________________________________" << endl << endl; 
    double tong = 0; 
    for (int i = 0; i < ds_hd.size() - 1; i++)
    {
        ds_hd[i].TongTien = ds_hd[i].tinhThanhTien1HD();
        cout << setw(5) << left << i + 1;
        Xuat_File_Thong_Tin_DSHD(ds_hd[i]);
        tong = tong + ds_hd[i].TongTien; 
    }
    cout << "\n\n TONG CONG: " << tong << " VND" << endl;
    cout << "_________________________________________________________________________________________________________" << endl; 
    
}

void HoaDon::timKiemHoaDon(vector<HoaDon> ds_hd, HoaDon hd)
{
    ifstream file;
    file.open("DSHD.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSHD(file, ds_hd);
    string maTimKiem;
    cout << "\n Nhap ma hoa don can tim: ";
    cin >> maTimKiem;
    int found = 0;
    for (int i = 0; i < ds_hd.size(); i++) {
        if (stricmp(ds_hd[i].maHD.c_str(), maTimKiem.c_str()) == 0) {
            cout << " ------------------------------------------------------------------------- " << endl;
            cout << "  Ngay hoa don: " << ds_hd[i].ngayHD << endl;
            cout << "                              HOA DON BAN HANG                  " << endl << endl;
            cout << "  Ma hoa don: " << ds_hd[i].maHD << endl;
            cout << "  Nguoi ban: " << ds_hd[i].tenNV_HD << endl;
            cout << "  Nguoi mua: " << ds_hd[i].tenKH_HD << endl << endl;
            /*for (int j = 1; j <= ds_hd[i].slCacSPMua; j++) {
                cout << "  Ten san pham thu " << j << ": " << ds_hd[i].cacSPMua[j] << endl;
                cout << "  Gia tien: " << ds_hd[i].tienTungSP[j] << " VND" << endl;
                cout << "  So luong: " << ds_hd[i].slTungSP[j] << endl;
                cout << endl;
            }*/
            cout << setw(10) << left << " ";
            cout << setw(5) << left << "STT"; 
            cout << setw(25) << left << "Ten san pham"; 
            cout << setw(10) << left << "Gia tien";
            cout << setw(5) << left << "SL";
            cout << endl << endl; 
            for (int j = 1; j <= ds_hd[i].slCacSPMua; j++) {
                cout << setw(10) << left << " ";
                cout << setw(5) << left << j; 
                cout << setw(25) << left << ds_hd[i].cacSPMua[j]; 
                cout << setw(10) << left << ds_hd[i].tienTungSP[j];
                cout << setw(5) << left << ds_hd[i].slTungSP[j];
                cout << endl; 
            }
            cout << "\n\n  Giam gia: " << ds_hd[i].apDungMaKM() << " VND"; 
            cout << endl << "\n  TONG CONG: " << ds_hd[i].tinhThanhTien1HD() << " VND" << endl << endl;
            cout << " ------------------------------------------------------------------------- " << endl;
            found = 1;
        }
    }
    if (found == 0) {
        cout << "\n Hoa don khong ton tai trong he thong!" << endl;
    }
    file.close();
}

double HoaDon::tinhThanhTien1HD()
{
    double thanhTienHD = 0;
    for (int i = 1; i <= slCacSPMua; i++) {
        thanhTienHD = thanhTienHD + tienTungSP[i] * slTungSP[i];
    }
    return thanhTienHD - apDungMaKM(); 
}

void operator + (vector<HoaDon> ds_hd)
{
    SanPham* p;
    ifstream file;
    Food spf, f;
    vector<Food> ds_spf;
    SanPham spd, d;
    vector<SanPham> ds_spd;

    system("cls");
    cout << "_________________________________________________________________________________________________ " << endl << endl;
    cout << "                                          DANH SACH SAN PHAM                                      " << endl;
    cout << endl;
    cout << setw(15) << left << "MA SP";
    cout << setw(17) << left << "TEN SP";
    cout << setw(15) << left << "DON GIA";
    cout << setw(15) << left << "SL SP";
    cout << setw(15) << left << "NSX";
    cout << setw(15) << left << "HSD";
    cout << endl;
    cout << "_________________________________________________________________________________________________ " << endl << endl;
    file.open("DSFOOD.txt", ios_base::in);  // mở file ra đọc
    spf.Doc_File_DSSP(file, ds_spf);
    for (int i = 0; i < ds_spf.size() - 1; i++)
    {
        p = &spf;
        p->Xuat_File_Thong_Tin_DSSP(ds_spf[i]);
    }
    file.close();
    cout << endl;
    file.open("DSDRINK.txt", ios_base::in);  // mở file ra đọc
    spd.Doc_File_DSSP(file, ds_spd);
    for (int j = 0; j < ds_spd.size() - 1; j++)
    {
        p = &spd;
        p->Xuat_File_Thong_Tin_DSSP(ds_spd[j]);
    }
    file.close();
    cout << "_________________________________________________________________________________________________ " << endl << endl;
    HoaDon hdt[100]; 
    int n; 
    cout << "\n\n Nhap SL hoa don can them: "; cin >> n; 
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin >> hdt[i];
        ds_hd.push_back(hdt[i]);
    }
    ofstream ofile;
    ofile.open("DSHD.txt", ios::app);
    for (int i = 0; i < n; i++)
        ofile << ds_hd[i];
    ofile.close();
}

void HoaDon::xoaHoaDon(vector<HoaDon> ds_hd, HoaDon hd)
{
    ifstream file;
    file.open("DSHD.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSHD(file, ds_hd);
    string ma;
    cout << "\n Nhap ma hoa don can xoa: ";
    cin >> ma;
    int found = 0;
    for (int i = 0; i < ds_hd.size(); i++) {
        if (stricmp(ds_hd[i].maHD.c_str(), ma.c_str()) == 0) {
            cout << "\n Xoa HD co ma " << ds_hd[i].maHD << " thanh cong! " << endl;
            ds_hd.erase(ds_hd.begin() + i);
            found = 1;
            cout << endl;
            ofstream ofile;
            ofile.open("DSHD.txt", ios::trunc);
            for (int i = 0; i < ds_hd.size() - 1; i++)
                ofile << ds_hd[i];
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n Hoa don khong ton tai trong he thong! " << endl;
    }
    file.close();
}

int HoaDon::ChonMenu()
{
    int n;
    cout << "\n\n Nhap lua chon: ";
    cin >> n;
    if (n > 0 || n < 8) {
        return n;
    }
    else {
        return ChonMenu();
    }
}

void HoaDon::MENU()
{
    cout << "\n -------------------------------------------------------- " << endl;
    cout << " |                                                      | " << endl;
    cout << " |                     DANH MUC HOA DON                 | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |  1. Them thong tin hoa don.                          | " << endl;
    cout << " |  2. Tim kiem thong tin hoa don.                      | " << endl;
    cout << " |  3. In danh sach cac hoa don.                        | " << endl;
    cout << " |  4. Xoa thong tin 1 hoa don.                         | " << endl;
    cout << " |                                                      | " << endl;
    cout << " -------------------------------------------------------- " << endl;
}

void HoaDon::XuLyMenu(ifstream& file, vector<HoaDon> ds_hd, HoaDon hd)
{
    int chon = ChonMenu();
    switch (chon)
    {
    case 1:
        system("cls");
        cout << "\n Ban da chon chuc nang Them thong tin hoa don! \n";
        +ds_hd;
        break;
    case 2:
        system("cls");
        cout << "\n Ban da chon chuc nang Tim kiem thong tin hoa don! \n";
        timKiemHoaDon(ds_hd, hd);
        break;
    case 3:
        system("cls");
        cout << "\n Ban da chon chuc nang In danh sach cac hoa don! \n";
        file.open("DSHD.txt", ios_base::in);  // mở file ra đọc
        Doc_File_DSHD(file, ds_hd);
        inDanhSachHoaDon(ds_hd);
        file.close();
        break;
    case 4:
        system("cls");
        cout << "\n Ban da chon chuc nang Xoa thong tin 1 hoa don! \n";
        xoaHoaDon(ds_hd, hd);
        break;
    }
}

// Ham get - set, Ham KTao - huy: 
string HoaDon::getmaHD() { return maHD; }
Date HoaDon::getngayHD() { return ngayHD; }
string HoaDon::gettenNV_HD() { return tenNV_HD; }
string HoaDon::gettenKH_HD() { return tenKH_HD; }
int HoaDon::getslCacSPMua() { return slCacSPMua; }
double HoaDon::getgiamGiaHD() { return giamGiaHD; }
string HoaDon::getmaKM() { return maKM; }
string HoaDon::getcacSPMua() { 
    for (int i = 0; i < slCacSPMua; i++) {
        return cacSPMua[i];
    }
}
int HoaDon::getslTungSP() {
    for (int i = 0; i < slCacSPMua; i++) {
        return slTungSP[i];
    }
}
double HoaDon::getTongTien() { return TongTien; }
void HoaDon::setmaHD(string maHD) { this->maHD = maHD; }
void HoaDon::setngayHD(Date ngayHD) { this->ngayHD = ngayHD; }
void HoaDon::settenNV_HD(string tenNV_HD) { this->tenNV_HD = tenNV_HD; }
void HoaDon::settenKH_HD(string tenKH_HD) { this->tenKH_HD = tenKH_HD; }
void HoaDon::setslCacSPMua(int slCacSPMua) { this->slCacSPMua = slCacSPMua; }
void HoaDon::setgiamGiaHD(double giamGiaHD) { this->giamGiaHD = giamGiaHD; }
void HoaDon::setmaKM(string maKM) { this->maKM = maKM; }
HoaDon::HoaDon(string _maHD, Date _ngayHD, string _tenNV_HD, string _tenKH_HD, string _cacSPMua[], int _slCacSPMua, int _slTungSP[], double _tienTungSP[], string _maKM, double _giamGiaHD) {
    maHD = _maHD;
    ngayHD = _ngayHD;
    tenNV_HD = _tenNV_HD;
    tenKH_HD = _tenKH_HD;
    maKM = _maKM; 
    giamGiaHD = _giamGiaHD;
    slCacSPMua = _slCacSPMua;
    for (int i = 1; i <= slCacSPMua; i++) {
        cacSPMua[i] = _cacSPMua[i];
        slTungSP[i] = _slTungSP[i];
        tienTungSP[i] = _tienTungSP[i];
    }
}
HoaDon::HoaDon(const HoaDon& hd) {
    maHD = hd.maHD;
    ngayHD = hd.ngayHD;
    tenNV_HD = hd.tenNV_HD;
    tenKH_HD = hd.tenKH_HD;
    maKM = hd.maKM; 
    giamGiaHD = hd.giamGiaHD;
    slCacSPMua = hd.slCacSPMua;
    for (int i = 1; i <= slCacSPMua; i++) {
        cacSPMua[i] = hd.cacSPMua[i];
        slTungSP[i] = hd.slTungSP[i];
        tienTungSP[i] = hd.tienTungSP[i];
    }
    TongTien = hd.TongTien;
}
HoaDon::~HoaDon() {}

double HoaDon::apDungMaKM()
{
    vector<ChuongTrinhKhuyenMai> ds_ct; 
    ifstream file;
    file.open("DSCT.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSCT(file, ds_ct);
    int found = 0; 
    for (int j = 0; j < ds_ct.size(); j++) {
        if (stricmp(ds_ct[j].getmaCT().c_str(), maKM.c_str()) == 0) {
            return ds_ct[j].getgiaTriKM(); 
            found = 1; 
        }
    }
    if (found == 0) {
        return 0; 
    }
    file.close(); 
}
