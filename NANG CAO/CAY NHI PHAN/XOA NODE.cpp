#include <stdio.h>
#include <stdio.h>

struct node{
	int data;
	struct node *pLeft;
	struct node *pRight;
};

typedef struct node NODE;
typedef NODE* TREE;

void KhoiTao(TREE &t){
	t=NULL;
}

void AddNode(TREE &t,int x){
	if(t==NULL){
		NODE *p=new NODE;
		p->data=x;
		p->pLeft=NULL;
		p->pRight=NULL;
		t=p;
	}else{
		if(x<t->data){
			AddNode(t->pLeft,x);
		}else if(x>t->data){
			AddNode(t->pRight,x);
		}
	}
}

void TimNodeThayThe(TREE &X, TREE &Y){ //NODE *Y=T->pRight
	//duyet sang ben trai nhat cua cay con phai
	if(Y->pLeft !=NULL){
		TimNodeThayThe(X,Y->pLeft);
	}else{
		X->data=Y->data; //cap nhat data cua node can xoa
		X=Y; 
		Y=Y->pRight;
	}
}

void XoaNode(TREE &t, int data){
	if(t==NULL){
		printf("TREE nullnullnull");
	}else{
		if(data<t->data){
			XoaNode(t->pLeft,data);
		}else if(data>t->data){
			XoaNode(t->pRight,data);
		}else{
			NODE *X=t;
			if(t->pLeft==NULL){
				t=t->pRight;
			}else if(t->pRight==NULL){
				t=t->pLeft;
			}else{ //xoa node co 2 con
				NODE *Y = t->pRight;
				TimNodeThayThe(X,Y);
			}
			delete X;
		}
	}
}

//xuat cay

void output(TREE t){
	if(t!=NULL){
		printf("%d ",t->data);
		output(t->pLeft);
		output(t->pRight);
	}
}

void Menu(TREE &t){
	while(true){
		printf("\n-------------------Menu-----------------\n");
		printf("1.Nhap du lieu\n");
		printf("2.Xuat du lieu\n");
		printf("3.Xoa Node bat ki\n");
		printf("0.Exit\n");
		printf("-------------------end------------------\n");
		int luachon;
		printf("Nhap lua chon cua ban: ");scanf("%d",&luachon);
		if(luachon<0 || luachon>3){
			printf("Xin vui long nhap lai");
		}else if(luachon==1){
			int x;
			printf("Nhap x: "); scanf("%d",&x);
			AddNode(t,x);
		}else if(luachon==2){
			output(t);
		}else if(luachon==3){
			int x;
			printf("Nhap node can xoa: "); scanf("%d",&x);
			XoaNode(t,x);
		}else{
			break;
		}
	}
}
int main(){
	TREE t;
	KhoiTao(t);
	Menu(t);
	return 0;
}

