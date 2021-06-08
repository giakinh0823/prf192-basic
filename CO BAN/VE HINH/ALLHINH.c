#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

//Ve hinh tam giac deu
void hinh1(){	
    int n;
	do{
		printf("Nhap chieu cao "); scanf("%d",&n);
	}while(n<=0);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n-i;j++) printf(" ");
		for(j=1;j<=i;j++) printf(" *");
	    printf("\n");
    }
} 

//Ve hinh tam giac can
void hinh2(){	
    int n;
    do{
		printf("Nhap chieu cao "); scanf("%d",&n);
	}while(n<=0);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n-i;j++)
			printf("   ");
		for(j=1;j<=2*i-1;j++)
			printf(" * ");
		printf("\n");
	}
}

//Ve hinh chu nhat
void hinh3(){
	int a,b;
	do{
		printf("Nhap chieu dai: "); scanf("%d", &a);			
		printf("Nhap chieu rong: "); scanf("%d", &b);			
		if(a<=b)
			printf("Dai phai lon hon rong, moi ban nhap lai a va b \n ");
	} while(a<=b||a<0||b<0);
	int i,f,g;
	for(f = 1; f <= a; f++) 
		printf(" * ");  
		printf("\n");
	for(i=1; i<=b-2; i++){	
		printf(" * ");	
		for (g=1; g <= a-2; g++)
			printf("   ");
			printf(" * \n");
		}
		for(f = 1; f <= a; f++)
			printf(" * ");
	printf("\n");
}

//Ve hinh tam giac vuong can dac
void hinh4(){
	int n;
	do{
		printf("Nhap n: "); scanf("%d",&n);
	} while(n<=0);
	int i,j;
	for(i = 1; i <= n; i++){
     	for(j = 1; j <= i; j++)
        	printf("* ");
 		printf("\n");
	}	
}

//ve hinh tam giac vuong can rong
void hinh5(){
	int n;
	do{
		printf("Nhap n: "); scanf("%d",&n);
	} while(n<=0);
	int i,j;
	for(i=0;i<n-1;i++){
   		for(j=0;j<n;j++){
		   	if ((j==0)||(j==i)) 
			   printf("* "); 
			else printf("  ");
        }
      	printf("\n");
    }
 	for(i=0;i<n;i++) printf("* ");
    printf("\n");
}

//ve hinh thoi
void hinh6(){
	int n, j, i;
	do{
		printf("Nhap n: "); scanf("%d",&n);
	} while(n<=0);
	n=(n/2)*2+1;
    for(i=1; i<=n; i++){
        for (j=1; j<=n; j++){
            if (j-1>=n/2-i+1&&i+n/2>=j&&i<=j+n/2&&j-n/2<=n-i+1) 
            	printf("*");
            else printf(" ");
    	}
    	printf("\n");
    }
}

//ve hinh trai tim
void hinh7(){
	int size;
	printf("Nhap size: "); scanf("%d",&size);
	int a, b;
    for (a = size/2; a <= size; a = a+2)
    {
        for (b = 1; b < size-a; b = b+2)        
            printf(" ");
         for (b = 1; b <= a; b++)
            printf("*");
           for (b = 1; b <= size-a; b++)
            printf(" ");
                 for (b = 1; b <= a; b++)
            printf("*");
 
        printf("\n");
    }
  
    for (a = size; a >= 0; a--)
    {        for (b = a; b < size; b++)
            printf(" ");
         for (b = 1; b <= ((a * 2) - 1); b++)
            printf("*");
        printf("\n");  
    }
}

//ve hinh thang can
void hinh8(){
	int n;
	do{
		printf("Nhap n: "); scanf("%d",&n);
	} while(n<=0);
	int i,j,k;
	for(i=0;i<=n;i++){
		for(k=0;k<n-i;k++) printf(" ");
        for(k=0;k<=2*i+1;k++)
        printf("*");
        printf("\n");
    }
}

int main(){
	printf("\tXin chao");
	printf("\n1: Ve hinh tam giac deu");
	printf("\n2: Ve hinh tam giac can");
	printf("\n3: Ve hinh chu nhat rong");
	printf("\n4: Ve hinh tam giac vuong can dac");
	printf("\n5: Ve hinh tam giac vuong can rong");
	printf("\n6: Ve hinh thoi");
	printf("\n7: Ve hinh trai tim");
	printf("\n8: Ve hinh thang can");
	printf("\n0: Thoat");
	int luachon;
	printf("\nBan chon: ");
	scanf("%c", &luachon);
	switch(luachon)
	{
	case '0': 
		printf("\nXin chào và hen gap lai\n"); 
    	break;
	case '1':
		hinh1() ; break;
		
	case '2':
		hinh2() ; break;
	
	case '3':
		hinh3() ; break;
		
	case '4':
		hinh4() ; break;
		
	case '5':
		hinh5() ; break;
		
	case '6':
		hinh6() ; break;
		
	case '7':
		hinh7() ; break;
		
	case '8':
		hinh8() ; break;
	} 
	return 0;
}
