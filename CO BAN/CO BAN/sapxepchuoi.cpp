#include <stdio.h>
#include <conio.h>

void push(int a[], int n, int x){  //them phan tu vao stack
	a[n]=x;
	n++;
}

int pop(int arr[],int n){ //Lay phan tu ra khoi stack
	if(n==0){
		return printf("Stack null");
	}
	int x=arr[n-1];
	n--;
	return x;
}

void popall(int arr[], int n){ // lay tat ca phan tu ra khoi stack
	while(n>0){
		int x=pop(arr,n);
		printf("%d ",x);
	}	
}

int main(){
	int n=0;
	int a[100];
	push(a,n,17);
	push(a,n,23);
	push(a,n,03);
	push(a,n,16);
	int i;
	printf("%d\n",n);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	popall(a,n);
	getch();
	return 0;
}
