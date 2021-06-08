#include <stdio.h>
#include <string.h>

int vitri(char *a,char *b){
	int d=-1;
	if(strstr(a,b)!=NULL){
		d=strlen(a)-strlen(strstr(a,b)); 
	}
	return d;
}

int main(){
	char a[255],b[255];
	printf("Nhap a: "); gets(a);
	printf("Nhap b: "); gets(b);
	printf("Vi tri b trong xau a: %d",vitri(a,b));
	return 0;
}

