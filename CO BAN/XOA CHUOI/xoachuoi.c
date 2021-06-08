#include <stdio.h>
#include <string.h>

void xoa(char *s,int vt,int n){
	strcpy(s+vt,s+vt+n);
	puts(s);
}



int main(){
	char a[255];
	int n,vt;
	printf("Nhap xau a: ");gets(a);
	printf("Nhap vi tri can xoa: ");scanf("%d",&vt);
	printf("Nhap so luong ky tu can xoa: ");scanf("%d",&n);
	xoa(a,vt,n);
	return 0;
}
