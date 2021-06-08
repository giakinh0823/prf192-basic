#include <stdio.h>
#include <string.h>

void timtu(char *a,char *b){
	char *t=strstr(a,b);
	puts(t);
}

int main(){
	char a[255],b[255];
	printf("Nhap a: ");gets(a);
	printf("Nhap b: ");gets(b);
	timtu(a,b);
}
