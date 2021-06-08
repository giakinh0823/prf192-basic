#include <stdio.h>

int tinhtong(int n){
	if(n==1){
		return 1;
	}
	return n+tinhtong(n-1);
}

int main(){
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	printf("Ket qua: %d",tinhtong(n));
	return 0;
}
