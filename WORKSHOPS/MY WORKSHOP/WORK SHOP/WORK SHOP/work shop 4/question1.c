#include <stdio.h>
#include <math.h>

double factorial(int n){
	if (n<=1){
		return n;
	}
	return (double)(n * factorial(n-1));
}

double myExp(double x, int n){
	if(n==0){
		return 1;
	} 
	return pow(x,n)/factorial(n) + myExp(x,n-1);
};

double myExpDouble(double x, double epsi){
	double result;
	int i=0;
	while(epsi <= abs(pow(x,i)/factorial(i))){
		result = myExp(x,i);
		i++;
	}
	return result;
};

int main(){
 	system("cls");
  	double x, epsi; int n;
  	x = 6; epsi = 0.0001; n = 1000;
  	printf("\n");
  	printf("exp(%.1lf) = %lf\n", x,exp(x));  
  	printf("exp(%.1lf,%d) = %lf\n", x, n, myExp(x,n));  
  	printf("exp(%.1lf,%lf) = %lf\n",x, epsi, myExpDouble(x,epsi));  
  	printf("\n");
  	system("pause");
  	return(0);
 }

