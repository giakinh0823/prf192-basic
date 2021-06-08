#include <stdio.h>

struct SanPham {
	int ma;
	char ten[150];
	double gia;
} a[100];
int n;


void nhapMang(){
	int i;
	for(i=0;i<n;i++){
		printf("San pham: %d\n",i+1);
		printf("Ma: ");
		scanf("%d",&a[i].ma);
		printf("Ten sp: ");
		scanf("%s",&a[i].ten);
		printf("Gia sp: ");
		scanf("%lf", &a[i].gia);
	}
}

void xuatMang(){
	int i;
	printf("San pham sau khi nhap: \n");
	for(i=0;i<n;i++){
		printf("%-10d  %-10s  %-10.2lf\n",a[i].ma,a[i].ten,a[i].gia);
	}
	printf("\n");
}



void qickSort(int c, int d){
	int i=c,j=d-1, x=a[(c+d-1)/2].gia;
	while(i<=j){
		while(a[i].gia<x) i++;
		while (a[j].gia>x) j--;
		if(i<=j){
			struct SanPham temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
			j--;
		}
	};
	if(i<d-1) qickSort(i,d-1);
	if(j>c) qickSort(c,j);
}

int timkiem(struct SanPham a[], int n, double x){
	int left = 0, right = n-1,mid;
	do{
		mid=(left+right)/2;
		if(x==a[mid].gia){
			return mid; 
		}else if(x>a[mid].gia){
			left=mid+1;
		}else{
			right=mid-1;
		}
	}while(left<=right);
	return printf("Null");
}

int main(){
	printf("Nhap n: "); scanf("%d",&n);
	nhapMang();
	xuatMang();
	qickSort(0,n);
	xuatMang();
	double x;
	printf("Nhap x: "); scanf("%lf",x);
	int kq=timkiem(a,n,x);
	printf("San phan ban can tim o vi tri: %d",kq+1);
	getch();
	return 0;
}
