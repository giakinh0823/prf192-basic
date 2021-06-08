#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void noichuoi(char *a,char *b){
	strcat(a,b);
	puts(a);
}

int main () {
	system("cls");
	char a[100],b[100];
	printf("Nhap a: "); gets(a);
	printf("Nhap b: "); gets(b);
	printf("\nOUTPUT:\n");
	
	noichuoi(a,b);
	
	printf("\n");
	system("pause");
	return 0;
}
