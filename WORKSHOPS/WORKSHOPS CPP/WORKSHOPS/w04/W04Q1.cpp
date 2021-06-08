//THAYCACAC
#include <stdio.h>
#include <math.h>
double myExp(double x, int n){
	double s=1,t=1;
	for(int i=1; i<=n; i++){
		t*=x/i;
		s+=t;
	}
	return(s);
}
double myExp_2(double x, double epsi){
	int t=1, n=0;
	double s=1;
	while(s>epsi){
		s*=x/t;
		t++;
		n++;
	}
	return (myExp(x,n));
}
int main(){
  double x, epsi; int n;
  x = 1.5; epsi = 0.00001; n = 1000;
  printf("\n");
  printf(" exp(%.1f) = %f\n", x,exp(x));  
  printf(" exp(%.1f,%d) = %f\n", x, n, myExp(x,n));  
  printf(" exp(%.1f,%f) = %f\n",x, epsi, myExp_2(x,epsi));  
  printf("\n");
  return(0);
 }

