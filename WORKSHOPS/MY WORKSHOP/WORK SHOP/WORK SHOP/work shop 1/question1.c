#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double a,b,c,x;
	printf("Enter a = "); scanf("%lf",&a);
	printf("Enter b = "); scanf("%lf",&b);
	printf("Enter c = "); scanf("%lf",&c);
	printf("Enter x = "); scanf("%lf",&x);
	double s1 = a*pow(x,2)+b*x+c;
	double delta = pow(b,2) - 4*a*c;
	double s2;
	if(delta>0){
		s2=sqrt(delta);
	}else{
		s2=0;
	}
	printf("S1 = %.2lf, S2 = %0.2lf\n", s1 , s2);
	printf("\n");
	printf("Enter a, b, c = "); scanf("%lf %lf %lf",&a, &b, &c);
	if(a+b>c && b+c>a && a+c>b){
		double p = a+b+c;
		double deltaP = p/2;
		double area = sqrt(deltaP*(deltaP-a)*(deltaP-b)*(deltaP-c));  
		printf("Perimeter = %0.4lf", p);
		printf("\nArea = %0.4lf",area);
	}else{
		printf("a, b, c are not sides of a triangle.");
	}
	return 0;
}
