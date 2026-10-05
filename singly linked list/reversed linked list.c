#include <stdio.h> 
#include <stdlib.h> 

struct node{
    int data;
    struct node*next;
};

struct node*head = NULL;
struct node*temp=NULL;

void insertatend()
{
   struct node*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data:  ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL){
        head = newnode;
        temp = newnode;
    }else{
        temp -> next = newnode;
        temp = newnode;
    }
}


void display()
{
    temp = head;
    printf("\nThe Initialised datas are:   ");
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp = temp->next;
    }
    printf("\nNULL");
}


void count()
{
  temp = head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    printf("\nThe Count is: %d",count);
}

void reverse(){
    temp = head;
    struct node *nextnode, *currentnode, *prevnode;
    prevnode = NULL;
    currentnode = head;
    while(currentnode!=NULL){
        nextnode = currentnode-> next;
        currentnode -> next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}
    


int main()
{
    char choice;
    do{
        insertatend();
        printf("\nDo You Need To Continue \n X-Disconnect\nY-Continue\n<----Choice---->: ");
        scanf("\n %c",&choice);
    }
        while(choice=='Y' || choice=='y');

    printf("\n\n<----The Initialised element Are--->");
    display();

    printf("\n\n <----The Count Of The Element---->");
    count();

    printf("\n<----The Reversed Element are---->");
    reverse();
    display();
}
    