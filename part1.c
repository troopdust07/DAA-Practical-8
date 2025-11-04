#include <stdio.h> 
#include <stdbool.h> 
#define MAX 20 

bool isSafe(int v, int graph[MAX][MAX], int color[], int c, int V) { 
for (int i = 0; i < V; i++) { 
if (graph[v][i] && c == color[i]) 
return false; 
} 
return true; 
} 

bool graphColoringUtil(int graph[MAX][MAX], int m, int color[], int v, int V) { 
if (v == V) 
return true; 
  
for (int c = 1; c <= m; c++) { 
if (isSafe(v, graph, color, c, V)) { 
color[v] = c; 
if (graphColoringUtil(graph, m, color, v + 1, V)) 
return true; 
color[v] = 0; 
} 
} 
return false; 
} 

void graphColoring(int graph[MAX][MAX], int m, int V) { 
int color[MAX] = {0}; 
if (graphColoringUtil(graph, m, color, 0, V)) { 
printf("\nVertex -> Color\n"); 
for (int i = 0; i < V; i++) 
printf("%d -> %d\n", i, color[i]); 
} else { 
printf("No solution exists\n"); 
} 
} 

int main() { 
int V, E, m; 
int graph[MAX][MAX] = {0}; 
  
printf("Enter vertices: "); 
scanf("%d", &V); 
  
printf("Enter edges: "); 
scanf("%d", &E); 
  
printf("Enter edge pairs:\n"); 
for (int i = 0; i < E; i++) { 
int u, v; 
scanf("%d %d", &u, &v); 
graph[u][v] = 1; 
graph[v][u] = 1; 
} 

printf("Enter colors: "); 
scanf("%d", &m); 
  
graphColoring(graph, m, V); 
return 0; 
}
