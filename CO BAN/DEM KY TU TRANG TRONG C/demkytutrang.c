#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int demkitu(char *s){
	int d = 0;
	while(strstr(s," ") != NULL){
		d++;
		s = strstr(s," ") + 1;
	}
	return d;
}
int main () {
	system("cls");
	char s[100];
	gets(s);
	
	printf("\nOUTPUT:\n");
		
	printf("%d", demkitu(s));
	
	printf("\n");
	system("pause");
	return 0;
}
