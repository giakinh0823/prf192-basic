#include <stdio.h>

//123

int tinhtong(int n){
	if(n==0){
		return 0;
	}
	return n%10 + tinhtong(n/10);
}

int main(){
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	printf("Ket qua: %d",tinhtong(n));
	return 0;
}
