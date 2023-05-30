// Program to Demonstarte Tower Of Hanoi problem

# include<stdio.h>

void towerOfHanoi(int n, char src, char aux, char dest){

    if(n == 1){
        printf("Move Disk 1 from rod %c to rod %c \n", src , dest);
        return;
    }

    towerOfHanoi(n-1, src, dest, aux);
    printf("Move Disk %d from rod %c to rod %c \n", n, src, dest);
    towerOfHanoi(n-1, aux, src, dest);

}
int main()
{
    int n;
    printf("Enter the Number of Disks : \n");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');


    return 0;
}