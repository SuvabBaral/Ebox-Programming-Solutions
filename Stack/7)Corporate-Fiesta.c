#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player{
    int *id;
    int top;
    int maxSize;
    
};
void push(struct player *p,int item );
void pop(struct player *p);
void display(struct player p);
void initplayer(struct player *p,int maxSize){
p->top=-1;
p->id=(int *)malloc(sizeof(int) * maxSize);
p->maxSize=maxSize;
}
void push(struct player *p,int item){
    if(p->top==((p->maxSize)-1)){
        printf("Stack is full\n");
        return;
    }
    else{
        p->id[++(p->top)]=item;
    }
}

void pop(struct player *p){
    if((p->top) == -1){
        printf("Stack is empty\n");
        return;
    }
    else{
        // int n=p->a[p->top];
        (p->top)--;
        // return n;
    }
}
int main(){
    struct player p;
    int n,i;
    char ch,ch1;
    int firstID;
    scanf("%d%d",&n,&firstID);
    initplayer(&p,1000);
    push(&p,firstID);
    int first,first1;
    for(i=0;i<n;i++){
        scanf(" %c %d",&ch,&first);
        
        if(ch=='F'){
            push(&p,first);
        }
        else{
            pop(&p);
            if(i+1<n){
            scanf(" %c %d",&ch1,&first1);
           if(ch1=='F'){
            push(&p,first1);
            }
            else{
                p.top++;
            }
            n-=1;
        }
        }
        
    }
    printf("Player %d",p.id[p.top]);
    
    
    
    return 0;
}