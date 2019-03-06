#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tnode {
	int data;
	struct tnode * leftc;
	struct tnode * rightc;
};

void insert(struct tnode **, int num);
void inorder(struct tnode *);
int getLeafCount(struct tnode* node);

int main() {
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
	printf("The number of leaf nodes in the tree is %d\n",getLeafCount(root));
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

void inorder(struct tnode * s) {
   if(s!=NULL){
        inorder(s->leftc);
        printf(" %d",s->data);
        inorder(s->rightc);
    }
}

int getLeafCount(struct tnode* node) {
   static int i=0;
   if(node==NULL) return i;
   if((node)->leftc==NULL && (node)->rightc==NULL){
       i++;
   }
   else{
   getLeafCount(node->leftc);
   getLeafCount(node->rightc);
   }
   return i;
}