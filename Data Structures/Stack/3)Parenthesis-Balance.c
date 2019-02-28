#include<stdio.h>
#include<stdlib.h>
struct stack{
    char *s;
    int top;
};
void initstack(struct stack *p);
void push(struct stack *p,char);
char pop(struct stack *p);
void balancedornot(struct stack p,char *par);
int main(){
    struct stack q;
    int n;
    initstack(&q);
    scanf("%d",&n);
    char a[128];
    do{
        scanf(" %[^\n]s",a);
        balancedornot(q,a);
    }while(--n);
    
    return 0;
}
void initstack(struct stack *p){
    p->top=-1;
    p->s=(char *)malloc(sizeof(char) * 128);
}
void push(struct stack *p,char c){
    if(p->top==128){
        printf("Stack is full\n");
        return;
    }
    else{
        p->s[++(p->top)]=c;
    }
}
char pop(struct stack *p){
    if((p->top) == -1){
        printf("Stack is empty\n");
        return ' ';
       }
    else{
        // p->s[p->top];
        (p->top)--;
        return ' ';
    }
}

void balancedornot(struct stack p,char *par){
    
  int i;
 initstack(&p);
  for(i=0;par[i]!='\0';i++){
      if(par[i]=='(' || par[i]=='['){
          push(&p,par[i]);
}
      else if(par[i]==')'){
          if(p.s[p.top]=='(') {
              pop(&p);
              
               
          }
          else {printf("No\n"); return;}
      }
      else if(par[i]==']'){
          if(p.s[p.top]=='['){
          pop(&p);
          
        //   printf("\n%c\n",c);
          }
          else {printf("No\n"); return;}
      }
  }
  if(p.top==-1 && par[i]=='\0') printf("Yes\n");
  else printf("No\n");
}