#include <stdio.h>
#include <math.h>

int clean_stdlin(){
	while(getchar() != '\n'){}
	return 1;
}

int scp(int n){ // so chinh phuong
  	int i;
  	if(n==1) return 1;
	for(i=1;i<=n/2;i++)
	{
		if(i*i==n){
			return 1;
		}
	}
	return 0;
}


int main(){
  	int n; 
	char c;
   	do{
     	printf("Nhap n: ");
	}while(((scanf("%d%c",&n,&c) != 2 || c!='\n') && clean_stdlin()) || (n<0 || n>1000));

  	printf("%d co phai la so chinh phuong khong: ",n);
  	if(scp(n)==1){
    	printf("Co");
  	}else{
    	printf("Khong");
  	}
  	return 0;
}
