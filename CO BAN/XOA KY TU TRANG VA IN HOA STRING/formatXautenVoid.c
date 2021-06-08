#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void xoakitu(char s[]){
	int i;
	while(s[0]==32){
		for(i=0;i<strlen(s)-1;i++){
			s[i]=s[i+1];
		}
		s[strlen(s)-1]='\0';
	}
	while(s[strlen(s)-1]==32){
		s[strlen(s)]='\0';
	}
	i=0;
	while(i<strlen(s)){
		int j=i;
		while(s[j]==32 && s[j+1]==32){
			int k;
			for(k=j;k<strlen(s)-1;k++){
				s[k]=s[k+1];
			}
			s[strlen(s)-1]='\0';
		}
		i++;
	}
	
	s[0]=s[0]-32;
	i=1;
	while(i<strlen(s)){
		if(s[i-1]==32) s[i]=s[i]-32; 
		i++;
	}
}
int main () {
	system("cls");
	char s[100];
	gets(s);
	
	printf("\nOUTPUT:\n");
		
	xoakitu(s);
	
	printf("%s",s);
	printf("\n");
	system("pause");
	return 0;
}
