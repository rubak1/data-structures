#include <stdio.h> 
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
    struct node *temp = NULL;

void insertatend()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode -> next = NULL;
    
      printf("Enter the Data:  ");
                scanf("\n%d",&newnode->data);

    if(head == NULL){
        head = newnode;
        temp = newnode;
    }else {
        temp -> next = newnode;
        temp = newnode;
    }
}

void search(){
    temp = head;
    int searchdata;
    int found = 0;

    printf("\nEnter the Data: ");
    scanf("%d",&searchdata);

    while(temp!=NULL){
        if(temp->data==searchdata){
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found==1){
        printf("\nElement is found");
    } else {
        printf("\nElement is Not Found");
    }
}

    void display(){
        temp = head;
        printf("\nInitialze the list:  ");
        while(temp!=NULL){
            printf("\n%d",temp->data);
            temp = temp -> next;
        }
        printf("\nNULL");
    }

    int main(){
        char choice;

        do{
            insertatend();
                
                printf("\nDo you need to continue:x/y:  ");
                scanf("%s",&choice);
                
            }
            while(choice=='y' || choice=='Y');
            display();
        search();
        
    }