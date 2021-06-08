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

//xuat du lieu NRL

void Duyet_NRL(TREE t){
	//neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL){
		printf("%d ",t->data);//xuat du lieu trong node
		Duyet_NRL(t->pRight);//duyet qua phai
		Duyet_NRL(t->pLeft);//duyet qua trai
	}
}

//xuat du lieu LNR

void Duyet_LNR(TREE t){
	//neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL){
		Duyet_LNR(t->pLeft);//duyet qua trai
		printf("%d ",t->data);//xuat du lieu trong node 
		Duyet_LNR(t->pRight);//duyet qua phai	
	}
}

//xuat du lieu RNL

void Duyet_RNL(TREE t){
	//neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL){
		Duyet_RNL(t->pRight);//duyet qua phai
		printf("%d ",t->data);//xuat du lieu trong node
		Duyet_RNL(t->pLeft);//duyet qua trai
	}
}

//xuat du lieu LRN

void Duyet_LRN(TREE t){
	//neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL){
		Duyet_LRN(t->pLeft);//duyet qua trai
		Duyet_LRN(t->pRight);//duyet qua phai
		printf("%d ",t->data);//xuat du lieu trong node
	
	}
}

//xuat du lieu RLN

void Duyet_RLN(TREE t){
	//neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL){
		Duyet_RLN(t->pRight);//duyet qua phai
		Duyet_RLN(t->pLeft);//duyet qua trai
		printf("%d ",t->data);//xuat du lieu trong node
	}
}

//ham nhap menu

void Menu(TREE &t){
	while(true){
		printf("\n-------------------Menu-----------------\n");
		printf("1.Nhap du lieu\n");
		printf("2.Xuat du lieu NLR\n");
		printf("3.Xuat du lieu NRL\n");
		printf("4.Xuat du lieu LNR\n");
		printf("5.Xuat du lieu RNL\n");
		printf("6.Xuat du lieu LRN\n");
		printf("7.Xuat du lieu NRL\n");
		printf("0.Exit\n");
		printf("-------------------end------------------\n");
		int luachon;
		printf("Nhap lua chon cua ban: ");scanf("%d",&luachon);
		if(luachon<0 || luachon>5){
			printf("Xin vui long nhap lai");
		}else if(luachon==1){
			int x;
			printf("Nhap x: "); scanf("%d",&x);
			AddNode(t,x);
		}else if(luachon==2){
			
		}else if(luachon==3){
		
		}else if(luachon==4){
			
		}else if(luachon==5){
			
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
