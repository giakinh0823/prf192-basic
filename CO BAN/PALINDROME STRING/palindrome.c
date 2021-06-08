#include <stdio.h>
#include <string.h>

int palin(char s[]){
	char str[255];
	strcpy(str,s); //tuong duong voi phep gan
	//dung strrev no se bien doi str va tu dong gan 
	if(strcmp(s,strrev(str))==0) { //strcpm la so sanh, neu =0 thi bang nhau
		return 1;
	}else return 0;
}

int main(){
	char s[255];
	printf("Nhap xau: ");scanf("%s",s);
	printf("Xau nay co phai la Palindrome khong: ");
	if(palin(s)==0){
		printf("Khong");
	}else{
		printf("Co");
	}
	return 0;
}
