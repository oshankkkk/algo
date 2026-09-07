#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	char *data;
}Node;

typedef struct{
Node *front;
Node *rear;
}Queue;

void enqueue(Queue *queue,char *data){
	Node *node=malloc(sizeof(Node));
	node->data=data;
	if (queue->front==NULL){
		queue->front=node;
		queue->rear=node;
	}else{
		queue->rear->next=node;
		queue->rear=node;
	}
};

Node* dequeue(Queue *queue){
	if(queue->front==NULL){
		printf("empty queue");
		return NULL;
	}
	Node *node=queue->front;
	queue->front=node->next;
	return node;
};

int main(){
	Queue q={0};
	enqueue(&q, "helo");
	enqueue(&q, "world");
	Node *node=dequeue(&q);
	printf("%s",node->data);
	free(node);	
	return 0;
}

