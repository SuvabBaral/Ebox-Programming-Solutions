#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node * link ;
};
void addcirq (struct node **f, struct node **r, int item) 
{
   struct node *nn=(struct node*)malloc(sizeof(struct node));
   nn->data=item;
   nn->link=NULL;
   if(*f==NULL)
   {
       *f=nn;
       *r=nn;
       (*r)->link=*f;
   }
   else
   {
       (*r)->link=nn;
       *r=nn;
       (*r)->link=*f;
   }
}
int delcirq (struct node **f, struct node **r) 
{
    if(*f==NULL)
    {
        printf("Queue is empty\n");
        return -1000;
    }
    else if((*f)==(*r))
    {
     int n=(*f)->data;
     *f=NULL;
     *r=NULL;
     return n;
    }
    else
    {
        int n=(*f)->data;
        (*f)=(*f)->link;
        (*r)->link=*f;
        return n;
    }
    
}
void cirq_display (struct node *f) 
{
    struct node *t=f;
    if(f==NULL)
   {  
       printf(" {}\n");
       return;
   }
   while(t->link!=f)
   {
   printf(" %d",t->data);
   t=t->link;
   }
   printf(" %d\n",t->data);
  
}
void printMenu()
{
    printf("Choice 1 : Enter element into Queue\nChoice 2 : Delete element from Queue\nChoice 3 : Display\nAny other choice : Exit\n");
}
int main()
{
    struct node *front=NULL,*rear=NULL;
    int c;
    while(1)
    {
    printMenu();
    printf("Enter your choice\n");
    scanf("%d",&c);
    if(c==1)
    {
        int n;
        printf("Enter the element to be inserted/entered\n");
        scanf("%d",&n);
        addcirq(&front,&rear,n);
    }
    else if(c==2)
    {
       int t= delcirq(&front,&rear);
       if(t!=-1000)
       printf("The deleted element is %d\n",t);
    }
    else if(c==3)
    {
        printf("The contents of the queue are");
        cirq_display(front);
    }
    else 
    exit(0);
    }
    return 0;
}