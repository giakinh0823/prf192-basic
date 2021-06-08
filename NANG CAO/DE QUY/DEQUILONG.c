#include <stdio.h>

int ackerman(int n, int m){
	if(n==0){
		return m+1;
	}else if(m==0){
		return ackerman(n-1,1);
	}else{
		return ackerman(n-1,ackerman(n,m-1));
	}
}
int main(){
	int n,m;
	printf("Nhap n va m: "); scanf("%d%d",&n,&m);	
	printf("%d",ackerman(n,m));
	return 0;
}
