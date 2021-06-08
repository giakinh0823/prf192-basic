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
		}else if(x>=t->data){
			AddNode(t->pRight,x);
		}
	}
}

//tim kiem node

NODE *TimKiem(TREE &t,int x){
	if(t==NULL){
		return NULL;
	}else{
		if(x<t->data){
			TimKiem(t->pLeft,x);
		}else if(x>t->data){
			TimKiem(t->pRight,x);
		}else{
			return t;
		}
	}
}

//node co 2 con

void Node2Con(TREE &t){
	if(t!=NULL){
		if(t->pLeft!=NULL && t->pRight!=NULL){
			printf("%d ",t->data);
		}
		Node2Con(t->pLeft);
		Node2Con(t->pRight);
	}
}

//node co 1 con

void Node1Con(TREE &t){
	if(t!=NULL){
		if((t->pLeft==NULL && t->pRight!=NULL) || (t->pLeft!=NULL && t->pRight==NULL)){
			printf("%d ",t->data);
		}
		Node1Con(t->pLeft);
		Node1Con(t->pRight);
	}
}

//node co 0 con

void Node0Con(TREE &t){
	if(t!=NULL){
		if(t->pLeft==NULL && t->pRight==NULL){
			printf("%d ",t->data);
		}
		Node0Con(t->pLeft);
		Node0Con(t->pRight);
	}
}

//tim max cach 1
int max=-32000;

void Max(TREE &t){
	if(t==NULL){
		return;
	}else{
		if(max<t->data){
			max=t->data;
		}
		Max(t->pLeft);
		Max(t->pRight);
	}
}

//tim max cach 2 tong quat

int TimMax(TREE &t){
	//neu node ko ton tai nhanh trai va nhanh phan
	if(t->pLeft==NULL && t->pRight==NULL){
		return t->data;
	}
	int max=t->data;		
	if(t->pLeft!=NULL){ //neu canh ton tai nhanh trai
		int left=TimMax(t->pLeft);//left la bien se giu gia tri cua cai node ngoai cung nhat ben trai cua node cha
		if(max<left){
			max=left;
		}
	}
	if(t->pRight!=NULL){
		int right=TimMax(t->pRight);
		if(max<right){
			max=right;
		}
	}
	return max;
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
		printf("3.Tiem Kiem Phan Trong Cay\n");
		printf("4.Xuat Node co 2 con\n");
		printf("5.Xuat Node co 1 con\n");
		printf("6.Xuat node khong co con nao\n");
		printf("7.Xuat Max\n");
		printf("8.Xuat Max cach 2\n");
		printf("0.Exit\n");
		printf("-------------------end------------------\n");
		int luachon;
		printf("Nhap lua chon cua ban: ");scanf("%d",&luachon);
		if(luachon<0 || luachon>8){
			printf("Xin vui long nhap lai");
		}else if(luachon==1){
			int x;
			printf("Nhap x: "); scanf("%d",&x);
			AddNode(t,x);
		}else if(luachon==2){
			output(t);
		}else if(luachon==3){
			int x;
			printf("Nhap phan tu can tim kiem: "); scanf("%d",&x);
			NODE *p=NULL;
			p=TimKiem(t,x);
			if(p==NULL){
				printf("nullnullnullnull!!!!!!!!!");
			}else{
				printf("Phan tu co ton tai");
			}
		}else if(luachon==4){
			Node2Con(t);
		}else if(luachon==5){
			Node1Con(t);
		}else if(luachon==6){
			Node0Con(t);
		}else if(luachon==7){
			Max(t);
			printf("%d",max);
		}else if(luachon==8){
			int max=TimMax(t);
			printf("%d",max);
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
