#include <stdio.h>
#include <stdlib.h>
struct tnode{
	struct tnode *leftc ;
	int data ;
	struct tnode *rightc ;
} ;

void insert ( struct tnode **, int ) ;
struct tnode* delete(struct tnode *, int );
void search ( struct tnode **, int, struct tnode **, struct tnode **, int * ) ;
void inorder ( struct tnode * ) ;

int main()
{
	struct tnode *bt ;
	int  b,n;
	printf("Binary Search Tree Implementation.\n\nChoice 1: Insert an element.\nChoice 2: Delete an element.\nChoice 3: Display.\n");
	printf("\nEnter your choice :\n");
	scanf("%d",&n);
	bt = NULL ;  /* empty tree */
	while((n==1)||(n==2)||(n==3))
	{
		switch ( n )
		{
			case 1:
			{
				printf("Enter the element to be inserted :\n");
				scanf("%d",&b);
				insert (&bt,b) ;
				break;
			}
			case 2:
			{
				printf("Enter the element to be deleted :\n");
				scanf("%d",&b);
				bt = delete ( bt, b ) ;
				break;
			}
			case 3:
			{
				if(bt==NULL)
				{
					printf("There are no elements in the BST.");
				}
				else
				{
					inorder ( bt ) ;
				}
				printf("\n");
				break;
			}
			default:
			{
				break;
			}
		}
		printf("Enter your choice :\n");
		scanf("%d",&n);
	}
	return 0;
}

/* inserts a new node in a binary search tree */
void insert ( struct tnode **sr, int num )
{
	if ( *sr == NULL )
	{
		*sr = malloc ( sizeof ( struct tnode ) ) ;

		( *sr ) -> leftc = NULL ;
		( *sr ) -> data = num ;
		( *sr ) -> rightc = NULL ;
	}
	else  /* search the node to which new node will be attached */
	{
		/* if new data is less, traverse to left */
		if ( num < ( *sr ) -> data )
			insert ( &( ( *sr ) -> leftc ), num ) ;
		else
			/* else traverse to right */
			insert ( &( ( *sr ) -> rightc ), num ) ;
	}
}
void search(struct tnode **s, int ele, struct tnode **target, struct tnode **prev, int *f )
{
    if((*s)==NULL)
    {
        *f=0;
        return;
    }
    
    if((*s)->data==ele)
   { 
       *f=1;
       *target=*s;
      
   }
    else
    {
        if((*s)->data > ele)
        {
            *prev=*s;
         search(&((*s)->leftc),ele,target,prev,f);
        }
        else
        {
            *prev=*s;
            search(&((*s)->rightc),ele,target,prev,f);
        }
    }
    
}
/* deletes a node from the binary search tree */
struct tnode* delete(struct tnode *root, int item) {
	//Fill your code here
	int f=0;
	struct tnode *target,*parent;
	if(root==NULL) {printf("Tree is empty\n");return root;}
else
{
    search(&root,item,&target,&parent,&f);
    //printf("%d %d",target->data,parent->data);
	if(f!=1)
	printf("Data to be deleted, not found\n");
	else
	{
	  if(target->leftc==NULL && target->rightc==NULL)
	  {
	      if(parent->data >item)
	      parent->leftc=NULL;
	      else
	      parent->rightc=NULL;
	  }
      if(target->leftc!=NULL && target->rightc==NULL)
	  {
	      if(parent->data >item)
	      parent->leftc=target->leftc;
	      else
	      parent->rightc=target->leftc;
	  }
if(target->leftc==NULL && target->rightc!=NULL)
	  {
	      if(parent->data >item)
	      parent->rightc=target->rightc;
	      else
	      parent->leftc=target->leftc;
	  }
	  if(target->leftc!=NULL && target->rightc!=NULL)
	  {
	      struct tnode *prev,*temp=target->rightc;
	      if(temp->leftc==NULL)
	      {
	          target->data=temp->data;
	          target->rightc=temp->rightc;
	      }
	      else
	      {
	          while(temp->leftc!=NULL)
	          {
	              prev=temp;
	              temp=temp->leftc;
	          }
	          target->data=temp->data;
	          prev->leftc=temp->rightc;
	      }
	  }
	}

	return root;
}
}

void inorder ( struct tnode *sr ) {
    /*----------Fill your code here-----------*/
    if(sr!=NULL)
    {
        inorder(sr->leftc);
        printf("%d ",sr->data);
        inorder(sr->rightc);
    }
}