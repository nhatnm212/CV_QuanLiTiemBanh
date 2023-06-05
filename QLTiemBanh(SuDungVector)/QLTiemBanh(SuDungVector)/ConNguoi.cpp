#include "ConNguoi.h" 

// Ham get-set: 
string ConNguoi::getmaSo() { return maSo; }
string ConNguoi::gethoTen() { return hoTen; }
string ConNguoi::getngaySinh() { return ngaySinh; }
string ConNguoi::getsoDT() { return soDT; }
void ConNguoi::setmaSo(string _maSo) { maSo = _maSo; }
void ConNguoi::sethoTen(string _hoTen) { hoTen = _hoTen; }
void ConNguoi::setngaySinh(string _ngaySinh) { ngaySinh = _ngaySinh; }
void ConNguoi::setsoDT(string _soDT) { soDT = _soDT; }

// Ham khoi tao - Huy: 
ConNguoi::ConNguoi(string _maSo, string _hoTen, string _ngaySinh, string _soDT) {
	maSo = _maSo;		 hoTen = _hoTen;		ngaySinh = _ngaySinh;		soDT = _soDT;		
}
ConNguoi::ConNguoi(const ConNguoi& n) {
	maSo = n.maSo;		hoTen = n.hoTen;		ngaySinh = n.ngaySinh;		soDT = n.soDT;		
}
ConNguoi::~ConNguoi() {}

// Nhap - Xuat: 
istream& operator >> (istream& in, ConNguoi& n) {
	cout << " Ma so: ";				getline(in, n.maSo);
	cout << " Ho va ten: ";			getline(in, n.hoTen);
	cout << " Ngay sinh: ";			getline(in, n.ngaySinh);
	cout << " So dien thoai: ";		getline(in, n.soDT);
	return in;
}
ostream& operator << (ostream& out, ConNguoi n) {
	out << n.maSo << "_";
	out << n.hoTen << "_";
	out << n.ngaySinh << "_";
	out << n.soDT << "_" << endl; 
	return out;
}

//// Ham bo tro: 
//void ConNguoi::Doc_File_N(ifstream& file, ConNguoi& n) {
//	getline(file, n.maSo, '_');
//	getline(file, n.hoTen, '_');
//	getline(file, n.ngaySinh, '_');
//	getline(file, n.soDT, '_');
//	string temp;
//	getline(file, temp);  // khắc phục lỗi xuống dòng sau khi đọc xong 1 dòng dữ liệu
//}
//void ConNguoi::Doc_File_DSN(ifstream& file, vector<ConNguoi>& ds_n) {
//	ConNguoi ng; 
//	while (file.eof() == false)   // doc file cho den khi ket thuc  
//	{
//		Doc_File_N(file, ng);
//		ds_n.push_back(ng);
//	}
//}
//void ConNguoi::Xuat_File_Thong_Tin_DSN(ConNguoi n) {
//	cout << setw(10) << left << n.maSo;
//	cout << setw(25) << left << n.hoTen;
//	cout << setw(15) << left << n.ngaySinh;
//	cout << setw(15) << left << n.soDT;
//	cout << endl;
//}
//void ConNguoi::inDSN(vector<ConNguoi>ds_n) {
//	cout << "_______________________________________________________________________________________ " << endl << endl;
//	cout << "                                      DANH SACH CON NGUOI                               " << endl;
//	cout << endl;
//	cout << setw(5) << left << "STT";
//	cout << setw(10) << left << "Ma so";
//	cout << setw(25) << left << "HO VA TEN";
//	cout << setw(15) << left << "NGAY SINH";
//	cout << setw(15) << left << "SDT";
//	cout << endl;
//	cout << "________________________________________________________________________________________ " << endl << endl;
//	for (int i = 0; i < ds_n.size() - 1; i++)
//	{
//		cout << setw(5) << left << i + 1;
//		Xuat_File_Thong_Tin_DSN(ds_n[i]);
//	}
//	cout << "_________________________________________________________________________________________ " << endl;
//
//}
//void operator + (vector<ConNguoi>ds_n) {
//	ConNguoi nt[100];
//	int n;
//	cout << "\n Nhap SL con nguoi can them: "; cin >> n;
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		cin.ignore();
//		cin >> nt[i];
//		ds_n.push_back(nt[i]);
//	}
//	ofstream ofile;
//	ofile.open("DSConNguoi.txt", ios::app);
//	for (int i = 0; i < n; i++)
//		ofile << ds_n[i];
//	ofile.close();
//}
//void ConNguoi::timKiemN(vector<ConNguoi>ds_n, ConNguoi n) {
//	ifstream file;
//	file.open("DSConNguoi.txt", ios_base::in);  // mở file ra đọc
//	Doc_File_DSN(file, ds_n);
//	string maTimKiem;
//	cout << "\n Nhap ma so can tim: ";
//	cin >> maTimKiem;
//	int found = 0;
//	for (int i = 0; i < ds_n.size(); i++) {
//		if (stricmp(ds_n[i].maSo.c_str(), maTimKiem.c_str()) == 0) {
//			cout << " --------------------------------------------------- " << endl;
//			cout << "                   THE DINH DANH                     " << endl << endl;
//			cout << "  Ho va ten: " << ds_n[i].hoTen << endl;
//			cout << "  Ma so: " << ds_n[i].maSo << endl;
//			cout << "  Ngay sinh: " << ds_n[i].ngaySinh << endl; 
//			cout << "  So dien thoai: " << ds_n[i].soDT << endl;
//			cout << " --------------------------------------------------- " << endl;
//			found = 1;
//		}
//	}
//	if (found == 0) {
//		cout << "\n Nguoi nay khong ton tai trong he thong!" << endl;
//	}
//	file.close();
//}
//void ConNguoi::xoa1N(vector<ConNguoi> ds_n, ConNguoi n) {
//	ifstream file;
//	file.open("DSConNguoi.txt", ios_base::in);  // mở file ra đọc
//	Doc_File_DSN(file, ds_n);
//	string ma;
//	cout << "\n Nhap ma so: ";
//	cin >> ma;
//	int found = 0;
//	for (int i = 0; i < ds_n.size(); i++) {
//		if (stricmp(ds_n[i].maSo.c_str(), ma.c_str()) == 0) {
//			cout << "\n Xoa thong tin nguoi co ma " << ds_n[i].maSo << " thanh cong! " << endl;
//			ds_n.erase(ds_n.begin() + i);
//			found = 1;
//			cout << endl;
//			ofstream ofile;
//			ofile.open("DSConNguoi.txt", ios::trunc);
//			for (int i = 0; i < ds_n.size() - 1; i++)
//				ofile << ds_n[i];
//			ofile.close();
//		}
//	}
//	if (found == 0) {
//		cout << "\n Nguoi nay khong ton tai trong he thong!!" << endl;
//	}
//	file.close();
//}
//void ConNguoi::CapnhatthongtinN(vector < ConNguoi> ds_n, ConNguoi n) {
//	ifstream file;
//	file.open("DSConNguoi.txt", ios_base::in);  // mở file ra đọc
//	Doc_File_DSN(file, ds_n);
//	string ma;
//	cout << "\n Nhap ma so can cap nhat: ";
//	cin >> ma;
//	int capnhat = 0;
//	cout << endl;
//	for (int i = 0; i < ds_n.size(); i++) {
//		if (stricmp(ds_n[i].maSo.c_str(), ma.c_str()) == 0) {
//
//			cout << "\n Ho va ten hien tai la: " << ds_n[i].hoTen << endl;
//			cout << " Ban muon cap nhap lai Ho va ten moi la: ";
//			cin.ignore();
//			getline(cin, n.hoTen);
//			ds_n[i].hoTen = n.hoTen;
//
//			cout << "\n Ma so hien tai la: " << ds_n[i].maSo << endl;
//			cout << " Ban muon cap nhap lai Ma so moi la: ";
//			getline(cin, n.maSo);
//			ds_n[i].maSo = n.maSo;
//
//			cout << "\n Ngay sinh hien tai la: " << ds_n[i].ngaySinh << endl;;
//			cout << " Ban muon cap nhap lai Ngay sinh moi la: ";
//			getline(cin, n.ngaySinh);
//			ds_n[i].ngaySinh = n.ngaySinh;
//
//			cout << "\n So dien thoai hien tai la: " << ds_n[i].soDT << endl;;
//			cout << " Ban muon cap nhap lai So dien thoai moi la: ";
//			getline(cin, n.soDT);
//			ds_n[i].soDT = n.soDT;
//
//			capnhat = 1;
//			ofstream ofile;
//			ofile.open("DSConNguoi.txt", ios::trunc);
//			for (int i = 0; i < ds_n.size() - 1; i++)
//				ofile << ds_n[i];
//			ofile.close();
//		}
//	}
//	if (capnhat == 0) {
//		cout << "\n Nguoi nay khong ton tai trong he thong!" << endl;
//	}
//	file.close();
//}
void ConNguoi::MENU() {

	cout << "\n -------------------------------------------------------- " << endl;
	cout << " |                                                      | " << endl;
	cout << " |                   DANH MUC CON NGUOI                 | " << endl;
	cout << " |                                                      | " << endl;
	cout << " |  1. Them 1 nguoi vao danh sach.                      | " << endl;
	cout << " |  2. In danh sach con nguoi.                          | " << endl;
	cout << " |  3. Cap nhat thong tin.                              | " << endl;
	cout << " |  4. Tim kiem thong tin.                              | " << endl;
	cout << " |  5. Xoa 1 nguoi trong danh sach.                     | " << endl;
	cout << " |                                                      | " << endl;
	cout << " -------------------------------------------------------- " << endl;

}
int ConNguoi::ChonMenu() {
	int n;
	cout << "\n Nhap lua chon: ";
	cin >> n;
	if (n > 0 || n < 6) {
		return n;
	}
	else {
		return ChonMenu();
	}
}
void ConNguoi::XuLyMenu(ifstream& file, vector<ConNguoi> ds_n, ConNguoi& n) {
	int chon = ChonMenu();
	switch (chon)
	{
	case 1:
		system("cls");
		cout << "\n Ban da chon chuc nang Them 1 nguoi vao danh sach! \n";
		//+ds_n;
		break;
	case 2:
		system("cls");
		cout << "\n Ban da chon chuc nang In danh sach con nguoi! \n";
		file.open("DSConNguoi.txt", ios_base::in);  // mở file ra đọc
		//Doc_File_DSN(file, ds_n);
		//inDSN(ds_n);
		file.close();
		break;
	case 3:
		system("cls");
		cout << "\n Ban da chon chuc nang Cap nhat thong tin! \n";
		//CapnhatthongtinN(ds_n, n);
		break;
	case 4:
		system("cls");
		cout << "\n Ban da chon chuc nang Tim kiem thong tin! \n";
		//timKiemN(ds_n, n);
		break;
	case 5:
		system("cls");
		cout << "\n Ban da chon chuc nang Xoa 1 nguoi trong danh sach! \n";
		//xoa1N(ds_n, n);
		break;
	}
}

