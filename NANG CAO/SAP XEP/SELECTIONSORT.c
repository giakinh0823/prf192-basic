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

void selectionSort(int a[], int n){
	int min;
	int i,j;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}	
			if(min!=i){
				int temp=a[min];
				a[min]=a[i];
				a[i]=temp;
			}
		}
	}
}

int main(){
	int n;
	int a[100];
	printf("Nhap n: "); scanf("%d",&n);
	nhapMang(a,n);
	selectionSort(a,n);
	xuatMang(a,n);
	return 0;
}
