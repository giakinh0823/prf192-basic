#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int vitri(char *a,char *b){
	int kq,d=0;
	if(strstr(a,b)!=NULL){
		kq=strlen(a)-strlen(strstr(a,b));
		int i;
		for(i=kq;i>=0;i--){
			if(a[i]==' '){
				d++;
			}
		}
		return d+1;
	}
	return -1;
}

int main () {
	system("cls");
	char a[100],b[100];
	printf("Nhap a: "); gets(a);
	printf("Nhap b: "); gets(b);
	printf("\nOUTPUT:\n");
	
	printf("vi tri: %d",vitri(a,b));
	printf("\n");
	system("pause");
	return 0;
}
