#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void xoakhoangtrang(char *s){
	char *c=strstr(s,"  ");
	int i;
	while(c!=NULL){
		int t=strlen(s)-strlen(c);
		for(i=t;i<strlen(s);i++){
			s[i]=s[i+1];
		}
		c = strstr(s,"  ");
	}
	if(s[0]==' ') {
		s=s+1;
	}
	
	int n=strlen(s);
	if(s[n-1]==' ') s[n-1]='\0';
	printf("%s",s);
}

int main () {
	system("cls");
	char s[100];
	printf("Nhap s: "); gets(s);
	
	printf("\nOUTPUT:\n");
	
	xoakhoangtrang(s);
	
	printf("\n");
	system("pause");
	return 0;
}
