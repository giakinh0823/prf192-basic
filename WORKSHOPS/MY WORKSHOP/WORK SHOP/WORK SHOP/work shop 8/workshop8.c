#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * f = fopen("data1.txt","rt");
  double a[100]; 
  int n,i, k; 
  double t;
  i = 0;
  while(1) {
   k = fscanf(f,"%lf",&t);
   if(k==-1) break;
   a[i++] = t;
  }
  fclose(f);
  n = i;
  printf("n = %d\n",n);
  for(i=0;i<n;i++) printf("%.1f  ", a[i]);
  printf("\n");   
  double s = 0; double mean;
  for(i=0;i<n;i++) s += a[i];
  printf("\n");   
  mean = s/n;
  printf("mean = %.2f\n",mean);
  //system("pause");
  return 0;  

}


