#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void push(struct node **,int);
void display(struct node *);
int count(struct node *);
void pop(struct node **);
int main(){
    struct node *q=NULL;
    int ele,c;
    printf("Choice 1 : To push data\n");
    printf("Choice 2 : To pop data\n");
    printf("Choice 3 : To display\n");
    printf("Choice 4 : To count\n\n");
    do{
        printf("Enter your choice\n");
        scanf("%d",&c);
        switch(c){
            case 1:
            printf("Enter the data to be pushed\n");
            scanf("%d",&ele);
            push(&q,ele);
            break;
            
            case 2:
            pop(&q);
            break;
            
            case 3:
            printf("Linked List Contents\n");
            display(q);
            break;
            
            case 4:
            printf("Number of elements in the linked list is %d\n",count(q));
            break;
            
            default:
            printf("END");
            return 0;
        }
      
    }while(1);
    
    
    return 0;
}

void push(struct node **q, int ele){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=ele;
    if((*q)==NULL){
        nn->link=NULL;
        (*q)=nn;
    }
    else{
        if(count((*q))==5) printf("Stack is full\n");
        else{
            struct node *temp=(*q);
            nn->link=temp;
            (*q)=nn;
        }
    }
}

void pop(struct node **q){
    if((*q)==NULL){
        printf("No element in the stack\n");
        return;
    }
    else{
        struct node *temp=(*q);
        int n=temp->data;
        temp=temp->link;
        (*q)=temp;
        printf("Element Popped is %d\n",n);
    }
}
int count(struct node *q){
    int c;
    struct node *temp=q;
    while(temp!=NULL){
        c++;
        temp=temp->link;
    }
    return c;
    
}

void display(struct node *q){
    struct node *temp=q;
    if(q==NULL){
        printf("\n");
        return;
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->link;
        }
        
    }
    printf("\n");
}