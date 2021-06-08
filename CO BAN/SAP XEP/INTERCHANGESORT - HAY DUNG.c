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
	nhapMang(a,7);
	interChangeSort(a,7);
	printf("\nOUTPUT:\n");
	xuatMang(a,7);
	return 0;
}
