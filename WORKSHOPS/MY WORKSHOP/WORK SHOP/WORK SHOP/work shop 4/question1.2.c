#include <stdio.h>
#include <conio.h>
#include <math.h>

double myExp(double x, int n){
	int i=1;
	double result=1 , fraction=1 ,numerator = 1 ,denominator = 1;
	do{
//		numerator *= x; 
//		denominator *= i;
	    fraction *= x/i; 
		result += fraction; 
		i++; 
	}while(i <= n); 
	return result;
}

double myExpDouble(double x, double epsi){
	int i=1;
	double result=1 , fraction=1 ,numerator = 1 ,denominator = 1;
	do{
//		numerator *= x; 
//		denominator *= i;
	    fraction *= x/i; 
		result += fraction; 
		i++; 
	}while(fraction >= epsi); 
	return result;
}


int main(){	
	double x, epsi; int n;
	x = 6; epsi = 0.0001; n = 100000;
	printf("exp(%.1lf) = %lf\n", x, exp(x));  
  	printf("exp(%.1lf,%d) = %lf\n", x, n, myExp(x,n));  
  	printf("exp(%.1lf,%lf) = %lf\n", x, epsi, myExpDouble(x,epsi));  
  	printf("\n");
	return (0);
}
