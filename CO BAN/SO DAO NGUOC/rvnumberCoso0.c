#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int clean_stdlin(){
	while(getchar() != '\n'){}
	return 1;
}

char* rv(int n){
	char *buffer =(char*)malloc(33*sizeof(char));
	itoa(n,buffer,10);
	strrev(buffer);
	return buffer; 
}

int main(){
  	int n; 
	char c;
   	do{
     	printf("Nhap n: ");
	}while(((scanf("%d%c",&n,&c) != 2 || c!='\n') && clean_stdlin()) || (n<0 || n>10000));
	
  	printf("So dao nguoc la: %s", rv(n));
  	return 0;
}
