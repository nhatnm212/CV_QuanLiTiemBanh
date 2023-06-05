#include "NguyenLieu.h" 

// hàm nhập 1 nguyên liệu
istream& operator >> (istream& in, NguyenLieuTrongKho& nl) {
    cout << "\n Nhap ten NL: ";                 getline(in, nl.tenNL); 
    cout << " Nhap ma NL: ";                    in >> nl.maNL;
    cout << " Nhap SL Xuat kho gan nhat: ";     in >> nl.slXuat;
    cout << " Nhap SL Ton kho: ";               in >> nl.slTon;             in.ignore(); 
    cout << " Don vi tinh: ";                   in >> nl.dvTinh; 
    cout << endl;
    return in;
}

// hàm xuất 1 nguyên liệu
ostream& operator << (ostream& out, NguyenLieuTrongKho nl) {
    out << nl.tenNL << ".";
    out << nl.maNL << " ";
    out << nl.slXuat << " ";
    out << nl.slTon << " "; 
    out << nl.dvTinh << " ";
    out << endl;
    return out;
}

// hàm đọc thông tin nguyen lieu
void NguyenLieuTrongKho::Doc_File_NL(ifstream& file, NguyenLieuTrongKho& nl)
{
    getline(file, nl.tenNL, '.');
    getline(file, nl.maNL, ' ');
    file >> nl.slXuat;
    file >> nl.slTon;
    file.ignore(); 
    getline(file, nl.dvTinh, ' ');
    string temp;
    getline(file, temp);  // khắc phục lỗi xuống dòng sau khi đọc xong 1 dòng dữ liệu
}

// Hàm chính đọc dữ liệu Danh sach nguyen lieu
void NguyenLieuTrongKho::Doc_File_DSNL(ifstream& file, vector<NguyenLieuTrongKho>& ds_nl)
{
    while (file.eof() == false)   // doc file cho den khi ket thuc  
    {
        NguyenLieuTrongKho nl;
        Doc_File_NL(file, nl);
        ds_nl.push_back(nl);
    }
}

// xuất thông tin dạng bảng
void NguyenLieuTrongKho::Xuat_File_Thong_Tin_DSNL(NguyenLieuTrongKho nl)
{
    cout << setw(30) << left << nl.tenNL; 
    cout << setw(10) << left << nl.maNL; 
    cout << setw(10) << left << nl.slXuat; 
    cout << setw(10) << left << nl.slTon; 
    cout << setw(10) << left << nl.dvTinh; 
    cout << endl;
}

// ham in du lieu doc tu file
void NguyenLieuTrongKho::inDSNL(vector<NguyenLieuTrongKho>ds_nl)
{
    cout << "_____________________________________________________________________________" << endl << endl; 
    cout << "                         DANH SACH CAC NGUYEN LIEU" << endl;
    cout << endl;
    cout << setw(5) << left << "STT";
    cout << setw(30) << left << "TEN NL";
    cout << setw(10) << left << "MA NL";
    cout << setw(10) << left << "SL XUAT";
    cout << setw(10) << left << "SL TON";
    cout << setw(10) << left << "DV Tinh"; 
    cout << endl;
    cout << "______________________________________________________________________________" << endl << endl;
    for (int i = 0; i < ds_nl.size() - 1; i++)
    {
        cout << setw(5) << left << i + 1;
        Xuat_File_Thong_Tin_DSNL(ds_nl[i]);
    }
    cout << "______________________________________________________________________________" << endl;
}

// hàm thêm nguyên liệu
void operator + (vector<NguyenLieuTrongKho>ds_nl) {
    NguyenLieuTrongKho nlt[100];
    int n;
    cout << "\n Nhap SL nguyen nhap them: "; cin >> n;  cin.ignore(); 
    cout << endl;
    for (int i = 0; i < n; i++) {
        cin >> nlt[i];
        ds_nl.push_back(nlt[i]);
    }
    ofstream ofile;
    ofile.open("DSNL.txt", ios::app);
    for (int i = 0; i < n; i++)
        ofile << ds_nl[i];
    ofile.close();
}

//hàm tìm kiếm nguyenlieu
void NguyenLieuTrongKho::TimKiemNL(vector<NguyenLieuTrongKho>ds_nl, NguyenLieuTrongKho nl)
{
    string ten; 
    cin.ignore(); 
    cout << "\n Nhap ma/ten nguyen lieu ban can tim: ";  getline(cin, ten); 
    cout << endl;
    int found = 0; //  luu vet 
    for (int i = 0; i < ds_nl.size(); i++)
    {
        // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
        if (stricmp(ds_nl[i].maNL.c_str(), ten.c_str()) == 0 || stricmp(ds_nl[i].tenNL.c_str(), ten.c_str()) == 0)
        {
            cout << " --------------------------------------------------- " << endl;
            cout << "                   THE NGUYEN LIEU                     " << endl << endl;
            cout << "  Ten Nguyen Lieu : " << ds_nl[i].tenNL << endl;
            cout << "  Ma Nguyen Lieu: " << ds_nl[i].maNL << endl;
            cout << "  SL Xuat kho gan nhat: " << ds_nl[i].slXuat << endl;
            cout << "  SL Ton kho: " << ds_nl[i].slTon << endl;
            cout << "  Don vi tinh: " << ds_nl[i].dvTinh << endl << endl; 
            cout << " --------------------------------------------------- " << endl;
            found = 1;
        }
    }
    if (found == 0) {
        cout << "\n Nguyen lieu khong ton tai trong kho!" << endl;
    }
}

// ham cap nhap soluong NL
void NguyenLieuTrongKho::CapnhatsoluongNL(vector<NguyenLieuTrongKho> ds_nl, NguyenLieuTrongKho nl)
{
    ifstream file;
    file.open("DSNL.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSNL(file, ds_nl);
    cout << "\n  1. Them n so luong nguyen lieu trong kho " << endl;
    cout << "  2. Lay ra n so luong nguyen trong kho " << endl << endl;
    int n; 
    cout << " Nhap lua chon: "; 
    cin >> n; 
    cin.ignore(); 
    if (n == 1) {
        string ten;
        int sl;
        cout << "\n 1. THEM NGUYEN LIEU " << endl; 
        cout << "\n Nhap ma/ten nguyen lieu: ";
        getline(cin, ten); 
        cout << "\n Nhap so luong ban muon them: ";
        cin >> sl;
        int found = 0; //  luu vet 
        for (int i = 0; i < ds_nl.size(); i++)
        {
            // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
            if (stricmp(ds_nl[i].maNL.c_str(), ten.c_str()) == 0 || stricmp(ds_nl[i].tenNL.c_str(), ten.c_str()) == 0)
            {
                ds_nl[i].slTon = ds_nl[i].slTon + sl; 
                cout << endl;
                cout << "\n Cap nhat so luong nguyen lieu thanh cong! " << endl;
                cout << endl;
                found = 1;
                ofstream ofile;
                ofile.open("DSNL.txt", ios::trunc);
                for (int i = 0; i < ds_nl.size() - 1; i++)
                    ofile << ds_nl[i];
                ofile.close();
            }
        }
        if (found == 0) {
            cout << "\n Nguyen lieu khong ton tai trong kho!" << endl;
        }
    }
    else if (n == 2) {
        string ten;
        int sl;
        cout << "\n 2. LAY NGUYEN LIEU " << endl;
        cout << "\n Nhap ma/ten nguyen lieu: ";
        getline(cin, ten); 
        cout << "\n Nhap so luong ban muon lay ra: ";
        cin >> sl;
        int found = 0; //  luu vet 
        for (int i = 0; i < ds_nl.size(); i++)
        {
            // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
            if (stricmp(ds_nl[i].maNL.c_str(), ten.c_str()) == 0 || stricmp(ds_nl[i].tenNL.c_str(), ten.c_str()) == 0)
            {
                ds_nl[i].slXuat = sl;
                ds_nl[i].slTon = ds_nl[i].slTon - sl;
                cout << endl;
                cout << "\n Cap nhat so luong nguyen lieu thanh cong! " << endl;
                cout << endl;
                found = 1;
                ofstream ofile;
                ofile.open("DSNL.txt", ios::trunc);
                for (int i = 0; i < ds_nl.size() - 1; i++)
                    ofile << ds_nl[i];
                ofile.close();
            }
        }
        if (found == 0) {
            cout << "\n Nguyen lieu khong ton tai trong kho!" << endl;
        }
    }
    else {
        cout << "\n Lua chon cua ban khong hop le! " << endl;
    }
    file.close();
}

// hàm xóa 1 nguyên liệu
void NguyenLieuTrongKho::XoaNL(vector<NguyenLieuTrongKho> ds_nl, NguyenLieuTrongKho nl)
{
    ifstream file;
    file.open("DSNL.txt", ios_base::in);  // mở file ra đọc
    Doc_File_DSNL(file, ds_nl);
    string ma;
    cout << "\n Nhap ma/ten nguyen lieu ban muon xoa: ";  getline(cin, ma);
    cout << endl;
    int found = 0; //  luu vet 
    for (int i = 0; i < ds_nl.size(); i++)
    {
        // dùng hàm so sánh 2 chuỗi không phân biệt kí tự hoa thường
        if (stricmp(ds_nl[i].maNL.c_str(), ma.c_str()) == 0 || stricmp(ds_nl[i].tenNL.c_str(), ma.c_str()) == 0)
        {
            ds_nl.erase(ds_nl.begin() + i);
            cout << "\n Xoa nguyen lieu thanh cong! " << endl;
            cout << endl;
            found = 1;
            ofstream ofile;
            ofile.open("DSNL.txt", ios::trunc);
            for (int i = 0; i < ds_nl.size() - 1; i++)
                ofile << ds_nl[i];
            ofile.close();
        }
    }
    if (found == 0) {
        cout << "\n Nguyen lieu khong ton tai trong kho!" << endl;
    }
    file.close();
}

// hàm menu quan li
void NguyenLieuTrongKho::MENU()
{
    cout << "\n -------------------------------------------------------- " << endl;
    cout << " |                                                      | " << endl;
    cout << " |                   DANH MUC NGUYEN LIEU               | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |       1. Them thong tin Nguyen lieu.                 | " << endl;
    cout << " |       2. In danh sach cac Nguyen lieu.               | " << endl;
    cout << " |       3. Cap nhat so luong Nguyen lieu.              | " << endl;
    cout << " |       4. Tim kiem thong tin Nguyen lieu.             | " << endl;
    cout << " |       5. Xoa thong tin 1 Nguyen lieu.                | " << endl;
    cout << " |                                                      | " << endl;
    cout << " -------------------------------------------------------- " << endl;
}

void NguyenLieuTrongKho::XuLyMenu(ifstream& file, vector < NguyenLieuTrongKho > ds_nl, NguyenLieuTrongKho& nl)
{
    int chon;
    cout << "\n Nhap lua chon: "; 
    cin >> chon;
    switch (chon)
    {
    case 1:
        system("cls");
        cout << "\n Ban da chon chuc nang Them thong tin Nguyen lieu! \n"; 
        +ds_nl;
        cout << "\n Them Nguyen Lieu Thanh Cong! " << endl; 
        break;
    case 2:
        system("cls");
        cout << "\n Ban da chon chuc nang In danh sach cac Nguyen lieu! \n";
        file.open("DSNL.txt", ios_base::in);  // mở file ra đọc
        Doc_File_DSNL(file, ds_nl);
        inDSNL(ds_nl);
        file.close();
        break;
    case 3:
        system("cls");
        cout << "\n Ban da chon chuc nang Cap nhat so luong Nguyen lieu! \n";
        CapnhatsoluongNL(ds_nl, nl);
        break;
    case 4:
        system("cls");
        cout << "\n Ban da chon chuc nang Tim kiem thong tin Nguyen lieu! \n";
        file.open("DSNL.txt", ios_base::in);  // mở file ra đọc
        Doc_File_DSNL(file, ds_nl);
        TimKiemNL(ds_nl, nl);
        file.close();
        
        break;
    case 5:
        system("cls");
        cout << "\n Ban da chon chuc nang Xoa thong tin 1 Nguyen lieu! \n";
        XoaNL(ds_nl, nl);
        break;
    }

}

// Ham get-set: 
void NguyenLieuTrongKho::settenNL(string x) {
    tenNL = x;
}
string NguyenLieuTrongKho::gettenNL() {
    return tenNL;
}
void NguyenLieuTrongKho::setmaNL(string x) {
    maNL = x;
}
string NguyenLieuTrongKho::getmaNL() {
    return maNL;
}
void NguyenLieuTrongKho::setslNhap(int x) {
    slNhap = x;
}
int NguyenLieuTrongKho::getslNhap() {
    return slNhap;
}
void NguyenLieuTrongKho::setslXuat(int x) {
    slXuat = x;
}
int NguyenLieuTrongKho::getslxuat() {
    return slXuat;
}
void NguyenLieuTrongKho::setslTon(int x) {
    slTon = x;
}
int NguyenLieuTrongKho::getslTon() {
    return slNhap - slXuat;
}
void NguyenLieuTrongKho::setdvTinh(string x) {
    dvTinh = x;
}
string NguyenLieuTrongKho::getdvTinh() {
    return dvTinh;
}

// Ham khoi tao - huy 
NguyenLieuTrongKho::NguyenLieuTrongKho(string _tenNL, string _maNL, int _slNhap, int _slXuat, int _slTon, string _dvTinh) {
    tenNL = _tenNL;
    maNL = _maNL;
    slNhap = _slNhap;
    slXuat = _slXuat;
    slTon = _slTon;
    dvTinh = _dvTinh; 
}
NguyenLieuTrongKho::NguyenLieuTrongKho(const NguyenLieuTrongKho& nl) {
    tenNL = nl.tenNL;
    maNL = nl.maNL;
    slNhap = nl.slNhap;
    slXuat = nl.slXuat;
    slTon = nl.slTon;
    dvTinh = nl.dvTinh; 
}
NguyenLieuTrongKho::~NguyenLieuTrongKho() {}

