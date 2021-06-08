//THAYCACAC
#include <iostream>
#include <math.h>

void input(double &a, double &b, double &c, double &x){
	printf("Enter a = ");
	scanf("%lf",&a);
	printf("Enter b = ");
	scanf("%lf",&b);
	printf("Enter c = ");
	scanf("%lf",&c);
	printf("Enter x = ");
	scanf("%lf",&x);
}
double s1(double a, double b, double c, double x){
	double s1=a*x*x+b*x+c;
	return s1;
}
double s2(double a, double b, double c){
	double s2;
	if((b*b-4*a*c)>0)
		s2=sqrt(b*b-4*a*c);
	else s2=0;
	return s2;
}
void input2(double &a, double &b, double &c){
	printf("\nEnter a, b, c = ");
	scanf("%lf%lf%lf",&a,&b,&c);
}
double perimeter(double a, double b, double c){
	return (a+b+c);
	
}
double area(double a, double b, double c){
	double p, area;
	p=(a+b+c)/2;
	area=sqrt(p*(p-a)*(p-b)*(p-c));
	return area;
}
int main() {
	double a, b,c,x;
	input(a,b,c,x);
	printf("S1 = %.2lf",s1(a,b,c,x));
	printf("\tS2 = %.2lf",s2(a,b,c));
	input2(a,b,c);
	if((a+b)>c&&(a+c)>b&&(b+c)>a){
		printf("Perimeter = %.3lf",perimeter(a,b,c));
		printf("\nArea = %.3lf",area(a,b,c));
	}
	else	printf("a, b, c are not side of a triangle");
	
}
