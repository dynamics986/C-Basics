#include <stdio.h>
#include <string.h>

#define MAX 102

int edges[MAX][MAX];
int nodes[MAX];

int isBipartite(int start, int n) {
    int queue[MAX]; // process nodes one by one, BFS
    int front = 0, rear = 0;
    
    nodes[start] = 1; // one identifier is 1
    queue[rear++] = start;
    
    while (front < rear) {
        int current = queue[front++];
        
        for (int i = 1; i <= n; i++) { 
            if (edges[current][i]) { // check all adjacent nodes
                if (nodes[i] == -1) {
                    nodes[i] = 1 - nodes[current]; // fill another identifier
                    queue[rear++] = i; 
                }
                else if (nodes[i] == nodes[current]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        int n;
        scanf("%d", &n);
        
        // Initialize edges and nodes array
        memset(edges, 0, sizeof(edges));
        memset(nodes, -1, sizeof(nodes)); // not filled
        
        // Input Process
        int u, v;
        while (scanf("%d", &u)) {
            if (u == -1) break;
            scanf("%d", &v);
            edges[u][v] = 1;
            edges[v][u] = 1;
        }
        
        // Check bipartite condition for all nodes
        int bipartite = 1;
        for (int i = 1; i <= n; i++) {
            if (nodes[i] == -1) {
                if (!isBipartite(i,n)) {
                    bipartite = 0;
                    break;
                }
            }
        }
        
        printf("%s\n", bipartite ? "YES" : "NO");
    }
    
    return 0;
}