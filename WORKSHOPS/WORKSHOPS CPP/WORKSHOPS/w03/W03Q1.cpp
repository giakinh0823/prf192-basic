//THAYCACAC
#include <stdio.h>

void input(int &n){
	printf("\nEnter n = ");
	scanf("%d",&n);
}
void binary(int n){
	int i,a[10];
	printf("%d in binary number format is = ",n);
	for(i=0;n>0;i++){  
	a[i]=n%2;  
	n=n/2;  
	}  
	for(i=i-1;i>=0;i--){  
	printf("%d",a[i]);  
	}  
	printf("\n");
	return;
}
void sum(int n){
	int s=0;
	printf("The sum of all digits in %d is ",n);
	while(n!=0){
	s+=n%10;
	n/=10;
	}
	printf("%d\n",s);

}
void reverse(int n){
	int i;
	printf("The reverse of %d is ",n);
	while(n!=0){
		i=n%10;
		n/=10;
		printf("%d",i);
	}
}
int main(){
	int n,n1;
	input(n);
	binary(n);
	input(n);
	sum(n);
	reverse(n);
	
}



