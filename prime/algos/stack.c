#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
char *data;
struct Node *next;
}Node;
typedef struct{
Node *head;
}Stack;

void push(Stack *stack,char *data){
	Node *node=malloc(sizeof(Node));
	node->data=data;
	node->next=stack->head;
	stack->head=node;
};

Node* pop(Stack *stack){
	if(stack->head==NULL){
		printf("empty stack");
		return NULL;
	}
	Node *node=stack->head;
	stack->head=node->next;
	return node;
};

int main(){
	Stack q={0};
	push(&q, "helo");
	push(&q, "world");
	Node *node=pop(&q);
	printf("%s",node->data);
	free(node);	
	return 0;
}
