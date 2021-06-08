#include <stdio.h>

int checkdx(int a[],int n){
	int i=0;
	while(i<=n/2){
		if(a[i]!=a[n-i-1]) return 0;
		i++;
	}
	return 1;
}

int main(){
	int n;
	printf("Nhap n: ");scanf("%d",&n);
	int i;
	int a[n];
	for(i=0;i<n;i++){
		printf("a[%d] = ",i);scanf("%d",&a[i]);
	}
	printf("Mang nay co doi xung khong: %d",checkdx(a,n));
	return 0;
}
