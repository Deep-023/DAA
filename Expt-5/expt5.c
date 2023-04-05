//write a code for dijkstra's algorithm
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

int minDistance(int dist[], bool minSet[], int V)
{
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (minSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}  

void printSolution(int dist[], int V)
{
   printf("Vertex\t\tDistance from Source \n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t %d\n", i, dist[i]);
}

void dijkstra( int v, int graph[v][v], int source){
    int dist[v];
    bool minSet[v];
    for(int i=0;i<v;i++){
        dist[i]=INT_MAX;
        minSet[i]=false;
    }
    dist[source]=0;
    for(int count=0;count<v-1;count++){
        int u = minDistance(dist,minSet,v);
        minSet[u]=true;
        for(int i=0;i<v;i++){
            if(!minSet[i] && graph[u][i] && dist[u]!=INT_MAX && dist[u]+graph[u][i]<dist[i]){
                dist[i]=dist[u]+graph[u][i];
            }
        }
    }
    printSolution(dist,v);
}

int main(){
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    int graph[v][v];
    printf("Enter the adjacency matrix: ");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    dijkstra(v,graph,0);
    return 0;

}

