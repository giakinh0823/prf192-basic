#include <stdio.h>
#include <string.h>

// readfile
// c=fgetc(fp)
// fgets(s,10,fp);
// 	while(fscanf(fp,"[^\n]%*c",str) != EOF)
// int feof(file) diem cuoi cua file

int main(){
	FILE *fp=NULL;
	char str[61];
	fp=fopen("C:\\Users\\DELL\\Desktop\\CAC DANG BAI TAP TRONG C\\CO BAN\\READ FILE EOF\\spring.txt","r");
	if(fp!=NULL){
		while(fscanf(fp,"%60[^\n]%*c",str) != EOF){
			printf("%s\n",strrev(str));
		}
		rewind(fp); //doc lai tu dau file
		printf("Read again \n");
		while(fscanf(fp,"%60[^\n]%*c",str) != EOF){ 
			printf("%s\n",str);
		}
		fclose(fp);
	} else {
		printf("Failed to open file\n");
	}
	return 0;
}
