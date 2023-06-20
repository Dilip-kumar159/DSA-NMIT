#include<stdio.h>
int arr[5][5], n, indegree[10];

void find_degree(){

    for(int j=0; j<n; j++){
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i][j];
        }
            indegree[j] = sum;
    }
}

void topology(){

    int u, v, s[10], t[10], top = -1, k = 0;

    find_degree();

    for(int i=0; i<n; i++){
        if(indegree[i] == 0)
            s[++top] = i;
    }

    while(top != -1){

        u = s[top--];
        t[k++] = u;

        for(v = 0; v<n; v++){

            if(arr[u][v] == 1){
                indegree[v]--;
                if(indegree[v] == 0){
                    s[++top] = v;
                }
            }
        }
    }

    printf("\nTopological sort : ");
    for(int i=0; i<n; i++){
        printf("%d ", t[i]);
    }

}
int main()
{
    printf("\nEnter the vertices : ");
    scanf("%d", &n);

    printf("\nEnter the elements in matrix ");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    topology();

    return 0;
}