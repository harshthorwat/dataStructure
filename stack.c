#include<stdio.h>
#include<stdlib.h>
struct Head* createStack();
struct Head* push(struct Head*);
struct Head* pop(struct Head*);
int traversal(struct Head*);
struct Node* stackTop(struct Head*);
struct Node* search(struct Head*);

typedef struct Node
{
	int data;
	struct Node* next;
}node;

typedef struct Head
{
	int count;
	struct Node* top;
}h;

struct Head* createstack(){
h* head=(h*)malloc(sizeof(h));
if (!head)
{
	printf("Memory Error\n");
	return 0;
}
head->count=0;
head->top=NULL;
return head;
}

struct Head* push(struct Head* head){
	node* new=(node*)malloc(sizeof(node));
	if (!new)
	{
		printf("Stack Overflow\n");
		return 0;
	}
	int data;
	printf("Enter data to be pushed\n");
	scanf("%d",&data);
	new->data=data;
	new->next=head->top;
	head->top=new;
	head->count++;
	return head;
}

struct Head* pop(struct Head* head){
	if (head->count==0)
	{
		printf("Stack Underflow(Empty Stack)\n");
		return 0;
	}
	node* tmp=(node*)malloc(sizeof(node));
	if (!tmp)
	{
		printf("Memory Error\n");
		return 0;
	}
	tmp=head->top;
	head->top=tmp->next;
	free(tmp);
	head->count--;
	return head;
}

int traversal(struct Head* head){
	if(head->count==0){
		printf("Stack is empty\n");
		return 0;
	}
	node* tmp=(node*)malloc(sizeof(node));
	if (!tmp)
	{
		printf("Memory Error\n");
		return 0;
	}
	tmp=head->top;
	while(tmp){
		printf("%d\t",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
	return 0;
}

struct Node* stackTop(struct Head* head){
	if (head->count==0)
	{
		printf("Stack is Empty\n");
		return 0;
	}
	printf("Stack top is %d\n",head->top->data);
	return head->top;
}

struct Node* search(struct Head* h){
	if (!h->top)
	{
		printf("Can not search from empty stack\n");
		return 0;
	}
	node* n=(node*)malloc(sizeof(node));
	if (!n)
	{
		printf("Memory Error\n");
		return 0;
	}
	int d;
	printf("Enter data to be searched\n");
	scanf("%d",&d);
	n=h->top;
	while(n){
		if (n->data==d)
		{
			printf("Data found %d\n",n->data);
			return n;
		}
		n=n->next;
	}
	printf("Data not Found\n");
}

int main(){
h* head=(h*)malloc(sizeof(h));
if (!head)
{
	printf("Out of memory\n");
	return 0;
}
head=createstack();
while(1){
int choice;
printf("**********************************************\n");
printf("Enter 1 to push.\nEnter 2 to pop.\nEnter 3 to traversal.\nEnter 4 to stack top\nEnter 5 to count.\nEnter 6 to search\nEnter 7 to Exit\n");
scanf("%d",&choice);
switch(choice){
case 1: head=push(head); break;
case 2: head=pop(head); break;
case 3: traversal(head); break;
case 4: stackTop(head); break;
case 5: printf("Count is %d\n",head->count); break;
case 6: search(head); break;
case 7: return 0; break;
default: printf("You have Entered wrong choice\n");
}
}
return 0;
}
