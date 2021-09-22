#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct TopNode {
	int data;
	struct TopNode* link;
}TN;

typedef struct StackTop {
	int count;
	TN* top;
}TOP;

void push_node(int data, TN* link, TN** phead, TN* p);
void pop_node(TN** phead, TN* p, TN* removed);
void top_node(TN* head);
void display(TN* head);
void isempty(TN* head);
void isfull(TN* head);
void isoverflowed(TN* head);

int main()
{

	srand(time(NULL));

	TN* stack = NULL;

	int i, j, l;

	printf("pushed elements : ");
	for (i = 0; i < SIZE - 1; i++) {
		int k = rand() % 9; 
		push_node(k, NULL, &stack, NULL);
	}
	printf("\n\n");

	isfull(stack); 

	display(stack);
	printf("\n");

	l = rand() % 9; 

	push_node(l, NULL, &stack, NULL);
	printf("\n");

	isoverflowed(stack); 

	top_node(stack);
	printf("\n");

	for (j = 0; j < SIZE; j++) 
		pop_node(&stack, NULL, stack);

	display(stack);
	printf("\n");

	isempty(stack); 

	return 0;

}

void isempty(TN* head)
{
	if (head == NULL)
		printf("stack is empty\n\n");
}

void isfull(TN* head)
{
	if (head == (TN*)SIZE - 1)
		printf("stack is full\n\n");
}

void isoverflowed(TN* head)
{
	if (head > (TN*)SIZE - 1)
		printf("stack is overflowed\n\n");
}

void push_node(int data, TN* link, TN** phead, TN* p)
{
	TN* new_node;

	new_node = (TN*)malloc(sizeof(TN));
	if (new_node == NULL) printf("error\n\n");
	new_node->data = data;
	new_node->link = link;
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
	printf("%d ", new_node->data);
}

void pop_node(TN** phead, TN* p, TN* removed)
{
	printf("poped element : ");
	if (p == NULL) {
		*phead = removed->link;
	}
	else {
		p->link = removed->link;
	}
	printf("%d", removed->data);
	free(removed);
	printf("\n");
}

void top_node(TN* top)
{
	TN* p = top;
	printf("top element : ");
	if (p != NULL)
		printf("%d", p->data);
	printf("\n");
}

void display(TN* head)
{
	TN* p = head;
	printf("total elements : ");
	while (p != NULL) {
		printf("%d", p->data);
		p = p->link;
		if (p != NULL)
			printf(", ");
	}
	printf("\n");
}
