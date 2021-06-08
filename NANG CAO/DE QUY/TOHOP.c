#include <stdio.h>
//to ho nCk
int choose(int n,int k){
	if(k==0 || n==k) return 1;
	return choose(n-1,k)+choose(n-1,k-1);
}
int main(){
	int n,k;
	printf("Nhap n va k: ");
	scanf("%d%d",&n,&k);
	printf("%d",choose(n,k));
	return 0;
}

