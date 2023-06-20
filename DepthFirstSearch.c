#include<stdio.h>

void dfs(int edges[10][10], int n, int sv, int visited[]){

    printf("%d ", sv);
    visited[sv] = 1;

    for(int i=0; i<n; i++){

        if(i == sv) continue;

        if(edges[sv][i] == 1){
                if(visited[i] == 0){
                dfs(edges, n, i, visited);
            }
        }
    }
}

int main()
{
    int n, e;

    printf("\nEnter the Vertex : ");
    scanf("%d", &n);

    printf("\nEnter the Edges : ");
    scanf("%d", &e);

    int edges[10][10];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    printf("\nEnter edges from where to where\n");

    for(int i=0; i<e; i++){
        int f, s;
        scanf("%d", &f);
        scanf("%d", &s);
        
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int visited[10];
    for(int i=0; i<10; i++){
        visited[i] = 0;
    }

    printf("\nPrinting Dfs Traversal\n");
    dfs(edges, n, 0, visited);

    return 0;
}