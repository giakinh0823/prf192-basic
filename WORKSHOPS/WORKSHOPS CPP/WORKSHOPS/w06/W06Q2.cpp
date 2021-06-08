//THAYCACAC	
#include <stdio.h>
#define MAX 100
	
void inputArr(float a[MAX],int &n){
	do{
		printf("In put size of array: ");
		scanf("%d",&n);
		printf("Enter %d float number: ",n);
		for(int i=0;i<n;i++){
			scanf(" %f",&a[i]);
		};
	}while(n<0||n>100);
}
void display(float a[MAX],int n){
	for(int i=0;i<n;i++){
		printf("%5.1f",a[i]);
	}
}
void swap(float &a,float &b){
	float temp;
	temp=a;
	a=b;
	b=temp;
}
void sortArr(float a[MAX],int n){
	printf("Before sorting:");
	display(a,n);
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--)
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
	}
	printf("\nAfter sorting:");
	display(a,n);
}
void search(float a[MAX],int n,float &x){
	printf("Enter the value x to be search: " );
	scanf("%f",&x);
	for(int i=0;i<n;i++){
		if(x==a[i])
			printf("Found %.1f at position %d",x,i);
	}
}

int main(){
	int n,check=-1;
	float x,a[MAX];
	do{
		printf("\nSelect options:\n");
		printf("1. Enter the list of float numbers\n");
		printf("2. Sort the list in increasing order\n");
		printf("3. Search value x in the list\n");
		printf("4. Display the list\n");
		printf("0. Exit\n");
		printf("Your selection (0 -> 4): ");
		scanf("%d",&check);
		
		switch(check){
			case 1: inputArr(a,n); break;
			case 2: sortArr(a,n); break;
			case 3: search(a,n,x); break;
			case 4: display(a,n); break;
			case 0: return 0; 
		}
	}while(check!=0);
}
