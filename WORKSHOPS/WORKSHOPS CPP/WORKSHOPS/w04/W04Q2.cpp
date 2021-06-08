//THAYCACAC
#include <stdio.h>
#include <math.h>

double myPi(double epsi){
	double s=1,i,d=-1,s2=1,n;
	
	for(n=1; s2>epsi; n+=2){
		s2=1/n;
		if(s2<=epsi)	break;
	}
	printf("%f\n",n);
	
	for(i=3; i<=n; i+=2){
		s+=d/i;
		d=-d;
	}
	return(4*s);
}

int main(){
	printf("%lf",myPi(0.01));
}
