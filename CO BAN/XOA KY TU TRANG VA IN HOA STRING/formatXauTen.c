#include <stdio.h>
#include <string.h>

int main(){
	char s[255];
	printf("Nhap xau: "); gets(s);
	int i;
	int n=strlen(s);
	while(s[0]==32){
		for(i=0;i<n-1;i++){
			s[i]=s[i+1];
		}
		s[n-1]='\0';
		n=n-1;
	}
	printf("%d",n);
	while(s[n-1]==32){
		n=n-1;
		s[n]='\0';
	}
	i=0;
	while(i<strlen(s)){
		int j=i;
		while(s[j]==32 && s[j+1]==32){
			int k;
			for(k=j;k<strlen(s)-1;k++){
				s[k]=s[k+1];
			}
			s[strlen(s)-1]='\0';
		}
		i++;
	}
	
	s[0]=s[0]-32;
	i=1;
	while(i<strlen(s)){
		if(s[i-1]==32) s[i]=s[i]-32; 
		i++;
	}
	printf("Xau sao khi chuyen doi: %s",s);
	return 0;
}
