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

int sieunt(int n){ //so sieu nguyen to
  int m=n;
  while(m>0 && snt(m)==1){
    m=m/10;
  }
  if(m==0) return 1;
  return 0;
}



int main(){
  	int n; 
	char c;
   	do{
     	printf("Nhap n: ");
	}while(((scanf("%d%c",&n,&c) != 2 || c!='\n') && clean_stdlin()) || (n<0 || n>100000));

  	printf("%d co phai la so sieu nguyen to khong: ",n);
  	if(sieunt(n)==1){
    	printf("Co");
  	}else{
    	printf("Khong");
  	}
  	return 0;
}
