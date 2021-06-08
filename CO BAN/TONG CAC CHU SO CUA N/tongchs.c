#include <stdio.h>

int tongcs(int n){
	int m=n,s=0;
	while(m!=0){
		s=s+m % 10;
		m=m/10;
	}
	return s;
}

int main(){
	int n;
	printf("Nhap n: ");scanf("%d",&n);
	printf("Tong cac chu so cua n: %d",tongcs(n));
	return 0;
}
