#include <stdio.h>

//khai bao node

struct node{
	int data;
	struct node *pLeft;
	struct node *pRight;
};

typedef struct node NODE;
typedef NODE* TREE; //chuyen node* thanh TREE TREE=NODE*

int SNT(int n){
	if(n<2){
		return 0;
	}else{
		int i;
		for(i=2;i<n/2;i++){
			if(n%i==0){
				return 0;
			}
		}
	}
	return 1;
}

void KhoiTao(TREE &t){
	t=NULL;
}

void addNode(TREE &t, int x){
	if(t==NULL){
		NODE *p=new NODE;
		p->data=x;
		p->pLeft=NULL;
		p->pRight=NULL;
		t=p;
	}else{
		if(x<t->data){
			addNode(t->pLeft,x);
		}else if(x>=t->data){
			addNode(t->pRight,x);
		}
	}
}

void input(TREE &t,int n){
	int i;
	for(i=0;i<n;i++){
		int x;
		printf("a[%d]=",i+1);
		scanf("%d",&x);
		addNode(t,x);
	}
}

void output(TREE t){
	if(t!=NULL){
		if(SNT(t->data)==1) printf("%d ",t->data);
		output(t->pLeft);
		output(t->pRight);
	}
}

int main(){
	TREE t;
	KhoiTao(t);
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	input(t,n);
	output(t);
	return 0;
}
