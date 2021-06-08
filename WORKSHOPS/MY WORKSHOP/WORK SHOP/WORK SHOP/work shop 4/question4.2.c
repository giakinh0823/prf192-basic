#include <stdio.h>
#include <math.h>
#define PI 3.141592654

double factorial(int n){
	if (n<=1){
		return (double)(n);
	}
	return (double)(n * factorial(n-1));
}

double myCos(double *x, double *epsi){
	int i = 1;
	double result = 1;
	int sig = -1;
	double g = pow((double)(*x * PI/180),2*(double)i) / factorial(2 * i);
	while( g > *epsi) {
		g = pow((double)(*x * PI/180),2*(double)i) / factorial(2 * i);
		result += sig * g; 
		sig *= -1; //sig odd or even. odd = -1 or even = 1
		i++;
	}
	return result;
}

int main(){
	double x, epsi;
	printf("Enter x: "); scanf("%lf",&x);
	printf("Enter epsi: "); scanf("%lf", &epsi);
	printf("Cos(%lf): %lf",x, myCos(&x,&epsi));
	return 0;
}
