#include <stdio.h>
//de quy tuyen tinh la ham chi goi la  no 1 lan
// va no giam theo cap bac
//vi du tinh giai thua
int giaithua(int m){
	if(m<=1){
		return m;
	} else return m*giaithua(m-1);
}
int main(){
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	int gt=giaithua(5);
	printf("Ket qua: %d",gt);
	return 0;
}
