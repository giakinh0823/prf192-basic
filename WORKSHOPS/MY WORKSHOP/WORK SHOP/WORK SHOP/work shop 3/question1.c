#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *binary(int *n){
	char *bin = (char*)malloc(sizeof(char)); 
	strcpy(bin,"");
	while (*n!=0){
		int m = *n % 2;
		char result[2];
//		sprintf(result, "%d", m);
		itoa(m,result,10);
		strcat(bin,result);
		*n=*n/2;
	}
	strrev(bin);
	return bin;
}

int sum(int n){
	int total =0;
	while(n>0){
		total += n % 10;
		n=n/10;
	} 
	return total;
}

void chuyendoi(int n){
	int k =0;
	while(n>0){
		k = n % 10;
		printf("%d",k);
		n=n/10;
	} 
}

int main(){
	int n;
	printf("Enter n = "); scanf("%d",&n);
	int k=n;
	printf("%d, in binary number format is: %s\n",k, binary(&n));
	printf("\nEnter n = "); scanf("%d",&n);
	k=n;
	printf("The sum of all digits in %d is %d\n",k,sum(n));
	printf("\nThe reverse number of %d is ",k);
	chuyendoi(k);
	return 0;
}

