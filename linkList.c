#include<stdio.h>
#include<stdlib.h>
struct Head* createList();
struct Head* insert(struct Head*,int);
struct Head* delet(struct Head*);
int traversal(struct Head*);
struct node* search(struct Head*);

typedef struct node{
int data;
struct node* next;
}node;

typedef struct Head{
int count;
node* first;
}h;

struct Head* createList(){
h* head=(h*)malloc(sizeof(h));
if(!head){
    printf("Out of memory\n");
    return 0;
}
head->count=0;
head->first=NULL;
return head;
}

struct Head* insert(struct Head* h, int data){
node* New=(node*)malloc(sizeof(node));
if(!New){
    printf("Out of memory\n");
    return 0;
}
New->data=data;
int choice;
printf("Enter 1 to insert at beginning.\nEnter 2 to insert at end.\nEnter 3 to insert at specific position.\n");
scanf("%d",&choice);
switch(choice){
case 1:
    {
        New->next=h->first;
        h->first=New;
        h->count++;
        break;
    }
case 2:
    {
        node* tmp=(node*)malloc(sizeof(node));
        if(!tmp){
            printf("Memory Error\n");
            return 0;
        }
        tmp=h->first;
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next=New;
        New->next=NULL;
        h->count++;
        break;
    }
case 3:
    {
        printf("Enter the data after which you want to insert\n");
        int d=scanf("%d",&d);
        node* tmp=(node*)malloc(sizeof(node));
        if(!tmp){
            printf("Memory Error\n");
            return 0;
        }
        tmp=h->first;
        while(tmp->data!=d){
            tmp=tmp->next;
        }
        New->next=tmp->next;
        tmp->next=New;
        h->count++;
        break;
    }
    default:printf("You have entered wrong choice\n");
}
return h;
}

int traversal(struct Head* h){
if(h->count==0){
    printf("List is Empty\n");
    return 0;
}
node* tmp=(node*)malloc(sizeof(node));
tmp=h->first;
while(tmp!=NULL){
    printf("%d\t",tmp->data);
    tmp=tmp->next;
}
printf("\n");
return 0;
}

struct Head* delet(struct Head* h){
if(h->count==0){
    printf("Can not delete from empty list\n");
    return 0;
}
int data;
printf("Enter data to be deleted.\n");
scanf("%d",&data);
node* tmp=(node*)malloc(sizeof(node));
node* t=(node*)malloc(sizeof(node));
if(!tmp || !t){
    printf("Memory Error\n");
    return 0;
}
tmp=h->first;
if(tmp->data==data){
    h->first=tmp->next;
    tmp->next=NULL;
    free(tmp);
    h->count--;
}
else{
t=tmp->next;
while(t->data!=data){
    tmp=t;
    t=t->next;
}
tmp->next=t->next;
t->next=NULL;
free(t);
h->count--;
}
return h;
}

struct node* search(struct Head* head){
    if (!head->first)
    {
        printf("Can not search from empty list\n");
        return 0;
    }
    node* tmp=(node*)malloc(sizeof(node));
    if (!tmp)
    {
        printf("Memory Error\n");
        return 0;
    }
    int d;
    printf("Enter data to be searched\n");
    scanf("%d",&d);
    tmp=head->first;
    while(tmp){
        if (tmp->data==d)
        {
            printf("Data found %d\n",tmp->data);
            return tmp;
        }
        tmp=tmp->next;
    }
    printf("Data not found\n");
}

int main(){
h* head=(h*)malloc(sizeof(h));
if(!head){
    printf("Out of memory\n");
    return 0;
}
head=createList();
while(1){
int choice;
printf("*******************************************\n");
printf("Enter 1 to insert.\nEnter 2 to Traverse.\nEnter 3 for count.\nEnter 4 to delete.\nEnter 5 to search.\nEnter 6 to exit.\n");
scanf("%d",&choice);
switch(choice){
case 1:
    {
        int data;
        printf("Enter data to be inserted\n");
        scanf("%d",&data);
        head=insert(head,data);
        break;
    }
case 2:
    traversal(head); break;
case 3:
    printf("Count is %d\n",head->count); break;
case 4:
    delet(head); break;
case 5: search(head); break;
case 6:
    return 0;
default:printf("You have entered wrong choice\n");
}
}
return 0;
}
