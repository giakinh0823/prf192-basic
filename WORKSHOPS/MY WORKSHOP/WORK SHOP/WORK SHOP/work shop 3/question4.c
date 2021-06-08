#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *binary(int *n){
	char *bin = (char*)malloc(sizeof(char)); 
	strcpy(bin,"");
	while (*n!=0){
		int m = *n % 2;
		char result[2];
		itoa(m,result,10);
		strcat(bin,result);
		*n=*n/2;
	}
	strrev(bin);
	return bin;
}

int sum(char *str){
	int total =0;
	int n = atoi(str);
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
	char s[100];
	printf("\nEnter n = "); scanf("%s",&s);
	char l[100];
	strcat(l,s);
	printf("The sum of all digits in %s is %d\n",s, sum(s));
	printf("\nThe reverse number of %s is %s", l,strrev(s));
	return 0;
}

