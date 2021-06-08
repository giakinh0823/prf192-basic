#include <stdio.h>
#include <math.h>

void TestSaving(double principal, double rate, int year){
	printf("1. Test saving account");
	printf("\nprincipal = ");
	scanf("%lf", &principal);
	printf("Annual rate = ");
	scanf("%lf", &rate);
	printf("No of years = ");
	scanf("%d", &year);
	printf("principal = ");
	printf("%.2lf", principal);
	printf("\namount after %d years = ", year);
	printf("%.2lf", pow((1+rate),year)*principal);
}

void Investment(double future, double rate, int year){
	printf("\n\n2. Investment calculsation");
	printf("\nfuture = ");
	scanf("%lf", &future);
	printf("Annual rate = ");
	scanf("%lf", &rate);
	printf("No of years = ");
	scanf("%d", &year);
	printf("principle should be = ");
	printf("%.2lf", future/pow((1+rate),year));
}

int main(){
	double principal, rate, future;
	int year;
	TestSaving(principal, rate, year);
	Investment(future, rate, year);
}
