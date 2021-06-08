//THAYCACAC
#include <stdio.h>
#include <math.h>
double mySin(double x, double epsi){
	double s,t,d;
  	int i;
		t = x/1;
		s = t; d = -1;
		i = 3;
		while(1)
		   { t *= x*x/(i*(i-1));
		     d = -d;
		     s += d*t;
		     if(fabs(t) <= epsi) break;
		     i += 2;
		   }
	return(s);      
 }    
int main(){
	double x, epsi;
	printf("Enter x = ");
	scanf("%lf",&x);
	printf("Enter epsi = ");
	scanf("%lf",&epsi);
	printf("mySin(%f,%f) = %.3f\n",x,epsi,mySin(x,epsi)); 
	return(0);
 }
