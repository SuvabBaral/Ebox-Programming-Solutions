#include<stdio.h>
#include<stdlib.h>
struct stack{
    int a[5];
    int top;
};

void push(struct stack *p,int item );
int pop(struct stack *p);
void display(struct stack p);
void initstack(struct stack *p){
p->top=-1;
}
int main(){
    int c,n,ele;
    struct stack q;
    initstack(&q);
    do{
        printf("Choice 1 : Push\n");
        printf("Choice 2 : Pop\n");
        printf("Choice 3 : Display\n");
        printf("Any other choice : Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&c);
        switch(c){
            case 1:
            printf("Enter the element to be pushed\n");
            scanf("%d",&ele);
            push(&q,ele);
            break;
            
            case 2:
            n=pop(&q);
            if(n!=-1000)
            printf("The popped element is %d\n",n);
            break;
            
            case 3:
            printf("The contents of the stack are");
            display(q);
            break;
            
            default:
            return 0;
        }
    }while(1);
    
    
    return 0;
}

void push(struct stack *p,int item){
    if(p->top==4){
        printf("Stack is full\n");
        return;
    }
    else{
        p->a[++(p->top)]=item;
    }
}

int pop(struct stack *p){
    if((p->top) == -1){
        printf("Stack is empty\n");
        return -1000;
    }
    else{
        int n=p->a[p->top];
        (p->top)--;
        return n;
    }
}
void display(struct stack p){
    if(p.top==-1){
        printf(" {}\n");
        
        return;
    }
    int i=0;
    
    while(i<=(p.top)){
        printf(" %d",p.a[i]);
        i++;
    }
    printf("\n");
}