#include <stdio.h>

int main(){
	int n;
	printf("Nhap n: "); scanf("%d",&n);
	int i;
	int a[n],b[n];
	for(i=0;i<n;i++){
		printf("a[%d]=",i); scanf("%d",&a[i]);
		if(a[i]<10 || a[i]>99){
			a[i]=0;
			b[i]=0;
		}else{
			b[i]=1;
		}
	}
	int max=0;
	for(i=0;i<n-1;i++){
		if(a[i]!=0){
			int j;
			for(j=i+1;j<n;j++){
				if(a[i]==a[j]){
					b[i]++;
					a[j]=0;
					if(b[i]>max){
						max=b[i];
					}
				}
			}
		}
	}
	for(i=0;i<n;i++){
		if(b[i]==max) printf("%d ",a[i]);
	}
	return 0;
}
