#include <stdio.h>
#include <string.h>

//ha gia kinh -> timten: kinh

void timten(char *a,char *b){
	int n=strlen(a);
	char *s;
	int i;
	for(i=n-1;i>0;i--){
		if(a[i]==' '){
			s=a+i+1;
			break;
		}
	}
	if(strcmp(s,b)==0){
		printf("%s",s);
	}else {
		printf("Ban nhap sai ten");
	}
}

int main(){
	char a[255],b[255];
	printf("Nhap a: "); gets(a);
	printf("Nhap b: "); gets(b);
	timten(a,b);
	return 0;
}

