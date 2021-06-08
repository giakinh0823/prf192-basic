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


void interChangeSort(int a[], int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int main(){
	int n;
	int a[100];
	printf("Nhap n: "); scanf("%d",&n);
	nhapMang(a,n);
	interChangeSort(a,n);
	xuatMang(a,n);
	return 0;
}
