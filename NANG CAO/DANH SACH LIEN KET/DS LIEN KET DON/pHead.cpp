#include <stdio.h>


/*------------Khai bao danh sach lien ket don-----------*/
//Khai bao mot Node

struct node{
	int data;//du lieu trong 1 Node
	struct node *pNext; //con tro dung de lien ket giua cac Node voi nhau
};

typedef struct node NODE; //thay the TEN (struct node) thanh NODE cho de nhin va de viet

//Khai bao cau truc danh sach lien ket don

struct list{
	NODE *pHead;//node quan ly dau danh sach
	NODE *pTail;//node quan ly cuoi danh sach
};

typedef struct list LIST; //thay the TEN (struct list) thanh LIST cho de nhin va de viet

 
 /*---------KHOI TAO DANH SACH LIEN KET DON--------------*/
 
 void KhoiTao(LIST &l){ //khi khoi tao ra list co dau & de luu su khoi tao
 	//cho 2 node tro den NULL - vi danh sach lien ket don chua co phan tu
 	l.pHead = NULL;
 	l.pTail = NULL;
 }
 //ham khoi tao 1 cai node
 
 NODE *khoitaoNODE(int x){
 	NODE *p= new NODE; //cap phat vung nho cho NODE p;
 	if(p==NULL){ //khi bo nho ram het thi khong co bo nho de cap phat
		printf("Khong du bo nho de cap phat"); 
		return NULL;
	}
 	p->data=x; //truyen gia tri x cho data
 	p->pNext=NULL; //dau tien khai bao node thi node do chua co lien ket den node nao het=>con tro cua no se tro den NULL
 	return p; //tra ve NODE p vua khoi tao
 }
 
 //ham them node vao dau danh sach lien ket
 
 void themvaodau(LIST &l, NODE *p){
 	if(l.pHead == NULL){ //neu danh sach rong
	 	l.pHead=l.pTail=p; //node dau cung chinh la node cuoi cung chung la p
	}else{ //khi danh sach co 1 node roi
		p->pNext=l.pHead; //cho con tro can them tro den node dau - pHead
		l.pHead=p; //cap nhat lai pHead = p
	}
 }
 
 //ham them node vao cuoi danh sach lien ket
 
 void themvaocuoi(LIST &l, NODE *p){
 	if(l.pHead==NULL){
		l.pHead=l.pTail=p; 
	}else{
		l.pTail->pNext=p; //cho con tro cua pTail lien ket voi node P;
		l.pTail=p; //cap nhat p la node cuoi la node pTail
	}
 }
 
 //ham xuat lien ket don
 
 void XuatDanhSach(LIST l){
 	//for(i=0;i<n;i++){}
 	for(NODE *k=l.pHead;k!=NULL; k=k->pNext){
	 	printf("%d ",k->data);
	}
 }

int main(){
	LIST l;
	KhoiTao(l); //khoi tao danh sach lien ket don;
	int n,i;
	printf("Nhap so luong node can them: "); scanf("%d",&n);
	for(i=0;i<n;i++){
		int x;
		printf("a[%d]=",i+1);
		scanf("%d",&x);
		NODE *p= khoitaoNODE(x); //khoi tao node so nguyen
		themvaodau(l,p); //them node p vao dau danh sach lien ket don
	}
	XuatDanhSach(l);
	return 0;
}
