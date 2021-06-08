#include <stdio.h>

int main(){
	int n,d,lanquay;
	int a[100];
	scanf("%d%d", &n, &lanquay);
	int i;
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	int dem=0;
	int m=0;
	
	while(dem!=lanquay){
		int z=a[0];
		for(i=0; i<n-1; i++){
			a[i]=a[i+1];
		}
		a[n-1]=z;
		for(i=0; i<n; i++){
			printf("%d ", a[i]);
		}
		printf("\n");
		dem++;
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
