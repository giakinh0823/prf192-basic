#include <stdio.h>
#include <string.h>
#include <conio.h>

char s[200] = "";

char *readNumber(int n){
	int units, tens, hundreds;
    char a[10][5]= {"", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    s[0] = 0;
    units = n % 10; 
    n /= 10;
    tens = n % 10; 
    hundreds = n / 10;
        
    if (hundreds > 0)
    {
        strcat(s, a[hundreds]);
        strcat(s, " tram ");
    }
    
    if (tens > 0)
    {
        if (tens == 1)
            strcat(s, "muoi "); 
        else
        {
            strcat(s, a[tens]);
            strcat(s, " muoi ");
        }
    }

    if (units > 0)
    {
        if (tens == 0 && hundreds != 0)
            strcat(s, "le ");
        if (units == 1)
            strcat(s, "mot");
        else if (units == 5 && (tens != 0 || hundreds != 0))
            strcat(s, "lam");
        else if (units == 5 && (tens = 0 || hundreds != 0))
            strcat(s, "nam");
        else
            strcat(s, a[units]);
    }
    return s;
}


int main()
{
    long int n;
    int millions, billions,thousands, units;
    char chuoi[250];
    printf("Enter n : "); scanf("%ld", &n);
    printf("So %ld doc la : ", n);
    if (n == 0)
        printf("Khong");
    else
    {
        if(n<0)
        {
            printf("Am ");
            n=0-n;
        }
        
		units = n % 1000;
        n /= 1000;
        thousands = n % 1000;
        n /= 1000;
        millions = n % 1000;
        billions = n / 1000;
        chuoi[0] = 0;
        if (billions > 0)
            printf("%s ty ", readNumber(billions));
        if (millions > 0)
            printf("%s trieu ", readNumber(millions));
        if (thousands > 0)
            printf("%s ngan ", readNumber(thousands));
        if (units > 0)
            printf("%s", readNumber(units));
    }
    return 0;
}




