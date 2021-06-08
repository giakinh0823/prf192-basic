#include <stdio.h>

void sort(double *a, int *n){
  int i;
  for(i=0;i<*n-1;i++){
    int j;
    for(j=i+1;j<*n;j++){
      if(*(a+i)>*(a+j)){
        double z;
        z=*(a+i);
        *(a+i)=*(a+j);
        *(a+j)=z;
      }
    }
  }
}

int clean_stdin() {
    while (getchar() != '\n') {}
    return 1;
}
 
void menu(int *choose){
  printf("Select options: \n");
  printf("1. Enter the list of float numbers");
  printf("\n2. Sort the list increasing order");
  printf("\n3. Search value x in the list");
  printf("\n4. Display the list");
  printf("\n0. Exit\n");
  char c;
  do{
    printf("Your selection (0 -> 4): "); 
  }while(((scanf("%d%c", choose, &c) !=2 || c !='\n') && clean_stdin()) ||(*choose<0 || *choose>4));
}


void input(double *a, int *n){
  char c;
  do{
    printf("Input size of array n = "); 
  }while(((scanf("%d%c", n, &c) !=2 || c !='\n') && clean_stdin()) || *n<=0); 
  printf("Enter %d float numbers: ",*n);
  int i;
  for(i=0; i<*n; i++){
    scanf("%lf", (a+i));
  }
}

void display(double *a, int *n){
  int i;
  for(i=0;i<*n;i++){
    printf("%0.1lf ", *(a+i));
  }
  printf("\n");
}

void search(double *a, int *n){
  double x;
  printf("Enter the value x to be searched: "); scanf("%lf",&x);
  int b[1000];
  int i,m=0;
  for(i=0; i<*n;i++){
    if(*(a+i)==x){
      b[m]=i;
      m++;
    }
  }
  printf("Found %0.1lf at position: ",x);
  for(i=0;i<m;i++){
    printf("%d ",b[i]);
  }
  if(m==0) printf("Not found");
  printf("\n");
}

int main() {
  int n=0;
  while(1){
    int choose=-1;
    menu(&choose);
    double a[10000];
    switch(choose){
      case 1:
        input(&a[0], &n);
        break;
      ;
      case 2:
        printf("Before sorting: ");
        display(&a[0], &n);
        sort(&a[0], &n);
        printf("After sorting: ");
        display(&a[0], &n);
        break;
      ;
      case 3:
        search(&a[0], &n);
        break;
      ;
      case 4:
        display(&a[0], &n);
        break;
      ;
      case 0:
      break;
      ;
    }
    if(choose==0) break;
  }
  return 0;
}
