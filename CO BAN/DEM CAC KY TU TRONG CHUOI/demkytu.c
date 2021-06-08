#include <stdio.h>
#include <string.h>

void demkytu(char* s){
	int a[100],n=0,i;
	for(i=0;i<(int)strlen(s);i++){
		int d=1,j,k;
		for(j=i+1;j<(int)strlen(s);j++)
			if(s[i]==s[j]){ 
				d++;
				for(k=j;k<(int)strlen(s);k++)
					s[k]=s[k+1];
				j--;
			}
		a[n++]=d;
	}
	for(i=0;i<(int)strlen(s);i++)
		printf("%c = %d\n",s[i],a[i]);
}


int main(){
	char a[255];
	printf("Nhap xau a: "); gets(a);
	demkytu(a);
	return 0;
}
