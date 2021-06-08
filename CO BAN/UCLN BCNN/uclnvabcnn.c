#include <stdio.h>

int ucln(int a, int b){
    if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b; 
        }else{
            b -= a;
        }
    }
    return a; 
}

int bcnn(int a, int b){
	return (a * b) / ucln(a, b);
}

int main(){
	int a,b;
	printf("Nhap a: "); scanf("%d",&a);
	printf("Nhap b: "); scanf("%d",&b);
	printf("UCLL: %d\n",ucln(a,b));
	printf("BCNN: %d",bcnn(a,b));
	return 0;
}
