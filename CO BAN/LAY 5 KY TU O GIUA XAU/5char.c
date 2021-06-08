#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  char s[20];
  do{
  	scanf("%s",s);
  }while((strlen(s)>=20 || strlen(s)<=5));
  
  
  
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  int d=0;
  int k=strlen(s)/2 - 2;
  while(d!=5){
	printf("%c",s[k]);
	k++;
	d++;
  }
  







  
  
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
