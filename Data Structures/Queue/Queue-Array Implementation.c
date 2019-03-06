#include<stdio.h>
#include<stdlib.h>
struct queue{
    int contents[5];
    int front;
    int count;
};
void initQueue(struct queue *q);
void enQueue(struct queue *q, int element);
int deQueue(struct queue *q);
void display(struct queue q);
int main(){
   
    
    return 0;
}

void initQueue(struct queue *q){
    q->front=0;
    q->count=0;
}

void enQueue(struct queue *q,int element){
    if(q->count==5){
        printf("Queue is full\n");
    }
    else{
        q->contents[((q->count)+(q->front)) % 5]=element;
        q->count++;
    }
}

int deQueue(struct queue *q){
    if(q->count==0){
        printf("Queue is empty\n");
        return -1000;
    }
    else{
        int n=q->contents[q->front];
        q->count--;
        q->front++;
        q->front=((q->front) % 5);
        return n;
    }
}
 void display(struct queue q){
     if(q.count==0){
         printf(" {}\n");
     }
     else{
         int i=0;
         while(i<q.count){
             printf(" %d",q.contents[((q.front)+i) % 5]);
             i++;
         }
         printf("\n");
     }
 }