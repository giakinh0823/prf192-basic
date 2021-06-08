#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *sort(double *a,double *b,double *c){
	if(*a < *b){
		double z=*a;
		*a=*b;
		*b=z;
	}
	if(*a < *c){
		double z=*a;
		*a=*c;
		*c=z;
	}
	if(*b < *c){
		double z=*b;
		*b=*c;
		*c=z;
	}
	
}

int main(){
	double a,b,c;
	printf("Enter a = "); scanf("%lf",&a);
	printf("Enter b = "); scanf("%lf",&b);
	printf("Enter c = "); scanf("%lf",&c);
	sort(&a,&b,&c);
	printf("Max = %0.2lf\n", a);
	printf("Min = %0.2lf\n", c);
	printf("%0.2lf <= %0.2lf <= %0.2lf",c,b,a);
}
