#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct harry
{
    char data;
    struct harry* next;
};
struct harry *q=NULL;
void reverse(struct harry**);
bool compare(struct harry*, struct harry *);
bool isMagical(struct harry *head);
void display(struct harry *p);
 void insert(struct harry** head, char data);

int main() {
	struct harry *p ;
	p=NULL;
	int choice;
	char str;
while(choice!=4)
	{
	printf("1.Magical spell letter\n2.Display the Magical spell\n3.isMagical\n4.Exit\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter a Magical spell letter\n");
				scanf("\n%c",&str);
				insert(&p,str);
				break;
			case 2:
				display(p);
				break;
			case 3:
				isMagical(p)? printf("Magical Spell\n"):printf("Not a magical spell\n");
				break;
			case 4:
				printf("Exit\n");
				break;
			}
		}
	return 0;
}

bool isMagical(struct harry *head)
{   struct harry *temp=head;
             reverse(&temp);
     
    return compare(temp,q);
}
void reverse(struct harry** head)
{
    
    struct harry *temp=(*head);
    struct harry *prev=NULL;
    struct harry *link=temp->next;
    while(link!=NULL){
        temp->next=prev;
        prev=temp;
        temp=link;
        link=link->next;
    }
    temp->next=prev;
    (*head)=temp;
}
 

bool compare(struct harry* head1, struct harry *head2)
{
    
    bool flag=0;
    while(head1!=NULL || head2!=NULL){
    if(head1->data == head2->data){
        flag=1;
        head1=head1->next;
        head2=head2->next;
    }
    else{
        flag=0;
        break;
    }
    }
    
    
    
    
    return flag;
    
    
}
 
void insert(struct harry** head, char data)
{
    struct harry* nn;
    nn=(struct harry *)malloc(sizeof(struct harry));
    struct harry* nn2;
    nn2=(struct harry *)malloc(sizeof(struct harry));
    nn->data=data;
    nn2->data=data;
    
    if((*head)==NULL){
        (*head)=nn;
        nn->next=NULL;
    }
    else{
        nn->next=(*head);
        (*head)=nn;
    }
    if((q)==NULL){
        (q)=nn2;
        nn2->next=NULL;
    }
    else{
        nn2->next=(q);
        (q)=nn2;
    }
}

 

void display(struct harry *p)
{
    struct harry *temp;
    temp=p;
    if(p==NULL){
        printf("There is no Magical spell\n");
        return;
    }
    else{
        // int i=1;
        // printf("vehicle list:\n");
        while(temp!=NULL){
              printf("%c",temp->data);
            temp=temp->next;
        }
        printf("\n");
    } 
}