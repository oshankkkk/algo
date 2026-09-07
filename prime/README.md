## BigO-fyi
### What is bigO
Measurement of how your programs memory and computation grows repect to the growth of the input size.

### how to look for bigO
- Look for loops
- Drop constant
- Always the worst case

```
smallest ---> largest 
O(1)(constant time)->O(logn)->O(n)(linear)->O(nlogn)->O(n^2)->O(2^n)->O(n!)

The log is with base 2 btw
```

> Quick sort is nlogn, binary search is logn, If you half the input in each step it can be either logN or NlogN

## Data structures and algorithms
- There is no hierachy/order on where to start learning these, or what came before what. we can mix and match stuff even, like you can have data structs build on top of other data structs and same for algorithms, just need to know they exists.
### Arrays

> Almost all data structs are build on this.

Arrays are just a continues stream of bytes and we take the count and multiply it by the size per elemant to get the total size (yk like malloc in c) and then we can traverse if with the offset we use as the index. When you write something to a array, you overwrite the value in that offset/index, same with deleting you set that byte to 0. Array operations are contant time O(1) cause we just take the array+bytes per elemant*offset/index, we get the value. No need to traverse the array. It does not grow with input.

### linear search
Its just searching one by one

```c
#include <stdbool.h>
int linear_search(int haystack[],int size,int needle){
	for(int x=0;x<size;x++){
		if (haystack[x]==needle){
			return true;
		}	
	}	
return false;
}
```

### Binary search
We need to sort the data for this. After sorting we can maybe function in a fixed length and check if the value if greater or smaller and jump based on that to find the value. In binary search we keep dividing N by 2 until we get 1, so thats where O(logN) comes from.

In binary search we can make hight inclusive or exclusive. You have to pick which one to do before you code or else your gonna get off by 1 errors.

```c
int binary_search(int arr[],int size,int find){
	int lo=0;
	int hi=size-1;

	while (lo<=hi){

		int mid=lo+(hi-lo)/2;
		int val=arr[mid];

		if (val>find){
			hi=mid-1;
		}else if(val<find){
			lo=mid+1;	
		}else{
			return val;
		}
	}
	return -1;
}
```

```c
int binary_search(int arr[],int size,int find){
	int lo=0;
	int hi=size;

	while (lo<hi){

		int mid=lo+(hi-lo)/2;
		int val=arr[mid];

		if (val>find){
			hi=mid;
		}else if(val<find){
			lo=mid+1;	
		}else{
			return val;
		}
	}
	return -1;
}
```

//need to do the crystal question 

Binary search is start from the middle, check for left or right, go there, then again check for left or right and continue until you either land of the place you want to or end of the map. This can be numbers or anything, at the end its just picking left or right.

### Bubble sort
Its  O(n^2). The whole algo is super simple, just swap each elemant with the elemant next to it based on the condtion and keep doing that for all the elemants. 
```c
int bubble_sort(int arr[],int size){
	for (int x=0; x<size;x++) {
		for (int j=0; j<size-x-1;j++) {
			if(arr[j]>arr[j+1]){
			int temp=arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=temp;
			}	
		}
	}	
	return 0;
}
```
### Linked lists
Signly linked lists only has a reference to the node after it, while a doubly linked list has both a prev and a next node pointer. Its the most basic complex looking data structure that other complex ones like graphs are built on.

getting/deletion/preappend/append head/tail - contant time
getting/deletion middle - constant time + traversal complexity(prolly linear O(n))

```c
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
    //tail->next=head;	<--triggers a inifinte loop
    traverseList(head);
    return 0;
}
```

> traversing a linked list is not recommended, theres better data structures for that

### Queue and Stacks
Pushing and poping from a queue is contant time, cause we dont go over anything. First In First Out. 
First in last out, stack of pancakes yk.
##### Queue

```c
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
```

##### Stack

```c

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
```

//implement a aync request queue

### Arrays vs linkedlists
Memory is allocated before hand in arrays which increase performace while draining memory, while in linkedlists its doesnt pre allocate stuff, yk it assigns pointers to other elemants as it grows. making it weight less on memory, but also less perfomace when it comes to access something from the middle, so you gotta walk it and thats linear. So if you want to get stuff from anywhere fast, gotta use a array. Arrays are O(n) for read and write stuff cause you just work with indexes. For a aync request queue, array can we used but its not performant when the usage increases. Basically you just need to understand when to use what.

### Arraylist

