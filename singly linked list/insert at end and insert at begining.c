#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node*temp=NULL;

void insertatend ()
{
    struct node*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter the data:  ");
        scanf("%d",&newnode->data);
        newnode->next=0;

        if(head==NULL){
            head = newnode;
            temp = newnode;
        }else{
         newnode->next = head;
          head = newnode;
        }
}

void insertatbegining(){
    struct node*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Data: ");
    scanf("%d",&newnode->data);
    newnode -> next = NULL;

    if(head==NULL){
        head = newnode;
        temp = newnode;
    }
    else{
        temp -> next = newnode;
        temp = newnode;
    }
}

    void display(){
        temp = head;
        printf("\n Initialise the data:\n ");
            while(temp!=NULL){
                printf("%d",temp->data);
                temp = temp -> next;
            }
        printf("\nNULL");
    }
int main() {
    char choice;
    printf("\n--- INSERT AT END ---\n");
    do { 
        insertatend();
        printf("\nDo you need to continue? (y/n): ");
        scanf(" %c", &choice); 
    } 
        while(choice == 'y' || choice == 'Y'); 
    display();
    printf("\n--- INSERT AT BEGINNING ---\n"); 
    do 
    {
        insertatbegining(); 
        printf("\nDo you need to continue? (y/n): ");
        scanf(" %c", &choice); 
    } 
        while(choice == 'y' || choice == 'Y'); 
    display();
    return 0;
}