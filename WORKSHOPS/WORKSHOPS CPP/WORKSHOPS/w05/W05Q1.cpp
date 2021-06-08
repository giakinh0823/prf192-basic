#include <stdio.h>
#include <stdlib.h>

bool CheckPrime(int i){
	for(int k=2; k<=i-1; k++){
		if(i%k==0)	return false;
	}
	return true;
}

void Display(int lower, int upper){
	bool check;
	int row=1,a[100];
	int n=0;
	for(int i=lower; i<=upper; i++){
		if(i==1||i==0) continue;
		check=CheckPrime(i);
		if(check==true){
			printf("%5d",i);
			a[n++]=i;
		}
	} 
	printf("\n3 last: ");
	for(int i=n-3;i<n;i++)
		printf("%5d",a[i]);
	
}

int main(){
	int lower, upper, columns;
	printf("Table of Primes");
	printf("\n==============");
	printf("\nLower limit: ");
	scanf("%d",&lower);
	printf("Upper limit: ");
	scanf("%d",&upper);
	Display(lower, upper);
}
