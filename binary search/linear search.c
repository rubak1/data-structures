#include <stdio.h> 
#include <stdlib.h> 

struct node{
    int data;
    struct node*next;
};
struct node*head = NULL;
struct node*temp = NULL;

void insert(){
    struct node*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> next = NULL;
    printf("Enter the Element:  ");
    scanf("%d",&newnode->data);

    if(head == NULL){
        head = newnode;
        temp = newnode;
    }else {
        temp->next = newnode;
        temp = newnode;
    }
}
void display(){
    temp = head;
    printf("\nInitialize the element:  ");

    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp = temp->next;
    }

    printf("\nNULL");
}
void search(){
    int n,i,count = 0;
    struct node*temp;



    while(temp!=NULL){
        count++;
        temp = temp->next;
    }

    printf("\n%d",count);

    printf("\nEnter the Element to search: ");
    scanf("%d",&n);

    temp = head;

    while(temp!=NULL){
        if(n==temp-> data){
            printf("\nData is Found");
            printf("\n%d",temp->data);
            return;
        }

        temp = temp->next;
       
    }

    printf("\nData is not found");
}
int main(){
    char choice;
    do{
    insert();
    printf("\nDo you need to continue:x/y:  ");
        scanf(" %c",&choice);
    }
        while(choice=='y' ||choice=='Y');
    display();
    search();
        
}