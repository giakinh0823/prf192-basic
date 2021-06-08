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

void bubbleSort(int a[], int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[j]<a[j-1]){
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
}

int main(){
	int n;
	int a[100];
	printf("Nhap n: "); scanf("%d",&n);
	nhapMang(a,n);
	bubbleSort(a,n);
	xuatMang(a,n);
	return 0;
}
