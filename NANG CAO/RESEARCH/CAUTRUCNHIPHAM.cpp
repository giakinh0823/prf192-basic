#include <stdio.h>

struct SanPham {
	int ma;
	char ten[150];
	double gia;
} a[100];

void nhapMang(SanPham a[],int n);
void xuatMang(SanPham a[],int n);

void nhapMang(SanPham a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("San pham: %d\n",i+1);
		printf("Ma: ");
		scanf("%d",&a[i].ma);
		printf("Ten sp: ");
		scanf("%s",&a[i].ten);
		printf("Gia sp: ");
		scanf("%lf", &a[i].gia);
	}
}

void xuatMang(SanPham a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("San pham: %d\n",i+1);
		printf("Ma: ",&a[i].ma);
		printf("Ten sp: ",&a[i].ten);
		printf("Gia sp: ", &a[i].gia);
	}
	printf("\n");
}



void qickSort(int c, int d){
	int i=c,j=d-1, x=a[(c+d-1)/2].gia;
	do{
		while(a[i].gia<x) i++;
		while (a[j].gia>x) j--;
		if(i<j){
			int temp=a[i].gia;
			a[i].gia=a[j].gia;
			a[j].gia=a[i].gia;
		}
	}while(i<j);
	if(i<d-1) qickSort(i,d-1);
	if(j>c) qickSort(c,j);
}

int main(){
	int n;
	printf("Nhap n: "); scanf("%d",n);
	printf("%d",n);
	nhapMang(a,n);
	xuatMang(a,n);
	return 0;
}
