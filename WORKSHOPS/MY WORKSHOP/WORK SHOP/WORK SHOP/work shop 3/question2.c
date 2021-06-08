#include <stdio.h>
#include <math.h>


int main(){
	double x1, x2, a, b, c, delta;

  	printf("Enter a, b and c where a*x^2 + b*x + c = 0 and a # 0\n");
  	a=0;
  	while(a==0){
  		printf("Enter a, b, c: "); scanf("%lf%lf%lf", &a, &b, &c);
  		if(a==0){
  			printf("Please enter a # 0\n");
		}
	}
	delta = abs(b*b) - (4*a*c);
	if(delta < 0) { 
		printf("Equations have no solutions");
  	}else if(delta == 0){ 
  		printf("Equations have a unique solution\n");
    	x1 = x2 = (double)(-b/(2*a));
    	printf("X1 = X2 = %.2lf\n", x1);
  	}else{
  		printf("Equation has two solutions\n");
  		x1 = (-b + sqrt(delta))/(2*a);
  		x2 = (-b - sqrt(delta))/(2*a);
		printf("X1 = %.2lf\n", x1);
  		printf("X2 = %.2lf\n", x2);
  	}
  	
  return 0;
}
