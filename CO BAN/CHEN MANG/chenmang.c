#include <stdio.h>

int main(){
	int n;
	printf("Nhap n: ");scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++){
		printf("a[%d]= ",i);scanf("%d",&a[i]);
	}
	int x;
	printf("Nhap gia tri can chen x: "); scanf("%d",&x);
	int vt;
	printf("Nhap vi tri can chen: ");scanf("%d",&vt);
	if(vt==n+1){
		a[n+1]=x;
	}else{
		n=n+1;
		for(i=n;i>vt;i--){
			a[i]=a[i-1];
		}
		a[vt]=x;
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
