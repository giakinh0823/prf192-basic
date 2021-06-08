#include <stdio.h>

//Gia tri cua a: 10
//Gia tri cua a: 11
//Gia tri cua a: 12
//Gia tri cua a: 13
//Gia tri cua a: 14
//Gia tri cua a: 16
//Gia tri cua a: 17
//Gia tri cua a: 18
//Gia tri cua a: 19  

int main () {
    int a = 10;
 
    TEST:do {
        if( a == 15) {
            // quay ve do khi a = 15 (bo qua lenh print)
            a = a + 1;
            goto TEST;
        }
        printf("Gia tri cua a: %d\n", a);
        a++;
    } while( a < 20 );
  
   return 0;
}
