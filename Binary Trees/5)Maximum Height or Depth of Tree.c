#include <stdio.h>
#include <stdlib.h>
#include<string.h>

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
int height(struct tree *root);
  
int main()
{
    struct tree* root = NULL;
  char ans[3];
  int data;
    struct queue* queue = createQueue(100);
 do
 {
  printf("Enter the element to be inserted in the tree\n");
            scanf("%d",&data);          
        insert(&root, data, queue);
    printf("Do you want to insert another element?\n");
              scanf("%s",ans);
         } while (strcmp(ans,"yes") ==0); 
    printf("Hight of tree is %d",height(root));
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
{
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->size=size;
    q->front=-1;
    q->rear=-1;
    q->array=(struct tree **)malloc(sizeof(struct tree *)*size);
     return q;
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
{
    if(queue->rear==-1){
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