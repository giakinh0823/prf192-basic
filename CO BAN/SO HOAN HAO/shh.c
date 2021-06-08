#include <stdio.h>
#include <math.h>

int clean_stdlin(){
	while(getchar() != '\n'){}
	return 1;
}

int shh(int n){
  int s=0,i;
  for(i=1;i<=n/2;i++){
    if(n%i==0){
      s+=i;
    }
  }
  if (s==n) return 1;
  return 0;
}

int main(){
  	int n; 
	char c;
   	do{
     	printf("Nhap n: ");
	}while(((scanf("%d%c",&n,&c) != 2 || c!='\n') && clean_stdlin()) || (n<0 || n>10000));

  	printf("%d co phai la so hoan hao phuong khong: ",n);
  	if(shh(n)==1){
    	printf("Co");
  	}else{
    	printf("Khong");
  	}
  	return 0;
}
