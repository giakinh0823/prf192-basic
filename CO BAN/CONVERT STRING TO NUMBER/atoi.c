#include <stdio.h>
#include <string.h>

int check(char s[]){
	int i;
	for(i=0;i<strlen(s);i++){
       	if(s[i]<48 || s[i]>57) return 0; 
    }
	return 1;
}

int cvSToN(char s[]){
	return atoi(s); //atof la double
}

int main(){
	char s[255];
	printf("Nhap xau: ");scanf("%s",s);
	if(check(s)==1){
		printf("Xau sao khi chuyen doi: %d",cvSToN(s));
	}else{
		printf("-1");
	}
	return 0;
}
