#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	char *data;
}Node;
Node* newNode(char *data){
	Node* newnode=malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
void traverseList(Node *head){
	Node *temp=head;
	while(1){
		printf("%s ",temp->data);
		if(temp->next==NULL){
			break;
		}
		temp=temp->next;
	}
}
int main(){
	Node *head=newNode("hello");
	Node *sec=newNode("Oshan,");
	head->next=sec;	
	Node *third=newNode("how");
	sec->next=third;	
	Node *tail=newNode("are you?");
	third->next=tail;	
//	tail->next=head;	
	traverseList(head);
	return 0;
}
