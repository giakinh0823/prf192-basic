#include <stdio.h>

int main(){
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		int j;
		for(j=0;j<n;j++){
			if(j<i){
				printf(" ");
			}else printf("*");
		}
		printf("\n");
	}
}
