# include<stdio.h>
int arr[10][10], visited[10], n;

void dfs(int v){

    visited[v] = 1;

    for(int i=0; i<n; i++){

        if(arr[v][i] == 1 && visited[i] == 0){
            printf("%d -> %d ", v, i);
        }
    }   
}
int main()
{
    int count=0;
    printf("\nEnter the Vertex : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        visited[i] = 0;
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    dfs(0);
    printf("\n");

    for(int i=0; i<n; i++){

        if(visited[i]) count++;
    }

    if(count == n-1) 
        printf("\nGraph is Connected");
    else    
        printf("\nGraph is not Connected");

    return 0;
}