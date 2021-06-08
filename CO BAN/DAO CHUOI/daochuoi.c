#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void daochuoi(char *s){
	strrev(s);
//	puts(s); // giong voi printf
}

int main () {
	system("cls");
	char s[100];
	
	printf("Nhap s: "); gets(s);
	printf("\nOUTPUT:\n");
	
	daochuoi(s);
	
	printf("%s",s);
	printf("\n");
	system("pause");
	return 0;
}
