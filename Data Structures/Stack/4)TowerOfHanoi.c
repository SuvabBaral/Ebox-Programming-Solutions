#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<math.h>
struct stack{
    int *a;
    int top;
    int maxSize;
    
};
void initstack(struct stack *p,int maxSize);
void push(struct stack *p,int item);
int pop(struct stack *p);
void moveDisk(char,char,int);
void moveDisksBetweenTwoPoles(struct stack *src, struct stack *dest, char s, char d);
void hanoiIterative(int no_of_disks,struct stack *src, struct stack *aux, struct stack *dest);
void initstack(struct stack *p,int maxSize){
    p->maxSize=maxSize;
    p->a=(int *)malloc(sizeof(int)*maxSize);
    p->top=-1;
}
void push(struct stack *p,int item){
    if(p->top==p->maxSize-1){
       return;
    }
    else{
        p->a[++(p->top)]=item;
    }
}

int pop(struct stack *p){
    if((p->top) == -1){
        return INT_MIN;
    }
    else{
        int n=p->a[p->top];
        (p->top)--;
        return n;
    }
}
void moveDisk(char fromPeg,char toPeg,int disk){
    printf("Move the disk %d from '%c' to '%c'\n",disk,fromPeg,toPeg);
}
void moveDisksBetweenTwoPoles(struct stack *src,struct stack *dest,char s,char d){
    int ele;
    if(dest->top==-1){
    ele=pop(src);
    push(dest,ele);
     moveDisk(s,d,ele);
    
    }
    else if(dest -> a[dest->top] < src->a[src->top]){
         ele=pop(dest);
        push(src,ele);
        moveDisk(d,s,ele);
       
       
     }
     else{
         ele=pop(src);
         push(dest,ele);
         moveDisk(s,d,ele);
         
     }
    
        
    
}
bool isEven(int n){
    bool even=true;
    int i=1;
    for(i=1;i<=n;i++){
        even=!even;
    }
    return even;
    
}
void hanoiIterative(int no_of_disks,struct stack *src,struct stack *aux,struct stack *dest){
    int i; 
    for(i=no_of_disks;i>=1;i--){
        push(src,i);
    }
    i=1;
    if(!isEven(no_of_disks)){
    while((dest->top!=(no_of_disks-1)   ||  aux->top!=(no_of_disks-1))     && (i<=(pow(2,no_of_disks)-1))){
        if(i % 3==1){
            moveDisksBetweenTwoPoles(src,dest,'S','D');
        }
        else if(i % 3==2 ){
            moveDisksBetweenTwoPoles(src,aux,'S','A');
        
        }
        else if(i % 3==0){
            moveDisksBetweenTwoPoles(aux,dest,'A','D');
        }
        i++;
        
    }
    }

     else{
        while((dest->top!=(no_of_disks-1)   ||  aux->top!=(no_of_disks-1))     && (i<=(pow(2,no_of_disks)-1))){
        if(i % 3==1){
            moveDisksBetweenTwoPoles(src,dest,'S','A');
        }
        else if(i % 3==2 ){
            moveDisksBetweenTwoPoles(src,aux,'S','D');
        
        }
        else if(i % 3==0){
            moveDisksBetweenTwoPoles(aux,dest,'D','A');
        }
        i++;
        
    }
    }
}
int main(){
    int no_of_disks;
    printf("Enter the number of disks\n");
    scanf("%d",&no_of_disks);
    struct stack src,aux,dest;
    initstack(&src,no_of_disks);
    initstack(&aux,no_of_disks);
    initstack(&dest,no_of_disks);
   
    hanoiIterative(no_of_disks,&src,&aux,&dest);

    
    
    
    return 0;
}