#include <stdio.h>

double myPi(double *epsi){
	int i = 0;
	double result = 0;
	int sig = 1;
	double g = 1.0 / (2 * i + 1);
	while( g > *epsi) {
		g = 1.0 / (2 * i + 1);
		result += sig * g; 
		sig *= -1; //sig odd or even. odd = -1 or even = 1
		i++;	
	}
	return 4 * result;
}

int main() {
	double epsi;
	printf("Enter epsi: ");
	scanf("%lf", &epsi);
	printf("myPI = %0.10lf", myPi(&epsi));
	return 0;
}
