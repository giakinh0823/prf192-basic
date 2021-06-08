#include <stdio.h>
//De qui duoi la truong hop dac biet cau de qui tuyen tinh, 
//No co dang tuong tu nhu duoi day
int gcd(int m,int n){
	int r;
	if(m<n) return gcd(n,m);
	r=m%n;
	if(r==0){
		return n;
	} else return gcd(n,r);
}
int main(){
	int n,m;
	printf("Nhap n: "); scanf("%d",&n);
	printf("Nhap m: "); scanf("%d",&m);
	printf("Ket qua: %d",gcd(m,n));
	return 0;
}
