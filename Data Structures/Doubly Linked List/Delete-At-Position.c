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
void append ( struct student **, struct student ) ;
void display ( struct student * ) ;
void delatend (struct student **);

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
		append(&p,s);
		printf("Do you want to add details of another student? Type Yes/No\n");
		scanf("%s",ch);
	} while(!strcmp(ch,"Yes"));
        printf("The details of the students are\n");
        printf("%4s %10s %7s\n","ID","Name","Gender");
	display(p);
        do{
	delatend(&p);
        printf("The details of the students after deleting a student are\n");
        printf("%4s %10s %7s\n","ID","Name","Gender");
	display(p);
        printf("Do you want to delete details of another student? Type Yes/No\n");
        scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));

	return 0;
}

void append ( struct student **q, struct student s ) 
{
	struct student *nn=(struct student *)malloc(sizeof(struct student));
	nn->id=s.id;
	strcpy(nn->name,s.name);
	strcpy(nn->gender,s.gender);
	if((*q)==NULL){
	    nn->next=NULL;
	    nn->prev=NULL;
	    (*q)=nn;
	}
	else{
	    struct student *temp=(*q);
	    while(temp->next!=NULL){
	        temp=temp->next;
	    }
	    temp->next=nn;
	    nn->prev=temp;
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

void delatend (struct student **q)
 {
	struct student *temp=(*q);
	while(temp->next->next!=NULL)
	temp=temp->next;
 
 temp->next=NULL;
}