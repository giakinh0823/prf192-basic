#include <stdio.h>
//De qui nhi phan la dang de quy goi 2 lan chinh no
// vidu fibonaci
int fibonaci(int m){
	if(m<=2){
		return 1;
	}else return fibonaci(m-1)+fibonaci(m-2);
						
							
//	1 1 2 3 5 8 13 21 34 55

//vidu: fibonaci(6)
//									                 6
//							    5                                  4
//				      4                   3          |        3          2(=>1)			
//               3         2(=>1)   2(=>1)  1(=>1)      2(=>1)  1(=>1)  
//		   2(=>1)   1(=>1) 
// Cong tat ca gia tri tra ve 1 se ra ket qua   
}
int main(){
	int n,m;
	printf("Nhap n: "); scanf("%d",&n);
	printf("Ket qua: %d",fibonaci(n));
	return 0;
}
