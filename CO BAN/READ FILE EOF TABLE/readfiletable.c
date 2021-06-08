#include <stdio.h>
#include <string.h>

// readfile
// c=fgetc(fp)
// fgets(s,10,fp);
// 	while(fscanf(fp,"[^\n]%*c",str) != EOF)
// int feof(file) diem cuoi cua file

int main(){
	FILE *fp=NULL;
	char str[255];
	int n;
	fp=fopen("C:\\Users\\DELL\\Desktop\\CAC DANG BAI TAP TRONG C\\CO BAN\\READ FILE EOF TABLE\\spring.txt","r");
	if(fp!=NULL){
		printf("\tWinter Items\n");
		printf("----------------------------\n");
		while(fscanf(fp,"%d %[^\n]%*c",&n,str) != EOF){
			printf("%6d %-20s\n",n,str);
		}
		fclose(fp);
	} else {
		printf("Failed to open file\n");
	}
	return 0;
}
