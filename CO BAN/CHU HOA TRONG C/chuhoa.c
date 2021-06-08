#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void chuhoa(char *s){
	int i;
	
//	for(i=0;i<strlen(s);i++){
//		s[i]=toupper(s[i]);
//	}
	
	for(i=0;i<strlen(s);i++){
		if(s[i]>=97 && s[i]<=122){
			s[i]=s[i]-32;
		}
	}
//	puts(s); // giong voi printf
}

int main () {
	system("cls");
	char s[100];
	
	printf("Nhap s: "); gets(s);
	printf("\nOUTPUT:\n");
	
	chuhoa(s);
	
	printf("%s",s);
	printf("\n");
	system("pause");
	return 0;
}
