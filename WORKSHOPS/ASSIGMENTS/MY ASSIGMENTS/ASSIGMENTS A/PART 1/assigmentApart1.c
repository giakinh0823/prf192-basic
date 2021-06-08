#include <stdio.h>

#define RATE_PENSION 0.05;
#define PERSONAL_ALLOWANCE 4000.0;

double caculate(double taxable, double income){
	double personal=4000;
	double tax_surplus;
  double tax;
	if(taxable<=5000){
		tax=taxable*0.05;
	}	
	else if(taxable<=10000){
		tax_surplus=taxable-5000;
		tax=5000*0.05+tax_surplus*0.1;
	}
	else if(taxable<=20000){
		tax_surplus=taxable-10000;
		tax=5000*0.05+5000*0.1+tax_surplus*0.15;
	}
	else if(taxable<=30000){
		tax_surplus=income-20000;
		tax=5000*0.05+5000*0.1+10000*0.15+tax_surplus*0.2;
	}
	else if(taxable<=50000){
		tax_surplus=taxable-30000;
		tax=5000*0.05+5000*0.1+10000*0.15+10000*0.2+tax_surplus*0.25;
	}
	else if(taxable<=80000){
		tax_surplus=income-50000;
		tax=5000*0.05+5000*0.1+10000*0.15+10000*0.2+20000*0.25+tax_surplus*0.3;
	}
	else {
		tax_surplus=taxable-80000;
		tax=5000*0.05+5000*0.1+10000*0.15+10000*0.2+20000*0.25+30000*0.3+tax_surplus*0.35;
	}
	return tax;
}

int clean_stldin(){
  while(getchar() != '\n'){}
  return 1;
}

double contributions(){
  char c,choose;
  do{
    printf("Pension contributions (5) (y/n): "); 
  }while(((scanf("%c%c",&choose,&c) !=2 || c!='\n') && clean_stldin()) || (choose!='y' && choose !='n'));
  if(choose=='y') return 0.05;
  return 0;
}

double healthInsurance(){
  char c,choose;
  do{
    printf("Health Insurance (1) (y/n): "); 
  }while(((scanf("%c%c",&choose,&c) !=2 || c!='\n') && clean_stldin()) || (choose!='y' && choose !='n'));
  if(choose=='y') return 0.01;
  return 0;
}

double dependant(){
  char c;
  int depen=0;

  do{
    if(depen<0){
      printf("Invalid input, try again.\n");
    }
    printf("Number dependants < 18 years old: ");
  }while(((scanf("%d%c",&depen,&c) !=2 || c!='\n') && clean_stldin()) || (depen<0));
  return depen * 1600;
}

double gifts(){
  double g;
  printf("Gift of charity: "); scanf("%lf", &g);
  return g;
}

void taxCalculator(){

  char c;
  double income;

  do{
    if(income<0){
      printf("Invalid input, try again.\n");
    }
    printf("Income for the current month (in thousand VND): ");
  }while(((scanf("%lf%c",&income,&c) !=2 || c!='\n') && clean_stldin()) || (income<0));

  double personal = PERSONAL_ALLOWANCE;
  double contri = contributions();
  double health = healthInsurance();
  double depen = dependant();
  double gift = gifts();

  printf("Gross Income: %22.1lf\n", income);
  printf("Dedution\n");
  printf("Personal allowance: %16.1lf\n", personal);
  printf("Pension contributions: %13.1lf\n", contri*income);
  printf("health insurance: %18.1lf\n", health*income);
  printf("Dependant: %25.1lf\n", depen);
  printf("Charaty: %27.1lf\n",gift);
  printf("-------------------------------------\n");
  double total = personal+contri*income +  health*income+depen+gift;
  printf("Total: %30.1lf\n",total);
  double taxable = income - total;
  printf("Taxable Income: %21.1lf\n",taxable);
  double tax = caculate(taxable,income);
  printf("Tax: %32.1lf\n",tax);
  printf("Net Income: %25.1lf\n",income-tax);
}

void menu(int *n){
  printf("Choose one of the following options: \n");
  printf("1. Tax calculator\n");
  printf("0. Exit\n");
  char c;
  do{
    printf("Your selection (0 -> 1): ");
  }while(((scanf("%d%c",n,&c) != 2 || c != '\n') && clean_stldin()) || (*n!=0 && *n!=1));
}

int main(void) {
  int n=0;
  do{
    menu(&n);
    switch(n){
      case 1:
      taxCalculator();
      break;
      case 0:
      break;
    }
    if(n==0) break;
    getchar();
    char c,choose;
    do{
      printf("Another run (y/n): "); 
    }while(((scanf("%c%c",&choose,&c) !=2 || c != '\n') && clean_stldin()) || (choose!='y' && choose !='n'));
    if(choose == 'n') break;
  }while(1);
  return 0;
}
