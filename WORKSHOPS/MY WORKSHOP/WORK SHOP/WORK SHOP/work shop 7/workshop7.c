#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int clean_stdin() {
    while (getchar() != '\n') {}
    return 1;
}

void menu(int *choose){
  printf("Choose one of following options: \n");
  printf("1. Input a string");
  printf("\n2. Split a string into words");
  printf("\n3. Convert a string into proper form");
  printf("\n4. Remove redundant spaces");
  printf("\n5. Check vaild name");
  printf("\n0. Exit\n");
  char c;
  do{
    printf("Your selection (0 -> 5): "); 
  }while(((scanf("%d%c", choose, &c) !=2 || c !='\n') && clean_stdin()) ||(*choose<0 || *choose>5));
}

void input(char *str){
  printf("Input a string: "); scanf("%[^\n]",str);
}

void removeSpace(char *str){
  char *s=str;
  char *c=strstr(s,"  "); 
  while(c!=NULL){
    int t = strlen(s)-strlen(c); //tim vi tri xuat hien dau khoang trang
    int i;
    for(i=t;i<strlen(s);i++){ //xoa dau khoang trang do
      s[i]=s[i+1];
    }
    c=strstr(s,"  "); 
  }
  while(s[0]==' '){
    int i;
    for(i=0;i<strlen(s);i++){ //xoa dau khoang trang do
      s[i]=s[i+1];
    }
  }
  while(s[strlen(s)-1]==' '){
    s[strlen(s)-1]='\0';
  }
  str=s;
}

void split(char str[]){
  // char c[strlen(str)];
  // strcpy(c, str);
  char *c = (char*)malloc(strlen(str)*sizeof(char));
  c=str;
  removeSpace(c);
  char s[255][255];
  int i=0;
  int d=0;
  // strcpy(s[d]," ");
  while(strlen(c)>0){
    if(c[0]!=' '){
      strncat(s[d],c,1);
      int k;
      for(k=0;k<strlen(c)-1;k++){
        c[k]=c[k+1];
      }
      c[strlen(c)-1]='\0';
    }else{
      int k;
      for(k=0;k<strlen(c)-1;k++){
        c[k]=c[k+1];
      }
      c[strlen(c)-1]='\0';
      d++;
    }
  }
  d++;
  printf("The original string: %s",str);
  printf("\nNumber of words in the string: %d, they are\n",d);
  for(i=0; i<d;i++){
    printf("%s\n",s[i]);
  }
}

void properForm(char *str){
  char *c=str;
  if(c[0]>=97 && c[0]<=122){
    c[0]=c[0]-32;
  }
  int i=1;
  while(i<strlen(c)){
    if(c[i-1]==32 && (c[i]>=97 && c[i]<=122)){
      c[i]=c[i]-32;
    }
    i++;
  }
  str=c;
}

int checkValid(char *str){
  char *s=str;
  char *c=strstr(s," ");
  while(c!=NULL){
    int t = strlen(s)-strlen(c); //tim vi tri xuat hien dau khoang trang
    int i;
    for(i=t;i<strlen(s);i++){ //xoa dau khoang trang do
      s[i]=s[i+1];
    }
    c=strstr(s," "); 
  }
  int i=0;
  while(i<strlen(s)){
    if(s[i]<65 || s[i]>122) return 0;
    if(s[i]>90 && s[i]<97) return 0;
    i++;
  }
  return 1;
}

int main() {
  char str[255];
  char xau[255];
  while(1){
    int choose=-1;
    menu(&choose);
    double a[10000];
    switch(choose){
      case 1: 
      input(str);
      break;
      case 2:
      strcpy(xau,str);
      split(xau);  
      break;
      case 3:	
      printf("The original string: %s\n",str);
      removeSpace(str);
      properForm(str);
      printf("The proper form: %s\n",str);
      break;
      case 4: 
      removeSpace(str);
      printf("The clean form: %s\n",str);
      break;
      case 5:
      strcpy(xau,str);
      if(checkValid(xau)){
        printf("The string: %s is valid name\n",str);
      }else{
         printf("The string: %s is not valid name\n",str);
      }
      break;
      case 0:
      break;
    }
    if(choose==0) break;
  }
  return 0;
}
