#include <stdio.h>
#include <string.h>

int main(void) {
  char p[255], o[255];
  printf("nhap string o: "); scanf("%s",o);
  printf("Nhap string p: "); scanf("%s",p);
  int i;
  for(i=0;i<strlen(o);i++){
    int j; int k=0, check=1; 
    for(j=i;j<i+strlen(p);j++){
   // printf("%c = %c\n",o[j],p[k]);
      if(o[j]!=p[k]){ 
        check=0;
        break;
      }
      k++;
    }
   //printf("%d",check);
    if(check==1){
      for(j=i+strlen(p)-1;j>=i;j--){
        printf("%c",o[j]);
      }
      i=i+strlen(p)-1;
    }else{
       printf("%c",o[i]);
    }
  }
  return 0;
}
