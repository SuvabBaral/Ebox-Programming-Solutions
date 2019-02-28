#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 50
struct postfix
{
       int stack[MAX];
        int top,nn;
      char *s;
};
    void initpostfix(struct postfix *);
     void setexpr(struct postfix *, char *str);
     void push(struct postfix *, int item);
     int pop(struct postfix *);
     void calculate(struct postfix *);
     void show(struct postfix );
     void display(struct postfix *p){
         int i=0;
         for(i=0;i<p->top;i++){
             printf("%d ",p->stack[i]);
         }
         printf("\n");
     }

int main()
{
   char expr[MAX];
  printf("Enter postfix expression to be evaluated:\n");
  scanf("%s",expr);
   struct postfix p;
  initpostfix(&p);
  setexpr(&p,expr);
  calculate(&p);
  show(p);
  return 0;
}
void initpostfix(struct postfix *p)
  {
       p->top  = -1;
  }
void setexpr(struct postfix *p, char *str)
{
   
    p->s = str;
}
void push(struct postfix *p, int item)
{
       
        p->top++;
        p->stack[p->top]=item;
}
int pop(struct postfix *p)
{
     int t = p->stack[p->top];
     p->top--;
     return t;
}
void calculate(struct postfix *p)
{
    int i=0;
    while((*(p->s+i))!='\0'){
        if(((*(p->s+i)) >47) && ((*(p->s+i))<58)){
            push(p,(int)(*(p->s+i))-48);
        }
        else if((*(p->s+i))=='+'){
            int x = pop(p);
            int y = pop(p);
            push(p,x+y);
        }
        else if((*(p->s+i))=='-'){
            int x = pop(p);
            int y = pop(p);
            push(p,y-x);
        }
        else if((*(p->s+i))=='*'){
            int x = pop(p);
            int y = pop(p);
            push(p,y*x);
        }
        else if((*(p->s+i))=='/'){
            int x = pop(p);
            int y = pop(p);
            push(p,y/x);
        }
        i++;
    }
}
void show(struct postfix p)
{
    
     printf("Result is: %d",pop(&p));
}