#include <stdio.h> 
#include <stdlib.h>

int main()
{
    int i,n, *x;
    printf("nhap n: "); scanf("%d",&n);
    x=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("a[%d]= ",i+1);
        scanf("%d",(x+i));
    }
    for(i=0;i<n;i++)
    printf("%d ",*(x+i));
    
    return 0;
}
