#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char data;
	struct Node* next;
}Node;

typedef struct {
	Node* front;
	Node* end;
}Queue;

void initQueue(Queue* list) {
	list->front = NULL;
	list->end = NULL;
}

void enqueue(Queue* list,char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (list->front == NULL && list->end == NULL) {
		list->front = newNode;
		list->end = newNode;
	}
	list->end->next = newNode;
	list->end = newNode;

}

void dequeue(Queue* list) {
	Node* temp = list->front;
	list->front = list->front->next;
	char result = temp->data;
	free(temp);
}

void printHelloQueue() {
	//arrange
	Queue s;

	initQueue(&s);

	enqueue(&s, 'h');
	enqueue(&s, 'e');
	enqueue(&s, 'l');
	enqueue(&s, 'l');
	enqueue(&s, 'o');


	return;
}
int main() {

	printHelloQueue();


	return 0;
}