#include <stdio.h>
#include <conio.h>

int top=-1;
int MAXSIZE=100;
int stack[100];

int isEmpty(){ //kiem tra stack co rong ko
	if(top==-1){
		return 1;
	}else return 0;
}

int isFull(){ //kiem tra stack co full khong
	if(top==MAXSIZE){
		return 1;
	} else return 0;
}

int push(int data){  //them phan tu vao stack
	if(!isFull()){
		top++;
		stack[top]=data;
	}else return printf("Stack full");
}

int pop(){ //Lay phan tu ra khoi stack
	int data;
	if(!isEmpty()){
		data=stack[top];
		top=top-1;
		return data;
	}else return printf("Stack null\n");
}

void popall(){ // lay tat ca phan tu ra khoi stack
	while(!isEmpty()){
		int data=pop();
		printf("%d ",data);
	}	
}

int main(){
	push(17);
	push(23);
	push(03);
	push(16);
	popall();
	getch();
	return 0;
}
