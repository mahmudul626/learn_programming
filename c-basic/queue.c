#include <stdio.h>

#define SIZE 5
int queue[SIZE];
int front = 0;
int rear = 0;

void enqueue(int data) {
	queue[rear++] = data;
}

int dequeue() {
	int data = queue[front++];
	return data;
}

int main() {
	enqueue(10);
	enqueue(20);
	enqueue(30);

	printf("1st de : %d\n", dequeue());
	printf("2nd de : %d\n", dequeue());

	return 0;
}
