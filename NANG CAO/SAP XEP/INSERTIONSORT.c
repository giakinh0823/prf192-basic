#include <stdio.h>

void nhapMang(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\n");
}

void xuatMang(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}


void insertionSort(int a[], int n){
	int pos=0;//luu vi tri can chen
	int x;//lua gia tri a[i] tranh bi ghi de
	int i;
	for(i=0;i<n;i++){
		x=a[i];
		for(pos=i; (pos>0) && (a[pos-1]>x); pos--){
			a[pos]=a[pos-1];
		}
		a[pos]=x;
	}
}

int main(){
	int n;
	int a[100];
	printf("Nhap n: "); scanf("%d",&n);
	nhapMang(a,n);
	insertionSort(a,n);
	xuatMang(a,n);
	return 0;
}
