#include <stdio.h>

void init(int tmp[]){
	int i;
	for(i=0;i<200;i++){
		tmp[i]=-1;
	}
}

int fiboQHD(int tmp[], int n){
	if(tmp[n]==-1){
		if(n<=1){
			tmp[n]=n;
		}else{
			tmp[n]=fiboQHD(tmp,n-1)+fiboQHD(tmp,n-2);
		}
	}
	return tmp[n];
}

int main(){
	int tmp[200];
	init(tmp);
	int n;
	printf("Nhap N: "); scanf("%d",&n);
	printf("%d",fiboQHD(tmp,n));
	return 0;
}
