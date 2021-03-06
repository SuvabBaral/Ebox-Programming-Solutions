#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct tnode
{
	int data;
	struct tnode * leftc;
	struct tnode * rightc;
};

void insert(struct tnode **, int num);
void inorder(struct tnode *);
int height(struct tnode* node);
int isBalanced(struct tnode *root);
int max(int a, int b);

int main()
{
	struct tnode * root=NULL;
	char ch[5];
	int num;
	do
	{
		printf("Enter the element to be inserted in the tree\n");
		scanf("%d",&num);
		insert(&root, num);
		printf("Do you want to insert another element?\n");
		scanf("%s",ch);
	}while(strcmp(ch,"yes")==0);

	printf("The elements in the tree are");
	inorder(root);
	printf("\n");
	if(isBalanced(root))
		printf("The tree is height balanced\n");
	else
		printf("The tree is not height balanced\n");
	return 0;
}

void insert(struct tnode ** s, int num)
{
if((*s) == NULL)
{
(*s) = (struct tnode *) malloc( sizeof (struct tnode));
(*s)->data = num;
(*s)->leftc = NULL;
(*s)->rightc = NULL;
}
else
{
if(num < (*s)->data)
  insert(&( (*s)->leftc ), num);
else
  insert(&( (*s)->rightc ), num);
}
}

void inorder(struct tnode * s)
{
    if(s!=NULL){
        inorder(s->leftc);
        printf(" %d",s->data);
        inorder(s->rightc);
    }
}

/* Returns true if binary tree with root as root is height-balanced */
int isBalanced(struct tnode *root)

{
    if(root==NULL){
        return 1;
    }
    int a=height(root->leftc);
    int b=height(root->rightc);
    if(isBalanced(root->leftc) && isBalanced(root->rightc) && (abs(a-b)<=1)){
        return 1;
    }
    else return 0;
}

/*  The function Compute the "height" of a tree. Height is the
    number of nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct tnode* node)
{
	if(node == NULL)
       return 0;
   return 1 + max(height(node->leftc), height(node->rightc));
} 

int max(int a, int b)
{
  return (a >= b)? a: b;
}