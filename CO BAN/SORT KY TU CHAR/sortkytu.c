#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	char a[4][2];
	int i;
  	for(i=0;i<4;i++){
		scanf("%s",a[i]);  
	}
  
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  for(i=0;i<3;i++){
		int j;
		for(j=i+1;j<4;j++){
			if(strcmp(a[i],a[j])>0){
				char temp[2];
				strcpy(temp,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],temp);
			}
		}
	}
  for(i=0;i<4;i++){
  	printf("%s ",a[i]);
  }	







  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
