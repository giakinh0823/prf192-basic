#include <stdio.h>

//khai bao

struct node{
	int data;
	struct node *pNext;
};

typedef struct node NODE;

struct list{
	NODE *pHead;
	NODE *pTail;
};

typedef struct list LIST;                                  
                                           
void KhoiTao(LIST &l){                       
	l.pHead=NULL;
	l.pTail=NULL;
}

NODE *KhoiTaoNode(int x){
	NODE *p = new NODE;
	if(p==NULL){
		printf("Khong du bo nho");
		return NULL;
	}
	p->data=x;
	p->pNext=NULL; 
	return p;
}
 
void ThemVaoDau(LIST &l,NODE *p){
	if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}else{
		p->pNext=l.pHead;
		l.pHead=p;
	}
}

void ThemVaoCuoi(LIST &l,NODE *p){
	if(l.pHead==NULL){
		l.pHead=l.pTail=p;
	}else{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}

void XuatNode(LIST l){
	for(NODE *k=l.pHead;k!=NULL; k=k->pNext){
	 	printf("%d ",k->data);
	}
}

void ThemNode_p_VaoSauNode_q_(LIST &l,NODE *p){
	int x;
	printf("Nhap gia tri node q: ");scanf("%d",&x);
	NODE *q= KhoiTaoNode(x);
	//neu danh sach chi co 1 phan tu va phan tu do chi co 1 node q => bai toan tro thanh them vao cuoi
	if(q->data == l.pHead->data && l.pHead->pNext==NULL){
		ThemVaoCuoi(l,p);
	}else{
		//duyet tu dau danh sach den cuoi danh sach de tim node q
		for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
			//neu node q co ton tai...
			if(q->data == k->data){
				NODE *h=KhoiTaoNode(p->data);//khoi tao node h de them vao sau node q
				NODE *temp=k->pNext; // b1: cho node g cho den nam sau node q;
				h->pNext=temp; //b2: cho con tro node p tao moi let tu node p den node g(la node nam sau node q)
				k->pNext=h; //b3: tao lien ket node q den node p
			}
		}
	}
}
void ThemNode_p_VaoTruocNode_q_(LIST &l,NODE *p){
	int x;
	printf("Nhap gia tri node q: ");scanf("%d",&x);
	NODE *q= KhoiTaoNode(x);
	if(q->data==l.pHead->data && l.pHead->pNext==NULL){
		ThemVaoDau(l,p);
	}else{
		NODE *g= new NODE;//node g de lua giu node o phia truoc node q
		for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
			if(q->data==k->data){
				NODE *h=KhoiTaoNode(p->data);
				g->pNext=h;
				h->pNext=k;
			}
			g=k;
		}
	}
}

void ThemNode_p_VaoViTriBatKi(LIST &l,NODE *p, int vt,int n){
	
	//danh sach rong
	if(l.pHead==NULL || vt==1){
		ThemVaoDau(l,p);
	}else if(vt==n+1){
		ThemVaoCuoi(l,p);
	}else{
		int d=0;
		NODE *g=new NODE;
		for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
			d++;
			if(d==vt){
				NODE *h=KhoiTaoNode(p->data);
				g->pNext=h;
				h->pNext=k;
				break;
			}
			g=k;
		}
	}
}

void XoaNodeDau(LIST &l){
	if(l.pHead==NULL){
		printf("Danh sach rong");
	}else{
		NODE *p=l.pHead; //node p la node can xoa
		l.pHead=l.pHead->pNext; //cap nhat lai l.pHead(node dau) la phan tu ke tiep
		delete p;
	}
}

void XoaNodeCuoi(LIST &l){
	if(l.pHead==NULL){
		printf("Danh sach rong");
		return;
	}
	if(l.pHead==NULL){
		printf("Danh sach rong");
	}else{
		NODE *g=new NODE;
		for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
			if(k->pNext==l.pTail){
				k->pNext=NULL; //gan phan tu n-1 = phan tu cuoi pTail
				delete l.pTail; //xoa phan tu cuoi
				l.pTail=k; //cap nhat lai pTail;
				break;
			}
		}
	}
}

//xoa mot node nam sau node q

void XoaNodeSauNode_q_(LIST &l,NODE *q){
	if(l.pHead==NULL){
		printf("Danh sach rong");
		return ;
	}
	//duyet tim node q;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(k->data==q->data && k->pNext!=NULL){
			NODE *g=k->pNext;//node g chinh la node nam sau node k => node nay la ta se xoa
			k->pNext=g->pNext;//cap nhap lien ket 
			delete g;//xoa node nam sau node q
			break;
		}else if(k->pNext==NULL){
			printf("Phia sau q khong con phan tu");
		} 
	}
}

//xoa node khoa k

void XoaNodek(LIST &l, NODE *q){
	while(l.pHead->data==q->data){
		XoaNodeDau(l);
	}
	while(l.pTail->data==q->data){
		XoaNodeCuoi(l);
	}
	NODE *g= new NODE;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
		if(k->data==q->data){
			NODE *temp=k->pNext;
			g->pNext=temp;
		}
		g=k;
	}
}

void Menu(LIST &l){
	int luachon;
	while(true){
		printf("\n---------Menu----------\n");
		printf("1. Them node vao danh sach\n");
		printf("2. Xuat danh sach\n");
		printf("3. Them node p vao sau node q\n");
		printf("4. Them node p vao truoc node q\n");
		printf("5. Them node p vao vi tri bat ki\n");
		printf("6. Xoa Node dau\n");
		printf("7. Xoa Node Cuoi\n");
		printf("8. Xoa Node sau node q\n");
		printf("9. Xoa Node co khoa k\n");
		printf("0. Thoat\n");
		printf("---------End----------\n");
		printf("Nhap lua chon: ");scanf("%d",&luachon);
		if(luachon<0 || luachon>9){
			printf("Lua chon khong hop le");
		}else if(luachon==1){
			int x; 
			printf("Nhap gia tri node moi: "); scanf("%d",&x);
			NODE *p=KhoiTaoNode(x);
			ThemVaoCuoi(l,p);
		}else if(luachon==2){
			XuatNode(l);
		}else if(luachon==3){
			int x;
			printf("Nhap gia tri node p can them vao sau: ");scanf("%d",&x);
			NODE *p=KhoiTaoNode(x);
			ThemNode_p_VaoSauNode_q_(l,p);
		}else if(luachon==4){
			int x;
			printf("Nhap gia tri node p can them vao truoc: ");scanf("%d",&x);
			NODE *p=KhoiTaoNode(x);
			ThemNode_p_VaoTruocNode_q_(l,p);
		}else if(luachon==5){
			//lay so luong node trong danh sach
			int n=0;
			for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
				n++;
			}
			int x;
			printf("Nhap gia tri node p can them: ");scanf("%d",&x);
			NODE *p=KhoiTaoNode(x);
			int vt;
			do{	
				printf("Nhap vi tri can them: "); scanf("%d",&vt);
				if(vt<1 || vt>n+1){
					printf("Ban hay nhap vi tri trong doan tu [1 -> %d]\n",n+1);
				}
			}while(vt<1 || vt>n+1);
			ThemNode_p_VaoViTriBatKi(l,p,vt,n);
		}else if(luachon==6){
			XoaNodeDau(l);
		}else if(luachon==7){
			XoaNodeCuoi(l);
		}else if(luachon==8){
			int x;
			printf("Nhap node q: ");scanf("%d",&x);
			NODE *q=KhoiTaoNode(x);
			XoaNodeSauNode_q_(l,q);
		}else if(luachon==9){
			int x;
			printf("Nhap khoa k can xoa: "); scanf("%d",&x);
			NODE *q = KhoiTaoNode(x);
			XoaNodek(l,q);
		}else{
			break;
		}
	}
}

//giai phong vung nho cho danh sach lien ket don

void GiaiPhongVungNho(LIST &l){
	//duyet tu dau danh sach den cuoi danh sach
	NODE *k=l.pHead;
	while(l.pHead!=NULL){
		k=l.pHead;
		l.pHead=l.pHead->pNext;
		delete k;
	}
	printf("Giai phong bo nho thanh cong");
}

int main(){
	LIST l;
	KhoiTao(l);
	Menu(l);
	GiaiPhongVungNho(l);
	return 0;
}
