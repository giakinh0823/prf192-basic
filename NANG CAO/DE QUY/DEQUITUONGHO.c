#include <stdio.h>
#include <stdbool.h>
//de quy tuong ho la de quy truc tiep chinh no, ma goi lai ham khac, trong ham khac goi lai no

bool isEven(int n);
bool isOdd(int n);

bool isEven(int n){
	if(n==0){
		return true;
	}else return isOdd(n-1);

}

bool isOdd(int n){
	return !isEven(n);
}


int main(){
	if(isEven(2)){
		printf("true");
	}else printf("false");
	return 0;
}
