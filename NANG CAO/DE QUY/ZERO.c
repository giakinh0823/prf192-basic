#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int a[]={1,2,3,4,5,6,7,8,9};
int dau[3]={1,2,3};
int b[8];


int kt(char xau[]){
	int s=0,d=0;
	int len=strlen(xau),k=0;
	while(k<len){
		if((xau[k]==*"-") || (xau[k]==*"+")){
			d=k;
			k++;
		};
		int l=0;
		while((xau[k]>=*"1") && (xau[k]<=*"9") && (k<len)){
			char ji=xau[k];
			int num=atoi(&ji);
			l=l*10+num;
			k++;
		}
		if(xau[d]==*"-"){
			s=s-l;
		}else{
			s=s+l;
		}
	}
//	printf("%d\n",s);
//	s=0;
	if (s!=0){
		return 1;
	}else {
		printf("%d=",s);
		return 0;
	}
}


void ghi(char st[]){
	if(kt(st)==0)
	printf("%s\n",st);
}

void try(int i){
	int j;
	for(j=0;j<3;j++){
		b[i]=dau[j];
		if(i==7){
			char str[30]="1";
			int k;
			for(k=0;k<8;k++){
				if(b[k]==1){
					char buffer[30];
					itoa (a[k+1],buffer,10);
					strcat(str, buffer);
				}else if(b[k]==2){
					strcat(str,"-");
					char buffer[30];
					itoa (a[k+1],buffer,10);
					strcat(str, buffer);
				}else{	
					strcat(str,"+");
					char buffer[30];
					itoa (a[k+1],buffer,10);
					strcat(str, buffer);
				}
			}
			ghi( str);
			//printf("%s\n",str);
		}else try(i+1);
	}
}


int main(){
	try(0);
	return 0;
}
