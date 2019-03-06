#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tnode  {
	int data;
	struct tnode * leftc;
	struct tnode * rightc;
};

void insert(struct tnode **, int num);
void inorder(struct tnode * s);
int max(int a, int b);
int height(struct tnode* node);
int diameter(struct tnode * tree);

int main()  {
	struct tnode * root=NULL;
	char ch[5];
	int num;
	do {
		printf("Enter the element to be inserted in the tree\n");
		scanf("%d",&num);
		insert(&root, num);
		printf("Do you want to insert another element?\n");
		scanf("%s",ch);
	}while(strcmp(ch,"yes")==0);

	printf("The elements in the tree are");
	inorder(root);
	printf("\n");
	printf("The diameter of the tree is %d\n",diameter(root));
	return 0;
}

void insert(struct tnode ** s, int num) {
	if((*s) == NULL) {
		(*s) = (struct tnode *) malloc( sizeof (struct tnode));
		(*s)->data = num;
		(*s)->leftc = NULL;
		(*s)->rightc = NULL;
	}
	else 	{
		if(num < (*s)->data)
		  insert(&( (*s)->leftc ), num);
		else
		  insert(&( (*s)->rightc ), num);
	}
}

void inorder(struct tnode * s)  {
	if(s != NULL)
	{
		inorder(s->leftc);
		printf(" %d",s->data);
		inorder(s->rightc);
	}
}

int diameter(struct tnode * tree)  {
    int h1=height(tree->leftc)+1;
    int h2=height(tree->rightc)+1;
    return h1+h2-1;

}
 

int height(struct tnode* node)  {
   if(node == NULL)
       return 0;
   return 1 + max(height(node->leftc), height(node->rightc));
} 

int max(int a, int b)  {
  return (a >= b)? a: b;
}