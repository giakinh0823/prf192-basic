#include <stdio.h>


int main(){
	int n;
	printf("Nhap n: ");scanf("%d",&n);
	int i;
	int a[n];
	for(i=0;i<n;i++){
		printf("a[%d]=",i);scanf("%d",&a[i]);
	}
	int x;
	printf("Nhap so can xoa: ");scanf("%d",&x);
	i=0;
	while(i<n){
		if(a[i]==x){
			int j;
			for(j=i;j<n-1;j++){
				a[j]=a[j+1];
			}
			n--;
		}else{
			i++;
		}
	}
	printf("Mang sau khi xoa la: ");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
