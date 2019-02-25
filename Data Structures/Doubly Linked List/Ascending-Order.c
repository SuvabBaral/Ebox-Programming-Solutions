#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
  int id;
  char name[10];
  char gender[10];
  struct student * prev;
  struct student * next;
};
void insert ( struct student **, struct student s ) ;
void display ( struct student * ) ;


int main() {
	struct student *p ;
	p=NULL;
        struct student s; 
        char ch[10];
	do {
		printf("Enter the id\n");
		scanf("%d",&s.id);
                printf("Enter the name\n");
		scanf("%s",s.name); 
		printf("Enter the gender\n");
		scanf("%s",s.gender);
		s.prev=NULL;
                s.next=NULL;
		insert(&p,s);
                printf("Do you want to add details of another student? Type Yes/No\n");
		scanf("%s",ch);
	} while(!strcmp(ch,"Yes"));
        printf("The details of the students are\n");
        printf("%4s %10s %7s\n","ID","Name","Gender");
	display(p);
	return 0;
}


void insert ( struct student **q, struct student s ) {
	struct student *nn=(*q);
	nn=(struct student *)malloc(sizeof(struct student) );
	nn->id=s.id;
	strcpy(nn->name , s.name);
	strcpy(nn->gender,s.gender);
	if((*q)==NULL){
	    nn->next=NULL;
	    nn->prev=NULL;
	    (*q)=nn;
	}
	else{
	    struct student *temp=(*q);
	    struct student *pred=NULL;
	    if(temp->id > nn->id){
	        nn->next=temp;
	        temp->prev=nn;
	        nn->prev=NULL;
	        (*q)=nn;
	    }
	    else{
	        while(temp!=NULL && temp->id <= nn->id){
	            pred=temp;
	            temp=temp->next;
	        }
	        if(temp==NULL){
	            nn->next=pred->next;
	            pred->next=nn;
	            nn->prev=pred;
	        }
	        else{
	            nn->next=pred->next;
	            pred->next->prev=nn;
	            pred->next=nn;
	            nn->prev=pred;
	        }
	        
	    }
	}
	
}

void display ( struct student *q )
{
  struct student *temp=q;
  while(temp!=NULL)
  {
    printf("%4d ",temp->id);
    printf("%10s ",temp->name);
    printf("%7s ",temp->gender);
    printf("\n");
    temp=temp->next;
  }
      
}