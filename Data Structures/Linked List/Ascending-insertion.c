#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct keyboard {
	int key;
	struct keyboard * link;
};
void insert ( struct keyboard **, int ) ;
void display ( struct keyboard * ) ;


int main() {
	struct keyboard *p ;
	p=NULL;
	int keys,choice=1;
	
while(choice<3){
	printf("1.Enter a disassembled key\n2.View keyboard\n3.Exit\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:
	do{
		printf("Enter the key number\n");
		scanf("%d",&keys);
		}while(keys>0 && keys >9);
		insert(&p,keys);
		break;
	case 2:
		display(p);
		break;
	case 3:
		printf("Exit\n");
		break;
}
}
	return 0;
}


void insert ( struct keyboard **q, int num ) {
	struct keyboard *nn;
	nn=(struct keyboard *)malloc(sizeof(struct keyboard));
	nn->key=num;
    if((*q)==NULL){
        nn->link=NULL;
        (*q)=nn;
    }
    else{
        struct keyboard *temp=(*q);
        struct keyboard *prev;
            if(temp->key <= num){
                while(temp!=NULL && temp->key <= num){
                    prev=temp;
                    temp=temp->link;
                }
                nn->link=prev->link;
                prev->link=nn;
            }
            else{
                nn->link=temp;
                (*q)=nn;
                
            }
    }
	
}

void display ( struct keyboard *q ) {
	struct keyboard *temp;
    temp=q;
    if(q==NULL){
        printf("Keyboard has no disassembled key\n");
        return;
    }
    else{
        // int i=1;
        // printf("keyboard list:\n");
        printf("Keyboard:\n");
        while(temp!=NULL){
            //  if(temp->link==NULL) printf("%d",temp->key);
            //  else
            printf("%d ",temp->key);
            temp=temp->link;
        }
        printf("\n");
    } 
}