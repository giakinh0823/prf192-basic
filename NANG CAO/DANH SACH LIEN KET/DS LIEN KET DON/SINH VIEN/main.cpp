#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Khai bao cau truc NODE sinh vien ngay thang nam sinh

struct date{
	int ngay;
	int thang;
	int nam;
};

typedef struct date DATE;

//doc ngay thang nam

void DocNgaySinh(ifstream &filein , DATE &date){
	filein >> date.ngay;
	filein.seekg(1,ios::beg); //dich sang phai 1 byte de bo ky tu '/'
	filein >> date.thang;
	filein.seekg(1,ios::beg);
	filein >> date.nam;
}

//Khai bao cau truc sinh vien 
struct sinhvien{
	string name; 
	string masv;
	DATE ngaysinh;
	float diem;
};

typedef struct sinhvien SINHVIEN;

//Khai bao node sinh vien

struct node {
	SINHVIEN data; 
	struct node *pNext;
};

typedef struct node NODE;

//Khai bao cau truc lien ket don cho sinh vien

struct list{
	NODE *pHead;
	NODE *Ptail;
};

typedef struct list LIST;

//khoi tao node cho sinh vien

NODE *KhoiTaoNode(SINHVIEN x){
	NODE *p=new NODE;
	if(p==NULL){
		printf("Khong du bo nho");
		return NULL;
	}
	p->data=x; //dua du lieu sinh vien x
	p->pNext=NULL; 
	return p;
}


//Khoi Tao List sinh vien

void KhoiTao(LIST &l){
	l.pHead=NULL;
	l.Ptail=NULL;	
}

void ThemVaoDauDS(LIST &l,NODE *p){
	if(l.pHead==NULL){
		l.pHead=l.Ptail=p;
	}else{
		p->pNext=l.pHead;
		l.pHead=p;
	}
}

void ThemVaoCuoiDS(LIST &l,NODE *p){
	if(l.pHead==NULL){
		l.pHead=l.Ptail=p;
	}else{
		l.Ptail->pNext=p;
		l.Ptail=p;
	}
}
//doc thong tin 1 sinh vien

void DocThongTin1SV(ifstream &filein, SINHVIEN &sv){
	//doc ten sinh vin
	getline(filein, sv.name, ',');//doc den dau , thi dung
	filein.seekg(1,ios::beg);
	//doc ma sinh vien
	getline(filein, sv.masv, ',');
	filein.seekg(1,ios::beg);	
	//doc ngay sinh
	DocNgaySinh(filein, sv.ngaysinh);
	filein.seekg(2,ios::beg);
	filein >> sv.diem;
}

//xuat sinh vien

void xuat(SINHVIEN sv){
	cout << "Ho va Ten: \n" << sv.name;
	cout << "Ma sinh vien: \n" << sv.masv;
	cout << "Ngay Sinh: \n" << sv.ngaysinh.ngay << "/" << sv.ngaysinh.thang << "/" << sv.ngaysinh.nam;
	cout << "Diem: " << sv.diem;
}

int main(int argc, char** argv){
	SINHVIEN sv;
	//mo file len
	ifstream filein;
	filein.open("sinhvien.txt", ios::in);
	DocThongTin1SV(filein, sv);
	xuat(sv);
	filein.close();
	system("pause");
	return 0;
}



