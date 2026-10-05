#include <stdio.h> 
#include <stdlib.h> 

struct node{
    int data;
    struct node*next;
};

struct node*head = NULL;
struct node*temp=NULL;

//insert at end 
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
        temp -> next = newnode;   // as end we need to move the temp and at last we need to print that
        temp = newnode;             
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
    } else{
        newnode -> next = head;   //as we need to insert at the begning so we need to move the head element.. 
        head = newnode;
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
      head = head->next;    //delete at begning that we need to delete the nulls next previous element.. 
      free(temp);
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
        temp = temp->next;   //as the count it will be count the every iteratration 
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

    do 
    {
        insertatbegining(); 
        printf("\nDo you need to continue? (y/n): ");
        scanf(" %c", &choice); 
    } 
        while(choice == 'y' || choice == 'Y'); 
    
    printf("\n\n <----The Insert at Begning---->");
     display();
    
    printf("\n\n <----The Count Of The Element---->");
    count();

    printf("\n<----The Reversed Element are---->");
    reverse();
    display();

    printf("\n<---The Delete at end--->");
    delete();
    display();

     printf("\n<---The Delete at begning--->");
    deleteatbegning();
    display();
}
    