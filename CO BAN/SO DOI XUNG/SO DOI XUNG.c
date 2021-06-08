#include <stdio.h>

int checkdx(int n){
	int m=n,s=0;
	while(m!=0){
		s=s*10 + m % 10;
		m=m/10;
	}
	if(s==n) return 1;
	return 0;
}

int main(){
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	printf("So nay co phai so doi xung khong: %d",checkdx(n));
	return 0;
}
