#include "KhachHang.h"


// hàm nhap thong tin 1 khach hàng
istream& operator >> (istream& in, KhachHang& kh) {
    string maKH, hoTen, ngaySinh, soDT;
    double soDiemKH; 
    Date ngayDKTheKH; 
    cout << " Ho va ten: ";                 getline(in, hoTen);
    cout << " Ma khach hang: ";             getline(in, maKH);
    cout << " Ngay sinh: ";                 getline(in, ngaySinh);
    cout << " So dien thoai: ";             getline(in, soDT);
    cout << " So diem khach hang: ";        in >> soDiemKH;
    cout << " Ngay dang ky: ";              in >> ngayDKTheKH;
    cout << endl;
    kh = KhachHang(maKH, hoTen, ngaySinh, soDT, ngayDKTheKH, soDiemKH); 
    return in;
}

// hàm xuất thông tin 1 khách hàng 
ostream& operator << (ostream& out, KhachHang kh) {
    out << kh.gethoTen() << "_";
    out << kh.getmaSo() << "_";
    out << kh.getngaySinh() << "_";
    out << kh.getsoDT() << "_";
    out << kh.soDiemKH << " ";
    out << kh.ngayDKTheKH << " ";
    out << endl;
    return out;
}

// hàm đọc thông tin khach hang
void KhachHang::Doc_File_N(ifstream& file, KhachHang& kh)
{
    string maKH, hoTen, ngaySinh, soDT;
    double soDiemKH;
    Date ngayDKTheKH;
    getline(file, hoTen, '_');
    getline(file, maKH, '_');
    getline(file, ngaySinh, '_');
    getline(file, soDT, '_');
    file >> soDiemKH;
    file >> ngayDKTheKH;
    string temp;
    getline(file, temp);  // khắc phục lỗi xuống dòng sau khi đọc xong 1 dòng dữ liệu
    kh = KhachHang(maKH, hoTen, ngaySinh, soDT, ngayDKTheKH, soDiemKH); 
}

// Hàm chính đọc dữ liệu Danh sach KH
void KhachHang::Doc_File_DSN(ifstream& file, vector<KhachHang>& ds_kh) 
{
    while (file.eof() == false) 
    {
        KhachHang kh; 
        Doc_File_N(file, kh); 
        ds_kh.push_back(kh); 
    }
}

// xuất thông tin dạng bảng
void KhachHang::Xuat_File_Thong_Tin_DSN(KhachHang kh)
{
    cout << setw(25) << left << kh.gethoTen();
    cout << setw(15) << left << kh.getmaSo();
    cout << setw(15) << left << kh.getngaySinh();
    cout << setw(15) << left << kh.getsoDT();
    cout << setw(15) << left << kh.soLanMuaHang();
    cout << setw(5) << left << kh.soDiemKH << "    ";
    cout << setw(0) << left << kh.ngayDKTheKH;
    cout << endl;
}

// ham in du lieu doc tu file
void KhachHang::inDSN(vector<KhachHang>ds_kh)
{
    cout << "____________________________________________________________________________________________________________" << endl << endl; 
    cout << "                                             DANH SACH KHACH HANG" << endl;
    cout << endl;
    cout << setw(5) << left << "STT";
    cout << setw(25) << left << "HO VA TEN";
    cout << setw(15) << left << "MA NV";
    cout << setw(15) << left << "NGAY SINH";
    cout << setw(15) << left << "SDT";
    cout << setw(15) << left << "SO LAN MUA";
    cout << setw(5) << left << "DIEM" << "    ";
    cout << setw(0) << left << "NGAY DK THE";
    cout << endl;
    cout << "____________________________________________________________________________________________________________" << endl << endl; 
    for (int i = 0; i < ds_kh.size() - 1; i++)
    {
        cout << setw(5) << left << i + 1;
        Xuat_File_Thong_Tin_DSN(ds_kh[i]);
    }
    cout << "____________________________________________________________________________________________________________" << endl;
}

// hàm cập nhật thông tin khách hàng
void KhachHang::capNhatN(vector<KhachHang> ds_kh, KhachHang kh) {
    ifstream file;
    file.open("DSKH.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSN(file, ds_kh);
    string ma;
    cout << "\n Nhap ma khach hang can cap nhat: ";
    cin >> ma; 
    int capnhat = 0;
    cout << endl;
    for (int i = 0; i < ds_kh.size(); i++) {
        if (stricmp(ds_kh[i].getmaSo().c_str(), ma.c_str()) == 0) {

            string _hoTen, _maKH, _ngaySinh, _soDT;

            cout << "\n Ho va ten hien tai la: " << ds_kh[i].gethoTen() << endl;
            cout << " Ban muon cap nhap lai Ho va ten moi la: ";
            cin.ignore();
            getline(cin, _hoTen);
            ds_kh[i].sethoTen(_hoTen);

            cout << "\n Ma khach hang hien tai la: " << ds_kh[i].getmaSo() << endl;
            cout << " Ban muon cap nhap lai Ma khach hang moi la: ";
            getline(cin, _maKH);
            ds_kh[i].setmaSo(_maKH);

            cout << "\n Ngay sinh hien tai la: " << ds_kh[i].getngaySinh() << endl;;
            cout << " Ban muon cap nhap lai Ngay sinh moi la: ";
            getline(cin, _ngaySinh);
            ds_kh[i].setngaySinh(_ngaySinh);

            cout << "\n So dien thoai hien tai la: " << ds_kh[i].getsoDT() << endl;;
            cout << " Ban muon cap nhap lai So dien thoai moi la: ";
            getline(cin, _soDT);
            ds_kh[i].setsoDT(_soDT);

            capnhat = 1;
            ofstream ofile;
            ofile.open("DSKH.txt", ios::trunc);
            for (int i = 0; i < ds_kh.size() - 1; i++)
                ofile << ds_kh[i];
            ofile.close();
        }
    }
    if (capnhat == 0) {
        cout << "\n Khach hang khong ton tai trong he thong!" << endl;
    }
    file.close();
}

// hàm xoa 1 KH
void KhachHang::xoa1N(vector<KhachHang> ds_kh, KhachHang kh) {
    ifstream file;
    file.open("DSKH.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSN(file, ds_kh);
    string ma;
    cout << "\n Nhap ma Khach Hang: ";
    cin >> ma;
    int found = 0;
    for (int i = 0; i < ds_kh.size(); i++) {
        if (stricmp(ds_kh[i].getmaSo().c_str(), ma.c_str()) == 0) {
            cout << "\n Xoa thong tin Khach hang co ma " << ds_kh[i].getmaSo() << " thanh cong!" << endl;
            ds_kh.erase(ds_kh.begin() + i);
            found = 1;
            cout << endl;
            ofstream ofile;
            ofile.open("DSKH.txt", ios::trunc);
            for (int i = 0; i < ds_kh.size() - 1; i++)
                ofile << ds_kh[i];
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n Khach hang khong ton tai trong he thong!!" << endl;
    }
    file.close();
}

// ham them khach hang
void operator + (vector<KhachHang> ds_kh) {
    KhachHang kht[100];
    int n;
    cout << "\n Nhap SL khach hang can them: ";     cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin >> kht[i];
        ds_kh.push_back(kht[i]);
    }
    ofstream ofile;
    ofile.open("DSKH.txt", ios::app);
    for (int i = 0; i < n; i++)
        ofile << ds_kh[i];
    ofile.close();
}

// tim kiem Kh
void KhachHang::timKiemN(vector<KhachHang> ds_kh, KhachHang kh) {
    ifstream file;
    file.open("DSKH.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSN(file, ds_kh);
    string maTimKiem;
    cout << "\n Nhap ma/ten khach hang can tim: ";
    cin.ignore(); 
    getline(cin, maTimKiem); 
    int found = 0;
    for (int i = 0; i < ds_kh.size(); i++) {
        if (stricmp(ds_kh[i].getmaSo().c_str(), maTimKiem.c_str()) == 0 || stricmp(ds_kh[i].gethoTen().c_str(), maTimKiem.c_str()) == 0) {
            cout << " --------------------------------------------------- " << endl;
            cout << "  LOAI THE: ";    ds_kh[i].xepHangKH(kh);     cout << endl;
            cout << "                   THE KHACH HANG                    " << endl << endl;
            cout << "  Ho va ten: " << ds_kh[i].gethoTen() << endl;
            cout << "  Ma khach hang: " << ds_kh[i].getmaSo() << endl;
            cout << "  Ngay sinh: " << ds_kh[i].getngaySinh() << endl;
            cout << "  So dien thoai: " << ds_kh[i].getsoDT() << endl;
            cout << "  Ngay dang ky the: " << ds_kh[i].ngayDKTheKH << endl;
            cout << "  So lan mua hang: " << ds_kh[i].soLanMuaHang() << endl; 
            cout << "  So diem tich luy: " << ds_kh[i].soDiemKH << endl << endl;
            cout << " --------------------------------------------------- " << endl;
            found = 1;
        }
    }
    if (found == 0) {
        cout << "\n Khach hang khong ton tai trong he thong!" << endl;
    }
    file.close();
}

void KhachHang::xepHangKH(KhachHang kh) {
    if (soDiemKH >= 80) {
        cout << "THE KIM CUONG" << endl;
    }
    else if (soDiemKH >= 50 && soDiemKH < 80) {
        cout << "THE VANG" << endl;
    }
    else if (soDiemKH >= 25 && soDiemKH < 50) {
        cout << "THE BAC" << endl;
    }
    else if (soDiemKH >= 0 && soDiemKH < 25) {
        cout << "THE THANH VIEN" << endl;
    }
}

void KhachHang::congdiemKH(vector<KhachHang> ds_kh, KhachHang kh) {
    ifstream file;
    file.open("DSKH.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSN(file, ds_kh);
    string maTimKiem;
    cout << "\n Nhap Ma khach hang: ";
    cin >> maTimKiem;
    int found = 0;
    for (int i = 0; i < ds_kh.size(); i++)
    {
        // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
        if (stricmp(ds_kh[i].getmaSo().c_str(), maTimKiem.c_str()) == 0) {
            cout << "\n So diem cua khach hang " << ds_kh[i].gethoTen() << " la: " << ds_kh[i].soDiemKH << endl;
            cout << "\n So diem cong them: ";
            float a;
            cin >> a;
            ds_kh[i].soDiemKH = ds_kh[i].soDiemKH + a;
            cout << "\n So diem hien tai la: " << ds_kh[i].soDiemKH << endl;
            found = 1;
            ofstream ofile;
            ofile.open("DSKH.txt", ios::trunc);
            for (int i = 0; i < ds_kh.size() - 1; i++)
                ofile << ds_kh[i];
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n Khach Hang khong ton tai trong he thong!" << endl;
    }
}

int KhachHang::ChonMenu() {
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

void KhachHang::MENU() {
    cout << "\n -------------------------------------------------------- " << endl;
    cout << " |                                                      | " << endl;
    cout << " |                   DANH MUC KHACH HANG                | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |       1. Them thong tin Khach hang.                  | " << endl;
    cout << " |       2. In danh sach cac Khach hang.                | " << endl;
    cout << " |       3. Cap nhat thong tin Khach hang.              | " << endl;
    cout << " |       4. Cap nhat diem Khach hang.                   | " << endl;
    cout << " |       5. Tim kiem thong tin Khach hang.              | " << endl;
    cout << " |       6. Xoa thong tin 1 Khach hang.                 | " << endl;
    cout << " |                                                      | " << endl;
    cout << " -------------------------------------------------------- " << endl;
}

void KhachHang::XuLyMenu(ifstream& file, vector<KhachHang> ds_kh, KhachHang kh) {

    int chon = ChonMenu();
    switch (chon)
    {
    case 1:
        system("cls");
        cout << "\n Ban da chon chuc nang Them thong tin Khach hang! \n";
        +ds_kh; 
        break;
    case 2:
        system("cls");
        cout << "\n Ban da chon chuc nang In danh sach cac Khach hang! \n";
        file.open("DSKH.txt", ios_base::in);  // mở file ra đọc
        Doc_File_DSN(file, ds_kh);
        inDSN(ds_kh);
        file.close();
        break;
    case 3:
        system("cls");
        cout << "\n Ban da chon chuc nang Cap nhat thong tin Khach hang! \n";
        capNhatN(ds_kh, kh);
        break;
    case 4:
        system("cls");
        cout << "\n Ban da chon chuc nang Cap nhat diem Khach hang! \n";
        congdiemKH(ds_kh, kh);
        break;
    case 5:
        system("cls");
        cout << "\n Ban da chon chuc nang Tim kiem thong tin Khach hang! \n";
        timKiemN(ds_kh, kh);
        break;
    case 6:
        system("cls");
        cout << "\n Ban da chon chuc nang Xoa thong tin 1 Khach hang! \n";
        xoa1N(ds_kh, kh);
        break;
    }
}

// Ham get - set, Ham KTao - huy: 
void KhachHang::setNgDangKyThe(Date x) {
    x = ngayDKTheKH;
}
Date KhachHang::getNgDangKyThe() {
    return ngayDKTheKH;
}
void KhachHang::setSoDiem(double x) {
    x = soDiemKH;
}
double KhachHang::getSoDiem() {
    return soDiemKH;
}
void KhachHang::setDiemC(double x) {
    x = diemCongKH;
}
double KhachHang::getDiemC() {
    return diemCongKH;
}
KhachHang::KhachHang(string _maKH, string _hoTen, string _ngaySinh, string _soDT, Date _ngayDKTheKH, double _soDiemKH) : ConNguoi(_maKH, _hoTen, _ngaySinh, _soDT) {
    ngayDKTheKH = _ngayDKTheKH;
    soDiemKH = _soDiemKH;
}
KhachHang::KhachHang(const KhachHang& kh) : ConNguoi(kh) {
    ngayDKTheKH = kh.ngayDKTheKH;
    soDiemKH = kh.soDiemKH;
}
KhachHang::~KhachHang() {}

int KhachHang::soLanMuaHang() {
    vector<HoaDon> ds_hd;
    ifstream file;
    file.open("DSHD.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSHD(file, ds_hd);
    int found = 0;
    int dem = 0; 
    for (int j = 0; j < ds_hd.size(); j++) {
        if (stricmp(ds_hd[j].gettenKH_HD().c_str(), gethoTen().c_str()) == 0) {
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


