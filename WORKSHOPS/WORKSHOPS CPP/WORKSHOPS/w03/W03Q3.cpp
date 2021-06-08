//THAYCACAC
#include <stdio.h>

void input(int &m, int &n){
	do{
	printf("Enter m = ");
	scanf("%d",&m);
	printf("Enter n = ");
	scanf("%d",&n);
	}while(m>=n);
}
int reverse(int n){
	int s=0,d;
	while(n!=0){
	d=n%10;
	s=s*10+d;
	n/=10;	
	}
	return s;
}
void palindromic(int m, int n){
	printf("All palindrom numbers: ");
	for(int i=m; i<=n; i++){
		if(i==reverse(i))
			printf("%d\n",i);
	}
}
int main(){
	int m,n;
	input(m,n);
	palindromic(m,n);
}
