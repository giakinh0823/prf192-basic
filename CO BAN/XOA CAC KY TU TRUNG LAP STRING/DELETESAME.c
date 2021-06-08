#include <stdio.h>
#include <string.h>


int main(){
	char s[255];
	printf("Nhap xau: ");scanf("%s",s);
	int i;
	for(i=0;i<strlen(s)-1;i++){
		if(s[i]!=' '){
			printf("%c",s[i]); 
			int j;
			for(j=i+1;j<strlen(s);j++){
				if(s[i]==s[j]) s[j]=' ';
			}
		}
	}
	return 0;
}
