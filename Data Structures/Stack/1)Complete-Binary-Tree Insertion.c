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
void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);
  
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
 
 printf("Inorder Traversal : The elements in the tree are");
            inorder(root);
            printf("\n");
            printf("Preorder Traversal : The elements in the tree are");
            preorder(root);
   printf("\n");
            printf("Postorder Traversal : The elements in the tree are");
            postorder(root);
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

void inorder(struct tree *temp) {
    if(temp!=NULL){
       inorder(temp->left);
       printf(" %d",temp->data);
       inorder(temp->right);
   }
 
}

void preorder(struct tree *temp) { 
    if(temp!=NULL){
  
       printf(" %d",temp->data);preorder(temp->left);
       
       preorder(temp->right);
   }
}
 

void postorder(struct tree *temp) {
  
    if(temp!=NULL){
       postorder(temp->left);
       
       postorder(temp->right);printf(" %d",temp->data);
   }
}