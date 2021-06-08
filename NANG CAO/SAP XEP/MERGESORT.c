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

void meger(int a[],int left, int mid , int right){
	int temp[right - left+1];
	int pos = 0,d=0;
	int i=left;
	int j=mid+1;
	while(!(i>mid && j>right)){
		if(i<=mid && j<=right && a[i]<a[j] || j>right){
			temp[pos++]=a[i++];
			d++;
		}else {
			temp[pos++]=a[j++];
			d++;
		}
	}
	for(i=0;i<d;i++){
		a[left+i]=temp[i];
	}
}

void megerSort(int a[],int left, int right){
	if(left>=right) return;
	int mid=(left+right)/2;
	megerSort(a,left,mid);
	megerSort(a,mid+1,right);
	meger(a,left,mid,right);
}

int main(){
	int n;
	int a[100];
	printf("Nhap n: "); scanf("%d",&n);
	nhapMang(a,n);
	megerSort(a,0,n-1);
	xuatMang(a,n);
	return 0;
}
