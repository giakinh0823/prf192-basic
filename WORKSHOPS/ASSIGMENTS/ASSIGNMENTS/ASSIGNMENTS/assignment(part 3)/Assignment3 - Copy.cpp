//THAYCACAC
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define PENSION 0.05
#define HEALTH_INSURANCE 0.01
//KHAI BAO STRUCT
struct personal{
	int code;
	char name[30];
	double income;
	char pension;
	char health;
	double dependant;
	double gift;
	double total;
	double tax;
	double allow;
	double taxable;
}personal_list[100];
//KHAI BAO CAC HAM
void readFile();
void input();
void inputName();
double inputIncome();
double inputPension();
double inputHealth();
double inputDependants();
double inputGift();
void caculate();

//HAM NHAP TEN
void inputName(int i){
	printf("Enter name: ");
	fflush(stdin);
	gets(personal_list[i].name);
}
//HAM NHAP INCOME
double inputIncome(int i){
	do{
		printf("Income for the current month (in thousand VND): ");
		scanf("%lf",&personal_list[i].income);
	}while(personal_list[i].income<0);
	return personal_list[i].income;
}
//HAM CHECK PENSION
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
		case 'y': personal_list[i].pension = 'y'; break;
		case 'n': personal_list[i].pension = 'n'; break;
	}
	return personal_list[i].pension;
}
//HAM CHECK HEALTH
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
		case 'y': personal_list[i].health = 'y'; break;
		case 'n': personal_list[i].health = 'n'; break;
	}
	return personal_list[i].health;
}
//HAM NHAP DEPENDENT
double inputDependants(int i){
	int numDependant;
	do{
		printf("Number of dependants < 18 years old: ");
		scanf("%d",&numDependant);
		if(numDependant < 0)
			printf("Invalid input, try again.\n");
	}while(numDependant<0);
	personal_list[i].dependant=numDependant;
	return personal_list[i].dependant;
}
//HAM NHAP GIFT
double inputGift(int i){
	fflush(stdin);
	do{
		printf("Gift of charity: ");
		scanf("%lf",&personal_list[i].gift);
	}while(personal_list[i].gift<0);
	return personal_list[i].gift;
}
//HAM TINH TAX
void caculate(int i){
	int personal=4000;
	personal_list[i].total=personal+personal_list[i].pension+personal_list[i].health+personal_list[i].dependant+personal_list[i].gift;
	personal_list[i].taxable=personal_list[i].income-personal_list[i].total;
	double tax_surplus;
	if(personal_list[i].taxable<=5000){
		personal_list[i].tax=personal_list[i].taxable*0.05;
	}	
	else if(personal_list[i].taxable>5000 && personal_list[i].taxable<=10000){
		tax_surplus=personal_list[i].taxable-5000;
		personal_list[i].tax=5000*0.05+tax_surplus*0.1;
	}
	else if(personal_list[i].taxable>10000 && personal_list[i].taxable<=20000){
		tax_surplus=personal_list[i].taxable-10000;
		personal_list[i].tax=5000*0.05+5000*0.1+tax_surplus*0.15;
	}
	else if(personal_list[i].taxable>20000 && personal_list[i].taxable<=30000){
		tax_surplus=personal_list[i].taxable-20000;
		personal_list[i].tax=5000*0.05+5000*0.1+10000*0.15+tax_surplus*0.2;
	}
	else if(personal_list[i].taxable>30000 && personal_list[i].taxable<=50000){
		tax_surplus=personal_list[i].taxable-30000;
		personal_list[i].tax=5000*0.05+5000*0.1+10000*0.15+10000*0.2+tax_surplus*0.25;
	}
	else if(personal_list[i].taxable>50000 && personal_list[i].taxable<=80000){
		tax_surplus=personal_list[i].taxable-50000;
		personal_list[i].tax=5000*0.05+5000*0.1+10000*0.15+10000*0.2+20000*0.25+tax_surplus*0.3;
	}
	else {
		tax_surplus=personal_list[i].taxable-80000;
		personal_list[i].tax=5000*0.05+5000*0.1+10000*0.15+10000*0.2+20000*0.25+30000*0.3+tax_surplus*0.35;
	}
	return ;
}
//HAM NHAP
void input(int &i){
	int check;
	bool checkCode;
	do{
		printf("\nEnter personal information: \n");
		do{
			checkCode=true;
			printf("Enter code (0 to stop): "); fflush(stdin);
			scanf("%d",&personal_list[i].code);
//Kiem tra code da co chua
			for(int j=0; j<i; j++){
				if(personal_list[i].code==personal_list[j].code){
					printf("Code is exits!!!\n");
					checkCode=false;
				}
			}
		}while(checkCode==false);
		if(personal_list[i].code==0) break;
		inputName(i);
		inputIncome(i);
		inputPension(i);
		inputHealth(i);
		inputDependants(i);
		inputGift(i);
		caculate(i);
		i++;
	}while(1);
}
//HAM HIEN THI
void display(int i){
	printf("Code    Name    Income  Pens   Ins   Depend    Charity  Taxable  Tax\n");
	printf("Code    Name    Income  Pens   Ins   Depend    Charity  Taxable  Tax\n");
	printf("-------------------------------------------------------------------------------------\n");
	for(int j=0; j<=i-1; j++){
		printf("%.3d    %-7s %-7.0lf %d %s %-7.0lf %-7.0lf %-7.0lf %-7.0lf\n",
			personal_list[j].code,
			personal_list[j].name, 
			personal_list[j].income, 
			personal_list[j].pension, 
			personal_list[j].health, 
			personal_list[j].dependant,
			personal_list[j].gift, 
			personal_list[j].taxable,
			personal_list[j].tax);
	}
}

//HAM SAP XEP THEO CODE
//Ham swap hai nuoi
void swapPersonal(personal &a, personal &b){
	personal temp;
	temp=a;	a=b; 	b=temp;
}
void sortCode(int i){
	printf("Sort in inceasing order by code done!!!");
	for(int j=0; j<i; j++){
		for(int k=j; k<i; k++){
			if(personal_list[j].code>personal_list[k].code)
				swapPersonal(personal_list[j],personal_list[k]);
		}
	}
}

//HAM MAIN
int main(){
	int i=0,selection;
	FILE *fileIn;
	do{
		printf("Choose one of the following options:\n");
		printf("1. Enter name of a file to store data\n");
		printf("2. Enter a list of employees\n");
		printf("3. Display tax information\n");
		printf("4. Search an employee by code\n");
		printf("5. Sort in inceasing order by code\n");
		printf("6. Sort directly on file by bubble sort\n");
		printf("7. Check if data on the file is sorted or not\n");
		printf("8. Delete an employee by code\n");
		printf("9. Save data\n");
		printf("0. Exit\n");
		printf("Your selection (0 -> 8): ");
		scanf("%d", &selection);
		switch(selection){
			case 1:  break;
			case 2: input(i); system("cls"); break;
			case 3: display(i); getch(); system("cls"); break;
			case 4:  break;
			case 5: sortCode(i); getch(); system("cls"); break;
			case 6: sortCode(i); getch(); system("cls"); break;
			case 7: break;
			case 8:  break;
			case 9:  break;
			case 0: return 0;
		}
	}while(selection!=0);
}
