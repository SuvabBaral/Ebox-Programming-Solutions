#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *right,*left;
};

struct queue
{
    int front, rear;
    int size;
    struct tree* *array;
};

struct tree* newNode(int data);
struct queue* createQueue(int size);
void enqueue(struct tree *root, struct queue* queue);
struct tree* dequeue(struct queue* queue);
void insert(struct tree **root, int data, struct queue* queue);
void levelOrder(struct tree* root);
int isSumProperty(struct tree* node); 


int main()
{
    struct tree* root = NULL;
  int data;
    struct queue* queue = createQueue(50);
    int i,n;
  printf("Enter the number of elements in the tree\n");
 scanf("%d",&n);
  printf("Enter the elements in the tree\n");
    for(i = 1; i <= n; ++i)
    {
      scanf("%d",&data);
        insert(&root, data, queue);
    }
  printf("The elements in the tree in level order are");
  levelOrder(root);
  printf("\n");
 
if(isSumProperty(root))
    printf("The tree satisfies the children sum property ");
  else
    printf("The tree does not satisfy the children sum property ");
 
    return 0;
}


struct tree* newNode(int data) 
{
   struct tree *nn=(struct tree *)malloc(sizeof(struct tree));
    nn->data=data;
    nn->right=NULL;
    nn->left=NULL;
    return nn;
}

struct queue* createQueue(int size)
{struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->size=size;
    q->front=-1;
    q->rear=-1;
    q->array=(struct tree **)malloc(sizeof(struct tree *)*size);
     return q;
 
}

void enqueue(struct tree *root, struct queue* queue)
{
    if(queue->rear==queue->size-1){
        return;
    }
    else{
        queue->array[++(queue->rear)]=root;
        if(queue->front==-1) queue->front++;
    }
}
 
struct tree* dequeue(struct queue* queue)
{if(queue->rear==-1){
        return NULL;
    }
        struct tree *temp=queue->array[queue->front];
       
        if(queue->rear==queue->front){
            queue->front=-1;
            queue->rear=-1;
        } 
        else
        queue->front++;
    return temp;
    
} 

void insert(struct tree **root, int data, struct queue* queue)
{
     struct tree *temp=newNode(data);
    if((*root)==NULL){
        (*root)=temp;
    }
    else{
        struct tree *t=queue->array[queue->front];
        if(t->left==NULL){
            t->left=temp;
        }
        else if(t->right==NULL){
            t->right=temp;
        }
        if(t->right!=NULL && t->left!=NULL){
            dequeue(queue);
        }
        
    }
    enqueue(temp,queue);
}
int height(struct tree* node) {
   if (node==NULL)
       return 0;
   else    {
     /* compute the height of each subtree */
     int lheight = height(node->left);
     int rheight = height(node->right);
 
     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
}
void printLevel(struct tree* root, int level){
    if(root==NULL){
        return;
    }
    if(level==1) printf(" %d",root->data);
    else{
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
}

void levelOrder(struct tree* root)
{
    int h=height(root);
    int i;
    for(i=1;i<=h;i++){
        printLevel(root,i);
    }
   
}
int isSumProperty(struct tree* node){ 
  int l= 0,  r= 0; 
  
  if(node == NULL || 
     (node->left == NULL && node->right == NULL)) 
    return 1; 
  else
  { 
    if(node->left != NULL) 
      l = node->left->data; 
    if(node->right != NULL) 
      r= node->right->data; 
    if((node->data == l + r)&&  isSumProperty(node->left) &&isSumProperty(node->right)) 
      return 1; 
    else
      return 0; 
  } 
}