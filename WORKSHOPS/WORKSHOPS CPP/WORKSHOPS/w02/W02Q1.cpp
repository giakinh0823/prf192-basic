//THAYCACAC
#include <iostream>
#include <math.h>
void input(int &n){
	printf("Enter n=");
	scanf("%d",&n);
	while(n<=5){
		printf("n must be > 5, please reenter!\n");
		printf("Enter n=");
		scanf("%d",&n);
	}
}
void sum(int n){
	double s1=0,s2=1,s3=0,t;
	for(int i=1;i<=n;i++){
		s1+=i;
		s2*=i;
		t=1/(float)i;
		s3+=t;
	};
	printf("s1 = %d\n",(int)s1);
	printf("s2 = %d\n",(int)s2);
	printf("s3 = %.4f\n",s3);
}
bool isPrime(int n){
	if(n==0) return false;
	if(n==1) return false;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0)	return false;
	}
	return true;
}
int main(){
	int n;
	bool check;
	input(n);
	sum(n);
	printf("\nEnter n = ");
	scanf("%d",&n);
	check=isPrime(n);
	if(check==true)	printf("%d is a prime number",n);
	else printf("%d is not a prime number",n);
}
