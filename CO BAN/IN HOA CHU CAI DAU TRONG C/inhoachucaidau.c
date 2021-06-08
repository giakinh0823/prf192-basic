#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void chuhoadau(char *s){
	int i;
	
	s[0]=toupper(s[0]);
	while(strstr(s, " ")!=NULL){
		s=strstr(s," ")+1; //o day no se tang len 1 tu ha gia kinh -> gia kinh -> kinh
		s[0]=toupper(s[0]);
	}
	
//	puts(s); // giong voi printf
}

int main () {
	system("cls");
	char s[100];
	
	printf("Nhap s: "); gets(s);
	printf("\nOUTPUT:\n");
	
	chuhoadau(s);
	
	printf("%s",s);
	printf("\n");
	system("pause");
	return 0;
}
