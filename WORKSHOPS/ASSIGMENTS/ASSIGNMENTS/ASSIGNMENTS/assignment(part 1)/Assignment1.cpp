//THAYCACAC
#include <stdio.h>
#define PENSION 0.05
#define HEALTH_INSURANCE 0.01
#define PERSONAL_ALLOWANCE 4000

double inputIncome(double &income){
	do{
		printf("\nIncome for the current month (in thousand VND): ");
		scanf("%lf",&income);
	}while(income<0);
	return income;
}
double inputPension(double income, double &pension){
	char check;
	do{
		printf("Pension contributions (5%%) y/n? ");
		fflush(stdin);
		check = getchar();
		if(check!='y'&&check!='n')
			printf("Invalid input, try again.\n");
	}while(check!='y'&&check!='n');
	switch(check){
		case 'y': pension = PENSION*income; break;
		case 'n': pension = 0; break;
	}
	return pension;
}
double inputHealth(double income, double &health){
	char check;
	do{
		printf("Health insurance (1%%) y/n? ");
		fflush(stdin);
		check = getchar();
		if(check!='y'&&check!='n')
			printf("Invalid input, try again.\n");
	}while(check!='y'&&check!='n');
	switch(check){
		case 'y': health = HEALTH_INSURANCE*income; break;
		case 'n': health = 0; break;
	}
	return health;
}
double inputDependants(double &dependant){
	int numDependant;
	do{
		printf("Number of dependants < 18 years old: ");
		scanf("%d",&numDependant);
		if(numDependant < 0)
			printf("Invalid input, try again.\n");
	}while(numDependant<0);
	dependant=1600.0*numDependant;
	return dependant;
}
double inputGift(double &gift){
	do{
		printf("Gift of charity: ");
		scanf("%lf",&gift);
	}while(gift<0);
	return gift;
}
void input(double &income, double &pension, double &health, double &dependant, double &gift){
	inputIncome(income);
	inputPension(income,pension);
	inputHealth(income,health);
	inputDependants(dependant);
	inputGift(gift);
}
void caculate(double income, double pension, double health, double dependant, double gift, double &total, double &personal, double &tax){
	personal=4000;
	total=personal+pension+health+dependant+gift;
	double tax_surplus, taxable;
	taxable=income-total;
	if(taxable<=5000){
		tax=taxable*0.05;
	}	
	else if(taxable>5000 && taxable<=10000){
		tax_surplus=taxable-5000;
		tax=5000*0.05+tax_surplus*0.1;
	}
	else if(taxable>10000 && taxable<=20000){
		tax_surplus=taxable-10000;
		tax=5000*0.05+5000*0.1+tax_surplus*0.15;
	}
	else if(taxable>20000 && taxable<=30000){
		tax_surplus=income-20000;
		tax=5000*0.05+5000*0.1+10000*0.15+tax_surplus*0.2;
	}
	else if(taxable>30000 && taxable<=50000){
		tax_surplus=taxable-30000;
		tax=5000*0.05+5000*0.1+10000*0.15+10000*0.2+tax_surplus*0.25;
	}
	else if(taxable>50000 && taxable<=80000){
		tax_surplus=income-50000;
		tax=5000*0.05+5000*0.1+10000*0.15+10000*0.2+20000*0.25+tax_surplus*0.3;
	}
	else {
		tax_surplus=taxable-80000;
		tax=5000*0.05+5000*0.1+10000*0.15+10000*0.2+20000*0.25+30000*0.3+tax_surplus*0.35;
	}
	return ;
}
void display(double income, double pension, double health, double dependant, double gift, double total, double personal, double tax){
	caculate(income,pension,health,dependant,gift,total,personal,tax);
	printf("Gross Income:               %.2lf\n",income);
	printf("Deduction\n");
	printf("   Personal allowance:     %.2lf\n",personal);
	printf("   Pension contributions:  %.2lf\n",pension);
	printf("   Health insurance:       %.2lf\n",health);
	printf("   Dependant:              %.2lf\n",dependant);
	printf("   Charity:                %.2lf\n",gift);
	printf("-----------------------------------\n");
	printf("Total:                     %.2lf\n",total);
	printf("Taxable Income:            %.2lf\n",income-total);
	printf("Tax:                       %.2lf\n",tax);
	printf("Net Income:                %.2lf\n",income-tax);
	
}
int main(){
	int choose=-1;
	char check;
	double income,pension,health,dependant,gift,personal,total,tax;
	do{
		printf("1. Tax calculator\n");
		printf("0. Exit\n");
		printf("Your selection (0 -> 1): ");
		scanf("%d",&choose);
		switch(choose){
			case 1: input(income, pension, health, dependant, gift);
					display(income, pension, health, dependant, gift, total, personal, tax); 
					do{
						printf("Another run (y/n)? ");
						fflush(stdin);
						check = getchar();
						if(check!='y'&&check!='n')
							printf("Invalid input, try again.\n");
						if(check=='y'){
							input(income, pension, health, dependant, gift);
							display(income, pension, health, dependant, gift, total, personal, tax); 
						}
					}while(check!='y'&&check!='n');
					break;
			case 0: return 0;
		}
	}while (choose!=0);
}
