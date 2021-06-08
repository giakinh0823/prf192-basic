//THAYCACAC
#include <stdio.h>
#include <math.h>
void input(int &m, int &n){
	printf("Enter m = ");
	scanf("%d",&m);
	printf("Enter n = ");
	scanf("%d",&n);
}
int gcd( int m, int  n){	
	while(m!=n){
		if(m>n)
			m=m-n;	
		else
		n=n-m;	
	}
		return m;
}
int lcm(int m,int n){
	return(m*n/gcd(m,n));
}
bool isPrime(int n){
	if(n==0) return false;
	if(n==1) return false;
	for(int i=2; i<=sqrt(n); i++)
	if(n%i==0) return false;
	return true;
}
void primeCommon(int m, int n){
	int min;
	bool check;
	min=m;
	if(min<n) min=n;
	printf("\nPrime common dividers of m and n = ");
	for(int i=0; i<=min; i++){
		check=isPrime(i);
		if(check==true&&m%i==0&&n%i==0)
		printf("%5d",i);
	}	
}

int main(){
	int m,n;
	input(m,n);
	primeCommon(m,n);
	printf("\nGCD = %d\n",gcd(m,n));
	printf("LCM = %d\n",m*n/gcd(m,n));
}
