#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tnode {
	int data;
	struct tnode * leftc;
	struct tnode * rightc;
};

void insert(struct tnode **, int num);
void inorder(struct tnode *);
int findMaxDepth(struct tnode * s);

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
	printf("The maximum depth of the tree is %d\n",findMaxDepth(root));
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

int findMaxDepth(struct tnode * s) {
    if(s==NULL){
        return 0;
    }
    else if(s->leftc==NULL && s->rightc==NULL){
        return 1;
    }
    int left=1,right=1;
    left+=findMaxDepth(s->leftc);
    right+=findMaxDepth(s->rightc);
    return (left > right)?left:right;
    
}