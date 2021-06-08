#include <stdio.h>
#include <stdbool.h>

int queue[100]; // mang hang doi
int MAXSIZE=100; // kick thuoc hang doi
int front=0;  // danh dau vi tri dau tien cua hang
int rear=-1; // danh dau vi tri cuoi cua hang


bool isFull(){ //kiem tra hang doi co full ko
	return rear == MAXSIZE - 1 ? true : false; 
}

bool isEmpty(){ //kiem tra hang doi co rong ko
	return (front < 0 || front > rear) ? true : false;
}

void enQueue(int data){ //them phan tu vao hang
	if(isFull()){
		printf("Queue full");
	} 
	rear++;
	queue[rear]=data;
}

void deQueue(){ //xoa phan tu khoi hang
	if(isEmpty()){
		printf("Queue null");
	}
	queue[front]=0;
	front++;
}

int peek(){ //lay phan tu dau hang
	return queue[front];
}

void peekAll(){ //lay tat ra cac phan tu khoi hang
	while(!isEmpty()){
		int data=peek();
		deQueue();
		printf("%d ",data);
	}
}

int main(){
	enQueue(5);
	enQueue(9);
	enQueue(7);
	enQueue(8);
	peekAll();
	return 0;
}
