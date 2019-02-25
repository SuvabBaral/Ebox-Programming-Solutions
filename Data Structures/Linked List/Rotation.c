#include<stdio.h>
#include<stdlib.h>
struct cabin
{
    int number;
    struct cabin * link;
};
void append (struct cabin **q,int n);
void display(struct cabin *q);
void rotateRight(struct cabin **q,int n);
void rotateleft(struct cabin **q,int n);
int main()
{
    int n,choice;
    struct cabin *list;
    list = NULL;
while(choice!=5)
{
    printf("1.Insert cabin\n2.Display\n3.Rotate Right\n4.Rotate Left\n5.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
switch(choice)
{
case 1:
    printf("Enter the cabin number\n");
    scanf("%d",&n);
    if(n>0 && n<100)
    append(&list,n);
    else
    printf("Invalid cabin number");
break;
case 2:
    display(list);
break;
case 3:
    printf("Enter the cabin number to rotate\n");
    scanf("%d",&n);
    rotateRight(&list,n);
break;
case 4:
    printf("Enter the cabin number to rotate\n");
    scanf("%d",&n);
    rotateleft(&list,n);

    break;
case 5:
printf("Exit\n");
break;
}
}
    return 0;
}

void append (struct cabin **q,int n)
{
    struct cabin *nn;
    nn=(struct cabin *)malloc(sizeof(struct cabin));
//  nn->id=s.id;
//  strcpy(nn->name,s.name);
//  strcpy(nn->gender,s.gender);
nn->number=n;
    nn->link=NULL;
    if((*q)==NULL){
        (*q)=nn;
    }
    else{
        struct cabin *temp=(*q);
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=nn;
    }
}
void display(struct cabin *q)
{   
 if(q==NULL){
     printf("No cabins were inserted\n");
     return;
 }       
 printf("Cabin positions are:");
 struct cabin *temp=q;
 while(temp!=NULL){
     printf("%d ",temp->number);
     temp=temp->link;
 }printf("\n");
}
void rotateRight(struct cabin **q,int n)
{
    if((*q)==NULL){
        printf("No cabins were inserted\n");
        return;
    }
    struct cabin *temp=(*q);
    struct cabin *end;
    struct cabin *next=(*q);
    int flag=0;
    int count=0;
   
    while(temp!=NULL){
        if(temp->number == n) { flag=1;}
        end=temp; temp=temp->link;
    }
    if(flag==0) {printf("Enter a valid cabin number\n"); return;}
    temp=next;
    next=temp;
    
    while(temp!=NULL && temp->number != n){
        end->link=temp;
        next=temp->link;
        temp->link=NULL;
        end=temp;
        temp=next;
        count++;
        
        
    }
    printf("Number of rotation = %d\n",count);
    (*q)=temp;
    display(*q);
}


void rotateleft(struct cabin **q,int n)
{
    if((*q)==NULL){
        printf("No cabins were inserted\n");
        return;
    }
    struct cabin *temp=(*q);
    struct cabin *t=(*q);
    struct cabin *end;
    struct cabin *next=(*q);
    int flag=0;
    int count=0;
   
    while(temp!=NULL){
        if(temp->number == n) { flag=1;}
        end=temp; temp=temp->link;
    }
    if(flag==0) {printf("Enter a valid cabin number\n"); return;}
    while(t!=NULL){
    if(t->number==n) break;
    t=t->link;
    }
    while(t!=NULL)
    {
        count++;
        t=t->link;
    }
    temp=next;
    while(temp!=NULL && temp->number != n){
        end->link=temp;
        next=temp->link;
        temp->link=NULL;
        end=temp;
        temp=next;
        
    }
    printf("Number of rotation = %d\n",count);
    (*q)=temp;
    display(*q);
}