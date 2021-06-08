#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void chuthuong(char *s){
	int i;
	for(i=0;i<strlen(s);i++){
		if(s[i]>=65 && s[i]<=90){
			s[i]=s[i]+32;
		}
	}
//	puts(s); // giong voi printf
}

int main () {
	system("cls");
	char s[100];
	
	printf("Nhap s: "); gets(s);
	printf("\nOUTPUT:\n");
	
	chuthuong(s);
	
	printf("%s",s);
	printf("\n");
	system("pause");
	return 0;
}
