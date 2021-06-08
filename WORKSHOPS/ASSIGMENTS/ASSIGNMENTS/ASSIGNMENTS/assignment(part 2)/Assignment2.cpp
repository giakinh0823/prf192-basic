//THAYCACAC
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define PENSION 0.05
#define HEALTH_INSURANCE 0.01

struct personal{
	int code;
	char name[30];
	double income;
	double pension;
	double health;
	double dependant;
	double gift;
	double total;
	double tax;
}personal_list[100];

void inputname(int i){
	printf("Enter name: ");
	fflush(stdin);
	gets(personal_list[i].name);
}
double inputIncome(int i){
	do{
		printf("Income for the current month (in thousand VND): ");
		scanf("%lf",&personal_list[i].income);
	}while(personal_list[i].income<0);
	return personal_list[i].income;
}
double inputPension(int i){
	char check;
	do{
		printf("Pension contributions (5%%) y/n? ");
		fflush(stdin);
		check = getchar();
		if(check!='y'&&check!='n')
			printf("Invalid input, try again.\n");
	}while(check!='y'&&check!='n');
	switch(check){
		case 'y': personal_list[i].pension = PENSION*personal_list[i].income; break;
		case 'n': personal_list[i].pension = 0; break;
	}
	return personal_list[i].pension;
}
double inputHealth(int i){
	char check;
	do{
		printf("Health insurance (1%%) y/n? ");
		fflush(stdin);
		check = getchar();
		if(check!='y'&&check!='n')
			printf("Invalid input, try again.\n");
	}while(check!='y'&&check!='n');
	switch(check){
		case 'y': personal_list[i].health = HEALTH_INSURANCE*personal_list[i].income; break;
		case 'n': personal_list[i].health = 0; break;
	}
	return personal_list[i].health;
}
double inputDependants(int i){
	int numDependant;
	do{
		printf("Number of dependants < 18 years old: ");
		scanf("%d",&numDependant);
		if(numDependant < 0)
			printf("Invalid input, try again.\n");
	}while(numDependant<0);
	personal_list[i].dependant=1600.0*numDependant;
	return personal_list[i].dependant;
}
double inputGift(int i){
	do{
		printf("Gift of charity: ");
		scanf("%lf",&personal_list[i].gift);
	}while(personal_list[i].gift<0);
	return personal_list[i].gift;
}
void caculate(int i){
	int personal=4000;
	personal_list[i].total=personal+personal_list[i].pension+personal_list[i].health+personal_list[i].dependant+personal_list[i].gift;
	if(personal_list[i].total<=5000)	personal_list[i].tax=personal_list[i].total*0.05;
	else if(personal_list[i].total>5000 && personal_list[i].total<=10000) personal_list[i].tax=personal_list[i].total*0.1;
	else if(personal_list[i].total>10000 && personal_list[i].total<=20000) personal_list[i].tax=personal_list[i].total*0.15;
	else if(personal_list[i].total>20000 && personal_list[i].total<=30000) personal_list[i].tax=personal_list[i].total*0.2;
	else if(personal_list[i].total>30000 && personal_list[i].total<=50000) personal_list[i].tax=personal_list[i].total*0.25;
	else if(personal_list[i].total>50000 && personal_list[i].total<=80000) personal_list[i].tax=personal_list[i].total*0.3;
	else personal_list[i].tax=personal_list[i].total*0.35;
	return ;
}
void input(int &i){
	int check;
	do{
		printf("\nEnter personal information: \n");
		printf("Enter code (0 to stop): ");
		fflush(stdin);
		scanf("%d",&personal_list[i].code);
		if(personal_list[i].code==0) break;
		inputname(i);
		inputIncome(i);
		inputPension(i);
		inputHealth(i);
		inputDependants(i);
		inputGift(i);
		caculate(i);
		++i;
	}while(1);
}

void display(int i){
	printf("Code    Name    Income  Allow   Pens   Ins   Charity    Depend   Taxable   Tax   Net\n");
	printf("-------------------------------------------------------------------------------------\n");
	for(int j=0; j<=i-1; j++){
		printf("%-5d %-10s %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf\n",
			personal_list[j].code,
			personal_list[j].name, 
			personal_list[j].income, 
			4000.0, 
			personal_list[j].pension, 
			personal_list[j].health, 
			personal_list[j].gift, 
			personal_list[j].dependant,
			personal_list[j].income-personal_list[j].total,
			personal_list[j].total, 
			personal_list[j].income-personal_list[j].tax);
	}
}
void search(int i){
	int check;
	printf("Enter code to be searched: ");
	scanf("%d",&check);
	for(int j=0; j<=i-1; j++){
		if(check==personal_list[j].code){
		printf("Code    Name    Income  Allow   Pens   Ins   Charity    Depend   Taxable   Tax   Net\n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("%-5d %-10s %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf\n",
			personal_list[j].code,
			personal_list[j].name, 
			personal_list[j].income, 
			4000.0, 
			personal_list[j].pension, 
			personal_list[j].health, 
			personal_list[j].gift, 
			personal_list[j].dependant,
			personal_list[j].income-personal_list[j].total,
			personal_list[j].total, 
			personal_list[j].income-personal_list[j].tax);
		}
	}
}
int main(){
	int i=0,selection;
	do{
		printf("Choose one of the following options:\n");
		printf("1. Enter a list of employees\n");
		printf("2. Display tax information\n");
		printf("3. Search an employee by code\n");
		printf("0. Exit\n");
		printf("Your selection (0-> 2): ");
		scanf("%d", &selection);
		switch(selection){
			case 1: input(i); break;
			case 2: display(i); break;
			case 3: search(i); break;
			case 0: return 0;
		}
	}while(selection!=0);
}
