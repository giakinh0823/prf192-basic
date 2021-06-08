#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void chuxenke(char *s){
	int n=strlen(s);	
	int i;
	for(i=0;i<n;i++){
		if(i%2==0){
			if((int)s[i]>=97 && (int)s[i]<=122){
				s[i]=(char)((int)s[i]-32);
			}
		}
		if(i%2!=0){
			if((int)s[i]>=65 && (int)s[i]<=90){
				s[i]=(char)((int)s[i]+32);
			}	
		}
	}
//	puts(s); // giong voi printf
}

int main () {
	system("cls");
	char s[100];
	
	printf("Nhap s: "); gets(s);
	printf("\nOUTPUT:\n");
	
	chuxenke(s);
	
	printf("%s",s);
	printf("\n");
	system("pause");
	return 0;
}
