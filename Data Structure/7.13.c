#include <stdio.h>
#include <string.h>

#define MAX 505

int adj[MAX][MAX];
int adj_count[MAX];
int indegree[MAX];
int used[MAX];

void reset(int n) {
    for (int i = 1; i <= n; i++) {
        adj_count[i] = 0;
        indegree[i] = 0;
        used[i] = 0;
    }
}

void topological_sort(int n) {
    int result[MAX], cnt = 0;
    while (cnt < n) {
        int min_node = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && indegree[i] == 0) {
                min_node = i;
                break;
            }
        }
        if (min_node == 0) break; // Should not happen for valid input
        result[cnt++] = min_node;
        used[min_node] = 1;
        for (int i = 0; i < adj_count[min_node]; i++) {
            int v = adj[min_node][i];
            indegree[v]--;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n, m;
        scanf("%d", &n);
        reset(n);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a][adj_count[a]++] = b;
            indegree[b]++;
        }
        topological_sort(n);
    }
    return 0;
}