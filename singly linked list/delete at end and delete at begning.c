#include <stdio.h>
#include<stdlib.h> 

struct node {
    int data;
    struct node*next;
}; 

struct node*head=NULL;
struct node*temp=NULL;

void insertatend(){
     struct node*newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL){
        temp = newnode;
        head = newnode;
    }else {
        temp -> next = newnode;
        temp = newnode;
    }
}
void delete(){
    struct node*newnode;
    struct node*prev;
    temp = head;

    if(head==NULL){  //it is used when the starting empty 
        printf("\nEnter the String Is Empty");
    }
    else if(head->next==NULL){  //it is used for the next element is empty
        free(head);
        head=NULL;
    }
    while(temp->next!=NULL){ //it is used for the element is not empty to move 
        prev = temp;
        temp = temp->next;
    }
    prev->next=NULL;
    free(temp);
}

void deleteatbegning(){
    struct node*newnode;
    temp = head;
  if(head==NULL){
      printf("\nData Are Empty");
  } else{
      head = head->next;
      free(temp);
  }
}

void display(){
    temp = head;
    printf("\n Initialised Values are:  ");
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp=temp->next;
    }
    printf("\nNULL");
}

int main(){
    char choice;
    do{
        insertatend();
        printf("\nDo You Need To Continue: ");
        scanf(" %c",&choice);
    }
        while(choice=='y'||choice=='Y');
    display();
    delete();
    printf("\n<<---Delete At End--->>");
    display();
        printf("\n<<---Delete At Begining");\
    deleteatbegning();
    display();
    
}