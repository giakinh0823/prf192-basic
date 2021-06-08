#include <stdio.h>

int giaithua(int m){
	if(m<=1){
		return m;
	} else return m*giaithua(m-1);
//				  5          4
//				  			 4          3
//				  						3	         2
//				  									 2          1		
//												 
//	              return 5*gt4(4*gt3(3*gt(2*gt1(1))))	
}
int main(){
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	int gt=giaithua(5);
	printf("Ket qua: %d",gt);
	return 0;
}
