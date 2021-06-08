#include <stdio.h>

// nhap vao 1 mang
// sap xep 
// tim min, max
// a[i]=123 => 321    m=0 b[m] m++
// in ra cac so nt trong mang
// in ra so hoan hao
// in ra giai thua cua cac phan tu tron mang vidu: a[1]=5 inra 5!=? dequy
// tin so fibonaci thu a[i] vidu a[i]=3 => in ra 2 dequi 
// kiem tra mang doi xung 7/ 1 7
//in ra cac so doi xxung trong mang


void sodoixung(int a[], int n){
	int i;
	for (i=0; i<n; i++){
		int b=0;
		int k=a[i];
		while(k>0){
			b=b*10+k%10;
			k=k/10;
		}
		if(b==a[i]){printf("%d ",a[i]);}
	}
}
void ktramangdoixung(int a[], int n){
	int i=0;
	int kt=1;
	while(a[i]==a[(n-1)-i]){
		if(a[i]!=a[(n-1)-i]){
			kt=0;
			break;
		}
		i++;
	}
	if(kt==1){ 
		printf("doixungne");
	}else printf("deophaidoixung");
}
	
int fibonaci(int f){
	if(f<=2) return 1;
	return fibonaci(f-1)+fibonaci(f-2);
}
long giaithua(int m){
		if(m==1) return 1;
		else return m*giaithua(m-1);	
}
void nhapmang(int a[], int n){
	int i;
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);	
	}
}
void sohoanhao(int a[], int n){
	int i;
	for(i=0; i<n; i++){
		int j=1, d=0;
		int k=a[i];
		while(j<k){
			if(k%j==0){  
				d=d+j; 
			}
			j++;
		}
		if(d==a[i]){
			printf("%d ", d);
		}
	}
	printf("\n");
}
void sont(int a[], int n){
	int i, j=2;
	for(i=0; i<n; i++){
		int kt=1;
		while(j<a[i]/2)	{
			if(a[i]%j==0){
				kt=0;
				break;
			}
			j++;
		}
		if(kt==1) printf("%d ", a[i]);
	}
	printf("\n");
}
void daoso(int a[], int n){
	int i;
	for(i=0; i<n; i++){
		int d=0,doi=0;
		while (a[i]>0){
			d = d*10+ a[i]%10;
			a[i]=a[i]/10; 
		}	
		a[i]=d;
	}
	
}
void minmax(int a[],int n){
	int min=a[0], max=a[0];
	int i;
	for(i=0; i<n; i++){
		if(max<a[i]){
			max=a[i];
		}
		if(min>a[i]){
			min=a[i];
		}
	} printf("%d %d \n", max, min);
}
void sapxep(int a[], int n){
	int i,j;
	int x;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[i]>a[j]){
				x=a[i];
				a[i]=a[j];
				a[j]=x;
			} 
		}
	}
}
void xuatmang(int a[], int n){
	int i;
	for( i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(){
	int n, a[100];
	scanf("%d", &n);
	nhapmang(a,n);
	xuatmang(a,n);
	sapxep(a,n);
	printf("sap xep\n");
	xuatmang(a,n);
	printf("min max: \n");
	minmax(a,n);
	printf("dao so\n");
	daoso(a,n);
	xuatmang(a,n);
	printf("snt: \n");
	sont(a,n);
	printf("shh: \n");
	sohoanhao(a,n);
	printf("giaithua: \n");
	int i;
	for(i=0; i<n; i++){	
//		printf("%ld ",giaithua(a[i]));
//		printf("fibonaci =", fibonaci(a[i]));
	}
	printf("\nfibonaci: \n");
	for(i=0; i<n; i++){	
//		printf("%d ", fibonaci(a[i]));
	}
	printf("\nktramangdoixung: \n");
	ktramangdoixung(a,n);
	printf("\nsodoixung: \n");
	sodoixung(a,n);
	
	return 0;	
}
