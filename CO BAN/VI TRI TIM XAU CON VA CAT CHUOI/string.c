#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tìm vi tri cua chuoi con

int findsubstr(const char *str, char *sub){
  const char *p = str;
  int len = strlen(sub);
  while(*p){
    if (strlen(p) >= len){
      if (strncmp(p, sub, strlen(sub)) == 0){
        return (p - str);
      }
    }else{
      break;
    }
    p++;
  }
  return -1;
}


//cat chuoi
char *substr(char *s, int start, int end)
{
	char *p=(char*)malloc(255*sizeof(char));
	int indext = 0,i=0;
	for (i = start; i <= end; i++)
	{
		p[indext] = s[i];
		indext++;
	}
	p[indext] = '\0';

	return p;
}

int main(void) {
  char p[255], o[255];
  printf("nhap string o: "); scanf("%s",o);
  printf("Nhap string p: "); scanf("%s",p);
  printf("%d\n",findsubstr(o,p));
  printf("%s",substr(o,0,3));
  return 0;
}
