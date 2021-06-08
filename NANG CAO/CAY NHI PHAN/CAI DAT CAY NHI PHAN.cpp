#include <stdio.h>

struct node{
	int data;
	struct node *pLeft; //node lien ket ben trai
	struct node *pRight; //node lien ket ben phai
};

typedef struct node NODE;
typedef NODE* TREE; //TREE cung la con tro

//khoi tao cay

void KhoiTaoCay(TREE &t){
	t=NULL;
}

//ham them phan tu x vao cay nhi phan

void ThemNodeVaoCay(TREE &t, int x){
	if(t==NULL){ //cay khong ton tai phan tu
		NODE *p= new NODE;
		p->data=x; 
		p->pLeft=NULL;
		p->pRight=NULL;
		t=p; //node p chinh la node goc
	}else{
		if(x<t->data){
			ThemNodeVaoCay(t->pLeft,x);//duyet qua trai de them phan tu x
		}else if(x>t->data){ 
			ThemNodeVaoCay(t->pRight,x);//duyet qua phai de them phan tu x;
		}
	}
}
//xuat du lieu NLR

void Duyet_NLR(TREE t){
	//neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL){
		printf("%d ",t->data);//xuat du lieu trong node
		Duyet_NLR(t->pLeft);//duyet qua trai
		Duyet_NLR(t->pRight);//duyet qua phai
	}
}

//ham nhap menu

void Menu(TREE &t){
	while(true){
		printf("\n-------------------Menu-----------------\n");
		printf("1.Nhap du lieu\n");
		printf("2.Xuat du lieu NLR\n");
		printf("0.Exit\n");
		printf("-------------------end------------------\n");
		int luachon;
		printf("Nhap lua chon cua ban: ");scanf("%d",&luachon);
		if(luachon<0 || luachon>2){
			printf("Xin vui long nhap lai");
		}else if(luachon==1){
			int x;
			printf("Nhap x: "); scanf("%d",&x);
			ThemNodeVaoCay(t,x);
		}else if(luachon==2){
			Duyet_NLR(t);
		}else{
			break;
		}
	}
}

int main(){
	TREE t;
	KhoiTaoCay(t);
	Menu(t);
	return 0;
}
