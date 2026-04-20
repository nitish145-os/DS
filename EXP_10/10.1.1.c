#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 100

int minKey(int key[], bool mstSet[], int vertices) {
	int min = INT_MAX;
	int min_index = -1;
	for(int i =0; i< vertices; i++){
		if(mstSet[i] == false && key[i]<min){
		min = key[i];
		min_index = i;
		}
	}
	return min_index;
}
void printTree(int parent[], int graph[V][V], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void prim(int graph[V][V], int vertices) {
	int par[vertices];
	int key[vertices];
	bool mstSet[vertices];
	
	for(int i =0; i < vertices; i++){
		key[i] = INT_MAX;
		mstSet[i] = false;
	}
	key[0] = 0;
	par[0] = -1;

	for(int count = 0; count < vertices-1; count++){
		int u = minKey(key, mstSet, vertices);
		mstSet[u] = true;
		for(int v =0; v<vertices; v++){
			if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v]<key[v]){
				par[v] = u;
				key[v] = graph[u][v];
			}
		}
		
	}
	printTree(par, graph, vertices);
}

int main() {
    int vertices;
    int graph[V][V];

    printf("No of vertices: ");
    scanf("%d", &vertices);

    printf("Adjacency matrix elements (row wise):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, vertices);

    return 0;
}
