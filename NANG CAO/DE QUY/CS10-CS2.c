#include <stdio.h>

void chuyendoi(int n){
	if(n>0){
		int ds=n%2;
		n=n/2;
		chuyendoi(n);
		printf("%d",ds);
	}
}

int main(){
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	chuyendoi(n);
	return 0;
}
