#include <stdio.h>
#include <math.h>

int clean_stdlin(){
	while(getchar() != '\n'){}
	return 1;
}

int rv(int n){
	int s=0,m=n;
  	while(m>0){
    	s=s*10+m%10;
    	m=m/10;
  	}
  	return s;
}

int main(){
  	int n; 
	char c;
   	do{
     	printf("Nhap n: ");
	}while(((scanf("%d%c",&n,&c) != 2 || c!='\n') && clean_stdlin()) || (n<0 || n>10000));
  	printf("So dao nguoc la: %d",  rv(n));
  	return 0;
}
