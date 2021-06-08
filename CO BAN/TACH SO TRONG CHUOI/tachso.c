#include <stdio.h>
#include <string.h>

void tachso(char*s){
	int a[100],j=0,i,t;
	for(i=0;i<strlen(s);i++)
		if(s[i]>='0'&&s[i]<='9'){ 
			a[j]=s[i];//kitukieucharchuyenthanhkieu
			j++;
			for(t=i;t<strlen(s);t++) s[t]=s[t+1];
			i--;
		}
	puts(s);
	for(i=0;i<j;i++) printf("%c",a[i]);
}

int main(){
	char a[255];
	printf("Nhap a: ");gets(a);
	tachso(a);
}
