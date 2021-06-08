#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int total(int n){
	if(n==1){
		return 1;
	}
	return n+total(n-1);
}

int factorial(int n){
	if(n==1){
		return 1;
	}
	return n*factorial(n-1);
}

double doubleTotal(double n){
	if(n==1){
		return 1;
	}
	return (double)(1/n) + doubleTotal(n-1);
}

int prime(n){
	if(n<2){
		return 0;
	}else{
		int i;
		for(i=2;i<=sqrt(n);i++){
			if(n % i ==0){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	int n=0;
	while(n<=5){
		printf("Enter n = "); scanf("%d",&n);
		if(n<=5){
			printf("n must be > 5, please reenter!\n");
		}
	}	
	int s1 = total(n);
	int s2 = factorial(n);
	double s3 = doubleTotal(n);
	printf("s1 = %d\n",s1);
	printf("s2 = %d\n",s2);
	printf("s3 = %0.4lf\n",s3);
	printf("Enter n = "); scanf("%d",&n);
	if(prime(n)==1){
		printf("%d is prime number",n);
	}else{
		printf("%d is not prime number",n);
	}
	return 0;
}
