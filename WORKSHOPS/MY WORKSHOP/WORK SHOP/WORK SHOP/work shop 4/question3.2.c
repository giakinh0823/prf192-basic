#include <stdio.h>
#include <math.h>
#define PI 3.141592654

double factorial(int n){
	if (n<=1){
		return (double)(n);
	}
	return (double)(n * factorial(n-1));
}

double mySin(double *x, double *epsi){
	int i = 0;
	double result = 0;
	int sig = 1;
	double g = pow((double)(*x * PI/180),2*(double)i+1) / factorial(2 * i + 1);
	while( g > *epsi) {
		g = pow((double)(*x * PI/180),2*(double)i+1) / factorial(2 * i + 1);
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
	printf("Sin(%lf): %lf", x,mySin(&x,&epsi));
	return 0;
}
