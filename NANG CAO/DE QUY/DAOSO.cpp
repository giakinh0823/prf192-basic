#include <stdio.h>

//123

void daoso(int n){
	if(n!=0){
		printf("%d",n%10);
		daoso(n/10);
	}
}

int main(){
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	daoso(n);
	return 0;
}
