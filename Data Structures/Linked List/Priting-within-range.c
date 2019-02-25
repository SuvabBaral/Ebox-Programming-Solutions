#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
  int id;
  char name[10];
  char gender[10];
  struct student * link;
};
void append ( struct student **, struct student ) ;
void display ( struct student * ) ;
int count ( struct student *);
void printrange( struct student *, struct student,int ,int);

int main() {
    struct student *p ;
    p=NULL;
    int low;
        int high;
    struct student s;
        char ch[10];
    do {
        printf("Enter the id\n");
        scanf("%d",&s.id);
                printf("Enter the name\n");
        scanf("%s",s.name); 
        printf("Enter the gender\n");
        scanf("%s",s.gender);
        s.link=NULL;
        append(&p,s);
                printf("Do you want to add details of another student? Type Yes/No\n");
        scanf("%s",ch);
    } while(!strcmp(ch,"Yes"));
    printf("The details of the students are\n");
        printf("%4s %10s %7s\n","ID","Name","Gender");
    display(p);
    printf("Enter the range of elements to print\n");
    scanf("%d",&low);
    scanf("%d",&high);
    if(high>count(p))
        printf("Invalid Range\n");
    else {
        printf("The elements in the range %d to %d are \n",low,high);
                printf("%4s %10s %7s\n","ID","Name","Gender");
        printrange(p,s,low,high);
            }
    return 0;
}

void append ( struct student **q, struct student s ) {
    struct student *nn;
    nn=(struct student *)malloc(sizeof(struct student));
    nn->id=s.id;
    strcpy(nn->name,s.name);
    strcpy(nn->gender,s.gender);
    nn->link=NULL;
    if((*q)==NULL){
        (*q)=nn;
    }
    else{
        struct student *temp=(*q);
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=nn;
    }
    
}

void display ( struct student *q ) {
  struct student * temp=q;
  while(temp!=NULL)
  {
        printf("%4d ",temp->id);
        printf("%10s ",temp->name);
        printf("%7s ",temp->gender);
            printf("\n");
    temp=temp->link;
  }
}

int count ( struct student *q ) {
  struct student *temp=q;
  int c=0;
  while(temp!=NULL)
  {
    c=c+1;
    temp=temp->link;
  }
  return c;
}
void printrange( struct student *q,struct student s,int low,int high) {
    struct student *temp=q;
    int i=1;
    while(temp!=NULL && i<low){
        temp=temp->link;
        i++;
    }
    while(temp!=NULL && low<=high){
         printf("%4d ",temp->id);
        printf("%10s ",temp->name);
        printf("%7s ",temp->gender);
            printf("\n");
    temp=temp->link;
    low++;
        
    }
}