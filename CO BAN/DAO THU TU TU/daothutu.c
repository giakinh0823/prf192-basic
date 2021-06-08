#include <stdio.h>
#include <string.h>

void daothutu(char *s){
	char c[255];
	c[0]='\0';
	int i;
	for(i=strlen(s)-1;i>=0;i--){
		if(s[i]==' '){
			strcat(strcat(c,s+i+1)," ");
			s[i]='\0';
		}
	}
	strcat(c,s);
	puts(c);
}


int main(){
	char a[255];
	printf("Nhap a: ");gets(a);
	daothutu(a);
}
