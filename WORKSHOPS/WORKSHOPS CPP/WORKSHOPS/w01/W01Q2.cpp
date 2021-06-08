//THAYCACAC
#include <iostream>

void input(double &a, double &b, double &c){
	printf("Enter a = ");
	scanf("%lf",&a);
	printf("Enter b = ");
	scanf("%lf",&b);
	printf("Enter c = ");
	scanf("%lf",&c);
}
void swap(double &a, double &b){
	double temp;
	temp=a;
	a=b;
	b=temp;
}
void arr(double a, double b, double c){
	if(a>b) swap(a,b);
	if(a>c) swap(a,c);
	if(b>c) swap(b,c);
	printf("\nMin = %.2lf",a);
	printf("\nMax = %.2lf",c);
	printf("\nArrange = %.2lf %.2lf %.2lf",a,b,c);
}
int main(){
	double a,b,c;
	input(a,b,c);
	arr(a,b,c);
}
