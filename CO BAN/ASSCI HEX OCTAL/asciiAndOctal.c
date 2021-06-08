#include <stdio.h>
#include <math.h>

 
int main(){
	system("cls"); 
    char a;
    printf("Nhap a: ");
    scanf("%c", &a);
    printf("Ascii: %d",a);
    printf("\nOct = %0.4o\n", a);
    printf("Hex = %0.4x\n",a);
	system("pause");
	return 0;
}
