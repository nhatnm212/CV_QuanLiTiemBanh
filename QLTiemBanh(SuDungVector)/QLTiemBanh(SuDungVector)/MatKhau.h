#ifndef MatKhau_H
#define MatKhau_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector> 
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

void Menu() {
    system("cls"); 
    cout << "\n -------------------------------------------------------- " << endl;
    cout << " |  Gia dinh 1                                          | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |                PHAN MEM QUAN LY TIEM BANH            | " << endl;
    cout << " |                                                      | " << endl;
    cout << " |  1. Danh muc Nhan vien.                              | " << endl;
    cout << " |  2. Danh muc Khach hang.                             | " << endl;
    cout << " |  3. Danh muc Hoa don.                                | " << endl;
    cout << " |  4. Danh muc San pham.                               | " << endl;
    cout << " |  5. Danh muc Chuong trinh khuyen mai.                | " << endl;
    cout << " |  6. Danh muc Nguyen lieu.                            | " << endl;
    cout << " |  7. Dang ky tai khoan moi (*).                       | " << endl;
    cout << " |  0. Dang xuat.                                       | " << endl;
    cout << " |                                                      | " << endl;
    cout << " -------------------------------------------------------- " << endl;
}

void XuliNL() {
    NguyenLieuTrongKho ql, nl;
    vector<NguyenLieuTrongKho> ds_nl;
    ifstream file;
    while (true)
    {
        cout << endl;
        cout << " ********************************** " << endl;
        cout << " *                                * " << endl;
        cout << " * Bam ENTER de tiep tuc.         * " << endl;
        cout << " * Bam ESC de thoat ve trang chu. * " << endl;
        cout << " *                                * " << endl;
        cout << " ********************************** " << endl;
        char a;
        a = getch(); // ham getch chi nhan mot va chi mot ki tu tu keyboard
        system("cls");
        if (a == 13) {
            ql.MENU();
            ql.XuLyMenu(file, ds_nl, nl);
        }
        if (a == 27) break;
    }
}

void XuLiN()
{
    ConNguoi* p; 
    ConNguoi ng; 
    ConNguoi cn; 
    vector<ConNguoi> ds_n; 
    ifstream file;
    while (true)
    {
        cout << endl;
        cout << " ********************************** " << endl;
        cout << " *                                * " << endl;
        cout << " * Bam ENTER de tiep tuc.         * " << endl;
        cout << " * Bam ESC de thoat ve trang chu. * " << endl;
        cout << " *                                * " << endl;
        cout << " ********************************** " << endl;
        char a;
        a = getch(); // ham getch chi nhan mot va chi mot ki tu tu keyboard
        system("cls");
        if (a == 13) {
            p = &cn; 
            p->MENU(); 
            p->XuLyMenu(file, ds_n, ng); 
        }
        if (a == 27) break;
    }
}

void XuLiNV()
{
    ConNguoi* p; 
    NhanVien nv, n1;
    vector<NhanVien> ds_nv;
    ifstream file;
    while (true)
    {
        cout << endl;
        cout << " ********************************** " << endl;
        cout << " *                                * " << endl;
        cout << " * Bam ENTER de tiep tuc.         * " << endl;
        cout << " * Bam ESC de thoat ve trang chu. * " << endl;
        cout << " *                                * " << endl;
        cout << " ********************************** " << endl;
        char a;
        a = getch(); // ham getch chi nhan mot va chi mot ki tu tu keyboard
        system("cls");
        if (a == 13) {
            p = &n1; 
            p->MENU();
            n1.XuLyMenu(file, ds_nv, nv);
        }
        if (a == 27) break;
    }
}

void XuliKH() {
    ConNguoi* p; 
    KhachHang kh, kh1;
    vector<KhachHang> ds_kh;
    ifstream file;
    while (true)
    {
        cout << endl;
        cout << " ********************************** " << endl;
        cout << " *                                * " << endl;
        cout << " * Bam ENTER de tiep tuc.         * " << endl;
        cout << " * Bam ESC de thoat ve trang chu. * " << endl;
        cout << " *                                * " << endl;
        cout << " ********************************** " << endl;
        char a;
        a = getch(); // ham getch chi nhan mot va chi mot ki tu tu keyboard
        system("cls");
        if (a == 13) {
            p = &kh1; 
            p->MENU();
            kh1.XuLyMenu(file, ds_kh, kh);
        }
        if (a == 27) break;
    }
}

void XuliSP()
{
    SanPham* p; 
    ifstream file;
    Food spf, f;
    vector<Food> ds_spf;
    SanPham spd, d;
    vector<SanPham> ds_spd;

    while (true)
    {
        cout << endl;
        cout << " ********************************** " << endl;
        cout << " *                                * " << endl;
        cout << " * Bam ENTER de tiep tuc.         * " << endl;
        cout << " * Bam ESC de thoat ve trang chu. * " << endl;
        cout << " *                                * " << endl;
        cout << " ********************************** " << endl;
        char a;
        a = getch(); // ham getch chi nhan mot va chi mot ki tu tu keyboard
        system("cls");
        if (a == 13) {
            system("cls");
            cout << "_________________________________________________________________________________________________ " << endl << endl;
            cout << "                                          DANH SACH SAN PHAM                                      " << endl;
            cout << endl;
            cout << setw(15) << left << "MA SP";
            cout << setw(30) << left << "TEN SP";
            cout << setw(15) << left << "DON GIA";
            cout << setw(10) << left << "SL SP";
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
            system("pause"); 
        }
        if (a == 27) break;
    }
}

void XuliTA()
{
    SanPham* p; 
    ifstream file;
    Food sp, sp1;
    vector<Food> ds_sp;

    while (true)
    {
        cout << endl;
        cout << " ********************************** " << endl;
        cout << " *                                * " << endl;
        cout << " * Bam ENTER de tiep tuc.         * " << endl;
        cout << " * Bam ESC de thoat ve trang chu. * " << endl;
        cout << " *                                * " << endl;
        cout << " ********************************** " << endl;
        char a;
        a = getch(); // ham getch chi nhan mot va chi mot ki tu tu keyboard
        system("cls");
        if (a == 13) {
            p = &sp1; 
            p->MENU();
            sp1.XuLyMenu(file, ds_sp, sp);
        }
        if (a == 27) break;
    }
}

void XuliNU()
{
    SanPham* p; 
    ifstream file;
    Drink sp, sp1;
    vector<Drink> ds_sp;

    while (true)
    {
        cout << endl;
        cout << " ********************************** " << endl;
        cout << " *                                * " << endl;
        cout << " * Bam ENTER de tiep tuc.         * " << endl;
        cout << " * Bam ESC de thoat ve trang chu. * " << endl;
        cout << " *                                * " << endl;
        cout << " ********************************** " << endl;
        char a;
        a = getch(); // ham getch chi nhan mot va chi mot ki tu tu keyboard
        system("cls");
        if (a == 13) {
            p = &sp1; 
            p->MENU();
            sp1.XuLyMenu(file, ds_sp, sp);
        }
        if (a == 27) break;
    }
}

void XuliHD()
{
    ifstream file;
    HoaDon hd, hd1;
    vector<HoaDon> ds_hd;

    while (true)
    {
        cout << endl;
        cout << " ********************************** " << endl;
        cout << " *                                * " << endl;
        cout << " * Bam ENTER de tiep tuc.         * " << endl;
        cout << " * Bam ESC de thoat ve trang chu. * " << endl;
        cout << " *                                * " << endl;
        cout << " ********************************** " << endl;
        char a;
        a = getch(); // ham getch chi nhan mot va chi mot ki tu tu keyboard
        system("cls");
        if (a == 13) {
            hd1.MENU();
            hd1.XuLyMenu(file, ds_hd, hd);
        }
        if (a == 27) break;
    }
}

void XuliCTKM()
{
    ifstream file;
    ChuongTrinhKhuyenMai ct, ct1;
    vector<ChuongTrinhKhuyenMai> ds_ct;

    while (true)
    {
        cout << endl;
        cout << " ********************************** " << endl;
        cout << " *                                * " << endl;
        cout << " * Bam ENTER de tiep tuc.         * " << endl;
        cout << " * Bam ESC de thoat ve trang chu. * " << endl;
        cout << " *                                * " << endl;
        cout << " ********************************** " << endl;
        char a;
        a = getch(); // ham getch chi nhan mot va chi mot ki tu tu keyboard
        system("cls");
        if (a == 13) {
            ct1.MENU();
            ct1.XuLyMenu(file, ds_ct, ct);
        }
        if (a == 27) break;
    }
}

class MatKhau {
private:
	string username; 
	string passwork; 
public: 
    // Ham get-set, KTao-Huy: 
	string getusername() {
		return username; 
	}
	string getpasswork() {
		return passwork; 
	}
	void setusername(string username) {
		this->username = username; 
	}
	void setpasswork(string passwork) {
		this->passwork = passwork; 
	}
	MatKhau(string _username = " ", string _passwork = " ") {
		username = _username; 
		passwork = _passwork; 
	}
	MatKhau(const MatKhau& mk) {
		username = mk.username;
		passwork = mk.passwork;
	}
	~MatKhau(){}
	// Nhap-Xuat: 
    friend istream& operator >> (istream& in, MatKhau& mk) {
		cout << "\n Ten dang nhap: ";		getline(in, mk.username); 
		cout << " Mat khau: ";				getline(in, mk.passwork); 
		cout << endl;
		return in;
	}
	friend ostream& operator << (ostream& out, MatKhau mk) {
		out << mk.username << "_";
		out << mk.passwork << endl; 
		return out;
	}
    // Ham bo tro: 
    void Doc_File_MK(ifstream& file, MatKhau& mk) {
        getline(file, mk.username, '_');
        getline(file, mk.passwork);
        /*string temp;
        getline(file, temp);*/
    }
    void Doc_File_DSMK(ifstream& file, vector<MatKhau>& ds_mk) {
		while (file.eof() == false) {
            MatKhau mk; 
            Doc_File_MK(file, mk); 
			ds_mk.push_back(mk); 
		}
	}
	void DangKyTaiKhoan(vector<MatKhau> ds_mk) {
		cout << "\n ---------------------------------------------------- " << endl;
		cout << "\n   CHUONG TRINH QUAN LI TIEM BANH CUA GIA DINH 1!   ";
		cout << "\n                 DANG KY TAI KHOAN                  " << endl;
		MatKhau mkt; 
        cin >> mkt;
        ds_mk.push_back(mkt);
		ofstream ofile;
		ofile.open("DSMK.txt", ios::app);
        ofile << mkt; 
        ofile.close(); 
	}
	void soSanhMK(vector<MatKhau> ds_mk, MatKhau mk) {
		
		int lcdn;
		string _username, _password; 
		while (true) {
			system("cls");
			cout << "\n ----------------------------------------------------- ";
            cout << "\n |                                                   | "; 
			cout << "\n |  CHUONG TRINH QUAN LI TIEM BANH CUA GIA DINH 1!   | ";
			cout << "\n |                     TRANG CHU                     | ";
			cout << "\n |  1. Dang nhap.                                    | ";
            cout << "\n |  2. Thong tin tac gia.                            | "; 
            cout << "\n |  0. Thoat khoi chuong trinh.                      | "; 
            cout << "\n |                                                   | ";
            cout << "\n ----------------------------------------------------- " << endl;
			cout << "\n   >> Nhap lua chon: "; cin >> lcdn; cin.ignore();

			if (lcdn == 1) {
                system("cls"); 
				cout << "\n ---------------------------------------------------- " << endl;
				cout << "\n   CHUONG TRINH QUAN LI TIEM BANH CUA GIA DINH 1!   ";
				cout << "\n               DANG NHAP TAI KHOAN                  " << endl;
				cout << "\n   >> Ten dang nhap: ";      getline(cin, _username);
				cout << "\n   >> Mat ma: ";             getline(cin, _password);
                ifstream file;
                file.open("DSMK.txt", ios_base::in);  // mở file ra đọc
                Doc_File_DSMK(file, ds_mk);
				for (int i = 0; i < ds_mk.size(); i++) {
					if ((ds_mk[i].username.compare(_username)) == 0 &&
						(ds_mk[i].passwork.compare(_password)) == 0) {
						system("cls");
                        while (true) {
                            Menu();
                            cout << "\n Nhap lua chon: ";
                            int luachonQuanLi;
                            cin >> luachonQuanLi;
                            system("cls");
                            if (luachonQuanLi == 0) {
                                cout << "\n Ban da chon Dang xuat khoi tai khoan!" << endl;
                                cin.ignore();
                                break;
                            }
                            if (luachonQuanLi == 1) {
                                system("cls");
                                XuLiNV();
                            }
                            if (luachonQuanLi == 2) {
                                system("cls");
                                XuliKH();
                            }
                            if (luachonQuanLi == 3) {
                                system("cls");
                                XuliHD();
                            }
                            if (luachonQuanLi == 4) {
                                system("cls");
                                cout << "\n *DANH MUC SAN PHAM: ";
                                cout << "\n\n 1. Quan ly thuc an (Food). ";
                                cout << "\n 2. Quan ly nuoc uong (Drink). ";
                                cout << "\n 3. Xem menu quan. ";
                                cout << "\n\n Nhap lua chon: ";
                                int lcql4;      cin >> lcql4;   cin.ignore();
                                if (lcql4 == 1) {
                                    XuliTA();
                                }
                                else if (lcql4 == 2) {
                                    XuliNU();
                                }
                                else if (lcql4 == 3) {
                                    XuliSP();
                                }
                            }
                            if (luachonQuanLi == 5) {
                                system("cls");
                                XuliCTKM();
                            }
                            if (luachonQuanLi == 6) {
                                system("cls");
                                XuliNL();
                            }
                            if (luachonQuanLi == 7) {
                                system("cls");
                                cin.ignore();
                                DangKyTaiKhoan(ds_mk);
                                cout << "\n Dang ky tai khoan thanh cong! " << endl;
                                system("pause");
                            }
                            /*if (luachonQuanLi == 8) {
                                system("cls");
                                XuLiN();
                            }*/
                        }
                    }
				}
                file.close(); 
			}
            else if (lcdn == 2) {
                system("cls");
                cout << "\n ----------------------------------------------------- ";
                cout << "\n |  Truong DH Su pham TPHCM                          | ";
                cout << "\n |                                                   | "; 
			    cout << "\n |  CHUONG TRINH QUAN LI TIEM BANH CUA GIA DINH 1!   | ";
			    cout << "\n |                GIOI THIEU TAC GIA                 | ";
                cout << "\n |                                                   | ";
			    cout << "\n |  1. Nguyen Le Kim Khanh        46.01.104.081      | ";
                cout << "\n |  2. Nguyen Minh Nhat           47.01.103.073      | ";
                cout << "\n |  3. Du Thi Nhu Quynh           46.01.104.151      | ";
                cout << "\n |  4. Le Thanh Ty                47.01.103.106      | ";
                cout << "\n |  5. Tran Xuan Vu               47.01.103.109      | ";
                cout << "\n |                                                   | ";
                cout << "\n ----------------------------------------------------- " << endl;
                system("pause"); 
            }
            else if (lcdn == 0) {
                cout << "\n Dang thoat khoi chuong trinh, cam on ban da su dung! " << endl; 
                break; 
            }
		}
	}
}; 

#endif; 
