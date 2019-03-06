//Graph --- Adjacency matrix and Adjacency list representation

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node ** convmattolist(int **,int,char *);
void printlist(struct node **,int);
void printadjmatrix(int **,int);

struct node
{
	int nodeno;
	int edgeweight;
	struct node *link;
};


int main()
{
	int **A;
	int rows,edges,snode,enode,weight;
	int i;
	char directed[4];

	struct node **list;


	printf("Please enter the number of nodes in the graph\n");
	scanf("%d",&rows);

	printf("Please enter the number of edges in the graph\n");
	scanf("%d",&edges);

	printf("Is the graph directed\n");
	scanf("%s",directed);

	A = (int **)malloc(rows * sizeof(int *));
	for(i=0;i<rows;i++)
		*(A+i) = (int *) calloc(rows,sizeof(int));

	// Read the graph information and construct the adjacency matrix
	for(i=0;i<edges;i++){
	printf("Enter the start node, end node and weight of edge no %d\n",i);
    scanf("%d%d%d",&snode,&enode,&weight);
	if(strcmp("yes",directed)==0){
	    A[snode][enode]=weight;
	}
	else{
	    A[snode][enode]=weight;
	    A[enode][snode]=weight;
	}
	    
	}
	list = convmattolist(A,rows,directed);
	printadjmatrix(A,rows);
	printlist(list,rows);
        return 0;

}
struct node *createNode(int data,int w){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->nodeno=data;
    nn->edgeweight=w;
    nn->link=NULL;
    return nn;
    
    
}

struct node ** convmattolist(int **A,int rows,char *dir)
{
    struct node **head=(struct node **)malloc(rows * sizeof(struct node *));
    int i,j;
    for(i=0;i<rows;i++){
    *(head+i)=NULL;
    for(j=0;j<rows;j++){
        if(A[i][j]!=0){
        if(*(head+i)==NULL){
            *(head+i)=createNode(j,A[i][j]);
        }
        else{
            struct node *temp=*(head+i);
            while(temp->link!=NULL){
                temp=temp->link;
            }
        temp->link=createNode(j,A[i][j]);
        }
    }
    }
    }
    return head;
}

void printadjmatrix(int **A,int rows)
{
	printf("Adjacency Matrix Representation:\n");
	int i,j;
	for(i=0;i<rows;i++){
	    for(j=0;j<rows;j++){
	        printf("%d ",A[i][j]);
	}
	printf("\n");
}
}


void printlist(struct node **list,int rows)
{
	printf("Adjacency List Representation:\n");
	struct node *temp;
	int i;
	for(i=0;i<rows;i++){
	 temp=*(list+i);
	 if(temp!=NULL){
	printf("Node %d is connected to the following nodes:\n",i);
	while(temp!=NULL){
	    printf("Node %d with edge weight %d\n",temp->nodeno,temp->edgeweight);
	    temp=temp->link;
	}
	}
	
}
}