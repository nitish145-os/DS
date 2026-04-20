#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph represented using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    Node *temp = (Node*) malloc(sizeof(struct Node));
	temp->vertex = vertex;
	temp->next = NULL;
	return temp;
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    Node *temp = createNode(v);
	temp->next = adjList[u];
	adjList[u] = temp;
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
    for(int i =0; i<V; i++){
		Node *prt1, *prt2;
		for(prt1 = adjList[i]; prt1!=NULL; prt1 = prt1->next){
			for(prt2 = prt1->next; prt2!=NULL; prt2 = prt2->next){
				int temp = prt1->vertex;
				prt1->vertex = prt2->vertex;
				prt2->vertex = temp;
			}
		}
	}

    
}

// Depth-First Search (DFS) function
void DFS(int start) {
	visited[start] = 1;
	printf("%d ", start);

	Node *temp = adjList[start];

	while(temp != NULL){
		int v = temp->vertex;
		if(!visited[v]){
			DFS(v);
		}
		temp = temp->next;
	}
	
}

int main() {
    int V, E;
    int u, v, start;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Read the edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort the adjacency list for each vertex
    sortAdjList(V);

    // Read the starting node
    scanf("%d", &start);

    // Perform DFS starting from the given node
    DFS(start);

    return 0;
}
