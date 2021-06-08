#include <stdio.h>
#include <string.h>

void xoatu(char* s,char* c){
	while(strstr(s,c)!=NULL){
	int t=strlen(s)-strlen(strstr(s,c)),d=strlen(c);
	if((s[t-1]==' ' && s[t+d]==' ') || (s[t-1]==' '&& t+d==strlen(s)))//truonghoptugiuavatucuoi
		strcpy(s+t-1,s+t+d);//s+t-1lakhoangtrang
    if(s[t+d]==' ' && t==0)//truonghopxoatudautien
    	strcpy(s,s+t+d+1);
	}
	puts(s);
}

int main(){
	char a[255],b[255];
	printf("Nhap xau a: ");gets(a);
	printf("Nhap tu can xoa: ");gets(b);
	xoatu(a,b);
	return 0;
}
