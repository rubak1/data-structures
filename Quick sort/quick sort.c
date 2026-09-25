#include <stdio.h> 
#include <stdlib.h> 

void swap(int*a,int*b){  //initializing the swaping function 
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int sort(int a[],int lb,int ub){     //quick sort need an swaping part for this 
    int start;
    int end;
    int piviot;

    piviot = a[lb];
    start = lb;
    end = ub;
//initializinng the piviot element and start what element and end what element
    while(start<end){       //right to left from start if greater         
        while(a[start]<=piviot){
            start++;
        }        //after that left to right after swap 
        while(a[end]>start){
            end--;
        }
        if(start<end){    //swaping
            swap(&a[start], &a[end]);
        }
    }
     swap(&a[lb], &a[end]);

    return end;
}      // swaping element that should be need to initialize in the down element main function 
void quicksort(int a[], int lb, int ub)
{
    int loc;

    if(lb < ub)
    {
        loc = sort(a, lb, ub);

        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}
int main(){
    int n,i,a[100];
    printf("Enter the Element:  ");
    scanf("%d",&n);

    printf("\nEnter the Element:  ");
    for(i=0;i<n;i++){
        scanf("%d ",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("\nThe Sorting Elements:  ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}