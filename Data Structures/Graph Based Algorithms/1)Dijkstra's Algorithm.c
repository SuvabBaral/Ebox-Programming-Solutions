#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[], int V)
{
   // Initialize min value
   int min = INT_MAX, min_index, v;
 
   for (v = 0; v < V; v++)
     if (sptSet[v] == 0 && dist[v] <= min && dist[v]!=0)
         min = dist[v], min_index = v;
 
//   printf("\nmin:%d",min_index);
   return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int *dist, int V)
{
	int i;
   printf("Vertex   Distance from Source\n");
   for (i = 0; i < V; i++)
      printf("%d%11d\n", i, dist[i]);
}
 
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int **graph, int src, int V)
{
int dist[V];
int sptSet[V];
int i,j;
int minIndex;

int sum;

for(i=0;i<V;i++){
    dist[i]=graph[src][i];
    sptSet[i]=0;
}
dist[src]=0;
sptSet[src]=1;
// printf("\n%d\n",dist[0]);
for(j=0;j<V;j++){
    minIndex=minDistance(dist,sptSet,V);
    sptSet[minIndex]=1;
    for(i=0;i<V;i++){
    if(i==src) continue;
    if(graph[minIndex][i]!=0){
    sum=dist[minIndex]+graph[minIndex][i];
    if(dist[i]==0){
        dist[i]=sum;
    }
    else if(sum<dist[i]){
        dist[i]=sum;
    }
    }
    }
    
}
    
     printSolution(dist, V);
     
}
 
// driver program to test above function
int main()
{
	int **graph;
	int V,src,i,edges,snode,enode,weight;
	printf("Enter the number of nodes in the graph\n");
	scanf("%d",&V);

	printf("Enter the number of edges in the graph\n");
	scanf("%d",&edges);
	graph = (int **)malloc(V * sizeof(int *));
	for(i=0;i<V;i++)
		*(graph+i) = (int *) calloc(V,sizeof(int));
	
	for(i = 0;i<edges;i++)
	{
		printf("Enter the start node, end node and weight of edge no %d\n",i);
		scanf("%d%d%d",&snode,&enode,&weight);
		*(*(graph+snode)+enode) = weight;
		*(*(graph+enode)+snode) = weight;
	}
// 	for(i=0;i<V;i++){
// 	    for(j=0;j<V;j++){
// 	        printf("%d ",graph[i][j]);
// 	    }
// 	    printf("\n");
// 	}
	
	printf("Enter the source matrix:\n");
	scanf("%d",&src);
        dijkstra(graph, src, V);
        return 0;