#include <stdio.h>
#include <string.h>

void chen(char*s,char*d,int vt){
	char c[255];
	strcpy(c,s+vt);
	strcpy(s+vt,d);
	strcat(s,c);
	puts(s);
}

int main(){
	char a[255],b[255];
	int vt;
	printf("Nhap xau a: ");gets(a);
	printf("Nhap xau can chen: ");gets(b);
	printf("Nhap vi tri can xoa: ");scanf("%d",&vt);
	
	chen(a,b,vt);
	return 0;
}
