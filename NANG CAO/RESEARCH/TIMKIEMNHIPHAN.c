#include <stdio.h>

int a[100];

void xuatMang(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void qickSort(int c,int d){
	int i=c,j=d-1;
	int x=a[(c+d-1)/2];
	while(i<=j){
		while(a[i]<x) i++;
		while (a[j]>x) j--;
		if(i<=j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	if(i<d-1) qickSort(i,d-1);
	if(j>c) qickSort(c,j);
}

int binarySearch(int a[], int n,int x){
	int left=0,right=n-1;
	int mid;
	do{
		mid=(left+right)/2;
		if(x==a[mid]){
			return mid; //tim thay x tai mid
		}else if(x<a[mid]){
			right=mid-1; //dich chuyen sang trai 1 don vi
		}else{
			left=mid+1; //dich chuyen sang phai 1 don vi
		}
	}while(left<=right);
	return -1;//khong tim thay se tra ve 1
}

int main(){
	int n,i;
	printf("Nhap n: "); scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	xuatMang(a,n);
	qickSort(0,n);
	xuatMang(a,n);
	int x;
	printf("Nhap x: "); scanf("%d",&x);
	int kq=binarySearch(a,n,x);
	printf("%d o vi tri %d",x,kq+1);
	return 0;
}
