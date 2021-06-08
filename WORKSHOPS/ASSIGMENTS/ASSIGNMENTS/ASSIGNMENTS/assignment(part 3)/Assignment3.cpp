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
	double pension;
	double health;
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
//HAM DOC FILE
void readFile(FILE *&fileIn, int &i){
	fileIn = fopen("TAX.txt","r");
	char check[10];
	if(!fileIn){
		printf("Khong tim thay file\n");
		getch();	return;
	}
	else{
		printf("Done!!!");
		i=-1;
		do{
			i++;
			fscanf(fileIn,"%d",&personal_list[i].code);
			fscanf(fileIn,"%s",&personal_list[i].name);
			fscanf(fileIn,"%lf",&personal_list[i].income);
			fscanf(fileIn,"%lf",&personal_list[i].allow);
			fscanf(fileIn,"%lf",&personal_list[i].pension);
			fscanf(fileIn,"%lf",&personal_list[i].health);
			fscanf(fileIn,"%lf",&personal_list[i].gift);
			fscanf(fileIn,"%lf",&personal_list[i].dependant);
			fscanf(fileIn,"%lf",&personal_list[i].taxable);
			fscanf(fileIn,"%lf",&personal_list[i].tax);
			fscanf(fileIn,"%lf",&personal_list[i].allow);
		}while(personal_list[i].code!=NULL);
	}
	fclose(fileIn);
}
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
		case 'y': personal_list[i].pension = PENSION*personal_list[i].income; break;
		case 'n': personal_list[i].pension = 0; break;
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
		case 'y': personal_list[i].health = HEALTH_INSURANCE*personal_list[i].income; break;
		case 'n': personal_list[i].health = 0; break;
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
	personal_list[i].dependant=1600.0*numDependant;
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
	printf("Code    Name    Income  Allow   Pens   Ins   Charity   Depend  Taxable  Tax    Net\n");
	printf("-------------------------------------------------------------------------------------\n");
	for(int j=0; j<=i-1; j++){
		printf("%.3d    %-7s %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf\n",
			personal_list[j].code,
			personal_list[j].name, 
			personal_list[j].income, 
			4000.0, 
			personal_list[j].pension, 
			personal_list[j].health, 
			personal_list[j].gift, 
			personal_list[j].dependant,
			personal_list[j].taxable,
			personal_list[j].tax, 
			personal_list[j].income-personal_list[j].tax);
	}
}
//HAM SEARCH
void search(int i){
	int check;
	printf("Enter code to be searched: ");
	scanf("%d",&check);
	for(int j=0; j<=i-1; j++){
		if(check==personal_list[j].code){
		printf("Code    Name    Income  Allow   Pens   Ins   Charity   Depend  Taxable  Tax    Net\n");
		printf("-------------------------------------------------------------------------------------\n");
		printf("%.3d    %-7s %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf\n",
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
//HAM KIEM TRA DA SAP XEP CHUA
void checkSort(int i){
	bool check=true;
	for(int j=0; j<i-1; j++){
			if(personal_list[j].code>personal_list[j+1].code){
				check=false; 
				break;
			}
	}
	if(check==true)		printf("Data on the file is sorted");
	if(check==false)	printf("Data on the file is not sorted");
}
//HAM XOA MOT NGUOI
void deletePersonal(int &i){
	int check;
	printf("Enter code to be searched: ");
	scanf("%d",&check);
	for(int j=0; j<i; j++){
		if(check==personal_list[j].code){
			for(int k=j; k<i; k++)
				swapPersonal(personal_list[k],personal_list[k+1]);
		}
	}
	printf("Delete done!!!");
	i--;
}
//HAM LUU DU LIEU
void saveData(FILE *&fileIn, int i){
	fileIn = fopen("TAX.txt","w");
	for(int j=0; j<=i-1; j++){
		fprintf(fileIn,"%.3d    %-7s %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf %-7.0lf\n",
			personal_list[j].code,
			personal_list[j].name, 
			personal_list[j].income, 
			4000.0, 
			personal_list[j].pension, 
			personal_list[j].health, 
			personal_list[j].gift, 
			personal_list[j].dependant,
			personal_list[j].income-personal_list[j].total,
			personal_list[j].tax, 
			personal_list[j].income-personal_list[j].tax);
	}
	fclose(fileIn);
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
			case 1: readFile(fileIn,i); getch(); system("cls"); break;
			case 2: input(i); system("cls"); break;
			case 3: display(i); getch(); system("cls"); break;
			case 4: search(i); getch();system("cls"); break;
			case 5: sortCode(i); getch(); system("cls"); break;
			case 6: sortCode(i); getch(); system("cls"); break;
			case 7: checkSort(i); getch(); system("cls"); break;
			case 8: deletePersonal(i); getch(); system("cls"); break;
			case 9: saveData(fileIn, i); getch(); system("cls"); break;
			case 0: return 0;
		}
	}while(selection!=0);
}
