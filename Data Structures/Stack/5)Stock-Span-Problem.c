#include<stdio.h>
#include<stdlib.h>
struct stack{
    int *a;
    int top;
    int maxSize;
};
void initstack(struct stack *p,int maxSize);
void push(struct stack *p,int item);
int pop(struct stack *p);
int isEmpty(struct stack *p);
void calculateSpan(int *price,int n,int *span);
void printSpan(int *span,int n);
int main(){
    int *price,n,i,*span;
    printf("Enter the number of days\n");
    scanf("%d",&n);  
    price = (int*)malloc(sizeof(int)*n);
    printf("Enter the stock prices\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",price+i);
    }  
    span = (int*)malloc(sizeof(int)*n);
    calculateSpan(price, n, span);
    printf("Span values\n");
    printSpan(span, n); 
    return 0;
}
void initstack(struct stack *p,int maxSize){
    p->top=-1;
    p->a=(int * )malloc(sizeof(struct stack)* maxSize);
    p->maxSize=maxSize;
}
int isEmpty(struct stack *p){
    if(p->top==-1)return 0;
    else return 1;
}
void calculateSpan(int *price, int n, int *span){
    struct stack p;
    initstack(&p,n);
    
    push(&p,price[0]);
    int i,j;
    for(i=0;i<n;i++){
        span[i]=1;
    }
    int ele;
    for(i=1;i<p.maxSize;i++){
        // push(&p,price[i]);
        ele=price[i];
        while(isEmpty(&p) && ((pop(&p)) <= ele)){
            span[i]+=1;
        }
       
       for(j=p.top+1;j<=i;j++){
                push(&p,price[j]);
            }
        
    }
    
    
}
void push(struct stack *p,int item){
        if(p->top!=p->maxSize){
        p->a[++(p->top)]=item;
        }
        else 
        return;
}
int pop(struct stack *p){
        if(p->top!=-1){
        int n=p->a[p->top];
        (p->top)--;
        return n;
        }
        return -1000;
    
}
void printSpan(int *span,int n){
    int i;
    // printf("%d",*(span+0)+1);
    for(i=0;i<n;i++){
        printf("%d ",*(span+i));
    }
    
}