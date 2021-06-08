#include <stdio.h>
#include <string.h>

int demtu(char *a,char *b){
	int d=0;
	while(strstr(a,b)!=NULL){
		d++;
		a=strstr(a,b)+1;
	}
	return d;
}

int main(){
	char a[255],b[255];
	printf("Nhap a: "); gets(a);
	printf("Nhap b: "); gets(b);
	printf("So tu: %d",demtu(a,b));
	return 0;
}

