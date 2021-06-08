#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int ispalindrome(int n){
	int s=n,k=0;
	while(s>0){
		k=k*10+s%10;
		s/=10;
	}
	if(k==n){
		return 1;
	}else return 0;
}

void palindrome(int n, int m){
	int i, d=0;
	for(i=m;i<=n;i++){
		if(ispalindrome(i) && d==0){
			printf("%d",i);
			m=i+1;
			break;
		}
	}
	for(i=m;i<=n;i++){
		if(ispalindrome(i)){
			printf(", %d",i);
		}
	}
}

int main(){    
	int n=0,m=1;
	while(m>=n){
		printf("Enter m = "); scanf("%d", &m);
		printf("Enter n = "); scanf("%d", &n);
		if(m>=n){
			printf("!Please enter m < n\n");
		}
	}
	printf("All palindrome numbers in the interval [%d,%d] = {",m,n);
	palindrome(n,m); 
	printf("}\n");
    
	return 0;
}


