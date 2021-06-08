#include <stdio.h>
#include <string.h>

struct Book {
  char code[20];
  char title[100];
  int quantity;
  double price;
  double value;
};

typedef struct Book book;

int clean_stdin(){
  while(getchar()!='\n'){}
  return 1;
}

void menu(int *choose){
  printf("Select options: \n");
  printf("1. Enter the list of books");
  printf("\n2. Display the list of books");
  printf("\n3. Sort the list of books");
  printf("\n4. Load data from title");
  printf("\n5. Find the <first> max price");
  printf("\n6. Find by code and edit the book");
  printf("\n7. Find by code and delete the book");
  printf("\n0. Exit\n");
  char c;
  do{
    printf("Your selection (0 -> 7): ");
  }while(((scanf("%d%c",choose,&c) != 2 || c != '\n') && clean_stdin()) || (*choose < 0 || *choose > 7));
}

int checkCode(book *p,int k){
  if(k==0) return 0;
  int i;
  for(i=0;i<k;i++){
    if(strcmp((p+i)->code,(p+k)->code)==0){
      return 1;
    }
  }
  return 0;
}

void input(book *p,int *n){
  char c;
  do{
    printf("Enter number of books: ");
  }while(((scanf("%d%c",n,&c) !=2 || c != '\n') && clean_stdin()) || *n<0);
  int i;
  for(i=0; i<*n;i++){
    printf("Book %d\n",i+1);
    do{
      printf("Enter code: ");  scanf("%s", (p+i)->code);
      if(checkCode(p, i)==1){
        printf("The code %s already exitsts, please reenter!\n", (p+i)->code);
      }
    }while(checkCode(p,i)==1);
    getchar();
    printf("Enter title: "); scanf("%[^\n]", (p+i)->title);
    printf("Enter quantity: "); scanf("%d", &(p+i)->quantity);
    printf("Enter price: "); scanf("%lf", &(p+i)->price);
    (p+i)->value = (p+i)->quantity * (p+i)->price;
  }
}

void display(book *p, int *n){
  int i;
  double totalPrice=0;
  printf("%-12s %-18s %-13s %-13s %-13s\n","code","title","Quantity","Price","Value");
  for(i=0;i<*n;i++){
    printf("%-12s %-18s %-13d %-13.1lf %-13.1lf\n",(p+i)->code, (p+i)->title, (p+i)->quantity, (p+i)->price, (p+i)->value);
    totalPrice += (p+i)->value;
  }
  printf("%60s %0.1lf\n","Total price:",totalPrice);
}

void sort(book *p, int *n){
  int i;
  for(i=0; i<*n-1;i++){
    int j;
    for(j=i+1; j<*n;j++){
      if(strcmp((p+i)->code,(p+j)->code)>0){
        book z;
        z=*(p+i);
        *(p+i) = *(p+j);
        *(p+j) = z;
      }
    }
  }
}

int maxPrice(book *p, int *n){
  if(*n==0) return 0;
  int i;
  double max=(p)->price;
  int vt=0;
  for(i=1; i<*n;i++){
    if((p+i)->price>max){
      vt=i;
      max = (p+i)->price;
    }
  }
  return vt+1;
}

int findCode(book *p,int n, char code[]){
  int i;
  for(i=0;i<n;i++){
    if(strcmp((p+i)->code, code)==0){
      return i;
    }
  }
  return -1;
}

int findCodeEdit(book *p,int n, char code[], int vt){
  int i;
  for(i=0;i<n;i++){
    if(strcmp((p+i)->code, code)==0 && i!=vt){
      return i;
    }
  }
  return -1;
} 

void editBook(book *p, int *n){
  char code[20];
  printf("Enter code: ");scanf("%s", code);
  int k=findCode(p,*n, code);
  if(k!=-1){
     printf("Book %d\n",k+1);
    do{
      printf("Enter code: ");  scanf("%s", (p+k)->code);
      if(findCodeEdit(p, *n, (p+k)->code, k)!=-1){
        printf("The code %s already exitsts, please reenter!\n", (p+k)->code);
      }
    }while(findCodeEdit(p, *n, (p+k)->code, k)!=-1);
    getchar();
    printf("Enter title: "); scanf("%[^\n]", (p+k)->title);
    printf("Enter quantity: "); scanf("%d", &(p+k)->quantity);
    printf("Enter price: "); scanf("%lf", &(p+k)->price);
    (p+k)->value = (p+k)->quantity * (p+k)->price;
  }else{
    printf("Can not found code\n");
  };
}

void deleteBook(book *p, int *n){
  char code[20];
  printf("Enter code: ");scanf("%s", code);
  int k=findCode(p,*n, code);
  if(k!=-1){
    int i;
    for(i=k;i<*n-1;i++){
      *(p+i)=*(p+i+1);
    }
    *n=*n-1;
  }else{
    printf("Can not found code\n");
  }
}

void writeFile(FILE *fptr,book *p, int *n){
  int i;
  double totalPrice=0;
  fprintf(fptr, "%-12s | %-18s | %-13s | %-13s | %-13s\n","code","title","Quantity","Price","Value");
  for(i=0;i<*n;i++){
    fprintf(fptr,"%-12s | %-18s | %-13d | %-13.1lf | %-13.1lf\n",(p+i)->code, (p+i)->title, (p+i)->quantity, (p+i)->price, (p+i)->value);
    totalPrice += (p+i)->value;
  }
  fprintf(fptr, "%65s %0.1lf\n","Total price:", totalPrice);
}


int main() {
  FILE *fptr;
  int n=0;
  book a[10000];
  while(1){
    int choose;
    menu(&choose);
    switch(choose){
      case 1:
      input(&a[0], &n);
      break;
      case 2:
      display(&a[0], &n);
      break;
      case 3:
      sort(&a[0], &n);
      display(&a[0], &n);
      break;
      case 4:
      fptr = fopen("E:\\book.txt","w");
      writeFile(fptr,&a[0], &n);
      fclose(fptr);
      break;
      case 5:
      printf("The max price point is: %d\n",maxPrice(&a[0], &n));
      break;
      case 6:
      editBook(&a[0], &n);
      break;
      case 7:
      deleteBook(&a[0], &n);
      break;
      case 0:
      break;
    }
    if(choose == 0) break;
  }
  return 0;
}
