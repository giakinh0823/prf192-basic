#include <stdio.h>

void nhapMang(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}

void xuatMang(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}


void qickSort(int a[],int c,int d){
	int i=c,j=d;
	int x=a[(c+d)/2];
	while(i<=j){
		while(a[i]<x) i++;
		while(a[j]>x) j--;
		if(i<=j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	}
	if(i<d) qickSort(a,i,d);
	if(j>c) qickSort(a,c,j);
}

int main(){
	int n;
	int a[100];
	printf("Nhap n: "); scanf("%d",&n);
	nhapMang(a,n);
	qickSort(a,0,n-1);
	xuatMang(a,n);
	return 0;
}
