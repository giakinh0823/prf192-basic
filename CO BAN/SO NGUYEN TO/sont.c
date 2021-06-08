#include <stdio.h>
#include <math.h>

int clean_stdlin(){
	while(getchar() != '\n'){}
	return 1;
}

int snt(int n){ 
  if(n<2) return 0;
  int i;
  for(i=2;i<=trunc(sqrt(n));i++){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}


int main(){
  	int n; 
	char c;
   	do{
     	printf("Nhap n: ");
	}while(((scanf("%d%c",&n,&c) != 2 || c!='\n') && clean_stdlin()) || (n<0 || n>1000));

  	printf("%d co phai la so nguyen to khong: ",n);
  	if(snt(n)==1){
    	printf("Co");
  	}else{
    	printf("Khong");
  	}
  	return 0;
}
