//THAYCACAC
#include <stdio.h>
#include <string.h>
struct bookstore{
	char code[7];
	char title[30];
	int quantity;
	double price;
}book[100];
void inputCode(int i){
	printf("Enter code: ");
	fflush(stdin);
	gets(book[i].code);
	for(int j=1;j<i;j++){
		if(strcmp(book[i].code,book[j].code)==0){
			printf("The code %s already exists, please reenter!\n",book[i].code);
			inputCode(i);
		}
	}
}
void inputBook(int &n){
	printf("Enter number of books: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("Book %d:\n",i);
		inputCode(i);
		printf("Enter title: ");
		fflush(stdin);
		gets(book[i].title);
		printf("Enter quantity: ");
		scanf("%d",&book[i].quantity);
		printf("Enter price: ");
		scanf("%lf",&book[i].price);
	}
}
void displayBook(int n){
	double total=0;
	printf("Code	Title	Quantity    Price	Value\n");
	for(int i=1;i<=n;i++){
		printf("%s %9s %9d %9.1lf %10.1lf\n",book[i].code,book[i].title,book[i].quantity,book[i].price,book[i].price*book[i].quantity);
		total+=book[i].quantity*book[i].price;
	}
	printf("\t\t\tTotal value:  %.1lf\n",total);
		
}
void swap(bookstore &a, bookstore &b){
	bookstore temp;
	temp=a;
	a=b;
	b=temp;	
}
void sortBook(int n){
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--)
			if(strcmp(book[j].code,book[j-1].code)<0)
				swap(book[j],book[j-1]);
	}
}
int main(){
	int check=-1,n;
	do{
		printf("Select options:");
		printf("\n1. Enter the list of books");
		printf("\n2. Display the list of books");
		printf("\n3. Sort the list of books by code");
		printf("\n0. Exit");
		printf("\nYour selection (0 -> 3): ");
		scanf("%d",&check);
		switch(check){
			case 1: inputBook(n);break;
			case 2: displayBook(n);break;
			case 3: sortBook(n);break;
			case 0: return 0;
		}
	}while(check!=0);
}                                                                                                                                                                                                            
