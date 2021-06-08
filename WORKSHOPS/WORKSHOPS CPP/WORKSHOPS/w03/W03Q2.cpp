//THAYCACAC
#include <stdio.h>
#include <math.h>

void input(float &a, float &b, float &c){
	printf("Enter a= ");
	scanf("%f",&a);
	printf("Enter b= ");
	scanf("%f",&b);
	printf("Enter c= ");
	scanf("%f",&c);
}
void quadratic(float a, float b, float c){
	float delta, x1,x2;
	if(a==0){
		printf("%",-c/b);
	}
	else{	
		delta=b*b-4*a*c;
		if(delta>0){
			x1=(-b+sqrt(delta))/(2*a);
			x2=(-b-sqrt(delta))/(2*a);
			printf("%f\n", x1);
			printf("%f", x2);
		}
		if(delta==0){
			x1=-b/(2*a);
			printf("%f",x1);
		}
		if(delta<0)
			printf("No root");
	return;
	}
}

int main(){
	float a,b,c;
	input(a,b,c);
	quadratic(a,b,c);
}
