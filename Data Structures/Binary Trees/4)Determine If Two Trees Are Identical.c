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
int inorder(struct tree *root1,struct tree *root2);
int main()
{
    int n;
    struct tree* root2 = NULL;
    struct tree* root1 =NULL;
  char ans[3];
  int data;
    struct queue* queue1 = createQueue(100);
    struct queue* queue2 = createQueue(100);
 do
 {
     printf("Data to be inserted in 1st tree or 2nd tree?\n");
     scanf("%d",&n);
     switch(n){
         case 1:
    printf("Enter the element to be inserted in the 1st tree\n");
            scanf("%d",&data);          
        insert(&root1, data, queue1);
    printf("Do you want to insert element?\n");
              scanf("%s",ans);
        break;
        
        case 2:
        printf("Enter the element to be inserted in the 2nd tree\n");
            scanf("%d",&data);          
        insert(&root2, data, queue2);
    printf("Do you want to insert element?\n");
              scanf("%s",ans);
        break;
    
        
         }
         }while (strcmp(ans,"yes") ==0); 
            if(inorder(root1,root2))
            printf("Both tree are identical.\n");
        else
            printf("Trees are not identical.\n");  
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
// int count(struct tree *temp){
//     static int c=0;
//     if(temp!=NULL){
//         count(temp->left);
//         c++;
//         count(temp->right);
//     }
//     return c;
// }

int inorder(struct tree *temp1,struct tree *temp2){
   
   if(temp1!=NULL && temp2!=NULL){
       if(temp1->data == temp2->data){
           inorder(temp1->left,temp2->left);
            inorder(temp1->right,temp2->right);
        return 1;    
       }
       }
       
   
   return  0;
   
}