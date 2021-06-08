#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int snt(int a){
	int i = 2;
	if(a < 2) return 0;
	while(i < a/2){
		if(a % i == 0) return 0;
		i++;
	}
	return 1;
}


int gcd(int *a, int *b){
	if (*a==0 || *b==0){
		return *a+*b;
	}
	while(*a!=*b){
		if(*a>*b){
			*a=*a-*b;
		}
		if(*a<*b){
			*b=*b-*a;
		}
	}
	return *a;
}

int main(){
	int m,n;
	printf("Enter n = "); scanf("%d",&n);
	printf("Enter m = "); scanf("%d",&m);
	printf("Prime dividers: ");
	int a=1;
	while(a <= m || a <= n){
		if(m % a == 0 && n % a == 0){
			if(snt(a) == 1) printf("%d ", a);
		}
		a++;
	}
	printf("\n");
	printf("LCM = %d\n",(n*m)/gcd(&n,&m));
	printf("GCD = %d",gcd(&n,&m));
}


