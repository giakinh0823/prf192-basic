#include <stdio.h>
//de qui da tuyen la bao gom de quy va vong lap

void print_array(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void print_permutations(int arr[], int n, int i){
	int j, swap;
	print_array(arr,n);
	for(j=i;j<n;j++){
		if(arr[i]>arr[j]){
			swap=arr[i];
			arr[i]=arr[j];
			arr[j]=swap;
		}
		print_permutations(arr,n,i+1);

	}
	
}

int main(){
	int n,a[100],i;
	printf("Nhap n: "); 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	print_permutations(a,n,0);
//	print_array(a,n);
}
