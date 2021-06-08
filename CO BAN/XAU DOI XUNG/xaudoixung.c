#include <stdio.h>
#include <string.h>

int doixung(char *a){
	char t[255];
	strcpy(t,a);
	if(strcmp(a,strrev(t))==0) return 1;
	return 0;
}

int main(){
	char a[255],b[255];
	printf("Nhap a: ");gets(a);
	printf("Xau nay co doi xung khong: %d",doixung(a));
}
