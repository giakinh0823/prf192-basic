#include <stdio.h>

int main() {
	int i,j;
	int a[10][10];
	int m,n;
	printf ("a[n][m]=");
	scanf ("%d%d", &n, &m);
	for(i=0;i<n;i++){
		for(j=0; j<m; j++){
		 scanf("%d", &a[i][j]);
		}		
	}
	for(i=0;i<n;i++){
		for(j=0; j<m; j++){
		 printf("%d",a[i][j]);
		}	
		printf("\n");		
	}
	int max=-3200;
	for(i=1;i<n-1;i++){
		for(j=1; j<m-1; j++){
		int sum=0;
//		 sum=a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1] + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
		 sum=a[i][j] + a[i-1][j] + a[i-1][j-1] + a[i-1][j+1] + a[i+1][j] + a[i+1][j-1] + a[i+1][j+1];
//		 printf("sum = %d",sum);
		 if (max<sum){
		 	max=sum;
			}	
		}		
	}
	printf("\n%d", max);
	
	return 0;	
}
